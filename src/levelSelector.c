#include "../header/base.h"
#include "../header/levelSelector.h"

LevelFile* listLevelFile() {
    LevelFile* list = newList(); 

    struct dirent *fichier; 

    DIR* dir = opendir("./level"); 
    if (dir == NULL) {
        return NULL; 
    }
    
    fichier = readdir(dir); 
    while (fichier != NULL) {
        if (strstr(fichier->d_name, ".txt") != NULL) {
            list = stockLevelFile(list, fichier->d_name); 
        } 
        fichier = readdir(dir); 
    }

    return list; 
}

LevelFile* stockLevelFile(LevelFile* list, char* namefile) {
    LevelFile* new = (LevelFile*) malloc(sizeof(LevelFile)); 
    new->name = strdup(namefile);
    
    if (list == NULL) {
        new->next = (LevelFile*) NULL; 
        return new; 
    }

    LevelFile* tmp = list; 
    for (tmp; tmp->next != NULL; tmp = tmp->next); 
    tmp->next = new; 

    return list; 
}

LevelFile* newList() {
    return (LevelFile*) NULL; 
}

void afficherLevelFile(LevelFile* list) {
    int i = 1; 
    for (LevelFile* tmp = list; tmp != NULL; tmp = tmp->next, i++) {
        printf("%d : %s\n", i, tmp->name); 
    }
}

char* iemeLevelFile(LevelFile* list, int i) {
    LevelFile* tmp = list; 

    for (int n = 1; n < i; n++) {
        tmp = tmp->next;
    }

    return tmp->name; 
}   

char* choixLevelFile() {
    LevelFile* allLevel = listLevelFile(); 
    int idLevel; 

    afficherLevelFile(allLevel); 

    printf("Veillez choisir quelle Level vous voulez jouer :");
    scanf("%d", &idLevel);
    printf("Vous avez donc choisis de jouer le LevelFile : %s\n", iemeLevelFile(allLevel, idLevel));

    return iemeLevelFile(allLevel, idLevel);
}

