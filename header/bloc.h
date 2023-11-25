#ifndef BLOC_H
#define BLOC_H

// include 
#include "base.h"
#include "emplacement.h"
#include "position.h"
#include "levelLoading.h"

// profil

/**
 * @brief Déplace un bloc dans le niveau sur l'axe Y.
 * 
 * Cette fonction modifie la position d'un bloc dans le level (représenté par 'l')
 * en déplaçant le bloc le long de l'axe Y en fonction du paramètre 'sens'.
 * 
 * @param l Pointeur vers le level dans lequel le bloc est déplacé.
 * @param f Pointeur vers la file des emplacements.
 * @param pl Pointeur vers la position actuelle du bloc.
 * @param sens Direction du déplacement. Les valeurs positives indiquent un déplacement vers le bas, et les valeurs négatives vers le haut.
 * @param nbBlocSurEmplacement Pointeur vers un entier qui est mis à jour pour refléter le nombre de blocs sur les emplacement après le déplacement du bloc.
 */
void deplacementBlocY(Level* l, FileEmplacement* f, Position* pl, int sens, int* nbBlocSurEmplacement);

/**
 * @brief Déplace un bloc dans le niveau sur l'axe X.
 * 
 * Cette fonction modifie la position d'un bloc dans le level (représenté par 'l')
 * en déplaçant le bloc le long de l'axe X en fonction du paramètre 'sens'.
 * 
 * @param l Pointeur vers le level dans lequel le bloc est déplacé.
 * @param f Pointeur vers la file des emplacements.
 * @param pl Pointeur vers la position actuelle du bloc.
 * @param sens Direction du déplacement. Les valeurs positives indiquent un déplacement vers le bas, et les valeurs négatives vers le haut.
 * @param nbBlocSurEmplacement Pointeur vers un entier qui est mis à jour pour refléter le nombre de blocs sur les emplacement après le déplacement du bloc.
 */
void deplacementBlocX(Level* l, FileEmplacement* f, Position* pl, int sens, int* nbBlocSurEmplacement); 

#endif