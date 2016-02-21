#ifndef GAME_H
#define GAME_H

enum Difficulty
{
	EASY = 0,
	NORMAL = 1,
	HARD = 2,
	INSANE = 3
};

void play_game(int difficulty);

#endif