/* Il y a parfois des questions dans l'énoncé du TP. Vous devez
   indiquer vos réponses en complétant Les lignes commençant par "X>>"
   (X étant un nombre ou une lettre pour identifier la question).

   Les groupes de TP sont de 2 personnes au maximum, redoublants
   seuls.  Indiquez les membres du groupe de TP sur la ligne suivante
   (commençant par "n>>", sur une seule ligne).
n>>

Avant de déposer ce fichier sur claroline, répondez aux questions suivantes
sur votre avancement (remplacez par "oui" si vous avez fini une étape)

Les fonctions lire_graphe_tla et affiche_tla sont finies et testées (en comparant avec le contenu du fichier log):
1>> non

Dans la fonction tri-topologique:
les initialisations sont faites et fonctionnent:
2>> non
La boucle principale qui affiche le sommet choisi et met à jour la liste des sources fonctionne:
3>> non
Le tableau rang[] est correctement rempli par l'algorithme
4>> non
La fonction main affiche correctement les sommets dans l'ordre du tri topologique à partir du tableau rang:
5>> non

Pourquoi y a-t-il necessairement un circuit dans le graphe si la liste
des sommets sources est vide avant que tous les sommets ne soient
explorés ?
6>>
6>>
(si votre réponse nécessite plus de 2 lignes, vous pouvez en rajouter
en les faisant commencer par "6>>").

Vérifiez la saisie de vos réponses en lançant le script :
./test_rendu.sh tri-topo.c

Ne pas modifier cette ligne (nombre de questions):
nbq>>6
*/
#include <stdio.h>
#include <stdlib.h>

#include "include/liste.h"

#define NMAX 100  /* nombre maximum de sommets */

Liste *TLA[NMAX+1]; /* tableau des listes d'adjacence */
/* TLA[i] est la liste des successeurs du sommet i. Comme les sommets sont
   numérotés à partir de 1, vous ne devez pas utiliser TLA[0] */
int n; /* le nombre de sommets */


void lire_graphe_tla() {
  /* à écrire, inspirez-vous de la fonction lire_graphe du tp1. Le format d'entrée est le même que dans le tp 1. */

}

void affiche_tla() {
  /* Affiche la liste des successeurs de chaque sommet (cf le fichier log
     pour des exemples) */
  /* À completer, utilisez la fonction affiche_liste() de include/liste.h */

}


int tritopologique(int rang[]) {
  /* Cette fonction effectue un tri topologique. Elle remplit le tableau
     rang[] passée en paramètre.  Elle retourne vrai si le tri topologique
     est possible et faux sinon. */
  /* Vous aurez besoin de declarer une liste des sommets sources l_sources,
     et un tableau dmoins pour les degrés entrants */
  /* Première étape : calcul des degrés entrants en parcourant les
     listes d'adjacences du tableau TLA */

  /* 2e étape : les sommets de degré entrant nul sont mis dans la liste 
     l_sources */

  /* Traitement de la liste l_sources et mise à jour de dmoins */

  /* La fonction retourne vrai si le tri est fait, et faux s'il y a
     un circuit */

  return 0; // à modifier 
}

void test_listes() {
  /* Exemple d'utilisation des fonctions sur les listes (cf include/liste.h) */
  Liste *l;

  l = creer_liste_vide();
  empile(5, l);
  empile(4, l);
  affiche_liste(l);
  printf("\n");

  empile(3, l);
  enfile(6, l);
  affiche_liste(l);
  printf("\n");

  printf("Sommet à l'indice 3 dans la liste : %d\n", element(l, 3));
  
  int s = depile(l);
  printf("sommet dépilé: %d\n",s);
  affiche_liste(l);
  printf("\n");
}


int main() {

  /* Pour tester les fonctions sur les listes. À commenter ensuite. */
  test_listes();

  /* Pour lire le graphe et l'afficher : */
  lire_graphe_tla();
  affiche_tla();
  /* à completer une fois que vous avez écrit le tri topologique */


  return 0;
}

