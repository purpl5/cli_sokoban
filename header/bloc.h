#pragma once
#ifndef BLOC
#define BLOC

// include 
#include "../header/levelLoading.h"
#include "../header/emplacement.h"
#include "../header/player.h"

// profil
void deplacementBlocY(Level* l, FileEmplacement* f, Position* pl, int sens);
void deplacementBlocX(Level* l, FileEmplacement* f, Position* pl, int sens); 

#endif