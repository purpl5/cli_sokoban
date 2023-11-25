#include "base.h"
#include "emplacement.h"
#include "jeu.h"
#include "levelLoading.h"
#include "levelSelector.h"
#include "player.h"

int main() {
    // Test
    char *nomLevel = choixLevelFile();

    /*
     *  Pour l'instant :
     *  l = contient tout le level au quelle on veux jouer
     *  f = contient tout les emplacement sur lesquelle nous devons mettre des
     * bloc (important de stocker ces informations)
     */
    Jeu *j = (Jeu *)malloc(sizeof(Jeu));

    j->l = loader(nomLevel);
    j->f = rechercheEmplacement(j->l);
    j->pl = recherchePlayer(j->l);

    afficherLevel(j->l);

    /*
    afficherEmplacement(j->f);
    afficherPlayer(j->pl);
    */

    gameOn(j);

    // Tout les free
    freeLevel(j->l);
    freeEmplacement(j->f);
    freePlayer(j->pl);
    free(j);

    return EXIT_SUCCESS;
}