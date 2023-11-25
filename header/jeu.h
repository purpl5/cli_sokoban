#ifndef JEU_H
#define JEU_H

// include
#include "base.h"
#include "emplacement.h"
#include "levelLoading.h"
#include "player.h"

// typedef
typedef struct Jeu {
    Level* l;
    FileEmplacement* f;
    Player* pl;
} Jeu;

// profil

/**
 * @brief Lance et gère la boucle principale du jeu.
 *
 * Cette fonction démarre le jeu et gère la boucle de jeu principale, y compris
 * le traitement des entrées de l'utilisateur et la mise à jour de l'état du
 * jeu.
 *
 * @param j Pointeur vers une structure de jeu contenant toutes les informations
 * nécessaires pour le jeu, y compris le niveau actuel, les emplacements et les
 * informations sur le joueur.
 */
void gameOn(Jeu* j);

#endif