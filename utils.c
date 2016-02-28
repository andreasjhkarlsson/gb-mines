#include <gb/gb.h>
#include <stdint.h>
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