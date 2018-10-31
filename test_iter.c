#include "test_iter.h"


void test_iter() {

    puts("");
    puts("");
    puts("Début de test_iter");
    puts("");

    dico d = create_dico();

    add_iter(d , "abc" , 3);
    add_iter(d , "abcde" , 5);
    add_iter(d , "abbde" , 5);
    add_iter(d , "abcdf" , 5);
    add_iter(d , "xyz" , 3);


    printf("contient iter  abc? %d\n", contains_iter(d , "abc" , 3));
    printf("contient iter  abcd? %d\n", contains_iter(d , "abcd" , 4));
    printf("contient iter  abcdeg? %d\n", contains_iter(d , "abcdeg" , 6));
    printf("contient iter  kahg? %d\n", contains_iter(d , "kahg" , 4));

    print_prefix(d);

    puts("");
    puts("retrait abcde");
    remove_iter(d , "abcde" , 5);
    print_prefix(d);


    puts("");
    puts("retrait abc");
    remove_iter(d , "abc" , 3);
    print_prefix(d);

    puts("");
    puts("retrait xyz");
    remove_iter(d , "xyz" , 3);
    print_prefix(d);

    puts("");
    puts("retrait abcdf");
    remove_iter(d , "abcdf" , 5);
    print_prefix(d);

    puts("");
    puts("out");
    puts("");

    print_prefix(d);

    puts("");
    puts("On recommence pour tester destroy_dico");

    add_iter(d , "abc" , 3);
    add_iter(d , "abcde" , 5);
    add_iter(d , "abcdf" , 5);
    add_iter(d , "xyz" , 3);

    print_prefix(d);
    destroy_dico(&d);
    print_prefix(d);

    puts("");
    puts("Fin de test_iter");

    return;
}
