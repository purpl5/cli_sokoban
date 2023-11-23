#include "../header/base.h"
#include "../header/levelLoading.h"
#include "../header/emplacement.h"
#include "../header/position.h"
#include "../header/jeu.h"

FileEmplacement* newEmplacement() {
    return (FileEmplacement*) NULL;
}

bool emplacementVide(FileEmplacement* f) {
    return f == (FileEmplacement*) NULL ? true : false; 
}

FileEmplacement* ajoutEmplacement(int x, int y, FileEmplacement* f) {
    FileEmplacement* new = (FileEmplacement*) malloc(sizeof(FileEmplacement)); 
    new->p = initPos(new->p, x, y); 

    if (emplacementVide(f)) {
        new->next == (FileEmplacement*) NULL;
        return new;
    }

    new->next = NULL;

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
    int i = 0; 
    for (FileEmplacement* tmp = f; tmp != (FileEmplacement*) NULL; tmp = tmp->next) {
        printf("L'emplacement %d est à la position : x : %d et y : %d\n", i, tmp->p->x, tmp->p->y); 
        i++; 
    }
}

void freeEmplacement(FileEmplacement* f) {
    while (f != (FileEmplacement*) NULL) {
        FileEmplacement* suppr = f; 
        f = f->next; 
        freePos(suppr->p); 
        free(suppr);
    }
}