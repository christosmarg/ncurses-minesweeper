#include "navigation.h"

void
navigate(Board *b, int *mv)
{
    static int y = 1, x = 2;
    curs_update(b, y, x);
    b->x = ARRSPACE_X(x);
    b->y = ARRSPACE_Y(y);
    refresh();
    getmv(b, mv, &y, &x);
}

void
getmv(const Board *b, int *mv, int *y, int *x)
{
    *mv = wgetch(b->gw);
    switch (*mv)
    {
        case 'k': case 'K': /* FALLTHROUGH */
        case 'w': case 'W':
            mvup(y);
            break;
        case 'j': case 'J': /* FALLTHROUGH */
        case 's': case 'S':
            mvdown(y, YMAX(b->gw));
            break;
        case 'h': case 'H': /* FALLTHROUGH */
        case 'a': case 'A':
            mvleft(x);
            break;
        case 'l': case 'L': /* FALLTHROUGH */
        case 'd': case 'D':
            mvright(x, XMAX(b->gw));
            break;
    }
}

void
mvup(int *y)
{
    (*y)--;
    if (*y < 1) *y = 1;
}

void
mvdown(int *y, int ymax)
{
    (*y)++;
    if (*y > ymax-2) *y = ymax-2;
}

void
mvleft(int *x)
{
    *x -= 3;
    if (*x < 2) *x = 2;
}

void
mvright(int *x, int xmax)
{
    *x += 3;
    if (*x > xmax-3) *x = xmax-3;
}

void
curs_update(const Board *b, int y, int x)
{
    wmove(b->gw, y, x);
}
