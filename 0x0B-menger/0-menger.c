#include "menger.h"

/**
 * menger - Draws a 2D Menger Sponge
 * @level: Level of the Menger Sponge to draw
 *
 */

void menger(int level)
{
	int total_size = pow(3, level);
	int i, j, x, y, is_empty;

	for (i = 0; i < total_size; i++)
	{
		for (j = 0; j < total_size; j++)
		{
			is_empty = 0;
			x = i;
			y = j;

			while (x > 0 || y > 0)
			{
				if (x % 3 == 1 && y % 3 == 1)
				{
					is_empty = 1;
					break;
				}
				x /= 3;
				y /= 3;
			}

			if (is_empty == 1)
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}
