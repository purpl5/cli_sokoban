#include "../header/base.h"
#include "../header/levelLoading.h"
#include "../header/mur.h"
#include "../header/position.h"


bool estUnMur(Level* l, Position* p) {
    return l->tab[p->y][p->x] == '#' ? true : false;
}
