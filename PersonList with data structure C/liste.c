#include <stdlib.h>
#include <stdio.h>
#include "liste.h"

//Afficher l'élément qui est un nbre entier
char* afficher(Objet* objet) {
    int* entier = (int*) objet;
    char* output = (char*) malloc(20 * sizeof(char));  // Assuming a reasonable size for the output buffer
    snprintf(output, 20, "%d \n", *entier);  // Use a safe buffer size
    return output;
}

//Faire la comparaison entre deux nbre entiers
int comparer(Objet* objet1, Objet* objet2) {

    int * a = (int*) objet1;
    int * b = (int*) objet2;
    if (a > b)
    {
      return 1;
    }
    else if (a == b)
    {
      return 0;
    }
    else
    {
      return -1;
    }
}

//Initialisation d'une liste
void initListe (Liste* li, int type, char* (*afficher) (Objet*), int (*comparer) (Objet*, Objet*)) {
li->premier = NULL;
li->dernier = NULL;
li->courant = NULL;
li->nbElt= 0;
li->type= type;
li->afficher = afficher;
 li->comparer = comparer;
}

//Creation d'une liste
Liste* creerListe (int type, char* (*afficher) (Objet*), int (*comparer) (Objet*, Objet*)){
	Liste* li=(Liste*) malloc(sizeof(Liste));
	initListe (li,type,afficher,comparer);
	return li;
}

//liste vide = pas d'elements
booleen listeVide (Liste* li) {
 return li->nbElt == 0;
}

//Fonction statique pour creer un tableau contenant l'element
static Element* creerElement(){
	return (Element*) malloc(sizeof(Element));
}

//Insertion en tete de liste
void insererEnTeteDeListe (Liste* li, Objet* objet) {
Element* nouveau = creerElement();
nouveau->reference = objet;
nouveau->suivant = li->premier ;
li->premier = nouveau;
if (li->dernier == NULL) li->dernier = nouveau;
li->nbElt++;
}

//Insertion en fin de liste
//D'abord on utilisera la fonction statique qui insere apres le precedent
static void  insererapre(Liste* li,Element* precedent ,Objet* objet)
{
	if(precedent==NULL)
		insererEnTeteDeListe (li,objet);
	else
	{
		Element* nouveau=creerElement();
		nouveau->reference=objet;
		nouveau->suivant=precedent->suivant;
		precedent->suivant=nouveau;
		if (precedent== li->dernier){
			li->dernier=nouveau;
			li->nbElt++;
					}}	}
//On va inserer apres l'element dernier dans la liste
void insererenfindeliste(Liste* li,Objet* objet ){
	insererapre(li,li->dernier,objet);

}

// Parcours
void ouvrirListe (Liste* li) {
 li->courant = li->premier;
}
booleen finListe (Liste* li) {
 return li->courant==NULL;
}
static Element* elementCourant (Liste* li) {
 Element* ptc = li->courant;
 if (li->courant != NULL) {
 li->courant = li->courant->suivant;
 }
 return ptc;
}
Objet* objetCourant (Liste* li) {
 Element* ptc = elementCourant (li);
 return ptc==NULL ? NULL : ptc->reference;
}
void listerListe (Liste* li) {
	if(listeVide(li)) printf("la liste est vide \n");
	else{
 ouvrirListe (li);
 while (!finListe (li)) {
 Objet* objet = objetCourant (li);
 printf("%s\n", li->afficher (objet));
 }	}
}
Objet* chercherUnObjet (Liste* li, Objet* objetCherche) {
 booleen trouve = faux;
 Objet* objet= NULL;
 ouvrirListe (li);
 while (!finListe (li) && !trouve) {
 objet = objetCourant (li);
 trouve = li->comparer (objetCherche, objet) == 0;
 }
 return trouve ? objet : NULL;
}

//Extraction en tete
Objet* extraireEnTeteDeListe (Liste* li) {
 Element* extrait = li->premier;
 if (!listeVide(li)) {
 li->premier = li->premier->suivant;
 if (li->premier==NULL) li->dernier=NULL;
 li->nbElt--;
 }
 return extrait != NULL ? extrait->reference : NULL;
}

//Extraction en fin de liste
//D'abord, on utilise la fonction qui extrait apres le precedent
static Objet* extraireApres (Liste* li, Element* precedent) {
 if (precedent == NULL) {
 return extraireEnTeteDeListe (li);
 } else {
 Element* extrait = precedent->suivant;
 if (extrait != NULL) {
 precedent->suivant = extrait->suivant;
 if (extrait == li->dernier) li->dernier = precedent;
 li->nbElt--;
 }}}
Objet* extraireEnFinDeListe (Liste* li) {
 Objet* extrait;
 if (listeVide(li)) {
 extrait = NULL;
 } else if (li->premier == li->dernier) { // un seul element
 extrait = extraireEnTeteDeListe (li);
 } else {
 Element* ptc = li->premier;
 while (ptc->suivant != li->dernier) ptc = ptc->suivant;
 extrait = extraireApres (li, ptc);
 }
 return extrait;
}

//Extraction total de l'objet
booleen extraireUnObjet (Liste* li, Objet* objet) {
 Element* precedent = NULL;
 Element* ptc = NULL;
 // repere l'element pr�c�dent
 booleen trouve = faux;
 ouvrirListe (li);
 while (!finListe (li) && !trouve) {
 precedent = ptc;
 ptc = elementCourant (li);
 trouve = (ptc->reference == objet) ? vrai : faux;
 }
 if (!trouve) return faux;
 Objet* extrait = extraireApres (li, precedent);
 return vrai;
}

//Destruction
void detruireListe (Liste* li) {
 ouvrirListe (li);
 while (!finListe (li)) {
 Element* ptc = elementCourant (li);
 free(ptc);
 }
  initListe(li, 0,NULL,NULL);
}
