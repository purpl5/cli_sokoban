#include "../header/position.h"
#include "../header/base.h"

Position* initPos(Position* p, int x, int y) {
    p = (Position*) malloc(sizeof(Position)); 
    p->x = x;
    p->y = y; 

    return p; 
}

void freePos(Position* p) {
    free(p); 
}