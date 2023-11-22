#pragma once
#ifndef LEVELSELECTOR
#define LEVELSELECTOR

// Bibliothèque spécifique au levelSelector.C
#include <dirent.h>
#include <string.h>

// typedef 
typedef struct level {
    char* name; 
    struct level* next;
} Level;

// Les profils 
Level* listLevel();
Level* stockLevel(Level* list, char* namefile);
Level* newList();
void afficherLevel(Level* list);
char* iemeLevel(Level* list, int i);
char* choixLevel();

#endif 