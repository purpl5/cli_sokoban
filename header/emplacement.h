#pragma once
#ifndef EMPLACEMENT
#define EMPLACEMENT

// include 
#include "../header/emplacement.h"
#include "../header/position.h"

// typedef 
typedef struct fileEmplacement {
    Position *p; 
    struct fileEmplacement *next;
} FileEmplacement; 

// profil 
FileEmplacement* newEmplacement();
bool emplacementVide(FileEmplacement* f);
FileEmplacement* ajoutEmplacement(int x, int y, FileEmplacement* f);
FileEmplacement* rechercheEmplacement(Level* l);
void afficherEmplacement(FileEmplacement* f);
void freeEmplacement(FileEmplacement* f);
#endif