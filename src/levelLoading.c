#include "../header/base.h"
#include "../header/levelLoading.h"

/*
*  Nom :
*  Précondition : 
*  Effet de bord : 
*  Argument : 
*  Explication de la fonction : 
*  Retour : 
*/

// ---------------------------------------

/*
*  Nom : newLevel
*  Précondition : aucune 
*  Effet de bord : aucune 
*  Argument : 
*     - nbColonne : le nombre de colonne que l'on veux dans notre tableau
*     - nbLigne : le nombre de ligne que l'on veux dans notre tableau
*  Explication de la fonction : la fonction va allouer notre tableau et initaliser chaque varible d'une variable de type LevelFile (concrètement ligne et colonne)
*  Retour : renvoie le level entièrement initaliser 
*/

Level* newLevel(int nbColonne, int nbLigne) {
    Level* l = (Level*) malloc(sizeof(Level)); 

    l->tab = (char**) malloc(nbLigne * sizeof(char*)); 

    for (int n = 0; n < nbLigne; n++) {
        l->tab[n] = (char*) malloc(nbColonne * sizeof(char)); 
    }

    l->ligne = nbLigne;
    l->colonne = nbColonne;

    return l; 
}

// ---------------------------------------

/*
*  Nom : pathFinder
*  Précondition : aucun
*  Effet de bord :  aucun 
*  Argument : 
*     - filename : nom du fichier a ajouter dans le chemi 
*  Explication de la fonction : va créer une variable path qui va contenir le chemin vers le level qui à son nom stocker dans filename 
*  Retour : retournele chemin 
*/

char* pathFinder(char* filename) {
    char *base = "./level/";
    char *path = (char*) malloc((strlen(base) + strlen(filename) + 1) * sizeof(char));
    strcpy(path, base);
    strcat(path, filename);

    return path; 
}

// ---------------------------------------

/*
*  Nom : nbColFinder
*  Précondition : le fichier doit être accessible en lecture et avoir la même longueur pour chaque ligne sinon la fonction renverra possiblement une valeur fausse 
*  Effet de bord : aucune 
*  Argument : 
*     - filename : nom de fichier 
*  Explication de la fonction : la fonction va cherche le nombre d'element dans la premièrme ligne du fichier 
*  Retour : va renvoyer nbColonne qui signifie le nombre d'élement dans la première ligne 
*/

int nbColFinder(char* filename) {
    FILE *fichier;
    int nbColonne = 0;
    char* path = pathFinder(filename); 

    fichier = fopen(path, "r"); 

    if (fichier == NULL) {
        printf("erreur, on arrive pas a ouvrir le fichier en question"); 
    }

    char ch = fgetc(fichier); 
    while (ch != '\n') {
        nbColonne++; 
        ch = fgetc(fichier);
    }

    free(path); 

    fclose(fichier);

    return nbColonne;
}


int nbLigFinder(char* filename) {
    FILE *fichier;
    int nbLigne = 1;
    char* path = pathFinder(filename); 

    fichier = fopen(path, "r"); 

    if (fichier == NULL) {
        printf("erreur, on arrive pas a ouvrir le fichier en question"); 
    }

    char ch = fgetc(fichier); 
    while (ch != EOF) {
        if(ch == '\n') {
            nbLigne++; 
        }
        ch = fgetc(fichier); 
    }

    free(path); 

    fclose(fichier);

    return nbLigne;
}

void afficherLevel(Level* l) {
    for (int i = 0; i < l->ligne; i++) {
        for(int j = 0; j < l->colonne; j++) {
            printf("%c", l->tab[i][j]); 
        }
        printf("\n");
    }
}

Level* loader(char* filename) {
    FILE *fichier; 
    int nbLigne = nbLigFinder(filename), nbColonne = nbColFinder(filename);

    Level* l = newLevel(nbColonne, nbLigne); 
    char* path = pathFinder(filename);

    fichier = fopen(path, "r");

    free(path);

    if (fichier == NULL) {
        printf("erreur");
        return (Level*) NULL;
    }
    
    char ch = fgetc(fichier);
     
    for (int i = 0; i < l->ligne; i++) {
        for(int j = 0; j < l->colonne; j++, ch = fgetc(fichier)) {
            if (ch == '\n') {
                ch = fgetc(fichier);
            }

            l->tab[i][j] = ch;
        }
        
    }

    fclose(fichier); 

    

    return l;
}

void freeTab(Level* l) {
    for (int i = 0; i < l->ligne; i++) {
        free(l->tab[i]);
    }
    
    free(l->tab);
}