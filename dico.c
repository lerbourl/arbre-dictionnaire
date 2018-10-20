#include "dico.h"

// http://chamilo.grenoble-inp.fr/courses/ENSIMAG4MMAPMA/document/2018/algo-man.html

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
    return D;
}

void destroy_dico(dico * d) {
    for (unsigned int k = 0; k < NB_KEYS ; k++) {
        free(*d[k]);
    }
    free(*d);
}


unsigned int nb_children(tree t) {
    unsigned int res = 0;
    unsigned int k = 0;

    for (k = 0; k < NB_KEYS ; k++) {
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
        if (d[k]->children != NULL) {
            somme++;
            somme+= nb_nodes(d[k]->children);
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
        if (d[k]->children != NULL) {

            mem = height(d[k]->children) + 1;
            if (mem > max) {
                max = mem;
            }
        }
    }
    return max;
}



void print_prefix(dico d) {
    print_prefix_decale(d , 0);
}

void print_prefix_decale(dico d , unsigned int decalage) {

    for (unsigned int k = 0 ; k < NB_KEYS ; k++) {
        if (d[k]->children != NULL) {
            for (unsigned p = 0 ; p < decalage ; p++) {
                printf("+ ");
            }
            printf("[%c]%c", d[k]->first , d[k]->first);
            if (d[k]->end_of_word) {
                printf("*");
            }
            printf("\n");
            print_prefix_decale(d[k]->children , decalage + 1);
        }
    }
}

bool equal(dico d1 , dico d2) {

    for (unsigned int k = 0 ; k < NB_KEYS ; k++) {
    /* Si les deux fils ne sont pas nulles, on rentre dedans */
        if (d1[k]->children != NULL && d2[k]->children != NULL) {
            if (d1[k]->first != d2[k]->first) {
                return false;
            }
            if (equal(d1[k]->children , d2[k]->children)) {
                return true;
            }
            return false;
        }
    /* Si seulement un des fils est nulle, alors les arbres sont différents */
        else if (d1[k]->children != NULL || d2[k]->children != NULL) {
            return false;
        }
    }
/* Traite le cas où la feuille n'a aucun fils, dans ce cas les sous abres sont égaux */
    return true;
}



bool contains_iter(dico d , char * word , unsigned size) {

    unsigned int ind;
    dico p = d;
    for (unsigned int k = 0 ; k < size ; k++) {
        ind = get_index(word[k]);

        if (p[ind]->children == NULL) {
            return false;
        }

        if (p[ind]->first != word[k]) {
            return false;
        }

        p = p[ind]->children;
    }
/* Traite les cas du type : on rentre uniquement le mot BASE et on cherche le mot BAS */
    if (!d[size-1]->end_of_word) {
        return false;
    }
    return true;
}


bool add_iter(dico d , char * word , unsigned size) {

    unsigned int ind = 0;
    dico p = d;

    for (unsigned int k = 0 ; k < size ; k++) {
        ind = get_index(word[k]);

        if (!p[ind]->first) {
            p[ind]->first = word[k];
        }

        if (p[ind]->children == NULL) {
            p[ind]->children = create_dico();
        }

        if (k != size - 1) {
            p = p[ind]->children;
        }
    }

    if (p[ind]->end_of_word) {
        return false;
    }
    p[ind]->end_of_word = true;
    return true;
}

bool remove_iter(dico d , char * word , unsigned size) {
    return true;

}
