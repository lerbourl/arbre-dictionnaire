#ifndef ITERATEUR_H
#define ITERATEUR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "dico.h"

struct iterator_info {
    tree t;
    int index_word;
};

struct _iterator {
    char * word;
    struct iterator_info * stack;
    int index_stack;
};

typedef struct _iterator iterator;

iterator * start_iterator(dico d);
void destroy_iterator(iterator ** it);
bool has_next(iterator * it);
char * next (iterator * it);

#endif
