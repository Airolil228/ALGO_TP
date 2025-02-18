#!/usr/bin/env bash
# un parametre: le nom du fichier source .c
fich="$1"

if (( $# != 1 )); then
    echo "$# Il faut un parametre: le fichier source .c"
    exit 2
fi

# recherche des noms
nb=$(grep -c "^n>>" "$fich")
if (( nb != 1 )); then
    echo "Erreur : le fichier contient $nb lignes commençant par \"n>>\". Il doit y avoir exactement une ligne commençant par \"n>>\" et contenant les noms des étudiants du groupe."
    exit 5
fi

noms=$(grep "^n>>" "$fich" | cut -c4-)
echo "Noms des étudiants : $noms"

# nombre de questions
nb=$(grep -c "^nbq>>" "$fich")
if (( nb != 1 )); then
    echo "Erreur : le fichier contient $nb lignes commençant par \"nnq>>\". Il doit y avoir exactement une ligne commençant par \"nbq>>\" et contenant le nombre de questions."
    exit 5
fi
nbq=$(grep "^nbq>>" "$fich" | cut -c6- | tr -cd "[[:digit:]]" )
echo "Nombre de questions : $nbq"
if (( nbq > 100 )); then
    echo "Erreur: trop de questions."
    exit 6
fi

# réponses aux questions
for ((i=1; i<=nbq; i++)); do
    echo "Reponse question $i :"
    grep "^$i>>" "$fich"
done
