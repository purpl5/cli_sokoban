#include "levelLoading.h"
#include "os.h"

Level* newLevel(int nbColonne, int nbLigne) {
    Level* l = (Level*)malloc(sizeof(Level));

    l->tab = (char**)malloc(nbLigne * sizeof(char*));

    for (int n = 0; n < nbLigne; n++) {
        l->tab[n] = (char*)malloc(nbColonne * sizeof(char));
    }

    l->ligne = nbLigne;
    l->colonne = nbColonne;

    return l;
}

char* pathFinder(char* filename) {
    char* base = "./level/";
    char* path =
        (char*)malloc((strlen(base) + strlen(filename) + 1) * sizeof(char));
    strcpy(path, base);
    strcat(path, filename);

    return path;
}

int nbColFinder(char* filename) {
    FILE* fichier;
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
    FILE* fichier;
    int nbLigne = 1;
    char* path = pathFinder(filename);

    fichier = fopen(path, "r");

    if (fichier == NULL) {
        printf("erreur, on arrive pas a ouvrir le fichier en question");
    }

    char ch = fgetc(fichier);
    while (ch != EOF) {
        if (ch == '\n') {
            nbLigne++;
        }
        ch = fgetc(fichier);
    }

    free(path);

    fclose(fichier);

    return nbLigne;
}

void afficherLevel(Level* l) {
    if (OS_NUMBER == 1) {
        system("clear");
    } else if (OS_NUMBER == 0) {
        system("cls");
    }

    for (int i = 0; i < l->ligne; i++) {
        for (int j = 0; j < l->colonne; j++) {
            printf("%c", l->tab[i][j]);
        }
        printf("\n");
    }
}

Level* loader(char* filename) {
    FILE* fichier;
    int nbLigne = nbLigFinder(filename), nbColonne = nbColFinder(filename);

    Level* l = newLevel(nbColonne, nbLigne);
    char* path = pathFinder(filename);

    free(filename);

    fichier = fopen(path, "r");

    free(path);

    if (fichier == NULL) {
        printf("erreur");
        return (Level*)NULL;
    }

    char ch = fgetc(fichier);

    for (int i = 0; i < l->ligne; i++) {
        for (int j = 0; j < l->colonne; j++, ch = fgetc(fichier)) {
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

void freeLevel(Level* l) {
    freeTab(l);
    free(l);
}
