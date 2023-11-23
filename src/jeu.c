#include "../header/base.h"
#include "../header/jeu.h"
#include "../header/player.h"

void gameOn(Jeu* j) {
    int i = 0; 

    int nbEmplacement = nbrEmplacement(j->f); 
    int* nbBlocSurEmplacement = (int*) malloc(sizeof(int));
    while (i != 1 || nbEmplacement != *(nbBlocSurEmplacement)) {
        char character;
        scanf("\n%c", &character);
        int sens; 

        char tabY1, tabY2, tabX1, tabX2; 

        /* 
        *  Posibilité :
        *     - dans tout les cas : verirfier que notre position actuelle n'est pas la position d'un emplacement, si oui, et que nous bougeons 
        *      nous devons remettre l'emplacement !  
        *     - rien : avancer
        *     - mur : ne rien faire 
        *     - emplacement : avancer
        *     - bloc  : 
        *        - dans tout les cas : verifier que le bloc n'etais pas sur un emplacement, si c'est le cas et qu'il change de position 
        *        enlever 1 à nbBlocSurEmplacement et remettre l'empalement ! 
        *        - rien : avancer
        *        - mur : ne rien faire
        *        - emplacement : avancer ajouter 1 au nbBlocSurEmplacement
        */

        switch (character) {
            case 'z':
                sens = -1; 
                tabY1 = j->l->tab[j->pl->p->y - 1][j->pl->p->x]; 

                if (tabY1 != '#') {
                    if (tabY1 == 'x') {
                        tabY2 = j->l->tab[j->pl->p->y - 2][j->pl->p->x];
                        if (tabY2 != '#') {

                        } else {
                            afficherLevel(j->l);
                        }

                    } else {
                        deplacementPlayerY(j->l, j->f, j->pl, sens); 
                        afficherLevel(j->l);
                    }
                    
                } else {
                    afficherLevel(j->l);
                }
                break;
                
            case 'q':
                sens = -1; 
                tabY1 = j->l->tab[j->pl->p->y ][j->pl->p->x - 1];

                if (tabY1 != '#') {
                    if (tabY1 == 'x') {
                        tabY2 = j->l->tab[j->pl->p->y][j->pl->p->x - 2];
                        if (tabY2 != '#') {

                        } else {
                            afficherLevel(j->l);
                        }

                    } else {
                        deplacementPlayerX(j->l, j->f, j->pl, sens); 
                        afficherLevel(j->l);
                    }
                } else {
                    afficherLevel(j->l);
                }
                break;

            case 'd':
                sens = 1; 
                tabX1 = j->l->tab[j->pl->p->y][j->pl->p->x  + 1];

                if (tabX1 != '#') {
                    if (tabX1 == 'x') {
                        tabX2 = j->l->tab[j->pl->p->y][j->pl->p->x + 2];
                        if (tabX2 != '#') {

                        } else {
                            afficherLevel(j->l);
                        }
                    } else {
                        deplacementPlayerX(j->l, j->f, j->pl, sens); 
                        afficherLevel(j->l);
                    }

                } else {
                    afficherLevel(j->l);
                }
                break;

            case 's':
                sens = 1; 
                tabX1 = j->l->tab[j->pl->p->y + 1][j->pl->p->x ];

                if (tabX1 != '#') {
                    if (tabX1 == 'x') {
                        tabX2 = j->l->tab[j->pl->p->y + 2][j->pl->p->x];
                        if (tabX2 != '#') {

                        } else {
                            afficherLevel(j->l);
                        }
                    } else {
                        deplacementPlayerY(j->l, j->f, j->pl, sens); 
                        afficherLevel(j->l);
                    }

                } else {
                    afficherLevel(j->l);
                }
                break;  

            case 'l' :
                i = 1; 
                printf("vous avez quitter le jeux !"); 
                break; 

            default:
                break;
        }
    }

    free(nbBlocSurEmplacement);
}