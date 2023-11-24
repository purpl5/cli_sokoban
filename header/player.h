#ifndef PLAYER_H
#define PLAYER_H

// include 
#include "base.h"
#include "position.h"
#include "levelLoading.h"
#include "emplacement.h"

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