#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "dico.h"
#include "lecteur.h"
// #include "test_basique.h"
// #include "test_iter.h"
// #include "test_rec.h"
// #include "test_5-6.h"
// #include "test_generique.h"
// #include "test_complet.h"

/* Le paramètre mode permet d'alterner entre le choix de lettres ou de chiffres en précisant 'a' ou '0' */
int getRep(int borneInf , int borneSup , char *message , int mode) {

    int rep = 0;
    char c[8];
    bool erreur = false;

    do {
        if (erreur) {
            printf("Donner un nombre entre %d et %d\n\n", borneInf , borneSup);
        }
        rep = 0;
        printf("%s", message);
        fgets(c , 7 , stdin);
        for (unsigned int k = 0 ; k < strlen(c)-1 ; k++) {
            rep = rep * 10 + c[k] - mode;
            // c[k] = '0';
        }
        erreur = true;
    } while(rep < borneInf || rep > borneSup);
    return rep;
}


int main()
{


    puts("Bienvenue dans le menu de tests du dictionnaire !!!");




    // system("cat dico.h");
    char c[64];
    char mot[64];
    int rep = 1;
    unsigned int choix = 0;
    unsigned int nb = 0;

    dico d = create_dico();





    do {


        puts("");
        puts("Que voulez-vous faire ?");

        do {
            if (rep < 0 || rep > 9) {
                printf("Erreur de sélection\n\n\n");
            }
            printf("\t0 -> Quitter\n\n");
            printf("\t1 -> Afficher le dictionnaire\n");
            printf("\t2 -> Ajouter un mot\n");
            printf("\t3 -> Supprimer un mot\n");
            printf("\t4 -> Tester si un mot est présent\n\n");

            printf("\t5 -> Connaitre le nombre de mots\n");
            printf("\t6 -> Connaitre le nombre d'enfants\n");
            printf("\t7 -> Connaitre le nombre de noeuds\n");
            printf("\t8 -> Connaitre la hauteur du dictionnaire\n");
            printf("\t9 -> Charger un fichier contenant des mots\n");

            fgets(c , 64 , stdin);
            rep = 0;

            if (c[0] == '\n') {
                rep = -1;
            }
            else {
                for (unsigned int k = 0 ; k < strlen(c)-1 ; k++) {
                    rep = rep * 10 + c[k] - 48;
                    c[k] = '0';
                }
            }
            // printf("rep : %d\n", rep);
        } while(rep < 0 || rep > 10);

        switch (rep) {

            case 0:
            break;

            case 1:

                choix = getRep(1 , 2 , "\nComment afficher le dictionnaire ?\n\t1 -> print_prefix\n\t2 -> print_dico\n" , '0');
                puts("");
                if (choix == 1) {
                    print_dico(d);
                }
                else if (choix == 2) {
                    print_dico(d);
                }
                else {
                    puts("Erreur de choix");
                    exit(EXIT_FAILURE);
                }
            break;


            case 2:
                puts("Quel mot ajouter ?");
                fgets(mot , 63 , stdin);
                mot[strlen(mot) - 1] = '\0';
                choix = getRep(1 , 2 , "\nComment ajouter le mot ?\n\t1 -> ajout itératif\n\t2 -> ajout récursif\n" , '0');
                if (choix == 1) {
                    if (add_iter(d , mot , strlen(mot))) {
                        puts("Le mot a été ajouté");
                    }
                    else puts("Le mot est déjà présent");
                }
                else if (choix == 2) {
                    if (add_rec(d , mot , strlen(mot))) {
                        puts("Le mot a été ajouté");
                    }
                    else puts("Le mot est déjà présent");
                }
                else {
                    puts("Erreur de choix");
                    exit(EXIT_FAILURE);
                }
            break;


            case 3:
                puts("Quel mot supprimer ?");
                fgets(mot , 63 , stdin);
                mot[strlen(mot) - 1] = '\0';
                choix = getRep(1 , 2 , "\nComment supprimer le mot ?\n\t1 -> remove itératif\n\t2 -> remove récursif\n" , '0');
                if (choix == 1) {
                    if (remove_iter(d , mot , strlen(mot))) {
                        puts("Le mot a été retiré");
                    }
                    else puts("Le mot n'a pas pu être retiré");
                }
                else if (choix == 2) {
                    if (remove_rec(d , mot , strlen(mot))) {
                        puts("Le mot a été retiré");
                    }
                    else puts("Le mot n'a pas pu être retiré");
                }
                else {
                    puts("Erreur de choix");
                    exit(EXIT_FAILURE);
                }
            break;


            case 4:
                puts("Quel mot tester ?");
                fgets(mot , 63 , stdin);
                mot[strlen(mot) - 1] = '\0';
                choix = getRep(1 , 2 , "\nComment tester le mot ?\n\t1 -> contains itératif\n\t2 -> contains récursif\n" , '0');
                if (choix == 1) {
                    if (contains_iter(d , mot , strlen(mot))) {
                        printf("Le mot est présent\n");
                    }
                    else printf("Le mot est absent\n");
                }
                else if (choix == 2) {
                    if (contains_rec(d , mot , strlen(mot))) {
                        printf("Le mot est présent\n");
                    }
                    else printf("Le mot est absent\n");
                }
                else {
                    puts("Erreur de choix");
                    exit(EXIT_FAILURE);
                }
            break;


            case 5:
                nb = nb_words(d);
                printf("\nIl y a %d mot%c\n", nb , (nb > 1)? 's' : ' ');
            break;


            case 6:
                choix = getRep(0 , 25 , "Quel arbre choisir ? (une lettre suffit)\n" , 'a');
                nb = nb_children(d[choix]);
                printf("\nLa lettre %c a %d enfant%c\n", get_char(choix) , nb , (nb > 1)? 's' : ' ');
            break;


            case 7:
                nb = nb_nodes(d);
                printf("\nIl y a %d noeud%c\n", nb , (nb > 1)? 's' : ' ');
            break;


            case 8:
                nb = height(d);
                printf("\nLe mot le plus long est un mot de %d lettre%c\n", nb , (nb > 1)? 's' : ' ');
            break;


            case 9:

                system("ls -l ./dictionnaire/ | wc -l > nbFichier.txt");
                FILE * f1 = fopen("nbFichier.txt" , "rt");
                int nbFichier = 0;
                if (f1 == NULL) {
                    printf("Impossible d'ouvrir le fichier\n");
                    exit(EXIT_FAILURE);
                }

                if (fscanf(f1, "%d" , &nbFichier) == 0) {
                    printf("Erreur de lecture\n");
                    exit(EXIT_FAILURE);
                }


                fclose(f1);
                system("rm nbFichier.txt");

                system("ls ./dictionnaire/ > .nomDico");
                FILE *f2 = fopen(".nomDico" , "rt");
                char nomDico[64];

                do {
                    rewind(f2);
                    printf("\nListe des dictionnaires disponibles :\n");
                    system("ls -lsh ./dictionnaire/");
                    choix = getRep(0 , nbFichier - 2 , "\nPour sélectionner un dictionnaire, donner son numéro (on commence à 0)\n" , '0');

                    for (unsigned int k = 0 ; k <= choix ; k++) {
                        fscanf(f2 , "%s" , nomDico);
                    }

                    printf("Vous avez sélectionné %s\n", nomDico);
                    choix = getRep(0 , 2 , "\n0 -> Voir son contenu\n1 -> Choisir un autre fichier\n2 -> Charger ce fichier dans le dictionnaire\n" , '0');


                    if (choix == 0) {
                        char commande[128] = {"cat ./dictionnaire/"};
                        strcat(commande , nomDico);
                        puts("");

                        system(commande);

                        choix = getRep(0 , 1 , "\n0 -> Choisir un autre fichier\n1 -> Charger ce fichier dans le dictionnaire\n" , '0');
                        choix++;
                    }

                } while(choix != 2);

                fclose(f2);
                system("rm .nomDico");

                // nomDico[strlen(nomDico)] = '\0';
                chargerMotsDansDico(nomDico , d);

            break;

        }
    } while(rep);

    destroy_dico(&d);

    return 0;
}
