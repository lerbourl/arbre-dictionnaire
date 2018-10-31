#include "test_5-6.h"


void test_5_6() {
    puts("");
    puts("Début de test_5_6");
    puts("");

    dico d = create_dico();



    add_rec(d , "ours" , 4);
    add_rec(d , "ourson" , 6);
    add_rec(d , "oursonne" , 8);
    add_rec(d , "brule" , 5);
    add_rec(d , "brille" , 6);
    add_rec(d , "bord" , 4);
    add_rec(d , "bordeau" , 7);
    add_rec(d , "bateau" , 6);


    print_prefix(d);


    puts("");
    printf("nombre de mots dans l'arbre : %d\n",nb_words(d));
    puts("");

    print_dico(d);


    puts("");
    puts("Fin de test_5_6");
    puts("");

}
