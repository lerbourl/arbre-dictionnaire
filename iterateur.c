#include "iterateur.h"

iterator * start_iterator(dico d){
    if (d == NULL) {
        return NULL;
    }
    iterator* dit = calloc(1, sizeof(iterator));
    dit->word = calloc(height(d), sizeof(char));
    dit->stack = calloc(nb_nodes(d), sizeof(struct iterator_info));
    dit->index_stack = -1;
    empile_fils(dit, d, 0);
    return dit;
}

void destroy_iterator(iterator ** it){
    if (*it == NULL) return;
    free((*it)->word);
    free((*it)->stack);
    free(*it);
    *it = NULL;
}

bool has_next(iterator * it){
    return (it->index_stack);
}

char * next (iterator * it){
    /* on est jamais trop prudents... */
    if (!has_next(it)){
        return "erreur ! next appelé mais pile vide !";
    }
    struct iterator_info inf;
    int i;
    do{
        /* on depile */
        inf = it->stack[it->index_stack];
        it->index_stack--;
        /* on met à jour word */
        it->word[inf.index_word] = inf.t->first;
        i = 1;
        while(it->word[inf.index_word + i] != 0){
            it->word[inf.index_word + i] = 0;
            i++;
        }
        /* on empile tous les fils de l'arbre */
        if (inf.t->children != NULL){
            empile_fils(it, inf.t->children, inf.index_word + 1);
        }
    }while(!(inf.t->end_of_word));
    return it->word;
}

void empile_fils(iterator* dit, dico d, int iw){
    int i;
    for (i = 0; i < NB_KEYS; i++){
        if (d[i] != NULL){ // il y a un arbre, on empile
            dit->stack[dit->index_stack + 1].t = d[i];
            dit->stack[dit->index_stack + 1].index_word = iw;
            dit->index_stack++;
        }
    }
}
