#include "base.h"
#include "emplacement.h"
#include "jeu.h"
#include "levelLoading.h"
#include "levelSelector.h"
#include "player.h"

int main() {
    char *nomLevel = choixLevelFile();

    Jeu *j = (Jeu *)malloc(sizeof(Jeu));

    j->l = loader(nomLevel);
    j->f = rechercheEmplacement(j->l);
    j->pl = recherchePlayer(j->l);

    afficherLevel(j->l);

    gameOn(j);

    // Tout les free
    freeLevel(j->l);
    freeEmplacement(j->f);
    freePlayer(j->pl);
    free(j);

    return EXIT_SUCCESS;
}