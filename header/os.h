#ifndef OS_H
#define OS_H

/**
 * @file os.h
 * @brief Définitions pour la gestion de la compatibilité entre différents
 * systèmes d'exploitation.
 *
 * Ce fichier contient des directives de préprocesseur pour déterminer
 * l'environnement d'exécution du jeu (Windows, Unix, etc.) et définir des
 * constantes en conséquence. Il est utilisé pour gérer les différences entre
 * les systèmes d'exploitation dans le code.
 */

/**
 * @def OS_NUMBER
 * @brief Constante définissant le type de système d'exploitation.
 *
 * Cette constante est utilisée pour gérer les différences entre les systèmes
 * d'exploitation. Elle est définie comme 0 pour Windows et 1 pour les systèmes
 * Unix (Linux, MacOS, etc.).
 */

#ifdef _WIN32
#define OS_NUMBER 0
#endif

#ifdef __unix__
#define OS_NUMBER 1
#endif

/**
 * @brief Lance et gère la boucle principale du jeu.
 *
 * Cette fonction clear l'invite de commande
 *
 */
void clearCmd();

#endif