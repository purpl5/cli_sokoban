#pragma once
#ifndef PLAYER
#define PLAYER

// include 
#include "../header/position.h"
#include "../header/levelLoading.h"
#include "../header/emplacement.h"


// typedef
typedef struct Player {
    Position* p; 
} Player;

// profil 
Player* recherchePlayer(Level *l);
void freePlayer(Player* p);
void afficherPlayer(Player* p);
void deplacementPlayerY(Level* l, FileEmplacement* f, Player* p, int sens);
void deplacementPlayerX(Level* l, FileEmplacement* f, Player* p, int sens);

#endif