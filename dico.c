#include "dico.h"

// sujet : http://chamilo.grenoble-inp.fr/courses/ENSIMAG4MMAPMA/document/2018/algo-man.html

unsigned get_index(char c) {
    int res = c - 'a';
    if (res < 0 || res > 26) {
        res = c - 'A';
    }
    assert(res >= 0 && res < 27);
    return (unsigned)res;
}


char get_char(unsigned index) {
    return index + 'a';
}

/* On alloue seulement D, les D[k] seront alloués au besoin par les fonctions add
ce qui permet d'économiser de la mémoire*/
dico create_dico() {
    dico D = calloc(NB_KEYS , sizeof(*D));
    // printf("taille *D : %d\n", (int)sizeof(*D));
    // printf("taille dico : %d\n", (int)sizeof(dico));

    // for(unsigned k = 0 ; k < NB_KEYS ; k++) {
    //     D[k] = calloc(1 , sizeof(*D[k]));
    // }
    // printf("taille *D[k] : %d\n", (int)sizeof(*D[0]));
    // printf("taille node : %d\n", (int)sizeof(struct node));
    // printf("taille char : %d\n", (int)sizeof(char));
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

    if (t == NULL) {
        return 0;
    }

    unsigned int res = 0;
    unsigned int k = 0;

    for (k = 0; k < NB_KEYS ; k++) {
        if (t->children[k]) {
            res++;
        }
    }
    return res;
}


unsigned int nb_nodes(dico d) {

    if (d == NULL) {
        return 0;
    }

    unsigned int somme = 0;

    for (unsigned int k = 0 ; k < NB_KEYS ; k++) {
    /* Si la feuille a un fils, on incrémente somme et on explore ce fils */
    if (d[k] != NULL) {
        /* Il faut incrémenter somme avant le test suivant sinon somme vaut 0
        quand on arrive sur une feuille */
            somme++;
            if (d[k]->children != NULL) {
                somme+= nb_nodes(d[k]->children);
            }
        }
    }
    return somme;
}


unsigned int height(dico d) {
    /* On descend jusqu'en bas de l'arbre puis la récursivité fait remonter
    la hauteur maximum à chaque étage */

   if (d == NULL) {
       return 0;
   }

   if (nb_nodes(d) == 0) return 0;


    unsigned int max = 1;
    unsigned int mem = 1;
    for (unsigned int k = 0 ; k < NB_KEYS ; k++) {
    /* Si la feuille a un fils, on explore ce fils */
        if (d[k] != NULL) {
            if (d[k]->children != NULL) {

                mem = height(d[k]->children) + 1;
                if (mem > max) {
                    max = mem;
                }
            }
        }
    }
    return max;
}



void print_prefix(dico d) {
    if (!print_prefix_decale(d , 0)) {
        printf("Le dictionnaire est vide\n");
        return;
    }
}


