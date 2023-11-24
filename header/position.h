#ifndef POSITION_H
#define POSITION_H

// include
#include "base.h"

// typedef 
typedef struct Position {
    int x;
    int y; 
} Position;

// profil 
Position* initPos(Position* p, int x, int y);
void freePos(Position* p);

#endif 