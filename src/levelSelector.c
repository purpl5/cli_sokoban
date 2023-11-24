#include "base.h"
#include "levelSelector.h"

// ---------------------------------------

/*
*  Nom : newList
*  Précondition : aucune 
*  Effet de bord : aucun
*  Argument : aucun
*  Explication de la fonction : Permet de creer une variable de type LevelFile*
*  Retour : NULL (cast important pour préciser le type)
*/

LevelFile* newList() {
    return (LevelFile*) NULL; 
}

// ---------------------------------------

/*
*  Nom : stockLevelFile
*  Précondition : Aucune
*  Effet de bord : Aucun 
*  Argument : 
*     - list : la list dans laquelle on veux stocker le Level 
*     - namefile : le nom du level
*  Explication de la fonction : la fonction va nous premettre de stocker un nouveal level & la fin de la list  
*  Retour : renvoie la list avec le nouveau level à la dernière position
*/

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

// ---------------------------------------

/*
*  Nom : listLevelFile
*  Précondition : Il faut que les levels soient contenu dans ./level/
*  Effet de bord : Aucun
*  Argument : Aucun
*  Explication de la fonction : Va stocker dans list (de type LevelFile*) 
*  le nom de chaque ficher de type level*.txt
*  Retour : retourne la list avec tout les nom de fichiers stocker dedans 
*/

LevelFile* listLevelFile() {
    LevelFile* list = newList(); 

    struct dirent *fichier; 

    DIR* dir = opendir("./level"); 
    if (dir == NULL) {
        return NULL; 
    }
    
    fichier = readdir(dir); 
    while (fichier != NULL) {
        if (strstr(fichier->d_name, ".txt") && strstr(fichier->d_name, "level") != NULL) {
            list = stockLevelFile(list, fichier->d_name); 
        } 
        fichier = readdir(dir); 
    }

    closedir(dir);

    return list; 
}

// ---------------------------------------

/*
*  Nom : iemeLevelFile
*  Précondition : Aucune  
*  Effet de bord : Il y a un affichage dans le cas ou i est superieur à la taille de la list
*  Argument :
*     - list : La liste dans laquelle on va chercher notre élément 
*     - i : la positon de l'élément qu'on cherche à trouver 
*  Explication de la fonction : La fonction va chercher dans la liste le ieme élément 
*  Retour : renvoie le nom de l'ieme élément 
*/

char* iemeLevelFile(LevelFile* list, int i) {
    LevelFile* tmp = list; 

    for (int n = 1; n < i; n++) {
        if (tmp == NULL) {
            printf("erreur, il n'a pas de valeur a la position %d de ceux tableau", i); 
            return (char*) NULL; 
        }
        tmp = tmp->next;
    }

    return tmp->name; 
}   

// ---------------------------------------

/*
*  Nom : afficherLevelFile
*  Précondition : Aucune 
*  Effet de bord : Va afficher tout les Level contenu dans la list
*  Argument : 
*     - list : liste contenant des Level 
*  Explication de la fonction : cette fonction va nous afficher en donnant un identifiant unique et croissant à chauqe level contenu dans list 
*  Retour : pas de retour c'est une procédure 
*/

void afficherLevelFile(LevelFile* list) {
    int i = 1; 
    for (LevelFile* tmp = list; tmp != NULL; tmp = tmp->next, i++) {
        printf("%d : %s\n", i, tmp->name); 
    }
}

// ---------------------------------------

/*
*  Nom : freeAllLevelFile
*  Précondition : aucune 
*  Effet de bord : aucun 
*  Argument : La liste que l'on veux free
*  Explication de la fonction : La fonction va free le nom de chaque élément et tout les l'élément de la liste
*  Retour : ne renvoie rien, c'est une procédure 
*/

void freeAllLevelFile(LevelFile* list) {
    while (list != NULL) {
        LevelFile* suppr = list; 
        list = list->next; 

        free(suppr->name);
        free(suppr); 
    }
}

// ---------------------------------------

/*
*  Nom : choixLevelFile
*  Précondition : Pas de précondition
*  Effet de bord : vas afficher plusieur text permettant de le choix du level que l'utilisateur veux jouer 
*  Argument : aucun 
*  Explication de la fonction : cette fonction permet en gros de faire tout les affichage et entrée d'utilisateur nécessité par le programme pour faire le choix d'un level
*  Retour : retour le nom du level choisis 
*/

char* choixLevelFile() {
    LevelFile* allLevel = listLevelFile(); 
    int idLevel = 0; 

    afficherLevelFile(allLevel); 

    printf("Veillez choisir quelle Level vous voulez jouer :");
    scanf("\n%d", &idLevel);
    printf("Vous avez donc choisis de jouer le LevelFile : %s\n", iemeLevelFile(allLevel, idLevel));

    char* levelName = strdup(iemeLevelFile(allLevel, idLevel));

    freeAllLevelFile(allLevel);
    
    return levelName;
}

