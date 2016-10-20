#include <gb/gb.h>
#include <stdint.h>
#include <stdlib.h>
#include "utils.h"

// Returns true/false if a button was pressed
// Optionally wait until button was released.
bool button_pressed(uint8_t button, int16_t maxWait)
{
	int16_t i;
	if (!(joypad()&button))
		return false;
	
	// Wait indefinitely
	if (maxWait == -1)
	{
		while (joypad()&button);
	}
	else
	{
		for (i = 0;i < maxWait;i++)
		{
			if (!(joypad()&button)) break;
			delay(1);
		}
	}

	return true;
}

// Seed prng using current time (8 bit) and previous seed.
// Call multiple times at unpredictable moments (like user input) to increase entropy.
// This works since DIV_REG is only an 8-bit counter, so by using only that,
// only 256 seeds are possible. Every tile this is called, it uses rand to
// create a 16 bit seed from the previous value.
void seed_prng()
{
	srand((rand()<<8)|DIV_REG);
}
