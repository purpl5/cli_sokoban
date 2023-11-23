#include "../header/bloc.h"

void deplacementBlocY(Level* l, FileEmplacement* f, Position* p, int sens) {
    if (estUnEmplacement(f, p)) {
        l->tab[p->y][p->x] = 'o'; 
    } else {
        l->tab[p->y][p->x] = ' '; 
    }

    p->y += sens; 
    l->tab[p->y][p->x] = 'p'; 

}

void deplacementBlocX(Level* l, FileEmplacement* f, Position* p, int sens) {
    if (estUnEmplacement(f, p)) {
        l->tab[p->y][p->x] = 'o'; 
    } else {
        l->tab[p->y][p->x] = ' '; 
    }

    p->x += sens; 
    l->tab[p->y][p->x] = 'p'; 
}