#include "myTime.h"
#include <stdlib.h>
#include <sys/time.h>
void timeInit(struct Timer *t)
{
        gettimeofday(&(t->t1), NULL);
        gettimeofday(&(t->t2), NULL);
}
void tick(struct Timer *t)
{
        gettimeofday(&(t->t2), NULL);
        t->elapsedTime = (t->t2.tv_sec - t->t1.tv_sec)*1000.0;
        t->elapsedTime += (t->t2.tv_usec - t->t1.tv_usec)/1000.0;
}
void frameTick(struct Timer *t, double frameTime)
{
        t->elapsedTime -= frameTime;
        t->t1.tv_sec  = t->t2.tv_sec;
        t->t1.tv_usec = t->t2.tv_usec;
}
