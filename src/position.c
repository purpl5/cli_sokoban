#include "position.h"

/**
 * @file position.c
 * @brief Implémentations des fonctions pour la gestion des positions dans le jeu.
 *
 * Ce fichier contient les implémentations des fonctions pour initialiser et libérer
 * des structures de position. Ces fonctions permettent de créer et de gérer des positions
 * pour divers éléments dans le jeu, comme les joueurs, les blocs et les emplacements.
 */

Position* initPos(Position* p, int x, int y) {
    p = (Position*)malloc(sizeof(Position));
    p->x = x;
    p->y = y;

    return p;
}

void freePos(Position* p) {
    free(p);
}