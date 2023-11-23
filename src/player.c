#include "../header/base.h"
#include "../header/player.h"
#include "../header/levelLoading.h"
#include "../header/position.h"

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

/*

void deplacementPlayerX(Player* p, Level* l, int sens) {
    l->tab[p->p->y][p->p->x] = ' '; 
    p->p->x += sens; 
    l->tab[p->p->y][p->p->x] = 'p'; 
}

void deplacementPlayerY(Player* p, Level* l, int sens) {
    l->tab[p->p->y][p->p->x] = ' '; 
    p->p->y += sens; 
    l->tab[p->p->y][p->p->x] = 'p'; 
}

*/