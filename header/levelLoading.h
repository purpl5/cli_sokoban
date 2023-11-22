#pragma once 
#ifndef LEVEL_LOADING
#define LEVEL_LOADING

// include 
#include <string.h>

// typedef 
typedef struct Level {
    int ligne;
    int colonne; 
    char** tab; 
} Level; 

// profil 
Level* newLevel(int nbColonne, int nbLigne);
char* pathFinder(char* filename);
int nbColFinder(char* filename);
int nbLigFinder(char* filename);
void afficherLevel(Level* l);
Level* loader(char* filename);

#endif