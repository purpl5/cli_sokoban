#include "../header/base.h"
#include "../header/player.h"
#include "../header/levelLoading.h"
#include "../header/position.h"
#include "../header/jeu.h"


Player* recherchePlayer(Level *l) {
    Player* player = (Player*) malloc(sizeof(Player));
    for (int i = 0; i < l->ligne; i++) {
        for (int j = 0; j < l->colonne; j++) {
            if (l->tab[i][j] == 'p') {
                player->p = initPos(player->p, j, i);
                return player; 
            }
        }
    }

    if (player == NULL) {
        printf("erreur, aucun player trouver"); 
        return (Player*) NULL; 
    }
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