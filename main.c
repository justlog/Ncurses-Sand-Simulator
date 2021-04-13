#include <ncurses.h>
#include <sys/time.h>
#include <stdlib.h>
#include "particle.h"
#include "cursor.h"
#include "myTime.h"
int maxlines, maxcols;
int numPar = 0;
char* matrix;
cursor cur;

int main()
{
        int ch = 0;
        double framesInMs = (1.0/60.0) * 1000.0;
        int spawnedParticles = 0;

        particle pList[MAXPAR];
        Timer t;

        //Initalize ncurses and global variables.
        initscr(); cbreak(); noecho();
        keypad(stdscr, TRUE);
        clear();
        nodelay(stdscr, TRUE);
        maxlines = LINES - 1;
        maxcols = COLS - 1;

        //Initalize world matrix.
        matrix = (char *)malloc(COLS * LINES * sizeof(char));
        for(int i = 0; i < LINES; ++i)
                for(int j = 0; j < COLS; ++j)
                {
                        matrix[i*LINES+j] = 0;
                }


        initCursor(&cur);

        printCursor(&cur);
        refresh();

        timeInit(&t);
        while((ch = getch()) != KEY_F(1))
        {
                mvprintw(0, 0, "Maximum lines:%d Maximum cols:%d", LINES, COLS);
                mvprintw(100, 100, "Spawned particles:%d", spawnedParticles);
                tick(&t);
                if(t.elapsedTime >= framesInMs)
                {
                        frameTick(&t, framesInMs);
                        updateParList(pList);
                }
                switch(ch)
                {
                        case KEY_LEFT:
                                clearCursor(&cur);
                                --(cur.x);
                                printCursor(&cur);
                                break;

                        case KEY_RIGHT:
                                clearCursor(&cur);
                                ++(cur.x);
                                printCursor(&cur);
                                break;

                        case KEY_UP:
                                clearCursor(&cur);
                                --(cur.y);
                                printCursor(&cur);
                                break;

                        case KEY_DOWN:
                                clearCursor(&cur);
                                ++(cur.y);
                                printCursor(&cur);
                                break;
                        case KEY_BACKSPACE:
                                spawnPar(pList);
                                ++spawnedParticles;
                                break;
                        default:
                                break;
                }
                mvprintw(0, 100, "x:%d y:%d", cur.x, cur.y);
                refresh();
        }


        refresh();
        getch();
        endwin();
}
