#pragma once
#ifndef PLAYER
#define PLAYER

// include 
#include "../header/position.h"
#include "../header/levelLoading.h"

// typedef
typedef struct Player {
    Position* p; 
} Player;

// profil 
Player* recherchePlayer(Level *l);
void freePlayer(Player* p);
void afficherPlayer(Player* p);

#endif