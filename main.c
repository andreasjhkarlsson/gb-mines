#include <gb/gb.h>
#include <gb/drawing.h>
#include <asm/types.h>
#include <board.h>
#include "start.h"
#include "game.h"


void main()
{
	int difficulty;
	DISPLAY_ON;
	while (1)
	{
		difficulty = show_start();
		play_game(difficulty);
		delay(250);
	}
}
