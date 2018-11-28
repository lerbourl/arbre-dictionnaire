#include <stdio.h>
#include <stdlib.h>
#include "dico.h"
#include "iterateur.h"
#include "lecteur.h"

int main(){
    dico d = create_dico();

    chargerMotsDansDico("./dictionnaire/pokemon2.txt" , d);
    iterator * dit = start_iterator(d);
    while (has_next(dit)) printf("-%s\n", next(dit));
    destroy_iterator(&dit);
    destroy_dico(&d);

    return 0;
}
