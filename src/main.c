#include "../header/base.h"
#include "../header/levelSelector.h"
#include "../header/levelLoading.h"

int main() {

    // Nous aurons donc stocker dans nomLevel le Level qui sera jouer par l'utilisateur;
    char* nomLevel = choixLevelFile();
    
    Level* l = loader(nomLevel);

    afficherLevel(l); 

    freeTab(l);
    free(l); 
    return EXIT_SUCCESS;
}