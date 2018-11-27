# include "test_generique.h"

void test_generique(char *nomDico , char *nomFichier) {

        dico d = create_dico();
        chargerMotsDansDico(nomDico , d);

        char *mot[] = {"ordinateur" , "chaussure"};

        remove_rec(d , mot[0] , strlen(mot[0]));
        remove_rec(d , mot[1] , strlen(mot[1]));

        chargeDicoDansFichier(d , "res");
        // print_dico(d);

        creerDicoSansAccent(nomDico , nomFichier);


        destroy_dico(&d);
        free(d);
        return;
}
