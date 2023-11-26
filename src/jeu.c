#include "jeu.h"
#include "bloc.h"
#include "emplacement.h"
#include "levelLoading.h"
#include "os.h"
#include "player.h"

/**
 * @file jeu.c
 * @brief Implémentations des fonctions pour la gestion du jeu.
 *
 * Ce fichier contient les implémentations des fonctions définies dans jeu.h.
 * Il comprend la fonction principale gameOn qui gère la boucle de jeu, y compris
 * le chargement des niveaux, la gestion des entrées du joueur, et la mise à jour
 * de l'état du jeu. Des fonctions supplémentaires comme afficherCommande pour
 * afficher les commandes disponibles sont également implémentées ici.
 */


void gameOn() {
    char* nomLevel = choixLevelFile();

    Jeu* j = (Jeu*)malloc(sizeof(Jeu));

    j->l = loader(nomLevel);
    j->f = rechercheEmplacement(j->l);
    j->pl = recherchePlayer(j->l);

    afficherLevel(j->l);
    afficherCommande();

    int end = 0;

    int nbEmplacement = nbrEmplacement(j->f);
    int* nbBlocSurEmplacement = (int*)malloc(sizeof(int));
    *nbBlocSurEmplacement = 0;
    while (end == 0 && nbEmplacement != *(nbBlocSurEmplacement)) {
        char character;
        scanf("\n%c", &character);
        int sens;

        char tabY1, tabY2, tabX1, tabX2;

        /*
         *  Posibilité :
         *     - dans tout les cas : verirfier que notre position actuelle n'est
         * pas la position d'un emplacement, si oui, et que nous bougeons nous
         * devons remettre l'emplacement !
         *     - rien : avancer
         *     - mur : ne rien faire
         *     - emplacement : avancer
         *     - bloc  :
         *        - dans tout les cas : verifier que le bloc n'etais pas sur un
         * emplacement, si c'est le cas et qu'il change de position enlever 1 à
         * nbBlocSurEmplacement et remettre l'empalement !
         *        - rien : avancer
         *        - mur : ne rien faire
         *        - emplacement : avancer ajouter 1 au nbBlocSurEmplacement
         */

        switch (character) {
            case KEY_UP:
                sens = -1;
                tabY1 = j->l->tab[j->pl->p->y - 1][j->pl->p->x];

                if (tabY1 != '#') {
                    if (tabY1 == 'x' || tabY1 == 'X') {
                        tabY2 = j->l->tab[j->pl->p->y - 2][j->pl->p->x];
                        if (tabY2 != '#' && tabY2 != 'x') {
                            Position* blocPos =
                                (Position*)malloc(sizeof(Position));
                            blocPos->x = j->pl->p->x;
                            blocPos->y = j->pl->p->y - 1;
                            deplacementBlocY(j->l, j->f, blocPos, sens,
                                             nbBlocSurEmplacement);
                            free(blocPos);

                            deplacementPlayerY(j->l, j->f, j->pl, sens);
                        }

                    } else {
                        deplacementPlayerY(j->l, j->f, j->pl, sens);
                    }
                }

                break;

            case KEY_LEFT:
                sens = -1;
                tabY1 = j->l->tab[j->pl->p->y][j->pl->p->x - 1];

                if (tabY1 != '#') {
                    if (tabY1 == 'x' || tabY1 == 'X') {
                        tabY2 = j->l->tab[j->pl->p->y][j->pl->p->x - 2];
                        if (tabY2 != '#' && tabY2 != 'x') {
                            Position* blocPos =
                                (Position*)malloc(sizeof(Position));
                            blocPos->x = j->pl->p->x - 1;
                            blocPos->y = j->pl->p->y;
                            deplacementBlocX(j->l, j->f, blocPos, sens,
                                             nbBlocSurEmplacement);
                            free(blocPos);

                            deplacementPlayerX(j->l, j->f, j->pl, sens);
                        }

                    } else {
                        deplacementPlayerX(j->l, j->f, j->pl, sens);
                    }
                }
                break;

            case KEY_RIGHT:
                sens = 1;
                tabX1 = j->l->tab[j->pl->p->y][j->pl->p->x + 1];
                if (tabX1 != '#') {
                    if (tabX1 == 'x' || tabX1 == 'X') {
                        tabX2 = j->l->tab[j->pl->p->y][j->pl->p->x + 2];

                        if (tabX2 != '#' && tabX2 != 'x') {
                            Position* blocPos =
                                (Position*)malloc(sizeof(Position));
                            blocPos->x = j->pl->p->x + 1;
                            blocPos->y = j->pl->p->y;
                            deplacementBlocX(j->l, j->f, blocPos, sens,
                                             nbBlocSurEmplacement);
                            free(blocPos);

                            deplacementPlayerX(j->l, j->f, j->pl, sens);
                        }

                    } else {
                        deplacementPlayerX(j->l, j->f, j->pl, sens);
                    }
                }
                break;

            case KEY_DOWN:
                sens = 1;
                tabX1 = j->l->tab[j->pl->p->y + 1][j->pl->p->x];

                if (tabX1 != '#') {
                    if (tabX1 == 'x' || tabX1 == 'X') {
                        tabX2 = j->l->tab[j->pl->p->y + 2][j->pl->p->x];
                        if (tabX2 != '#' && tabX2 != 'x') {
                            Position* blocPos =
                                (Position*)malloc(sizeof(Position));
                            blocPos->x = j->pl->p->x;
                            blocPos->y = j->pl->p->y + 1;
                            deplacementBlocY(j->l, j->f, blocPos, sens,
                                             nbBlocSurEmplacement);
                            free(blocPos);

                            deplacementPlayerY(j->l, j->f, j->pl, sens);
                        }
                    } else {
                        deplacementPlayerY(j->l, j->f, j->pl, sens);
                    }
                }
                break;

            case KEY_LEAVING:
                end = 1;
                break;

            case KEY_NEW_LEVEL:
                end = 2;
                gameOn();
                break;

            default:
                break;
        }

        if (end != 2 && end != 1) {
            afficherLevel(j->l);
            afficherCommande();
        }
    }

    if (end == 1) {
        clearCmd();
        printf("Perdu ! Tu as quitter le jeu sans le finir !\n");
    } else if (end != 2) {
        clearCmd();
        printf("Gagner !\n");
    }

    // Tout les free
    free(nbBlocSurEmplacement);
    freeLevel(j->l);
    freeEmplacement(j->f);
    freePlayer(j->pl);
    free(j);
}

void afficherCommande() {
    printf(
        "\n%c : avancer \n%c : gauche \n%c : droite \n%c : reculer \n%c : "
        "quitter\n%c : changer de level\n\n",
        KEY_UP, KEY_LEFT, KEY_RIGHT, KEY_DOWN, KEY_LEAVING, KEY_NEW_LEVEL);
}