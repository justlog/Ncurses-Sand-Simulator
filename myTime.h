#include <sys/time.h>

typedef struct Timer
{
        struct timeval t1, t2;
        double elapsedTime;
} Timer;

void timeInit(struct Timer *t);
void tick(struct Timer *t);
void frameTick(struct Timer *t, double frameTime);
