#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "dico.h"
#include "lecteur.h"
#include "test_basique.h"
#include "test_iter.h"
#include "test_rec.h"
#include "test_5-6.h"
#include "test_generique.h"

/* Le paramètre mode permet d'alternet entre le choix de lettres ou de chiffres */
int getRep(int borneInf , int borneSup , char *message , int mode) {

    int rep = 0;
    char c[8];

    do {
        rep = 0;
        printf("%s", message);
        fgets(c , 7 , stdin);
        for (unsigned int k = 0 ; k < strlen(c)-1 ; k++) {
            rep = rep * 10 + c[k] - mode;
            // c[k] = '0';
        }
    } while(rep < borneInf || rep > borneSup);
    return rep;
}


int main(int argc , char *argv[])
{


    puts("Bienvenue dans le menu de tests du dictionnaire !!!");




    // system("cat dico.h");
    char c[8];
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


            fgets(c , 7 , stdin);
            rep = 0;
            for (unsigned int k = 0 ; k < strlen(c)-1 ; k++) {
                rep = rep * 10 + c[k] - 48;
                c[k] = '0';
            }
            // printf("rep : %d\n", rep);
        } while(rep < 0 || rep > 9);

        switch (rep) {

            case 0:
            break;

            case 1:

                choix = getRep(1 , 2 , "\nComment afficher le dictionnaire ?\n\t1 -> print_prefix\n\t2 -> print_dico\n" , '0');
                puts("");
                if (choix == 1) {
                    if (!print_prefix(d)) {
                        puts("Le dictionnaire est vide");
                    }
                }
                else if (choix == 2) {
                    if (!print_dico(d)) {
                        puts("Le dictionnaire est vide");
                    }
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
                puts("Liste des dictionnaires disponibles");
                system("ls -sh ./dictionnaire/");
                puts("Pour voir son contenu, donner son numéro (on commence à 1 et 0 pour ignorer)");
                choix = getRep(0 , 3 , NULL , '0');
                if (choix == 1) {
                    sytem("cat dico1.txt");
                }

                if (choix == 2) {
                    sytem("cat dico2.txt");
                }

                if (choix == 3) {
                    sytem("cat test.txt");
                }

            break;

        }




        //
        // int errno = 0;
        // n = scanf("%m[1-9]", &p);
        // if (n == 1) {
        //     printf("read: %s\n", p);
        //     free(p);
        // } else if (errno != 0) {
        //     perror("scanf");
        // } else {
        //     fprintf(stderr, "No matching characters\n");
        //     exit(EXIT_FAILURE);
        // }
        //
        //
        //
        // printf("0 -> Quittez\n");
        // printf("1 -> Continuer\n");
        //
        // n = scanf("%m[0-1]", &rep);
        // if (n == 1) {
        //     printf("read: %s\n", rep);
        //     free(p);
        // } else if (errno != 0) {
        //     perror("scanf");
        // } else {
        //     printf("read: %s\n", rep);
        //     fprintf(stderr, "No matching characters\n");
        //     exit(EXIT_FAILURE);
        // }



    } while(rep);


    destroy_dico(&d);

    return 0;

    // if (argc != 3) {
	// fprintf(stderr, "Usage: %s FileInpit FileOutput\n", argv[0]);
	// exit(EXIT_FAILURE);
    // }
    // test_basique();
    // test_iter();
    // test_rec();
    // test_5_6();
    // test_generique(argv[1] , argv[2]);
    // return 0;
}
