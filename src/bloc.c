/**
 * @file bloc.c
 * @brief Implémentations des fonctions pour le déplacement des blocs dans le jeu.
 *
 * Ce fichier contient les implémentations des fonctions définies dans bloc.h.
 */

#include "bloc.h"
#include "levelLoading.h"
#include "player.h"
#include "position.h"

void deplacementBlocY(Level* l,
                      FileEmplacement* f,
                      Position* p,
                      int sens,
                      int* nbBlocSurEmplacement) {
    if (estUnEmplacement(f, p)) {
        *nbBlocSurEmplacement = *nbBlocSurEmplacement - 1;
    }

    p->y += sens;

    if (estUnEmplacement(f, p)) {
        *nbBlocSurEmplacement = *nbBlocSurEmplacement + 1;
        l->tab[p->y][p->x] = 'X';
    } else {
        l->tab[p->y][p->x] = 'x';
    }
}

void deplacementBlocX(Level* l,
                      FileEmplacement* f,
                      Position* p,
                      int sens,
                      int* nbBlocSurEmplacement) {
    if (estUnEmplacement(f, p)) {
        *nbBlocSurEmplacement = *nbBlocSurEmplacement - 1;
    }

    p->x += sens;

    if (estUnEmplacement(f, p)) {
        *nbBlocSurEmplacement = *nbBlocSurEmplacement + 1;
        l->tab[p->y][p->x] = 'X';
    } else {
        l->tab[p->y][p->x] = 'x';
    }
}