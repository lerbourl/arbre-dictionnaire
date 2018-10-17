#include "dico.h"

unsigned get_index(char c) {
    return c - 'a';
}


char get_char(unsigned index) {
    return index + 'a';
}


dico create_dico() {
    dico D = calloc(NB_KEYS , sizeof(*D));
    // sizeof(dico)

    for(unsigned k = 0 ; k < NB_KEYS ; k++) {
        D[k] = calloc(1 , sizeof(*D[k]));
        //sizeof(tree)
    }
}

void destroy_dico(dico * d) {
    for (unsigned int k = 0; k < NB_KEYS ; k++) {
        free(*d[k]);
    }
    free(*d);
}


int nb_children(dico * d , char c) {
    unsigned int res = 0 , ind = get_index(c);

    for (unsigned int k = 0; k < NB_KEYS ; k++) {
        if (*d[ind]->children[k]) {
            res++;
        }
    }
    return res;
}
