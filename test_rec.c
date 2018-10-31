#include "test_rec.h"
#include "dico.h"

void test_rec() {

    puts("");
    puts("Début de test_rec");
    puts("");

    dico d = create_dico();



    add_rec(d , "xyz" , 3);
    add_rec(d , "abc" , 3);
    add_rec(d , "abcde" , 5);
    add_rec(d , "abcdefg" , 7);
    // add_rec(d , "adcde" , 5);


    print_prefix(d);

    puts("");
    puts("Retrait de abc");
    puts("");

    // remove_rec(d , "adcde" , 5);
    // print_prefix(d);
    // puts("");

    remove_rec(d , "abcdefg" , 7);
    remove_rec(d , "abcde" , 5);
    print_prefix(d);
    puts("");

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
    puts("Fin de test_iter");
    puts("");


    return;

}
