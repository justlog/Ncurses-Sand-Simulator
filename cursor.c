#include <ncurses.h>
#include "cursor.h"
extern int maxlines;
extern int maxcols;

void initCursor(cursor* c)
{
        c->x = maxcols / 2;
        c->y = maxlines / 2;
        c->symbol = '+';
}
void printCursor(cursor* c)
{
        mvaddch(c->y, c->x, c->symbol);
        refresh();
}
void clearCursor(cursor* c)
{
        mvaddch(c->y, c->x, ' ');
        refresh();
}
