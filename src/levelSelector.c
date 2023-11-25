#include "levelSelector.h"
#include "base.h"

LevelFile* newList() {
    return (LevelFile*)NULL;
}

LevelFile* stockLevelFile(LevelFile* list, char* namefile) {
    LevelFile* new = (LevelFile*)malloc(sizeof(LevelFile));
    new->name = strdup(namefile);
    new->next = (LevelFile*)NULL;

    if (list == NULL) {
        return new;
    }

    LevelFile* tmp;

    for (LevelFile* i = list; i != NULL; i = i->next) {
        if (i->next == NULL) {
            tmp = i;
        }
    }

    tmp->next = new;

    return list;
}

LevelFile* listLevelFile() {
    LevelFile* list = newList();

    struct dirent* fichier;

    DIR* dir = opendir("./level");
    if (dir == NULL) {
        return NULL;
    }

    fichier = readdir(dir);
    while (fichier != NULL) {
        if (strstr(fichier->d_name, ".txt") &&
            strstr(fichier->d_name, "level") != NULL) {
            list = stockLevelFile(list, fichier->d_name);
        }
        fichier = readdir(dir);
    }

    closedir(dir);

    return list;
}

char* iemeLevelFile(LevelFile* list, int i) {
    LevelFile* tmp = list;

    for (int n = 1; n < i; n++) {
        if (tmp == NULL) {
            printf(
                "erreur, il n'a pas de valeur a la position %d de ceux tableau",
                i);
            return (char*)NULL;
        }
        tmp = tmp->next;
    }

    return tmp->name;
}

void afficherLevelFile(LevelFile* list) {
    int i = 1;
    for (LevelFile* tmp = list; tmp != NULL; tmp = tmp->next, i++) {
        printf("%d : %s\n", i, tmp->name);
    }
}

void freeAllLevelFile(LevelFile* list) {
    while (list != NULL) {
        LevelFile* suppr = list;
        list = list->next;

        free(suppr->name);
        free(suppr);
    }
}

char* choixLevelFile() {
    LevelFile* allLevel = listLevelFile();
    int idLevel = 0;

    afficherLevelFile(allLevel);

    printf("Veillez choisir quelle Level vous voulez jouer :");
    scanf("\n%d", &idLevel);

    char* levelName = strdup(iemeLevelFile(allLevel, idLevel));

    freeAllLevelFile(allLevel);

    return levelName;
}
