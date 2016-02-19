#include <gb/gb.h>
#include <gb/drawing.h>
#include <asm/types.h>
#include <board.h>
#include "logo.h"


void show_logo()
{
	set_bkg_data(0, logo_tile_count, logo_tile_data);
	set_bkg_tiles(0, 0, logo_tile_map_width, logo_tile_map_height, logo_map_data);
	SHOW_BKG;
	DISPLAY_ON;
}

void main()
{
	show_logo();


}
