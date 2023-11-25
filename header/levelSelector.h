#ifndef LEVEL_SELECTOR_H
#define LEVEL_SELECTOR_H

// Bibliothèque spécifique au levelSelector.C
#include "base.h"

// typedef 

/*
*  Nom du type : LevelFile
*  Contenu : 
*     - name : nom du fichier
*     - next : c'est une liste chainée, c'est donc l'élément suivant du tableau
*  Initialisation :
*     - newList()
*  Free : 
*     - freeAllLevel()
*/

typedef struct LevelFile {
    char* name; 
    struct LevelFile* next;
} LevelFile;

// Les profils 

/**
 * @brief Renvoie la liste des niveaux disponibles.
 *
 * Cette fonction parcourt les fichiers de niveau disponibles et les stocke dans une liste chaînée.
 *
 * @return Pointeur vers la liste chaînée des fichiers de niveau.
 */
LevelFile* listLevelFile();

/**
 * @brief Stocke un fichier de niveau dans la liste chaînée.
 *
 * Ajoute un nouveau fichier de niveau à la liste chaînée des fichiers de niveau.
 *
 * @param list Pointeur vers la liste chaînée actuelle des fichiers de niveau.
 * @param namefile Nom du fichier de niveau à ajouter.
 * @return Pointeur vers la liste chaînée mise à jour des fichiers de niveau.
 */
LevelFile* stockLevelFile(LevelFile* list, char* namefile);

/**
 * @brief Crée une nouvelle liste chaînée pour les fichiers de niveau.
 *
 * Initialise une nouvelle liste chaînée vide pour stocker les fichiers de niveau.
 *
 * @return Pointeur vers la nouvelle liste chaînée vide.
 */
LevelFile* newList();

/**
 * @brief Affiche la liste des fichiers de niveau.
 *
 * Parcourt la liste chaînée des fichiers de niveau et affiche leurs noms.
 *
 * @param list Pointeur vers la liste chaînée des fichiers de niveau à afficher.
 */
void afficherLevelFile(LevelFile* list);

/**
 * @brief Renvoie le nom du i-ème fichier de niveau dans la liste.
 *
 * Accède au i-ème élément de la liste chaînée des fichiers de niveau et renvoie son nom.
 *
 * @param list Pointeur vers la liste chaînée des fichiers de niveau.
 * @param i Index du fichier de niveau à récupérer.
 * @return Nom du i-ème fichier de niveau.
 */
char* iemeLevel(LevelFile* list, int i);

/**
 * @brief Permet à l'utilisateur de choisir un fichier de niveau.
 *
 * Affiche la liste des fichiers de niveau disponibles et permet à l'utilisateur de choisir l'un d'entre eux.
 *
 * @return Nom du fichier de niveau choisi par l'utilisateur.
 */
char* choixLevelFile();

/**
 * @brief Libère la mémoire allouée pour la liste des fichiers de niveau.
 *
 * Parcourt la liste chaînée des fichiers de niveau et libère la mémoire allouée pour chaque élément.
 *
 * @param list Pointeur vers la liste chaînée des fichiers de niveau à libérer.
 */
void freeAllLevelFile(LevelFile* list);

#endif 