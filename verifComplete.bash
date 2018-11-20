#!/usr/bin/env bash


display=`ls ./dictionnaire/`
echo -e "Liste des dictionnaires disponibles : \n$display "

# read -p 'Entrez le nom du dictionnaire : ' nomDico
# read -p 'Entrez le nom du fichier de stockage : ' nomFichier

gcc *.c *.h -Wextra -Wall -g -o verif

nomDico=test.txt
nomFichier=dicoPur.txt

./verif ./dictionnaire/$nomDico $nomFichier


echo 'différence :'
diff $nomFichier res

rm $nomFichier
rm res
