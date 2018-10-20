#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "dico.h"

int main()
{
    int a , b;

    dico d = create_dico();

    add_iter(d , "aaaa" , 4);
    add_iter(d , "test" , 4);
    add_iter(d , "tata" , 4);
    add_iter(d , "tete" , 4);
    add_iter(d , "testeur" , 7);
    a = add_iter(d , "tester" , 6);
    b = add_iter(d , "test" , 4);

    printf("a : %d\n", a);
    printf("b : %d\n", b);

    print_prefix(d);


    return 0;
}
