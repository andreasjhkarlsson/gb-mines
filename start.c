#include <gb/gb.h>
#include "start.h"
#include "about.h"
#include "game.h"

// Generated from: http://www.chrisantonellis.com/gameboy/gbtdg/

const int startscreen_tile_map_size = 0x0168;
const int startscreen_tile_map_width = 0x14;
const int startscreen_tile_map_height = 0x12;

const int startscreen_tile_data_size = 0x0630;
const int startscreen_tile_count = 0x0168;

const unsigned char startscreen_map_data[] = {
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,
	0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x00,0x00,0x00,0x00,0x00,0x10,0x11,0x12,0x13,0x14,
	0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x20,0x21,
	0x22,0x23,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x24,0x25,0x26,0x27,0x28,0x29,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F,0x30,0x31,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x32,0x33,0x2C,0x34,0x35,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x36,0x37,0x38,0x39,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x3A,0x3B,0x3C,0x3D,0x3E,0x3F,0x40,0x41,0x42,0x43,0x44,0x45,0x46,
	0x43,0x00,0x00,0x00,0x00,0x00,0x00,0x47,0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,
	0x50,0x51,0x52,0x53,0x54,0x00,0x00,0x00,0x00,0x00,0x00,0x55,0x56,0x57,0x58,0x59,
	0x5A,0x5B,0x5C,0x5D,0x5E,0x5F,0x60,0x61,0x62,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

const unsigned char startscreen_tile_data[] = {
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x60,0xF0,0x78,0xF0,0x78,0x79,0x7D,0x79,0x7F,0x7F,0x4E,0x7F,0x4E,0x6E,
	0x00,0x00,0xE5,0x73,0xE3,0xF7,0xE3,0xE3,0xE3,0xE3,0xE3,0xE3,0xE3,0xE3,0xE3,0xE3,
	0x00,0x00,0x8C,0xDE,0x8F,0xDF,0x8F,0x8F,0x8F,0x8F,0x8F,0x8F,0x8E,0x8D,0x8C,0x8C,
	0x00,0x00,0x0C,0x1E,0x1C,0x0E,0xCC,0x8C,0xEC,0xCC,0xFC,0xFC,0xFC,0xFC,0xFC,0x7C,
	0x00,0x00,0xFF,0xFF,0x71,0xF3,0x65,0x70,0x66,0x74,0x7E,0x7C,0x76,0x74,0x70,0x74,
	0x00,0x00,0x14,0x0F,0xB9,0x3F,0x79,0x38,0x3A,0x7C,0x3F,0x3F,0x3F,0x1F,0x0B,0xC7,
	0x00,0x00,0x1F,0x8E,0xCE,0x9F,0x8E,0xCF,0x0F,0x07,0x07,0x87,0x83,0xC7,0xC7,0xC3,
	0x00,0x00,0x3C,0x79,0x7D,0x78,0x7D,0x38,0x7C,0x3D,0x7D,0xFF,0xDF,0xFF,0xDE,0xCF,
	0x00,0x00,0xDF,0xDF,0xCE,0xDE,0xCC,0x8E,0x8C,0x8E,0x8F,0x0F,0x0E,0x0E,0x0E,0x0E,
	0x00,0x00,0xE7,0xE7,0x33,0x67,0xA3,0x03,0xC3,0x83,0xC3,0x83,0xC3,0x83,0x03,0x93,
	0x00,0x00,0xFB,0xF9,0x8C,0x99,0x28,0x80,0x30,0xA0,0xF0,0xE0,0xB0,0xA0,0x80,0xA4,
	0x00,0x00,0x1A,0xFC,0xF6,0xEF,0xE7,0xE7,0xE7,0xE7,0xEF,0xE7,0xFF,0xFE,0xFC,0xE0,
	0x00,0x00,0x7F,0x7F,0x3D,0x78,0x30,0x38,0x32,0x39,0x3F,0x3F,0x39,0x3B,0x39,0x38,
	0x00,0x00,0xCF,0x9F,0xCF,0xDE,0x4E,0x0E,0x0E,0x0E,0x0F,0x0E,0x0F,0x0F,0x4E,0x0E,
	0x00,0x00,0xA0,0xC0,0xE0,0xF0,0xF0,0x70,0xF0,0x70,0xF0,0xE0,0xE0,0xE0,0x70,0xF0,
	0x46,0x6C,0xCD,0x64,0x65,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xE3,0xE3,0xE7,0xF3,0xE3,0xF7,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x8C,0x8C,0x8C,0xDE,0x8C,0xDE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x3C,0x3C,0x0C,0x1C,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x70,0x71,0x7D,0xF3,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xA3,0xE3,0x73,0xBF,0x2D,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x83,0xC3,0x83,0x81,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xCF,0x8E,0x86,0x8E,0x06,0x84,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x0E,0x0E,0x0F,0x1E,0x1F,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x13,0x33,0xA3,0x77,0xE7,0xE7,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x84,0x8C,0xE9,0x9C,0xF8,0xF9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xE0,0xE0,0xF0,0xE0,0xE0,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x38,0x38,0x3F,0x78,0x7F,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x6E,0x4E,0xCF,0xDE,0x8F,0xDE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x78,0x70,0x78,0x78,0x1C,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x04,0x03,0x0F,0x0F,0x0F,0x1F,0x1C,0x38,0x38,0x30,0x70,0x30,
	0x00,0x00,0x00,0x00,0x40,0x80,0xF0,0xE0,0xF0,0xF8,0xBC,0x7C,0x0F,0x1E,0x0F,0x07,
	0x10,0x08,0x0C,0x18,0x04,0x0C,0x02,0x06,0x00,0x03,0x00,0x01,0x00,0x00,0x00,0x80,
	0x08,0x0C,0x0C,0x08,0x0C,0x08,0x08,0x08,0x00,0x08,0x80,0x08,0x88,0x00,0x00,0x00,
	0x00,0x04,0x0C,0x0C,0x08,0x18,0x30,0x10,0x20,0x20,0x00,0x40,0x80,0x00,0x00,0x00,
	0x00,0x00,0x01,0x00,0x01,0x03,0x01,0x03,0x01,0x03,0x01,0x03,0x0F,0x07,0x0F,0x1F,
	0x70,0x30,0x74,0xF8,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFF,0xFE,0xFF,0xFF,0xFF,0xFF,
	0x03,0x03,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xE0,
	0xC0,0xC0,0xF0,0xE0,0xF0,0x78,0x3E,0x3C,0x0F,0x1F,0x03,0x07,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x38,0xF8,0xF8,0xF0,0xF0,0xC0,0x00,0x00,0x00,
	0x00,0x00,0x1B,0x06,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x14,0x08,
	0x00,0x00,0x00,0x00,0x01,0x00,0x01,0x01,0x01,0x03,0x03,0x03,0x07,0x03,0x03,0x07,
	0x7F,0x3F,0xFF,0x7F,0xFF,0xFF,0xFF,0xFF,0x9F,0xCF,0xCF,0x87,0x8F,0x8F,0x0F,0x8F,
	0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
	0xF0,0xF0,0xF8,0xF8,0xFC,0xFC,0xFC,0xFE,0xFE,0xFE,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x01,
	0x22,0x00,0x61,0x00,0x20,0x41,0x40,0x41,0x00,0xC1,0xC0,0x80,0x80,0x80,0x80,0x80,
	0x03,0x06,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x03,0x07,0x07,0x03,0x03,0x03,
	0x1F,0x8F,0x8F,0x1F,0x8F,0x1F,0x9F,0x0F,0x1F,0x8F,0x8F,0x8F,0x87,0x8F,0xC7,0x87,
	0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,
	0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x03,0x01,0x01,0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xC7,0xC3,0xC3,0xE1,0xF1,0xE0,0x78,0xF0,0x38,0x7C,0x3C,0x1F,0x07,0x0F,0x02,0x01,
	0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFA,0xFC,
	0xFE,0xFE,0xFE,0xFC,0xF8,0xFC,0xF0,0xF8,0xE0,0xF0,0xC0,0xE0,0x00,0x80,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x0F,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD1,0xE3,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF4,0xF8,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x3F,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC5,0xC3,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xE0,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0xF8,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x05,0x03,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xE3,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xF8,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x30,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x3F,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x47,0x83,
	0x0F,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x07,0x0F,0x07,
	0xB1,0x7B,0x39,0x39,0x39,0x39,0x39,0x39,0xF9,0xF1,0xE1,0x01,0x01,0x01,0x81,0x03,
	0xFC,0xDE,0xDE,0xCE,0xDE,0xCE,0xFE,0xDC,0xFC,0xFC,0xCE,0xDE,0xCF,0xCE,0xEF,0xCF,
	0x1C,0x3C,0x19,0x1C,0x19,0x1D,0x1F,0x1F,0x1D,0x1D,0x1C,0x1D,0x1C,0x1C,0x1F,0x3C,
	0x6E,0xCF,0x5E,0x0E,0x8E,0x1F,0x8F,0x0F,0x8F,0x07,0x02,0x31,0x28,0x78,0x5C,0xEF,
	0x73,0xE3,0x67,0x33,0x83,0x07,0xC3,0xE3,0xE3,0xF1,0xF0,0xF4,0xE2,0xF6,0xE7,0xE3,
	0x9C,0xF8,0x98,0x8C,0xA0,0xC0,0xF0,0xF8,0xF8,0xFC,0xBC,0x7C,0x38,0x3C,0x38,0xF8,
	0x0E,0x0F,0x1E,0x0E,0x0E,0x1F,0x0F,0x0F,0x0F,0x07,0x02,0x11,0x08,0x18,0x1C,0x0F,
	0x77,0xE7,0x6C,0x36,0x84,0x00,0xC0,0xE0,0xE0,0xF0,0xF0,0xF0,0xE1,0xF0,0xE3,0xE1,
	0xFC,0xFC,0xE6,0xEC,0xE4,0xE0,0xE0,0xE0,0xE1,0xE0,0xE0,0xE1,0xE1,0xE1,0xE1,0xF3,
	0x78,0x70,0x78,0x78,0xF8,0x7C,0x1C,0xDC,0x8C,0x9E,0xFE,0xFE,0x0E,0xFF,0x8F,0x0F,
	0x1F,0x3D,0x1D,0x1C,0x1D,0x1C,0x1F,0x1D,0x1F,0x1F,0x1C,0x1D,0x1C,0x1C,0x9E,0x3C,
	0xC7,0xE7,0xEC,0xE6,0xE4,0xE0,0xE0,0xC0,0xC0,0xC0,0xE0,0xE0,0xF1,0xE0,0xF3,0xF1,
	0xFC,0xFC,0xE6,0xEC,0xE4,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xE0,0xF0,
	0x07,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x01,0x83,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xE3,0xC7,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xBF,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xCB,0xC7,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x42,0x81,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xD0,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x0B,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x40,0x81,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xE3,0xF7,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x1F,0x8F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x1E,0xBC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x38,0x71,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xE0,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

const unsigned char easy_map_data[] = {
	0x00,0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x00,0x00,0x00,0x00,0x07,0x08,0x09,0x0A,
	0x0B,0x0C,0x00,0x00
};

const unsigned char easy_tile_data[] = {
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x04,0x1C,0x38,0x20,0x70,
	0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0x3F,0x3B,0x19,0x3A,0x1A,0x3E,0x1E,0x38,0x1A,
	0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x18,0x38,0x1C,0x1C,0x3C,0x2C,0x2E,0x7E,0x3E,
	0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x3D,0x3C,0x77,0x76,0x78,0x7C,0x3E,0x2E,0x5E,
	0x00,0x00,0x00,0x00,0x00,0x00,0xEC,0xDC,0xCC,0xF8,0x70,0xF0,0x60,0x70,0x60,0x70,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x20,0x38,0x1C,0x04,0x0E,
	0x38,0x1C,0x08,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x3A,0x19,0x3F,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x56,0xEF,0x67,0xEF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x5C,0x6E,0x58,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x60,0x70,0x70,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x1C,0x38,0x10,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

const unsigned char normal_map_data[] = {
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x00,0x00,0x09,0x0A,0x0B,0x0C,0x0D,
	0x0E,0x0F,0x10,0x00
};

const unsigned char normal_tile_data[] = {
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x08,0x38,0x70,0x40,0xE0,
	0x00,0x00,0x00,0x00,0x00,0x00,0xF3,0x63,0x71,0x7B,0x39,0x7F,0x3F,0x7F,0x27,0x6F,
	0x00,0x00,0x00,0x00,0x00,0x00,0x8C,0x1E,0x77,0x3F,0x27,0x73,0x63,0x73,0x33,0x73,
	0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x7C,0x7C,0x6E,0xFC,0x6E,0x7C,0xFC,0xFE,0x6E,
	0x00,0x00,0x00,0x00,0x00,0x00,0xE1,0x63,0x77,0x73,0x7F,0x77,0x7F,0x7F,0x7F,0x5B,
	0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x8C,0x1C,0x8E,0x8E,0x1E,0x96,0x17,0xBF,0x1F,
	0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x78,0x70,0x38,0x38,0x30,0x38,0x30,0x3A,0x30,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x10,0x1C,0x0E,0x02,0x07,
	0x70,0x38,0x10,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x23,0x67,0x72,0x61,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x7B,0x3F,0x2C,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x77,0x6E,0xE6,0x77,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x6B,0x5B,0x4F,0xE3,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xAB,0x37,0x33,0xF7,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x37,0xBA,0xBE,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x0E,0x1C,0x08,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};


const unsigned char hard_map_data[] = {
	0x00,0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x00,0x00,0x00,0x00,0x07,0x08,0x09,0x0A,
	0x0B,0x0C,0x00,0x00
};

const unsigned char hard_tile_data[] = {
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0xA0,0x70,0xC0,0xE0,
	0x00,0x00,0x00,0x00,0x00,0x00,0xEE,0x77,0xE6,0x77,0x77,0x66,0x7F,0x7E,0x6F,0x76,
	0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x18,0x38,0x1C,0x1C,0x3C,0x2C,0x2E,0x7E,0x3E,
	0x00,0x00,0x00,0x00,0x00,0x00,0xF8,0x7C,0x7C,0x6E,0x7C,0x6E,0x7C,0x7C,0x7E,0x6E,
	0x00,0x00,0x00,0x00,0x00,0x00,0xFA,0xFC,0xE6,0x6E,0xE6,0x67,0xE6,0x67,0xE6,0x67,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x05,0x0E,0x03,0x07,
	0x78,0x30,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x67,0x76,0xEE,0x77,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x56,0x6F,0x67,0xEF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x77,0x6E,0xE6,0x77,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x66,0xEE,0xF8,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x1E,0x0C,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

const unsigned char insane_map_data[] = {
	0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x00,0x00,0x09,0x0A,0x0B,0x0C,0x0D,
	0x0E,0x0F,0x10,0x00
};

const unsigned char insane_tile_data[] = {
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x14,0x0E,0x18,0x1C,
	0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x0F,0x0D,0x0E,0x0E,0x0C,0x0E,0x0C,0x0E,0x0C,
	0x00,0x00,0x00,0x00,0x00,0x00,0xCE,0xC6,0xF4,0xE6,0xFE,0xF4,0xFE,0xFC,0xBE,0xDC,
	0x00,0x00,0x00,0x00,0x00,0x00,0x3C,0x78,0x78,0xEC,0xEC,0xF0,0xF8,0x7C,0x5D,0xBC,
	0x00,0x00,0x00,0x00,0x00,0x00,0x47,0x63,0xE3,0x73,0x71,0xF3,0xB1,0xBB,0xF9,0xFB,
	0x00,0x00,0x00,0x00,0x00,0x00,0x9D,0x1B,0x89,0xD9,0xC9,0xF9,0xF9,0xF9,0x39,0x79,
	0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xF0,0xC8,0x90,0xA0,0xA0,0xE0,0xE0,0xE8,0xA0,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xC0,0x28,0x70,0x18,0x38,
	0x0F,0x06,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x0C,0x0E,0x1D,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x8E,0xCC,0xC2,0xC4,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xB9,0xDD,0xB1,0x7B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x59,0xBF,0x9F,0xBF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x19,0x39,0x91,0x0B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xC8,0x98,0xF8,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0xF0,0x60,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};


void show_difficulty(int difficulty)
{
	const unsigned char* tiles;
	const unsigned char* map;
	int width = 10, height = 2;
	int background_offset = startscreen_tile_count;
	int x, y;
	unsigned char tile;

	if (difficulty == EASY)
	{
		tiles = easy_tile_data;
		map = easy_map_data;
	}
	else if (difficulty == NORMAL)
	{
		tiles = normal_tile_data;
		map = normal_map_data;
	}
	else if (difficulty == HARD)
	{
		tiles = hard_tile_data;
		map = hard_map_data;
	}
	else if (difficulty == INSANE)
	{
		tiles = insane_tile_data;
		map = insane_map_data;
	}

	HIDE_BKG; // Disable background during update to avoid flicker
	set_bkg_data(background_offset, width*height, tiles);
	for (x = 0;x < width;x += 1)
	{
		for (y = 0;y < height; y += 1)
		{
			tile = map[y*width + x] + background_offset;
			set_bkg_tiles((SCREENWIDTH/8/2 - width/2) + x, (SCREENHEIGHT / 8 - height-1) + y, 1, 1, &tile);
		}
	}
	SHOW_BKG;
}

int show_start()
{
	int difficulty = NORMAL;
	int input;
	set_bkg_data(0, startscreen_tile_count, startscreen_tile_data);
	set_bkg_tiles(0, 0, startscreen_tile_map_width, startscreen_tile_map_height, startscreen_map_data);

	
	show_difficulty(difficulty);

	SHOW_BKG;
	HIDE_SPRITES;
	while (1)
	{
		input = joypad();

		if (input&J_LEFT)
		{
			while (joypad()&J_LEFT); // Wait for button up
			if (difficulty == EASY) difficulty = INSANE;
			else difficulty -= 1;
			show_difficulty(difficulty);
		}
		if (input&J_RIGHT)
		{
			while (joypad()&J_RIGHT); // Wait for button up
			if (difficulty == INSANE) difficulty = EASY;
			else difficulty += 1;
			show_difficulty(difficulty);
		}

		if (input&J_SELECT)
		{
			show_about();
			// Recursion takes care of restoring background
			// Hopefully sdcc generates tail calls or else this could lead to stackoverflow
			return show_start(); 
		}

		if (input&J_START)
			break;
	}
	return difficulty;
}
