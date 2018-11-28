#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "dico.h"


int main() {

    dico d = create_dico();

    add_rec(d , "abc" , 3);
    add_rec(d , "abcde" , 5);
    add_rec(d , "abcdf" , 5);
    add_rec(d , "xyz" , 3);

    print_prefix(d);

    printf("\ncontient rec  abc? %d\n", contains_rec(d , "abc" , 3));
    printf("contient rec  abcd? %d\n", contains_rec(d , "abcd" , 4));
    printf("contient rec  abcdeg? %d\n", contains_rec(d , "abcdeg" , 6));
    printf("contient rec  kahg? %d\n", contains_rec(d , "kahg" , 4));


    puts("");
    puts("retrait abcde");
    remove_rec(d , "abcde" , 5);
    print_prefix(d);


    puts("");
    puts("retrait abc");
    remove_rec(d , "abc" , 3);
    print_prefix(d);

    puts("");
    puts("retrait xyz");
    remove_rec(d , "xyz" , 3);
    print_prefix(d);

    puts("");
    puts("retrait abcdf");
    remove_rec(d , "abcdf" , 5);
    print_prefix(d);


    return 0;

}
