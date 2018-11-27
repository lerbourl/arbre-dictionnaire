#include "lecteur.h"

int lireLigne(char *mot , int tailleMot , FILE *f) {
    int ligneValide = 1;
    if (fgets(mot , tailleMot , f) == 0) ligneValide = -1;
    else {
        mot[strlen(mot) - 1] = 0;
        for (unsigned int k = 0 ; k < strlen(mot) ; k++) {
            if (!((mot[k] >= 'a' && mot[k] <= 'z') || (mot[k] >= 'A' && mot[k] <= 'Z') )) {
                ligneValide = 0;
            }
        }
    }
    return ligneValide;
}

void chargerMotsDansDico(char *nomDico , dico d) {

    FILE *f = NULL;

    if (nomDico[0] != '.') {
        char nomFichier[128] = {"./dictionnaire/"};
        strcat(nomFichier , nomDico);
        f = fopen(nomFichier , "rt");
    }
    else {
        f = fopen(nomDico , "rt");
    }



    if (f == NULL) {printf("Impossible d'ouvrir le fichier\n"); return;}
    char mot[64];
    int taille = 64;
    int res;
    int alea;
    do {
        res = lireLigne(mot , taille , f);
        if (res == 1) {
            srand(time(NULL));
            alea = rand() % 2;
            if (alea == 0) {
                add_iter(d , mot , strlen(mot));
            }
            else {
                add_rec(d , mot , strlen(mot));
            }
        }
    } while(res != -1);

    fclose(f);
    return;
}


void chargeDicoDansFichier(dico d , char * nomFichier) {
    FILE *f = fopen(nomFichier , "wt");
    char buffer[26];
    chargeDico_buff(d , 0 , buffer , f);
    fclose(f);
}

void chargeDico_buff(dico d , unsigned int ind_buff , char * buffer , FILE *f) {

    if (d == NULL) return;

    for (unsigned int k = 0 ; k < NB_KEYS ; k++) {

        if (d[k] != NULL) {
            buffer[ind_buff] = d[k]->first;
            ind_buff++;
            if (d[k]->end_of_word) {
                char * mot = calloc(ind_buff + 1 , sizeof(char));
                unsigned int j;
                for (j = 0 ; j < ind_buff ; j++) {
                    // printf("%c", buffer[j]);
                    mot[j] = buffer[j];
                }
                mot[j] = '\0';
                fprintf(f , "%s\n" , mot);
                free(mot);
                mot = NULL;
            }
            if (d[k]->children != NULL) {
                chargeDico_buff(d[k]->children , ind_buff , buffer , f);
            }
            ind_buff--;
        }
    }
    return;
}




void creerDicoSansAccent(char *nomDico , char *nomFichier) {
    FILE *f = fopen(nomDico , "rt");
    FILE *f1 = fopen(nomFichier , "wt");

    if (f == NULL) {printf("Impossible d'ouvrir le fichier\n"); return;}
    char mot[64];
    int taille = 64;
    int res;
    do {
        res = lireLigne(mot , taille , f);
        if (res == 1) {
            // printf("mot : %s\n", mot);
            fprintf(f1 ,"%s\n" , mot);
        }
    } while(res != -1);

    fclose(f);
    fclose(f1);
    return;
}
