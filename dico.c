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


unsigned int nb_children(tree t) {
    unsigned int res = 0;

    for (unsigned int k = 0; k < NB_KEYS ; k++) {
    }
    if (t->children[k]) {
        res++;
    }
    return res;
}


unsigned int nb_nodes(dico d) {
    unsigned int somme = 0;
    for (unsigned int k = 0 ; k < NB_KEYS ; k++) {
    /* Si la feuille a un fils, on incrémente somme et on explore ce fils */
        if (d[k] != NULL) {
            somme++;
            somme+= nb_nodes_tree(&d[k]);
        }
    }

    /* Condition terminale : la feuille n'a pas de fils */

    // if (somme == 0) {
    //     return 0;
    // } Inutile car somme reste à 0 si pas de fils

    return somme;
}


unsigned int height(dico d) {
/* On descend jusqu'en de l'arbre puis la récursivité fait remonter
   la hauteur maximum à chaque étage */
    unsigned int max = 0;
    unsigned int mem = 0;
    for (unsigned int k = 0 ; k < NB_KEYS ; k++) {
    /* Si la feuille a un fils, on explore ce fils */
        if (d[k] != NULL) {

            mem = nb_nodes_tree(&d[k]) + 1;
            if (mem > max) {
                max = mem;
            }
        }
    }
    return max;
}
