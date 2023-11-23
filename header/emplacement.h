#pragma once
#ifndef EMPLACEMENT
#define EMPLACEMENT

// include 
#include "../header/emplacement.h"

// typedef 
typedef struct fileEmplacement {
    int x; 
    int y; 
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