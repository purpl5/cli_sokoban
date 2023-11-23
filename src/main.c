#include "../header/base.h"
#include "../header/levelSelector.h"
#include "../header/levelLoading.h"
#include "../header/emplacement.h"
#include "../header/player.h"

int main() {

    // Test 
    char* nomLevel = choixLevelFile();
    
    /* 
    *  Pour l'instant : 
    *  l = contient tout le level au quelle on veux jouer 
    *  f = contient tout les emplacement sur lesquelle nous devons mettre des bloc (important de stocker ces informations)
    */
   
    Level* l = loader(nomLevel);
    FileEmplacement* f = rechercheEmplacement(l); 
    Player* p = recherchePlayer(l); 

    afficherLevel(l); 
    afficherEmplacement(f); 
    afficherPlayer(p);

    // Tout les free 
    freeLevel(l);
    freeEmplacement(f);
    freePlayer(p); 

    return EXIT_SUCCESS;
}