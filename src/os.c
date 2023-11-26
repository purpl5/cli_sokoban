#include "os.h"
#include "base.h"

/**
 * @file os.c
 * @brief Implémentations des fonctions pour la gestion de la compatibilité
 * entre systèmes d'exploitation.
 *
 * Ce fichier contient les implémentations des fonctions pour assurer la
 * compatibilité entre différents systèmes d'exploitation, actuellement juste
 * pour gérer le clear du cmd.
 */

void clearCmd() {
    if (OS_NUMBER == 1) {
        system("clear");
    } else if (OS_NUMBER == 0) {
        system("cls");
    }
}