bool print_prefix_decale(dico d , unsigned int decalage) {

    bool affiche = false;
    if (d == NULL) return false;

    for (unsigned int k = 0 ; k < NB_KEYS ; k++) {
        if (d[k] != NULL) {
            affiche = true;
            if (d[k]->children != NULL || d[k]->end_of_word) {

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
    return affiche;
}


bool equal(dico d1 , dico d2) {

    bool res = true;

    for (unsigned int k = 0 ; k < NB_KEYS ; k++) {
    /* Si les deux fils ne sont pas nulles, on rentre dedans */
        if (d1[k] != NULL && d2[k] != NULL) {
            /* Vérif si les aractères sont identiques */
            if (d1[k]->first != d2[k]->first) {
                return false;
            }

            /* Vérif sur les fin de mot */
            if (d1[k]->end_of_word != d2[k]->end_of_word) {
                return false;
            }

            /* Si equal est faux, on s'arrête et on renvoie directement faux,
            pas possible de faire return equal(...) car renvoie le premier true
            qu'il voit et stop l'exploration de l'arbre */
            if (d1[k]->children != NULL && d2[k]->children != NULL) {
                if (!equal(d1[k]->children , d2[k]->children)) {
                    return false;
                }
            }
            /* Si seulement un des fils est nulle, alors les arbres sont différents */
            else if (d1[k]->children != NULL || d2[k]->children != NULL) {
                return false;
            }
        }
        else if (d1[k] != NULL || d2[k] != NULL) {
            return false;
        }

        // if (!res) {
        //     return false;
        // }

    }
    /* Traite le cas où la feuille n'a aucun fils, dans ce cas les sous abres sont égaux */
    if (res) {
        return true;
    }
    return false; //False pas utile je pense, du coup supprimer res
}


bool contains_iter(dico d , char * word , unsigned size) {

    unsigned int ind;
    dico p = d , p_mem = d;

    for (unsigned int k = 0 ; k < size ; k++) {
        ind = get_index(word[k]);

        if (p == NULL) {
            return false;
        }

        if (p[ind] == NULL) {
            return false;
        }

        if (tolower(p[ind]->first) != tolower(word[k])) {
            return false;
        }

        p_mem = p;
        p = p[ind]->children;
    }
    /* Traite les cas du type : on rentre uniquement le mot BASE et on cherche le mot BAS */
    if (!p_mem[get_index(word[size-1])]->end_of_word) {
        return false;
    }
    return true;
}

/* Dans toutes les fonctions d'ajout et de suppression on pourrait utiliser contains
et se passer de tous les tests dans ces fonctions qui vérifient que le mot est
bien présent mais cela implique de parcourir l'arbre 2 fois au lieu d'une seule fois */
bool add_iter(dico d , char * word , unsigned size) {

    if (d == NULL) return false;

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


bool contains_rec(dico d , char * word , unsigned size) {

    if (d == NULL) return false;

    /* On regarde toujours la première lettre du mot et dans la récursivité,
    on renvoie le mot à la lettre suivante */
    unsigned int ind = get_index(word[0]);

    /* Condition terminale : on arrive en fin de mot */
    if (size == 1) {
        if (d[ind] != NULL) {
            /* Il ne faut pas oublier de vérifier que c'est bien une fin de mot */
            if (!d[ind]->end_of_word) {
                return false;
            }

            if (tolower(d[ind]->first) == tolower(word[0])) {
                return true;
            }
        }
        return false;
    }
    /* On vérifie toujours que la case puis que children ont été alloué sinon
    c'est que le mot n'est pas présent */
    if (d[ind] != NULL) {
        if (d[ind]->children != NULL) {
            if (tolower(d[ind]->first) != tolower(word[0])) {
                return false;
            }
            return contains_rec(d[ind]->children , word + 1 , size - 1);
        }
    }
    return false;
}


bool add_rec(dico d , char * word , unsigned size) {

    if (d == NULL) return false;

    unsigned int ind = get_index(word[0]);

    if (size == 1) {
        if (d[ind] == NULL) {
            d[ind] = calloc(1 , sizeof(struct node));
        }

        if (!d[ind]->first) {
            d[ind]->first = word[0];
        }

        if (!d[ind]->end_of_word) {
            d[ind]->end_of_word = true;
            return true;
        }
        else return false;
    }


    if (d[ind] == NULL) {
        d[ind] = calloc(1 , sizeof(struct node));
    }

    if (d[ind]->children == NULL) {
        d[ind]->children = calloc(NB_KEYS , sizeof(dico));
    }

    if (!d[ind]->first) {
        d[ind]->first = word[0];
    }

    return add_rec(d[ind]->children , word + 1 , size - 1);
}


bool remove_rec(dico d , char * word , unsigned size) {

    if (d == NULL) return false;

    unsigned int ind = get_index(word[0]);

    if (size == 1) {
        if (d[ind] != NULL) {
            if (d[ind]->first == word[0]) {
                if (d[ind]->end_of_word) {
                    d[ind]->end_of_word = false;

                    if (d[ind]->children == NULL) {
                        destroy_tree(&d[ind]);
                        d[ind] = NULL;
                    }
                    /* De manière analogue à remove iter on supprime la liaison */
                    else {
                        bool set_null = true;
                        for (unsigned j = 0 ; j < NB_KEYS ; j++) {
                            if (d[ind]->children[j] != NULL) {
                                set_null = false;
                            }
                        }

                        if (set_null) {
                            destroy_tree(&d[ind]);
                            d[ind] = NULL;
                        }
                    }
                    return true;
                }
            }
        }
        return false;
    }

    /* Si l'un des 3 tests suivants est faux il faut retourner faux
     car cela signifie que le mot n'est pas présent */
    if (d[ind] != NULL) {
        if (d[ind]->first == word[0]) {
            if (d[ind]->children != NULL) {
                if (remove_rec(d[ind]->children , word + 1 , size - 1)) {
                    if (!d[ind]->end_of_word) {
                        bool seul_enfant = true;
                        for (unsigned int k = 0 ; k < NB_KEYS ; k++) {
                            if (d[ind]->children[k] != NULL /*&& k != ind*/) {
                                seul_enfant = false;
                            }
                        }

                        if (seul_enfant) {
                            destroy_tree(&d[ind]);

                            d[ind] = NULL;
                        }
                    }
                    return true;
                }
            }
        }
    }
    return false;
}



/* On explore l'arbre récursivement, si on trouve une fin de mot on incrémente
le nomre de mots et si on trouve un fils on l'explore en rajoutant le nombre de
mots trouvé lors de l'exploration à nb_word*/
unsigned int nb_words(dico d) {
    if (d == NULL) {
        return 0;
    }

    unsigned int nb_word = 0;

    for (unsigned int k = 0 ; k < NB_KEYS ; k++) {
        if (d[k] != NULL) {
            if (d[k]->end_of_word) {
                nb_word++;
            }
            if (d[k]->children != NULL) {
                nb_word+= nb_words(d[k]->children);
            }
        }
    }
    return nb_word;
}


void print_dico(dico d) {
    char buffer[64];
    if (!print_dico_buff(d , 0 , buffer , false)) {
        printf("Le dictionnaire est vide\n");
    }
}

bool print_dico_buff(dico d , unsigned int ind_buff , char * buffer , bool affiche) {

    if (d == NULL) return affiche;

    for (unsigned int k = 0 ; k < NB_KEYS ; k++) {

        if (d[k] != NULL) {
            buffer[ind_buff] = d[k]->first;
            ind_buff++;
            affiche = true;
            if (d[k]->end_of_word) {
                for (unsigned int j = 0 ; j < ind_buff ; j++) {
                    printf("%c", buffer[j]);
                }
                puts("");
            }
            if (d[k]->children != NULL) {
                print_dico_buff(d[k]->children , ind_buff , buffer , true);
            }
            ind_buff--;
        }
    }
    return affiche;
}
