#include "dico.h"

// http://chamilo.grenoble-inp.fr/courses/ENSIMAG4MMAPMA/document/2018/algo-man.html

unsigned get_index(char c) {
    int res = c - 'a';
    assert(res >= 0 && res < 27);
    return (unsigned)res;
}


char get_char(unsigned index) {
    return index + 'a';
}


dico create_dico() {
    dico D = calloc(NB_KEYS , sizeof(*D));
    // printf("taille *D : %d\n", (int)sizeof(*D));
    // printf("taille dico : %d\n", (int)sizeof(dico));

    // for(unsigned k = 0 ; k < NB_KEYS ; k++) {
    //     D[k] = calloc(1 , sizeof(*D[k]));
    // }
    // printf("taille *D[k] : %d\n", (int)sizeof(*D[0]));
    // printf("taille node : %d\n", (int)sizeof(struct node));
    return D;
}

void destroy_dico(dico * d) {

    if (*d == NULL) return;

    for (unsigned int k = 0; k < NB_KEYS ; k++) {
        if ((*d)[k] != NULL) {

            if ((*d)[k]->children != NULL) {

                destroy_dico(&(*d)[k]->children);
                (*d)[k]->children = NULL;
                // free((*d)[k]->children);
            }
            free((*d)[k]);
            (*d)[k] = NULL;
        }
    }
    free(*d);
    *d = NULL;
}


void destroy_tree(tree * t) {
    if (*t == NULL) return;

    if ((*t)->children != NULL) {
        destroy_dico(&(*t)->children);
    }
    free(*t);
    *t = NULL;
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

    if (d == NULL) return;

    for (unsigned int k = 0 ; k < NB_KEYS ; k++) {
        // if (d[k] == NULL) {puts("cara");return;}
        // printf("k : %d\n", k);
        // printf("d : %p\n", d[k]);
        if (d[k] != NULL) {
            // printf("cara : %c\n", d[k]->first);
            if (d[k]->children != NULL || d[k]->end_of_word/*|| (d[k]->first >= 'a' && get_index(d[k]->first) <= 'z')*/) {

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

        if (p[ind] == NULL) {
            p[ind] = calloc(1 , sizeof(struct node));
        }

        if (p[ind]->children == NULL && k != size - 1) {
            p[ind]->children = calloc(NB_KEYS , sizeof(dico));
        }

        if (!p[ind]->first) {
            p[ind]->first = word[k];
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

// bool add_iter(dico d , char * word , unsigned size) {
//
//     unsigned int ind = 0;
//     dico p = d;
//
//     for (unsigned int k = 0 ; k < size ; k++) {
//         ind = get_index(word[k]);
//
//         if (!p[ind]->first) {
//             p[ind]->first = word[k];
//         }
//
//         if (p[ind]->children == NULL) {
//             puts("voilà");
//             p[ind]->children = create_dico();
//         }
//
//         if (k != size - 1) {
//             p = p[ind]->children;
//         }
//     }
//
//     if (p[ind]->end_of_word) {
//         return false;
//     }
//     p[ind]->end_of_word = true;
//     return true;
// }


bool remove_iter(dico d , char * word , unsigned size) {

    unsigned int ind = 0 , mem_k = 0;
    dico p = d , p_mem1 = d;
    tree t_mem = NULL;

/* Exploration de l'arbre pour vérifier si les lettres appartiennent
à un mot autre que celui qu'on veut supprimer,
si c'est le cas on stocke le pointeur où il y a bifurcation*/
    for (unsigned int k = 0 ; k < size ; k++) {
        ind = get_index(word[k]);


    /* Le mot n'est pas présent */
        if (p == NULL || p[ind] == NULL) {
            return false;
        }

    /* Rencontre d'une fin de mot avant la fin de notre mot
    => il ne faut pas supprimer ce qui est avant */
        if (p[ind]->end_of_word && k != size - 1) {
            p_mem1 = p[ind]->children;
            mem_k = k + 1;
            t_mem = p[ind];
        }
        else {

        /* Renconre d'une bifurcation dans le mot
        => il ne faut pas supprimer ce qui est avant */
            if (k != size - 1) {
                unsigned int ind_suiv = get_index(word[k+1]);
                for (unsigned int j = 0 ; j < NB_KEYS ; j++) {
                    if (p[ind]->children[j] != NULL && j != ind_suiv) {
                        p_mem1 = p[ind]->children;
                        mem_k = k + 1;
                        t_mem = p[ind];
                    }
                }
            }

            /* Si le mot fait parti d'un autre mot mais n'est pas déjà
            enregistré comme présent dans le dico */
            else {
                if (!p[ind]->end_of_word) {
                    return false;  // Cas sans doute inutile à moins d'une erreur */
                }

            /* Si le mot compose un autre mot pas besoin de supprimer les lettres */
                p[ind]->end_of_word = false;

                if (p[ind]->children != NULL) {
                    return true;
                }
            }
        }
        p = p[ind]->children;
    }

/* On repart du dernier marqueur de fin de mot ou  de la dernière bifurcation
rencontré et on supprime */

    ind = get_index(word[mem_k]);
    destroy_tree(&p_mem1[ind]);

/* Supprime le lien entre la partie de l'arbre qu'on vient d'effacer
et le reste de l'arbre */

    if (t_mem != NULL) {
        if (t_mem->children != NULL) {
            bool set_null = true;
            for (unsigned j = 0 ; j < NB_KEYS ; j++) {
                if (t_mem->children[j] != NULL) {
                    set_null = false;
                }
            }

            if (set_null) {
                free(t_mem->children);
                t_mem->children = NULL;
            }
        }
    }

    return true;
}
