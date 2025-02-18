#ifndef LISTES_H
#define LISTES_H

/****************************************************************************/
/*******************   fichier liste.h  *************************************/
/****************************************************************************/

/* Listes de type FIFO ou LIFO.
   Pour une liste LIFO (pile), utiliser empile et depile 
   Pour une liste FIFO (file d'attente), utiliser enfile et defile
    rmq : depile et defile font la même chose.
*/

/* Le type des listes est "Liste" *********************/
typedef struct liste Liste;

Liste *creer_liste_vide();
/* Crée un liste vide et renvoie un pointeur dessus.
   Il est indispensable de creer les listes avant de les utiliser (sinon ça plante).
*/

void detruit_liste(Liste *l);
/* Detruit la liste et libere la memoire utilisé par la liste */
/* Cette fonction doit être appelée à chaque fois qu'une liste 
   n'est plus utilisée */

int est_vide(Liste *l);
/* Renvoie vrai si la liste l est vide. Équivalent à : taille(l) == 0 */

void enfile(int sommet, Liste *l);
/* Ajoute le sommet à la fin de la liste l (FIFO) */
/* La liste l passé en paramètre est donc modifiée */

void empile(int sommet, Liste *l);
/* Ajoute le sommet au début de la liste l */
/* La liste l passé en paramètre est donc modifiée */

int defile(Liste *l);
/* Retire le premier sommet de la liste l et le renvoie */ 
/* La liste l passé en paramètre est donc modifiée */
/* Appeler defile sur une liste vide plante probablement */

int depile(Liste *l);
/* idem defile */

int taille(Liste *l);
/* Retourne le nombre d'éléments de la liste */

int element(Liste *l, int index);
/* Retourne l'élément de la liste à l'index indiqué (les indices commencent à 0
   et doivent être inférieurs strict à taille(l)). La liste n'est pas modifiée. */


/************************* entrée/sorties ***************************/

void affiche_liste(Liste *l);
  /* affiche la liste passée en paramètre */

#endif
