#include "base.h"
#include "jeu.h"

/**
 * @file main.c
 * @brief Point d'entrée principal du jeu.
 *
 * Ce fichier contient la fonction main, qui est le point de départ du jeu.
 * Il initialise le jeu en appelant la fonction gameOn et termine par renvoyer
 * un code de succès lorsque le jeu se termine.
 */

int main() {
    gameOn();

    return EXIT_SUCCESS;
}