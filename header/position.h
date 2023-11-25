#ifndef POSITION_H
#define POSITION_H

/**
 * @file position.h
 * @brief Définitions et fonctions pour la gestion des positions dans le jeu.
 *
 * Ce fichier contient la structure Position et les fonctions associées pour
 * initialiser, manipuler et libérer des positions dans le jeu.
 */

#include "base.h"

/**
 * @struct Position
 * @brief Structure représentant une position dans le jeu.
 *
 * Cette structure contient les coordonnées x et y d'une position dans le jeu,
 * utilisées pour déterminer l'emplacement des joueurs, des blocs, etc.
 */
typedef struct Position {
    int x;  ///< Coordonnée X de la position.
    int y;  ///< Coordonnée Y de la position.
} Position;

// profil

/**
 * @brief Initialise une position.
 *
 * Cette fonction crée et initialise une structure de position avec les
 * coordonnées spécifiées.
 *
 * @param p Pointeur vers une structure de position existante ou NULL pour en
 * créer une nouvelle.
 * @param x Coordonnée X de la position.
 * @param y Coordonnée Y de la position.
 * @return Pointeur vers la structure de position initialisée.
 */
Position* initPos(Position* p, int x, int y);

/**
 * @brief Libère la mémoire allouée pour une position.
 *
 * Libère la mémoire allouée pour une structure de position.
 *
 * @param p Pointeur vers la position à libérer.
 */
void freePos(Position* p);

#endif