#ifndef JEU_H
#define JEU_H

/**
 * @file jeu.h
 * @brief Définitions et déclarations pour la gestion du jeu.
 *
 * Ce fichier contient les structures et fonctions nécessaires pour la gestion
 * globale du jeu, y compris la structure principale du jeu et la boucle de jeu.
 */

// include
#include "base.h"
#include "emplacement.h"
#include "levelLoading.h"
#include "player.h"

/**
 * @struct Jeu
 * @brief Structure représentant l'état global du jeu.
 *
 * Cette structure contient tous les éléments nécessaires pour gérer
 * l'état du jeu, y compris le niveau actuel, les emplacements ou il faut mettre
 * les blocs, et les informations sur le joueur.
 */

typedef struct Jeu {
    Level* l;            ///< Pointeur vers le niveau actuel du jeu.
    FileEmplacement* f;  ///< Pointeur vers la liste des emplacements de blocs
                         ///< dans le niveau.
    Player* pl;          ///< Pointeur vers les informations sur le joueur.
} Jeu;

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