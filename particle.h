#define MAXPAR 1000

typedef struct particle
{
        int x, y;
        char Sym;
} particle;

int canMove(particle *p);
void updateParList();
void clearPar(particle *p);
void printPar(particle *p);
void spawnPar();
