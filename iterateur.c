#include "dico.h"
#include "iterateur.h"

iterator * start_iterator(dico d){
    if (d == NULL) {
        return NULL;
    }
    int i;
    iterator* dit = calloc(1, sizeof(iterator));
    dit->word = calloc(height(d), sizeof(char));
    dit->stack = calloc(nb_nodes(d), sizeof(struct iterator_info));
    dit->index_stack = 0;
    for (i = 0; i < NB_KEYS, i++){
        if (d[i] != NULL){ // il y a un arbre, on empile
            dit->stack[index_stack].t = d[i];
            dit->stack[index_stack].index_word = 0;
            index_stack++;
        }
    }
    return dit;
}

void destroy_iterator(iterator ** it){

}

bool has_next(iterator * it){
    return (it->index_stack);
}

char * next (iterator * it){
    return;
}
