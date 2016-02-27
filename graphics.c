#include "graphics.h"
#include <stdlib.h>
#include <gb/gb.h>

// Tiledata buffers are too big to be stored in heap.
unsigned char tiledata_stack[360 * 4];

struct graphics
{
	struct loaded_tileset* first_tileset;
	struct graphics* next_graphics;
	unsigned char* saved_tilemap;
	unsigned char saved_lcdc;
	unsigned char stack_depth;
} base = {.first_tileset = NULL, .next_graphics = NULL, .stack_depth = 0};

// Top of graphics stack
struct graphics* graphics = &base;

void push_graphics()
{
	struct graphics* new_graphics = (struct graphics*) malloc(sizeof(struct graphics));

	// Save tilemap
	graphics->saved_tilemap = tiledata_stack + (360*graphics->stack_depth);
	graphics->saved_lcdc = LCDC_REG;
	get_bkg_tiles(0, 0, 20, 18, graphics->saved_tilemap);

	new_graphics->first_tileset = NULL;
	new_graphics->next_graphics = graphics;
	new_graphics->stack_depth = graphics->stack_depth + 1;
	graphics = new_graphics; // Place new graphics on top of stack.
}

void pop_graphics()
{
	struct loaded_tileset* tileset;
	struct loaded_tileset* next;
	struct graphics* old_graphics;

	// Free loaded tilesets
	tileset = graphics->first_tileset;
	while (tileset)
	{
		next = tileset->next;
		free(tileset);
		tileset = next;
	} 

	// Pop stack!
	old_graphics = graphics->next_graphics;
	free(graphics);
	graphics = old_graphics;

	HIDE_BKG;

	// Restore tiles
	tileset = graphics->first_tileset;
	while (tileset)
	{
		set_bkg_data(tileset->loaded_at, tileset->tileset->count, tileset->tileset->tiles);
		tileset = tileset->next;
	}

	// Restore tilemap
	set_bkg_tiles(0, 0, 20, 18, graphics->saved_tilemap);

	SHOW_BKG;

	// Restore LCDC
	LCDC_REG = graphics->saved_lcdc;
}

// Load tiles into vram
struct loaded_tileset* load_tileset(struct tileset* tileset)
{
	struct loaded_tileset* last_tileset = graphics->first_tileset;
	struct loaded_tileset* loaded_tileset;
	int offset = 0;

	// Do not load same tileset multiple times (checks the first loaded tileset)
	if (last_tileset && last_tileset->tileset == tileset)
		return last_tileset;

	while (last_tileset && last_tileset->next)
	{
		// Same check as above, but check every loaded tilecheck
		if (last_tileset->tileset == tileset)
			return last_tileset;
		last_tileset = last_tileset->next;
	}

	// Heap alloc :(( (todo, stack allocate or something)
	loaded_tileset = (struct loaded_tileset*) malloc(sizeof(struct loaded_tileset));

	if (last_tileset)
	{
		last_tileset->next = loaded_tileset;
		offset = last_tileset->loaded_at + last_tileset->tileset->count;
	}
	else
	{
		graphics->first_tileset = loaded_tileset;
	}

	loaded_tileset->loaded_at = offset;
	loaded_tileset->next = NULL;
	loaded_tileset->tileset = tileset;


	set_bkg_data(loaded_tileset->loaded_at, loaded_tileset->tileset->count, loaded_tileset->tileset->tiles);

	return loaded_tileset;
}

struct tilemap* load_tilemap(unsigned char* map, int width, int height)
{
	struct tilemap* tilemap = (struct tilemap*) malloc(sizeof(struct tilemap));
	tilemap->map = map;
	tilemap->width = width;
	tilemap->height = height;
	return tilemap;
}


void place_tiles(struct loaded_tileset* tileset, struct tilemap* tilemap, int dx, int dy)
{
	unsigned char tile;
	int x, y;

	if (tileset->loaded_at == 0)
	{
		set_bkg_tiles(dx, dy, tilemap->width, tilemap->height, tilemap->map);
		return;
	}

	for (x=0;x < tilemap->width;x++)
	{
		for (y=0;y < tilemap->height;y++)
		{
			tile = tilemap->map[y*tilemap->width + x] + tileset->loaded_at;
			set_bkg_tiles(dx+x, dy+y, 1, 1, &tile);
		}
	}
}

void place_tile(struct loaded_tileset* tileset, int tile, int x, int y)
{
	unsigned char tileset_tile = (unsigned char)tileset->loaded_at + tile;
	set_bkg_tiles(x, y, 1, 1, &tileset_tile);
}