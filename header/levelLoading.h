#ifndef LEVEL_LOADING_H
#define LEVEL_LOADING_H

/**
 * @file levelLoading.h
 * @brief Définitions et fonctions pour le chargement et la gestion des niveaux
 * du jeu.
 *
 * Ce fichier contient la structure Level et diverses fonctions pour créer,
 * charger, afficher et libérer les niveaux du jeu.
 */

#include "base.h"

/**
 * @struct Level
 * @brief Structure représentant un niveau dans le jeu.
 *
 * Cette structure contient les données d'un niveau, y compris sa taille et
 * le tableau représentant les différents éléments du niveau.
 */
typedef struct Level {
    int ligne;    ///< Nombre de lignes du niveau.
    int colonne;  ///< Nombre de colonnes du niveau.
    char** tab;   ///< Tableau 2D représentant le niveau.

} Level;

/**
 * @brief Crée un nouveau niveau.
 *
 * Initialise un nouveau niveau avec un nombre spécifié de colonnes et de
 * lignes.
 *
 * @param nbColonne Nombre de colonnes du niveau.
 * @param nbLigne Nombre de lignes du niveau.
 * @return Pointeur vers le niveau nouvellement créé.
 */
Level* newLevel(int nbColonne, int nbLigne);

/**
 * @brief Trouve le chemin d'un fichier de niveau.
 *
 * Construit et renvoie le chemin d'accès complet d'un fichier de niveau à
 * partir de son nom.
 *
 * @param filename Nom du fichier de niveau.
 * @return Chaîne de caractères contenant le chemin complet du fichier de
 * niveau.
 */
char* pathFinder(char* filename);

/**
 * @brief Trouve le nombre de colonnes dans un fichier de niveau.
 *
 * Lit un fichier de niveau et détermine le nombre de colonnes qu'il contient.
 *
 * @param filename Nom du fichier de niveau.
 * @return Nombre de colonnes dans le fichier de niveau.
 */
int nbColFinder(char* filename);

/**
 * @brief Trouve le nombre de lignes dans un fichier de niveau.
 *
 * Lit un fichier de niveau et détermine le nombre de lignes qu'il contient.
 *
 * @param filename Nom du fichier de niveau.
 * @return Nombre de lignes dans le fichier de niveau.
 */
int nbLigFinder(char* filename);

/**
 * @brief Affiche un niveau.
 *
 * Affiche le contenu d'un niveau spécifié sur la sortie standard.
 *
 * @param l Pointeur vers le niveau à afficher.
 */
void afficherLevel(Level* l);

/**
 * @brief Charge un niveau à partir d'un fichier.
 *
 * Lit un fichier de niveau et charge ses données dans une structure de type
 * Level.
 *
 * @param filename Nom du fichier de niveau à charger.
 * @return Pointeur vers le niveau chargé.
 */
Level* loader(char* filename);

/**
 * @brief Libère la mémoire d'un tableau de niveau.
 *
 * Libère la mémoire allouée pour le tableau de caractères d'un niveau.
 *
 * @param list Pointeur vers le niveau dont le tableau doit être libéré.
 */
void freeTab(Level* list);

/**
 * @brief Libère la mémoire d'un niveau.
 *
 * Libère la mémoire allouée pour une structure de niveau et son contenu.
 *
 * @param l Pointeur vers le niveau à libérer.
 */
void freeLevel(Level* l);

#endif