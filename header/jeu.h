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
    Player* pl;
} Jeu; 

// profil 
void gameOn(Jeu* j);

#endif