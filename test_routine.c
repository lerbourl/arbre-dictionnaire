#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "dico.h"


int main() {
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

    printf("\nNombre de mots dans l'arbre : %d\n\n",nb_words(d));

    print_dico(d);

    return 0;
}
