#include "../header/base.h"
#include "../header/levelSelector.h"
#include "../header/levelLoading.h"
#include "../header/emplacement.h"
#include "../header/player.h"
#include "../header/jeu.h"

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
    j->p = recherchePlayer(j->l); 

    afficherLevel(j->l); 
    afficherEmplacement(j->f); 
    afficherPlayer(j->p);

    // Tout les free 
    freeLevel(j->l);
    freeEmplacement(j->f);
    freePlayer(j->p); 
    free(j); 

    return EXIT_SUCCESS;
}