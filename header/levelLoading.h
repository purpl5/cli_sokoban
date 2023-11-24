#ifndef LEVEL_LOADING_H
#define LEVEL_LOADING_H

// include 
#include "base.h"

// typedef 

/*
*  Nom du type : Level
*  Contenu : 
*     - ligne : le nombre de ligne dans le tableau 
*     - colonne : le nombre de colonne dans le tableau
*     - tab : tableau stockant les caractéristique du Level
*  Initialisation :
*     - loader()
*  Free : 
*     - freeLevel()
*/

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
void freeTab(Level* list);
void freeLevel(Level* l);

#endif