#include <curses.h>
#include "particle.h"
#include "cursor.h"
extern int maxcols;
extern int maxlines;
extern int numPar;
extern char* matrix;
extern cursor cur;
int canMove(particle *p)
{
        return  !(((p->x - 1) < 0) || ((p->x + 1) > maxcols) || ((p->y - 1) < 0) || ((p->y + 1 > maxlines)));
}
void updateParList(particle pList[])
{
        for(int i = 0; i < numPar; ++i)
        {
                particle *currentP = &pList[i];
                if(canMove(currentP))
                {
                        //If has open spaces in matrix.
                        if(!(matrix[LINES * currentP->x + currentP->y + 1]))
                        {
                                matrix[LINES * currentP->x + currentP->y] = FALSE;
                                clearPar(currentP);
                                ++currentP->y;
                                matrix[LINES * currentP->x + currentP->y] = TRUE;
                                printPar(currentP);
                        }
                        else if(!(matrix[LINES * (currentP->x - 1) + currentP->y + 1]))
                        {
                                matrix[LINES * currentP->x + currentP->y] = FALSE;
                                clearPar(currentP);
                                ++currentP->y;
                                --currentP->x;
                                matrix[LINES * currentP->x + currentP->y] = TRUE;
                                printPar(currentP);
                        }
                        else if(!(matrix[LINES * (currentP->x+1) + currentP->y+1]))
                        {
                                matrix[LINES * currentP->x + currentP->y] = FALSE;
                                clearPar(currentP);
                                ++currentP->y;
                                ++currentP->x;
                                matrix[LINES * currentP->x + currentP->y] = TRUE;
                                printPar(currentP);
                        }
                }
        }
}
void spawnPar(particle pList[])
{
        matrix[LINES * cur.x + cur.y + 1] = TRUE;//Mark particle placement in matrix.
        //Settings particle coordinates.
        pList[numPar].x = cur.x;
        pList[numPar].y = cur.y+1;
        pList[numPar++].Sym = '.';//Increment number of particles.
}
void clearPar(particle *p)
{
        mvaddch(p->y, p->x, ' ');
        refresh();
}
void printPar(particle *p)
{
        mvaddch(p->y, p->x, p->Sym);
        refresh();
}
