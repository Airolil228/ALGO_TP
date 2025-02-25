/* Il y a parfois des questions dans l'énoncé du TP. Vous devez
   indiquer vos réponses en complétant Les lignes commençant par "X>>"
   (X étant un nombre ou une lettre pour identifier la question).

   Les groupes de TP sont de 2 personnes au maximum, redoublants
   seuls.  Indiquez les membres du groupe de TP sur la ligne suivante
   (commençant par "n>>", sur une seule ligne).
n>>

Avant de déposer ce fichier sur claroline, répondez aux questions suivantes
sur votre avancement (remplacez par "oui" si vous avez fini une étape)

Votre programme affiche correctement la matrice d'adjacence (vous l'avez testé sur plusieurs
graphes exemples et vous avez comparé avec les logs fournis) :
1>> oui

Votre programme calcule et affiche correctement les degrés entrants et sortants (vous l'avez testé) :
2>> oui 

Votre programme calcule et affiche correctement les sommets sources, puits et isolés (vous l'avez testé) :
3>> oui

Votre programme affiche correctement si le graphe est un trou noir et la liste des sommets courants (vous l'avez testé) :
4>> oui

Finalement, vous avez testé votre programme avec tous les graphes en utilisant le script test.sh comme indiqué dans la question 10 du sujet.
5>> non

Vérifiez la saisie de vos réponses en lançant le script :
./test_rendu.sh graphe_oriente.c

Ne pas modifier cette ligne (nombre de questions):
nbq>>5
*/
#include <stdio.h>
#include <stdlib.h>

#define NMAX 100           /* nombre maximum de sommets */
int MAD[NMAX+1][NMAX+1];  /* la matrice d'adjacence du graphe */
int n;                    /* le nombre de sommets */

void lire_graphe() {
  int i,j,o,e,m;

  scanf("%d",&n); /* nb de sommets */
  if (n > NMAX) {
    fprintf(stderr, "PB : Le nombre de sommets %d est plus grand que NMAX = %d\n", n, NMAX);
    exit(1);
  }
  scanf("%d",&m); /* nb d'arcs */

  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      MAD[i][j] = 0;

  for (i = 1; i <= m; i++) {
    /* lecture de l'arc (o,e) */
    scanf("%d", &o);
    scanf("%d", &e);
    if ((o < 1) || (e < 1) || (o > n) || (e > n)) {
      fprintf(stderr, "arc (%d,%d) non valide\n",o ,e);
      exit(1);
    }
    MAD[o][e] = 1;
  }
}

void afficheMADJ() {
  int i,j,k;

  printf("Matrice d'adjacence : \n");

  printf("   ");
  for(k = 1; k <= n; k++)
    printf(" %d",k);

  printf("\n");

  for(i = 1; i <= n; i++){
    printf(" %d:",i);
    for(j = 1; j <= n; j++){
      if(MAD[i][j] == 1)
        printf(" X");
      else
        printf(" .");
    }
    printf("\n");
  }
}

void afficher2(int *tab,int totale){
  int i;
  if(totale == 0){
    return ; 
  }
  else {
    for(i = 1; i < totale; i++)
    printf("%d ",tab[i]);
    printf("\n");
  }
}

void afficher1(int *dplus, int *dmoins){
  int i;
  for(i = 1; i <= n; i++){
    printf(" %d ",dplus[i]);
  }
  printf(" :degrés entrants \n");

  for(i = 1; i <= n; i++){
    printf(" %d ",dmoins[i]);
  }
  printf(" :degrés sortans");


}

void degres(int *dplus,int *dmoins){
  int i,j;
  for(i = 1; i <= n; i++){
    dplus[i]=0;
    dmoins[i]=0;
    for(j = 1;j <= n; j++){
      if( MAD[i][j] == 1)
        dmoins[i] += 1;
       if( MAD[j][i] == 1)
        dplus[i] += 1;
    }
  }
  afficher1(dplus,dmoins);
}


void sommet(int *dplus,int *dmoins){
  int i;
  int isole[n],puits[n],source[n];
  int ci,cp,cs;
  ci = 1;
  cp = 1;
  cs = 1; 
 
  for(i = 1; i <= n; i++){
    if(dplus[i] == 0 && dmoins[i]==0){
      isole[ci] = i;
      ci++;
      
      puits[cp] = i;
      cp++;

      source[cs] = i;
      cs++; 
    }
    if( (dplus[i] != 0 && dmoins[i]==0)){
      puits[cp] = i;
      cp++; 
    }
    if(dplus[i] == 0 && dmoins[i] !=0){
      source[cs] = i;
      cs++; 
    }
  }
  printf("\nSommets isole: ");
  afficher2(isole,ci);
  printf("Sommets puits: ");
  afficher2(puits,cp);
  printf("Sommets source: ");
  afficher2(source,cs); 
  
}

void trou_noir(){
  int TabCourant[n];
  int j,i,k,compt;
  
  i = 1;
  j = 2;
  compt = 1;

  int courant;
  int i1 = 1;
  int j1 = 1; 
  
  TabCourant[compt] = compt;
  compt++;

  
  while( j != n ){ 
     if(MAD[i][j] == 1){
	TabCourant[compt] = j; 
	compt++;
	i = j;  
      }	
    j++; 
  }
  
  
  printf("\nSuite des sommets courants: "); 
  for(k = 1; k < compt; k++){
    printf("%d ", TabCourant[k]); 
  }

  courant=TabCourant[compt-1];
  
  /*Verification d'un trou noir*/
  while( i1 != n){
    if( (MAD[i1][courant] == 0 && i1 != courant) ||  (MAD[i1][courant] == 1 && i1 == courant) ){
      printf("\nIl n'y a pas de trou noir dans le graphe ");
      return ;
    }else if( MAD[i1][courant] == 0 && i1 == courant){
      while(j1 != n){
	if(MAD[courant][j1] == 1){
	  printf("\nIl n'y a pas de trou noir dans le graphe ");
	  return ; 
	}else{
	  j1++;
	}
      }
    }
    i1++;
  }

  printf("\nLe sommet %d est un trou noir \n",courant);
    
}



int main() {
  int dplus[NMAX+1], dmoins[NMAX+1];

  lire_graphe();
  afficheMADJ();
  degres(dplus,dmoins);
  sommet(dplus,dmoins);
  trou_noir(); 
  
  return 0;
}
