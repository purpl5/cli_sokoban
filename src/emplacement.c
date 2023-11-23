#include "../header/base.h"
#include "../header/levelLoading.h"
#include "../header/emplacement.h"

FileEmplacement* newEmplacement() {
    return (FileEmplacement*) NULL;
}

bool emplacementVide(FileEmplacement* f) {
    return f == (FileEmplacement*) NULL ? true : false; 
}

FileEmplacement* ajoutEmplacement(int x, int y, FileEmplacement* f) {
    FileEmplacement* new = (FileEmplacement*) malloc(sizeof(FileEmplacement)); 

    new->x = x; 
    new->y = y; 

    if (emplacementVide(f)) {
        new->next == (FileEmplacement*) NULL;
        return new;
    }

    FileEmplacement* tmp;
    for(tmp = f; tmp->next != (FileEmplacement*) NULL; tmp = tmp->next);

    tmp->next = new; 

    return f; 
}

FileEmplacement* rechercheEmplacement(Level* l) {
    FileEmplacement* f = newEmplacement(); 

    for (int i = 0; i < l->ligne; i++) {
        for (int j = 0; j < l->colonne; j++) {
            if (l->tab[i][j] == 'o') {
                f = ajoutEmplacement(j, i, f); 
            }
        }
    }

    return f;
}

void afficherEmplacement(FileEmplacement* f) {
    for (FileEmplacement* tmp = f; tmp != (FileEmplacement*) NULL; tmp = tmp->next) {
        printf("x : %d et y : %d\n", tmp->x, tmp->y); 
    }
}

void freeEmplacement(FileEmplacement* f) {
    while (f != (FileEmplacement*) NULL) {
        FileEmplacement* suppr = f; 
        f = f->next; 

        free(suppr);
    }
}