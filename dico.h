#ifndef DICO_H
#define DICO_H

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

#endif
