#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <stdbool.h>

struct tileset
{
	const unsigned char* tiles;
	int count;
};

#define TILESET(NAME,...) const unsigned char NAME##_data_ [] = {__VA_ARGS__}; struct tileset NAME = {.count = sizeof(NAME##_data_) / 16, .tiles = NAME##_data_}

struct loaded_tileset
{
	struct tileset* tileset;
	int loaded_at;
	struct loaded_tileset* next;
};

struct tilemap
{
	const unsigned char* map;
	int width;
	int height;
};

#define TILEMAP(NAME,WIDTH,HEIGHT,...) const unsigned char NAME##_data_ [] = {__VA_ARGS__}; struct tilemap NAME = {.width = WIDTH, .height = HEIGHT, .map = NAME##_data_}

void push_graphics();

void pop_graphics();

struct loaded_tileset* load_tileset(struct tileset* tileset);

void place_tiles(struct loaded_tileset* tileset, struct tilemap* tilemap, int x, int y);

void place_tile(struct loaded_tileset* tileset, int tile, int x, int y);

#endif