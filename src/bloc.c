#include "bloc.h"
#include "levelLoading.h"
#include "position.h"
#include "player.h"

void deplacementBlocY(Level* l, FileEmplacement* f, Position* p, int sens, int* nbBlocSurEmplacement) {
    if (estUnEmplacement(f, p)) {
        *nbBlocSurEmplacement = *nbBlocSurEmplacement - 1; 
    } 

    p->y += sens; 

    if (estUnEmplacement(f, p)) {
        *nbBlocSurEmplacement = *nbBlocSurEmplacement + 1; 
    } 

    l->tab[p->y][p->x] = 'x'; 

}

void deplacementBlocX(Level* l, FileEmplacement* f, Position* p, int sens, int* nbBlocSurEmplacement) {
    if (estUnEmplacement(f, p)) {
        *nbBlocSurEmplacement = *nbBlocSurEmplacement - 1;
    } 

    p->x += sens; 

    if (estUnEmplacement(f, p)) {
        *nbBlocSurEmplacement = *nbBlocSurEmplacement + 1;
    } 

    l->tab[p->y][p->x] = 'x'; 
}