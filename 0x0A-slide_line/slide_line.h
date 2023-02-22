#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdlib.h>
#include <stdio.h>

int slide_line(int *line, size_t size, int direction);
static int slide_right(int *line, size_t size);
static int slide_left(int *line, size_t size);

#define SLIDE_LEFT 1
#define SLIDE_RIGHT 2

#endif /* SLIDE_LINE_H */
