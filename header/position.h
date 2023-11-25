#ifndef POSITION_H
#define POSITION_H

// include
#include "base.h"

// typedef
typedef struct Position {
    int x;
    int y;
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