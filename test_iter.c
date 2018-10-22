#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "dico.h"

int main()
{
    dico d = create_dico();

    add_iter(d , "abc" , 3);
    add_iter(d , "abcde" , 5);
    add_iter(d , "abcdf" , 5);
    add_iter(d , "xyz" , 3);

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

    free(d);

    return 0;
}
