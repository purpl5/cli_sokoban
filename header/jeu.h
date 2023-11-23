#pragma once 
#ifndef JEU 
#define JEU

// include 
#include "../header/levelLoading.h"
#include "../header/emplacement.h"
#include "../header/player.h"
#include <string.h>


// typedef 
typedef struct Jeu {
    Level* l; 
    FileEmplacement* f;
    Player* p;

    int nbEmplacement;
    int nbBlocSurEmplacement;
} Jeu; 

// profil 
Jeu* launchGame(Jeu* j);
void endGame(Jeu* j);
void game();

#endif