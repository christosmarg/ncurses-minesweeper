#ifndef NAVIGATION_H
#define NAVIGATION_H

#include "main.h"
#include "minesweeper.h"

void navigate	(Board *b, int *mv);
void getmv		(Board *b, int *mv, int *y, int *x);
void mvup		(int *y);
void mvdown		(int *y, int xmax);
void mvleft		(int *x);
void mvright	(int *x, int xmax);
void update_curs(Board *b, int y, int x);

#endif /* NAVIGATION_H */