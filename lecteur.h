#ifndef _TEST_LECTEUR
#define _TEST_LECTEUR

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "dico.h"


int lireLigne(char *mot , int tailleMot , FILE *f);
void chargerMotsDansDico(char *nomDico , dico d);
void ChargeDicoDansFichier(dico d);
void creerDicoSansAccent(char *nomDico , char *nomFichier);

void ChargeDico_buff(dico d , unsigned int ind_buff , char * buffer , FILE *f);

#endif