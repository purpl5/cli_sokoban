#include "base.h"
#include "levelSelector.h"
#include "levelLoading.h"
#include "emplacement.h"
#include "player.h"
#include "jeu.h"


int main() {

    // Test 
    char* nomLevel = choixLevelFile();

    /* 
    *  Pour l'instant : 
    *  l = contient tout le level au quelle on veux jouer 
    *  f = contient tout les emplacement sur lesquelle nous devons mettre des bloc (important de stocker ces informations)
    */
    Jeu * j = (Jeu*) malloc(sizeof(Jeu));

    j->l = loader(nomLevel);
    j->f = rechercheEmplacement(j->l); 
    j->pl = recherchePlayer(j->l); 


    afficherLevel(j->l);
    /*
    afficherEmplacement(j->f);
    afficherPlayer(j->p);
    */

    gameOn(j); 

    // Tout les free 
    freeLevel(j->l);
    freeEmplacement(j->f);
    freePlayer(j->pl); 
    free(j); 

    return EXIT_SUCCESS;
}