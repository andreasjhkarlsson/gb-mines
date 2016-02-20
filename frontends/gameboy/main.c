#include <gb/gb.h>
#include <gb/drawing.h>
#include <asm/types.h>
#include <board.h>
#include "start.h"
#include "game.h"


void main()
{
	SHOW_BKG;
	DISPLAY_ON;
	show_start();
	play_game();
}
