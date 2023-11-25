#ifndef PLAYER_H
#define PLAYER_H

// include 
#include "base.h"
#include "position.h"
#include "levelLoading.h"
#include "emplacement.h"

// typedef
typedef struct Player {
    Position* p; 
} Player;

// profil 

/**
 * @brief Recherche le joueur dans un niveau.
 *
 * Cette fonction parcourt le niveau spécifié pour trouver la position du joueur.
 *
 * @param l Pointeur vers le niveau dans lequel rechercher le joueur.
 * @return Pointeur vers la structure du joueur contenant sa position.
 */
Player* recherchePlayer(Level *l);

/**
 * @brief Libère la mémoire allouée pour un joueur.
 *
 * Libère la mémoire allouée pour la structure du joueur.
 *
 * @param p Pointeur vers le joueur à libérer.
 */
void freePlayer(Player* p);

/**
 * @brief Affiche la position du joueur.
 *
 * Affiche les coordonnées de la position actuelle du joueur.
 *
 * @param p Pointeur vers le joueur dont la position doit être affichée.
 */
void afficherPlayer(Player* p);

/**
 * @brief Déplace le joueur sur l'axe Y.
 *
 * Déplace le joueur verticalement en fonction du paramètre 'sens'.
 *
 * @param l Pointeur vers le niveau actuel.
 * @param f Pointeur vers la liste des emplacements.
 * @param p Pointeur vers le joueur à déplacer.
 * @param sens Direction et amplitude du déplacement (positif ou négatif).
 */
void deplacementPlayerY(Level* l, FileEmplacement* f, Player* p, int sens);

/**
 * @brief Déplace le joueur sur l'axe X.
 *
 * Déplace le joueur horizontalement en fonction du paramètre 'sens'.
 *
 * @param l Pointeur vers le niveau actuel.
 * @param f Pointeur vers la liste des emplacements.
 * @param p Pointeur vers le joueur à déplacer.
 * @param sens Direction et amplitude du déplacement (positif ou négatif).
 */
void deplacementPlayerX(Level* l, FileEmplacement* f, Player* p, int sens);

#endif