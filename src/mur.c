#include "../header/base.h"
#include "../header/levelLoading.h"
#include "../header/mur.h"


bool estUnMur(Level* l, int x, int y) {
    return l->tab[y][x] == '#' ? true : false;
}
