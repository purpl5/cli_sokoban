#ifndef EMPLACEMENT_H
#define EMPLACEMENT_H

// include
#include "base.h"
#include "levelLoading.h"
#include "position.h"

// typedef
typedef struct fileEmplacement {
    Position* p;
    struct fileEmplacement* next;
} FileEmplacement;

// profil

/**
 * @brief Crée un nouvel emplacement.
 *
 * Cette fonction initialise un nouvel emplacement.
 *
 * @return Pointeur vers le nouvel emplacement créé.
 */
FileEmplacement* newEmplacement();

/**
 * @brief Vérifie si un emplacement est vide.
 *
 * Cette fonction détermine si l'emplacement spécifié est vide.
 *
 * @param f Pointeur vers l'emplacement à vérifier.
 * @return Booléen indiquant si l'emplacement est vide (true) ou non (false).
 */
bool emplacementVide(FileEmplacement* f);

/**
 * @brief Ajoute un emplacement.
 *
 * Ajoute un nouvel emplacement avec les coordonnées spécifiées à la liste
 * d'emplacements.
 *
 * @param x Coordonnée X de l'emplacement.
 * @param y Coordonnée Y de l'emplacement.
 * @param f Pointeur vers le premier emplacement de la liste.
 * @return Pointeur vers la liste mise à jour des emplacements.
 */
FileEmplacement* ajoutEmplacement(int x, int y, FileEmplacement* f);

/**
 * @brief Recherche des emplacements dans un niveau.
 *
 * Parcourt un niveau pour trouver tous les emplacements et les ajoute à une
 * liste.
 *
 * @param l Pointeur vers le niveau à parcourir.
 * @return Pointeur vers la liste des emplacements trouvés dans le niveau.
 */
FileEmplacement* rechercheEmplacement(Level* l);

/**
 * @brief Affiche les emplacements.
 *
 * Parcourt et affiche les emplacements contenus dans la liste spécifiée.
 *
 * @param f Pointeur vers la liste des emplacements à afficher.
 */
void afficherEmplacement(FileEmplacement* f);

/**
 * @brief Libère la mémoire des emplacements.
 *
 * Libère la mémoire allouée pour tous les emplacements dans la liste.
 *
 * @param f Pointeur vers la liste des emplacements à libérer.
 */
void freeEmplacement(FileEmplacement* f);

/**
 * @brief Vérifie si une position est un emplacement.
 *
 * Détermine si la position spécifiée correspond à un emplacement dans la liste.
 *
 * @param f Pointeur vers la liste des emplacements.
 * @param p Pointeur vers la position à vérifier.
 * @return Booléen indiquant si la position est un emplacement (true) ou non
 * (false).
 */
bool estUnEmplacement(FileEmplacement* f, Position* p);

/**
 * @brief Compte le nombre d'emplacements.
 *
 * Compte le nombre d'emplacements dans la liste spécifiée.
 *
 * @param f Pointeur vers la liste des emplacements.
 * @return Le nombre d'emplacements dans la liste.
 */
int nbrEmplacement(FileEmplacement* f);

#endif