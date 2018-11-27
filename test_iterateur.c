#include <stdio.h>
#include <stdlib.h>
#include "dico.h"
#include "iterateur.h"
#include "lecteur.h"

int main(){
    dico d = create_dico();
    chargerMotsDansDico("./dictionnaire/pokemon1.txt" , d);
    print_dico(d);
    iterator * dit = start_iterator(d);
    //while (has_next(dit)) printf("-%s", next(dit));
    destroy_iterator(&dit);
    return 0;
}
