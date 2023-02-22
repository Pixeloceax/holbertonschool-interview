#include "slide_line.h"

/**
 *slide_left - slides and merges an array of integers to the left
 *@line: points to an array of integers containing size elements
 *@size: number of elements in array
 *Return: 1 upon success, or 0 upon failure
 */
static int slide_left(int *line, size_t size)
{
	int i, n;

	for (i = 0, n = 0; i < (int)size; i++)
	{
		if (line[i] != 0)
		{
			if (i != n)
			{
				line[n] = line[i];
				line[i] = 0;
			}
			n++;
		}
	}

	for (i = 0; i < (int)size - 1; i++)
	{
		if (line[i] == line[i + 1])
		{
			line[i] *= 2;
			line[i + 1] = 0;
		}
	}

	for (i = 0, n = 0; i < (int)size; i++)
	{
		if (line[i] != 0)
		{
			if (i != n)
			{
				line[n] = line[i];
				line[i] = 0;
			}
			n++;
		}
	}

	return (1);
}

/**
 *slide_right - slides and merges an array of integers to the right
 *@line: points to an array of integers containing size elements
 *@size: number of elements in array
 *Return: 1 upon success, or 0 upon failure
 */
static int slide_right(int *line, size_t size)
{
	int i, n;

	for (i = size - 1, n = size - 1; i >= 0; i--)
	{
		if (line[i] != 0)
		{
			if (i != n)
			{
				line[n] = line[i];
				line[i] = 0;
			}
			n--;
		}
	}

	for (i = size - 1; i > 0; i--)
	{
		if (line[i] == line[i - 1])
		{
			line[i] *= 2;
			line[i - 1] = 0;
		}
	}

	for (i = size - 1, n = size - 1; i >= 0; i--)
	{
		if (line[i] != 0)
		{
			if (i != n)
			{
				line[n] = line[i];
				line[i] = 0;
			}
			n--;
		}
	}

	return (1);
}

/**
 *slide_line - slides and merges an array of integers
 *@line: points to an array of integers containing size elements
 *@size: number of elements in array
 *@direction: can be either:
 *Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	if (direction == SLIDE_LEFT)
		return (slide_left(line, size));
	else
		return (slide_right(line, size));
}
