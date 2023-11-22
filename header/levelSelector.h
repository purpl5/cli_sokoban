#pragma once
#ifndef LEVEL_SELECTOR
#define LEVEL_SELECTOR

// Bibliothèque spécifique au levelSelector.C
#include <dirent.h>
#include <string.h>

// typedef 
typedef struct LevelFile {
    char* name; 
    struct LevelFile* next;
} LevelFile;

// Les profils 
LevelFile* listLevelFile();
LevelFile* stockLevelFile(LevelFile* list, char* namefile);
LevelFile* newList();
void afficherLevelFile(LevelFile* list);
char* iemeLevel(LevelFile* list, int i);
char* choixLevelFile();
void freeAllLevel(LevelFile* list);

#endif 