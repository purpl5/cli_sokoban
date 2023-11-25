#ifndef JEU_H
#define JEU_H

#define KEY_UP 'z'
#define KEY_RIGHT 'd'
#define KEY_LEFT 'q'
#define KEY_DOWN 's'
#define KEY_LEAVING 'l'
#define KEY_RESTART 'r'
#define KEY_NEW_LEVEL 'n'

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
#include "levelSelector.h"
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
 */
void gameOn();

/**
 * @brief Affiche les commandes 
 *
 * Affiche toutes les commandes faisable pour jouer au jeu. 
 *
 */
void afficherCommande();

#endif