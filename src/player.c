#include "player.h"
#include "emplacement.h"
#include "jeu.h"
#include "levelLoading.h"
#include "position.h"

/**
 * @file player.c
 * @brief Implémentations des fonctions pour la gestion du joueur dans le jeu.
 *
 * Ce fichier contient les implémentations des fonctions pour la gestion du
 * joueur, y compris la recherche du joueur dans le niveau, l'affichage de sa
 * position, la libération de sa mémoire, et son déplacement sur les axes X et
 * Y. Ces fonctions sont utilisées pour contrôler et suivre le joueur dans le
 * jeu.
 */

Player* recherchePlayer(Level* l) {
    Player* player = (Player*)malloc(sizeof(Player));
    player->p = (Position*)NULL;

    for (int i = 0; i < l->ligne; i++) {
        for (int j = 0; j < l->colonne; j++) {
            if (l->tab[i][j] == 'p') {
                player->p = initPos(player->p, j, i);
            }
        }
    }

    if (player == NULL) {
        printf("erreur, aucun player trouver");
    }

    return player;
}

void freePlayer(Player* p) {
    freePos(p->p);

    free(p);
}

void afficherPlayer(Player* p) {
    printf("Position du joueur : x = %d et y = %d\n", p->p->x, p->p->y);
}

void deplacementPlayerX(Level* l, FileEmplacement* f, Player* pl, int sens) {
    if (estUnEmplacement(f, pl->p)) {
        l->tab[pl->p->y][pl->p->x] = 'o';
    } else {
        l->tab[pl->p->y][pl->p->x] = ' ';
    }

    pl->p->x += sens;
    l->tab[pl->p->y][pl->p->x] = 'p';
}

void deplacementPlayerY(Level* l, FileEmplacement* f, Player* pl, int sens) {
    if (estUnEmplacement(f, pl->p)) {
        l->tab[pl->p->y][pl->p->x] = 'o';
    } else {
        l->tab[pl->p->y][pl->p->x] = ' ';
    }

    pl->p->y += sens;
    l->tab[pl->p->y][pl->p->x] = 'p';
}