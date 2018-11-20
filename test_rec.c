#include "test_rec.h"
#include "dico.h"

void test_rec() {

    puts("");
    puts("Début de test_rec");
    puts("");

    dico d = create_dico();



    // add_rec(d , "chaussure" , 9);
    // add_rec(d , "chaussette" , 10);
    // add_rec(d , "chausserai" , 10);
    // add_rec(d , "chausse" , 7);
    add_rec(d , "ordinateur" , 10);
    // add_rec(d , "abcdjje" , 7);
    // add_rec(d , "abcdjjuiop" , 10);
    add_rec(d , "abcdjjazer" , 10);
    add_rec(d , "abcdjjxyz" , 9);

    // add_rec(d , "adcde" , 5);


    print_prefix(d);

    puts("");
    puts("Retrait de abcdefzxe");
    puts("");

    // remove_rec(d , "adcde" , 5);
    // print_prefix(d);
    // puts("");

    remove_rec(d , "ordinateur" , 10);
    print_prefix(d);
    puts("");

    return;

    remove_rec(d , "abc" , 3);
    print_prefix(d);
    puts("");

    remove_rec(d , "xyz" , 3);
    print_prefix(d);
    puts("");

    free(d);

    return;

    add_rec(d , "abc" , 3);
    add_rec(d , "abcde" , 5);
    add_rec(d , "abbde" , 5);
    add_rec(d , "abcdf" , 5);
    add_rec(d , "xyz" , 3);

    print_prefix(d);

    dico d1 = create_dico();

    add_iter(d1 , "abc" , 3);
    add_iter(d1 , "abcde" , 5);
    add_iter(d1 , "abbde" , 5);
    add_iter(d1 , "abcdf" , 5);
    add_iter(d1 , "xyz" , 3);

    printf("equals ? %d\n", equal(d , d1));
    destroy_dico(&d1);

    puts("");
    puts("Retrait de abc");
    puts("");

    remove_rec(d , "abc" , 3);
    puts("");

    print_prefix(d);
    destroy_dico(&d);

    puts("");
    puts("Fin de test_rec");
    puts("");


    return;

}
