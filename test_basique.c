#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "dico.h"


int main() {

    dico d1 = create_dico();
    dico d2 = create_dico();
    dico d3 = create_dico();
    dico d4 = create_dico();


    add_iter(d1 , "abc" , 3);
    add_iter(d1 , "abcde" , 5);
    add_iter(d1 , "abcdf" , 5);
    add_iter(d1 , "aclmo" , 5);
    add_iter(d1 , "xyz" , 3);


    puts("Dico 1 :");
    print_prefix(d1);


    printf("\nNombre d'enfants de la lettre a : %d\n", nb_children(d1[0]));
    printf("Nombre de noeuds : %d\n", nb_nodes(d1));
    printf("Hauteur : %d\n", height(d1));


    add_iter(d2 , "abc" , 3);
    add_iter(d2 , "abcde" , 5);
    add_iter(d2 , "abcdf" , 5);
    add_iter(d2 , "aclmo" , 5);
    add_iter(d2 , "xyz" , 3);

    puts("");
    puts("Dico 2 identique à Dico 1 :");
    print_prefix(d2);

    puts("");
    printf("1 = 2 ? %d\n", equal(d1 , d2));

    add_iter(d3 , "abcde" , 5);
    add_iter(d3 , "abcdf" , 5);
    add_iter(d3 , "aclmo" , 5);
    add_iter(d3 , "xyz" , 3);

    puts("");
    puts("Dico 3 presque identique :");
    print_prefix(d3);

    puts("");
    printf("1 = 3 ? %d\n", equal(d1 , d3));

    add_iter(d4 , "abc" , 3);
    add_iter(d4 , "abcde" , 5);
    add_iter(d4 , "abcdf" , 5);
    add_iter(d4 , "k" , 1);
    add_iter(d4 , "aclmo" , 5);
    add_iter(d4 , "xyz" , 3);

    puts("");
    puts("Dico 4 :");
    print_prefix(d4);

    puts("");
    printf("1 = 4 ? %d\n", equal(d1 , d4));


    destroy_dico(&d1);
    destroy_dico(&d2);
    destroy_dico(&d3);
    destroy_dico(&d4);

    return 0;
}
