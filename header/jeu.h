#ifndef JEU_H
#define JEU_H

/** @def KEY_UP
 *  @brief Touche pour se déplacer vers le haut.
 *
 *  Cette macro définit la touche utilisée pour déplacer le joueur ou le curseur
 *  vers le haut dans le jeu.
 */
#define KEY_UP 'z'

/** @def KEY_RIGHT
 *  @brief Touche pour se déplacer vers la droite.
 *
 *  Cette macro définit la touche utilisée pour déplacer le joueur ou le curseur
 *  vers la droite dans le jeu.
 */
#define KEY_RIGHT 'd'

/** @def KEY_LEFT
 *  @brief Touche pour se déplacer vers la gauche.
 *
 *  Cette macro définit la touche utilisée pour déplacer le joueur ou le curseur
 *  vers la gauche dans le jeu.
 */
#define KEY_LEFT 'q'

/** @def KEY_DOWN
 *  @brief Touche pour se déplacer vers le bas.
 *
 *  Cette macro définit la touche utilisée pour déplacer le joueur ou le curseur
 *  vers le bas dans le jeu.
 */
#define KEY_DOWN 's'

/** @def KEY_LEAVING
 *  @brief Touche pour quitter le jeu.
 *
 *  Cette macro définit la touche utilisée pour quitter le jeu.
 */
#define KEY_LEAVING 'l'

/** @def KEY_RESTART
 *  @brief Touche pour redémarrer le niveau actuel.
 *
 *  Cette macro définit la touche utilisée pour redémarrer le niveau actuel.
 */
#define KEY_RESTART 'r'

/** @def KEY_NEW_LEVEL
 *  @brief Touche pour charger un nouveau niveau.
 *
 *  Cette macro définit la touche utilisée pour charger un nouveau niveau dans
 * le jeu.
 */
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