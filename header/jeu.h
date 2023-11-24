#ifndef JEU_H
#define JEU_H

// include 
#include "base.h"
#include "player.h"
#include "emplacement.h"
#include "levelLoading.h"

// typedef 
typedef struct Jeu {
    Level* l; 
    FileEmplacement* f;
    Player* pl;
} Jeu; 

// profil 
void gameOn(Jeu* j);

#endif