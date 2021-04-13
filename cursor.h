typedef struct cursor
{
        int x, y;
        int symbol;
} cursor;
void initCursor(cursor* c);
void printCursor(cursor* c);
void clearCursor(cursor* c);
