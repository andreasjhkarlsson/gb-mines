#include "utils.h"
#include <gb/gb.h>

// Returns true/false if a button was pressed
// Optionally wait until button was released.
bool button_pressed(unsigned char button, int maxWait)
{
	int i;
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