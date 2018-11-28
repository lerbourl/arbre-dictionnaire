#include <stdio.h>
#include <stdlib.h>

#include "dico.h"
#include "lecteur.h"

#define clrscr() printf("\033[H\033[2J")


int main() {

    char c[64];
    int nb;

    dico d = create_dico();
    clrscr();

    printf("On démarre avec un dictionnaire vide et on teste les fonctions qui affiche le dictionnaire et qui donne le nombre de mots, de noeuds, d'enfants et la hauteur du dictionnaire.\n");
    puts("Affichage du dico des deux manières");
    puts("");
    print_prefix(d);
    puts("");
    print_dico(d);
    printf("\nLe dictionnaire contient %d mot\n", nb_words(d));
    printf("\nIl y a %d noeud\n", nb_nodes(d));
    printf("\nLe mot le plus long est un mot de %d lettre\n", height(d));
    printf("\nLa lettre A a %d enfant\n", nb_children(d[0]));
    printf("\nLa lettre B a %d enfant\n", nb_children(d[1]));
    printf("\nLa lettre C a %d enfant\n", nb_children(d[2]));

    fgets(c , 64 , stdin);
    clrscr();

    /* Ajout de bonjour */
    add_rec(d , "bonjour" , strlen("bonjour"));
    printf("On refait les mêmes manipulations en rajoutant le mot bonjour\n");
    puts("Affichage du dico des deux manières");
    puts("");
    print_prefix(d);
    puts("");
    print_dico(d);
    printf("\nLe dictionnaire contient %d mot\n", nb_words(d));
    printf("\nIl y a %d noeud\n", nb_nodes(d));
    printf("\nLe mot le plus long est un mot de %d lettre\n", height(d));
    printf("\nLa lettre A a %d enfant\n", nb_children(d[0]));
    printf("\nLa lettre B a %d enfant\n", nb_children(d[1]));
    printf("\nLa lettre C a %d enfant\n", nb_children(d[2]));
    fgets(c , 64 , stdin);
    clrscr();


    /* Retrait de bonjour */
    remove_rec(d , "bonjour" , strlen("bonjour"));
    printf("On retire le mot bonjour du dictionnaire et on refait les tests précédents\n");
    puts("Affichage du dico des deux manières");
    puts("");
    print_prefix(d);
    puts("");
    print_dico(d);
    printf("\nLe dictionnaire contient %d mot\n", nb_words(d));
    printf("\nIl y a %d noeud\n", nb_nodes(d));
    printf("\nLe mot le plus long est un mot de %d lettre\n", height(d));
    printf("\nLa lettre A a %d enfant\n", nb_children(d[0]));
    printf("\nLa lettre B a %d enfant\n", nb_children(d[1]));
    printf("\nLa lettre C a %d enfant\n", nb_children(d[2]));
    fgets(c , 64 , stdin);
    clrscr();



    /* Chargement de pokemon1.txt */
    printf("On charge les mots du fichier pokemon1.txt dedans\nLe fichier contient :\n");
    system("cat ./dictionnaire/pokemon1.txt");
    fgets(c , 64 , stdin);


    chargerMotsDansDico("pokemon1.txt" , d);


    nb = nb_words(d);
    char * nomFichier = {"monDico"};
    chargeDicoDansFichier(d , nomFichier);


    printf("\nOn affiche les mots du dictionnaire\n\n");
    print_dico(d);
    fgets(c , 64 , stdin);


    printf("\nOn affiche les préfixes du dictionnaire\n\n");
    print_prefix(d);
    fgets(c , 64 , stdin);

    /* Nombre de mots */
    printf("Le dictionnaire contient %d mot%c\n", nb , (nb > 1)? 's' : ' ');
    fgets(c , 64 , stdin);

    /* Nombre de noeuds */
    nb = nb_nodes(d);
    printf("\nIl y a %d noeud%c\n", nb , (nb > 1)? 's' : ' ');
    fgets(c , 64 , stdin);

    /* Hauteur */
    nb = height(d);
    printf("\nLe mot le plus long est un mot de %d lettre%c\n", nb , (nb > 1)? 's' : ' ');
    fgets(c , 64 , stdin);

    /* Nombre d'enfants */
    printf("On va regarde le nombre d'enfants de la lettre M\n");
    nb = nb_children(d[get_index('m')]);
    printf("La lettre M a %d enfant%c\n", nb , (nb > 1)? 's' : ' ');
    fgets(c , 64 , stdin);

    printf("On va regarde le nombre d'enfants de la lettre N\n");
    nb = nb_children(d[get_index('n')]);
    printf("La lettre N a %d enfant%c\n", nb , (nb > 1)? 's' : ' ');
    fgets(c , 64 , stdin);

    printf("On va regarde le nombre d'enfants de la lettre A\n");
    nb = nb_children(d[get_index('a')]);
    printf("\nLa lettre A a %d enfant%c\n", nb , (nb > 1)? 's' : ' ');
    fgets(c , 64 , stdin);


    clrscr();






/**************** FONCTIONS RECURSIVES ****************/

    printf("Test des fonctions récursives :\n");
    fgets(c , 64 , stdin);

    printf("On va ajouter Pikachu\n");
    fgets(c , 64 , stdin);
    add_rec(d , "Pikachu" , strlen("Pikachu"));
    print_prefix(d);
    fgets(c , 64 , stdin);
    clrscr();

    printf("On va ajouter Nidorina\n");
    fgets(c , 64 , stdin);
    add_rec(d , "Nidorina" , strlen("Nidorina"));
    print_prefix(d);
    fgets(c , 64 , stdin);
    clrscr();

    printf("On va ajouter Nidorino\n");
    fgets(c , 64 , stdin);
    add_rec(d , "Nidorino" , strlen("Nidorino"));
    print_prefix(d);
    fgets(c , 64 , stdin);
    clrscr();

    printf("On va essayer d'ajouter Mew\n");
    fgets(c , 64 , stdin);
    add_rec(d , "Mew" , strlen("Mew"));
    print_prefix(d);
    printf("\nIl n'y a eu aucune modification\n");
    fgets(c , 64 , stdin);
    clrscr();

    printf("Test de la fonction contains\n\n");

    printf("Est ce que Mew est dans le dico ? %d\n", contains_rec(d , "Mew" , strlen("Mew")));
    printf("Est ce que Mewtwo est dans le dico ? %d\n", contains_rec(d , "Mewtwo" , strlen("Mewtwo")));
    printf("Est ce que Mewt est dans le dico ? %d\n", contains_rec(d , "Mewt" , strlen("Mewt")));
    printf("Est ce que Raichu est dans le dico ? %d\n", contains_rec(d , "Raichu" , strlen("Raichu")));
    printf("Est ce que Nido est dans le dico ? %d\n", contains_rec(d , "Nido" , strlen("Nido")));
    printf("Est ce que plusdedixlettres est dans le dico ? %d\n", contains_rec(d , "plusdedixlettres" , strlen("plusdedixlettres")));

    fgets(c , 64 , stdin);
    clrscr();

    printf("Le dico contient actuellement :\n");
    print_dico(d);
    printf("\nOn va maintenant supprimer tous les mots un par un\n");

    printf("Retrait de Dracaufeu\n");
    remove_rec(d , "Dracaufeu" , strlen("Dracaufeu"));
    print_dico(d);

    printf("Retrait de Draco\n");
    remove_rec(d , "Draco" , strlen("Draco"));
    print_dico(d);

    printf("Retrait de Dracolosse\n");
    remove_rec(d , "Dracolosse" , strlen("Dracolosse"));
    print_dico(d);

    printf("Retrait de Mew\n");
    remove_rec(d , "Mew" , strlen("Mew"));
    print_dico(d);

    printf("Retrait de Mewtwo\n");
    remove_rec(d , "Mewtwo" , strlen("Mewtwo"));
    print_dico(d);

    printf("Retrait de Minidraco\n");
    remove_rec(d , "Minidraco" , strlen("Minidraco"));
    print_dico(d);

    printf("Retrait de Nidorina\n");
    remove_rec(d , "Nidorina" , strlen("Nidorina"));
    print_dico(d);

    printf("Retrait de Nidorino\n");
    remove_rec(d , "Nidorino" , strlen("Nidorino"));
    print_dico(d);

    printf("Retrait de Nidoking\n");
    remove_rec(d , "Nidoking" , strlen("Nidoking"));
    print_dico(d);

    printf("Retrait de Nidoqueen\n");
    remove_rec(d , "Nidoqueen" , strlen("Nidoqueen"));
    print_dico(d);

    printf("Retrait de Pikachu\n");
    remove_rec(d , "Pikachu" , strlen("Pikachu"));
    print_dico(d);


    clrscr();




/**************** FONCTIONS ITERATIVES ****************/
    printf("Test des fonctions itératives :\n");
    fgets(c , 64 , stdin);

    printf("On recharge le fichier d'origine\n");
    chargerMotsDansDico("pokemon1.txt" , d);
    print_dico(d);
    fgets(c , 64 , stdin);


    clrscr();
    printf("On va ajouter Pikachu\n");
    fgets(c , 64 , stdin);
    add_iter(d , "Pikachu" , strlen("Pikachu"));
    print_prefix(d);
    fgets(c , 64 , stdin);
    clrscr();

    printf("On va ajouter Nidorina\n");
    fgets(c , 64 , stdin);
    add_iter(d , "Nidorina" , strlen("Nidorina"));
    print_prefix(d);
    fgets(c , 64 , stdin);
    clrscr();

    printf("On va ajouter Nidorino\n");
    fgets(c , 64 , stdin);
    add_iter(d , "Nidorino" , strlen("Nidorino"));
    print_prefix(d);
    fgets(c , 64 , stdin);
    clrscr();

    printf("On va essayer d'ajouter Mew\n");
    fgets(c , 64 , stdin);
    add_iter(d , "Mew" , strlen("Mew"));
    print_prefix(d);
    printf("\nIl n'y a eu aucune modification\n");
    fgets(c , 64 , stdin);
    clrscr();

    printf("Test de la fonction contains\n\n");

    printf("Est ce que Mew est dans le dico ? %d\n", contains_iter(d , "Mew" , strlen("Mew")));
    printf("Est ce que Mewtwo est dans le dico ? %d\n", contains_iter(d , "Mewtwo" , strlen("Mewtwo")));
    printf("Est ce que Mewt est dans le dico ? %d\n", contains_iter(d , "Mewt" , strlen("Mewt")));
    printf("Est ce que Raichu est dans le dico ? %d\n", contains_iter(d , "Raichu" , strlen("Raichu")));
    printf("Est ce que Nido est dans le dico ? %d\n", contains_iter(d , "Nido" , strlen("Nido")));
    printf("Est ce que plusdedixlettres est dans le dico ? %d\n", contains_iter(d , "plusdedixlettres" , strlen("plusdedixlettres")));

    fgets(c , 64 , stdin);
    clrscr();

    printf("Le dico contient actuellement :\n");
    print_dico(d);
    printf("\nOn va maintenant supprimer tous les mots un par un\n");

    printf("Retrait de Dracaufeu\n");
    remove_iter(d , "Dracaufeu" , strlen("Dracaufeu"));
    print_dico(d);

    printf("Retrait de Draco\n");
    remove_iter(d , "Draco" , strlen("Draco"));
    print_dico(d);

    printf("Retrait de Dracolosse\n");
    remove_iter(d , "Dracolosse" , strlen("Dracolosse"));
    print_dico(d);

    printf("Retrait de Mew\n");
    remove_iter(d , "Mew" , strlen("Mew"));
    print_dico(d);

    printf("Retrait de Mewtwo\n");
    remove_iter(d , "Mewtwo" , strlen("Mewtwo"));
    print_dico(d);

    printf("Retrait de Minidraco\n");
    remove_iter(d , "Minidraco" , strlen("Minidraco"));
    print_dico(d);

    printf("Retrait de Nidorina\n");
    remove_iter(d , "Nidorina" , strlen("Nidorina"));
    print_dico(d);

    printf("Retrait de Nidorino\n");
    remove_iter(d , "Nidorino" , strlen("Nidorino"));
    print_dico(d);

    printf("Retrait de Nidoking\n");
    remove_iter(d , "Nidoking" , strlen("Nidoking"));
    print_dico(d);

    printf("Retrait de Nidoqueen\n");
    remove_iter(d , "Nidoqueen" , strlen("Nidoqueen"));
    print_dico(d);

    printf("Retrait de Pikachu\n");
    remove_iter(d , "Pikachu" , strlen("Pikachu"));
    print_dico(d);




    system("rm monDico");
    destroy_dico(&d);
    return 0;
}
