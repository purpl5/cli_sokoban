#include "os.h"
#include "base.h"

void clearCmd() {
    if (OS_NUMBER == 1) {
        system("clear");
    } else if (OS_NUMBER == 0) {
        system("cls");
    }
}