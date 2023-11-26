#include "emplacement.h"
#include "jeu.h"
#include "levelLoading.h"
#include "position.h"

/**
 * @file emplacement.c
 * @brief Implémentations des fonctions pour la gestion des emplacements dans le jeu.
 *
 * Ce fichier contient les implémentations des fonctions pour créer, vérifier,
 * ajouter, rechercher, afficher, libérer, et déterminer le nombre d'emplacements,
 * ainsi que pour vérifier si une position est un emplacement. Ces fonctions
 * sont utilisées pour gérer les emplacements pour les blocs
 */

FileEmplacement* newEmplacement() {
    return (FileEmplacement*)NULL;
}

bool emplacementVide(FileEmplacement* f) {
    return f == (FileEmplacement*)NULL ? true : false;
}

FileEmplacement* ajoutEmplacement(int x, int y, FileEmplacement* f) {
    FileEmplacement* new = (FileEmplacement*)malloc(sizeof(FileEmplacement));
    new->p = (Position*)NULL;
    new->p = initPos(new->p, x, y);

    if (emplacementVide(f)) {
        new->next = (FileEmplacement*)NULL;
        return new;
    }

    new->next = NULL;

    FileEmplacement* tmp;
    for (tmp = f; tmp->next != (FileEmplacement*)NULL; tmp = tmp->next)
        ;

    tmp->next = new;

    return f;
}

FileEmplacement* rechercheEmplacement(Level* l) {
    FileEmplacement* f = newEmplacement();

    for (int i = 0; i < l->ligne; i++) {
        for (int j = 0; j < l->colonne; j++) {
            if (l->tab[i][j] == 'o') {
                f = ajoutEmplacement(j, i, f);
            }
        }
    }

    return f;
}

void afficherEmplacement(FileEmplacement* f) {
    int i = 0;
    for (FileEmplacement* tmp = f; tmp != (FileEmplacement*)NULL;
         tmp = tmp->next) {
        printf("L'emplacement %d est à la position : x : %d et y : %d\n", i,
               tmp->p->x, tmp->p->y);
        i++;
    }
}

void freeEmplacement(FileEmplacement* f) {
    while (f != (FileEmplacement*)NULL) {
        FileEmplacement* suppr = f;
        f = f->next;
        freePos(suppr->p);
        free(suppr);
    }
}

bool estUnEmplacement(FileEmplacement* f, Position* p) {
    FileEmplacement* tmp = f;
    while (tmp != (FileEmplacement*)NULL) {
        if (tmp->p->x == p->x && tmp->p->y == p->y) {
            return true;
        }
        tmp = tmp->next;
    }

    return false;
}

int nbrEmplacement(FileEmplacement* f) {
    FileEmplacement* tmp = f;
    int i = 0;
    while (tmp != (FileEmplacement*)NULL) {
        i++;
        tmp = tmp->next;
    }
    return i;
}