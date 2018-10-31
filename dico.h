#ifndef DICO_H
#define DICO_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct node {
    char first;
    bool end_of_word;
    struct node ** children;
};

typedef struct node * tree;
typedef struct node ** dico;

#define NB_KEYS 26
unsigned get_index(char c);
char get_char(unsigned index);


dico create_dico();
void destroy_dico(dico * d);
void destroy_tree(tree * t);

unsigned int nb_children(tree t);
unsigned int nb_nodes(dico d);
unsigned int height(dico d);

void print_prefix(dico d);
void print_prefix_decale(dico d , unsigned int decalage);
bool equal(dico d1 , dico d2);

bool contains_iter(dico d , char * word , unsigned size);
bool add_iter(dico d , char * word , unsigned size);
bool remove_iter(dico d , char * word , unsigned size);

bool contains_rec(dico d , char * word , unsigned size);
bool add_rec(dico d , char * word , unsigned size);
bool remove_rec(dico d , char * word , unsigned size);


unsigned int nb_words(dico d);
void print_dico(dico d);
void print_dico_buff(dico d , unsigned int ind_buff , char * buffer);


#endif
