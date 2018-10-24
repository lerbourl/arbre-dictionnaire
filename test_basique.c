#include "test_basique.h"


void test_basique() {

    puts("");
    puts("");
    puts("Début de test_basique");
    puts("");

    dico d = create_dico();

    dico d1 = create_dico();


    add_iter(d , "abc" , 3);
    add_iter(d , "abcde" , 5);
    add_iter(d , "abcdf" , 5);
    add_iter(d , "aclmo" , 5);
    add_iter(d , "xyz" , 3);


    puts("Dico 1 :");
    print_prefix(d);


    add_iter(d1 , "abc" , 3);
    add_iter(d1 , "abcde" , 5);
    add_iter(d1 , "abcdf" , 5);
    add_iter(d1 , "k" , 1);
    add_iter(d1 , "aclmo" , 5);
    add_iter(d1 , "xyz" , 3);

    puts("Copie Dico 1 :");
    print_prefix(d1);

    printf("nombre de noeuds : %d\n", nb_nodes(d));
    printf("hauteur : %d\n", height(d));
    printf("equal ? %d\n", equal(d , d1));



    puts("");
    puts("Fin de test_basique");

    return;
}
