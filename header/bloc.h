#ifndef BLOC_H
#define BLOC_H

// include 
#include "base.h"
#include "emplacement.h"
#include "position.h"
#include "levelLoading.h"

// profil
void deplacementBlocY(Level* l, FileEmplacement* f, Position* pl, int sens, int* nbBlocSurEmplacement);
void deplacementBlocX(Level* l, FileEmplacement* f, Position* pl, int sens, int* nbBlocSurEmplacement); 

#endif