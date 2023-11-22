#include "../header/base.h"
#include "../header/levelSelector.h"

Level* listLevel() {
    Level* list = newList(); 

    struct dirent *fichier; 
    DIR* dir = opendir("./level"); 
    if (dir == NULL) {
        return NULL; 
    }

    fichier = readdir(dir); 
    while (fichier != NULL) {
        if (strstr(fichier->d_name, ".txt") != NULL) {
            list = stockLevel(list, fichier->d_name); 
        } 
        fichier = readdir(dir); 
    }

    return list; 
}

Level* stockLevel(Level* list, char* namefile) {
    Level* new = (Level*) malloc(sizeof(Level)); 
    new->name = strdup(namefile);
    
    if (list == NULL ) {
        new->next = NULL; 
        return new; 
    }

    Level* tmp = list; 
    for (tmp; tmp->next != NULL; tmp = tmp->next); 
    tmp->next = new; 

    return list; 
}

Level* newList() {
    return (Level*) NULL; 
}

void afficherLevel(Level* list) {
    int i = 1; 
    for (Level* tmp = list; tmp != NULL; tmp = tmp->next, i++) {
        printf("%d : %s\n", i, tmp->name); 
    }
}

char* iemeLevel(Level* list, int i) {
    Level* tmp = list; 

    for (int n = 1; n < i; n++) {
        tmp = tmp->next;
    }

    return tmp->name; 
}   

char* choixLevel() {
    Level* allLevel = listLevel(); 
    int idLevel; 

    afficherLevel(allLevel); 

    printf("Veillez choisir quelle level vous voulez jouer :");
    scanf("%d", &idLevel);
    printf("Vous avez donc choisis de jouer le level : %s\n", iemeLevel(allLevel, idLevel));

    return iemeLevel(allLevel, idLevel);
}

