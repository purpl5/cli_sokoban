#include "../header/base.h"
#include "../header/levelSelector.h"
#include "../header/levelLoading.h"
#include "../header/emplacement.h"

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

    afficherLevel(l); 
    afficherEmplacement(f); 

    // Tout les free 
    freeLevel(l);
    freeEmplacement(f);

    return EXIT_SUCCESS;
}