#include <stdlib.h>
#include <stdio.h>
#include "liste.h"
#include "personne.h"

int menu () {
 printf ("\n\n*************GESTION D'UNE LISTE DE PERSONNES**********************\n\n");
 printf ("0 - Fin\n");
 printf ("1 - Insertion en tete de liste\n");
 printf ("2 - Insertion en fin de liste\n");
 printf ("3 - Retrait en tete de liste\n");
 printf ("4 - Retrait en fin de liste\n");
 printf ("5 - Retrait d'un element a partir de son nom\n");
 printf ("6 - Parcours de la liste\n");
 printf ("7 - Recherche d'un element a partir de son nom\n");
 printf ("8 - Destruction de la liste\n");
 printf ("\n");
 printf ("Votre choix ? ");
 int cod; scanf ("%d", &cod);
 printf ("\n");
 return cod;
}

int main(){
	Liste* li =creerListe (0, ecrirepersonne, comparerpersonne);
	int cod;
		do{
   cod = menu();
	switch (cod){
		case 1:{
			printf("donner le nom de personne : ");
			ch15 nom;
			scanf("%s",nom);
			printf("donner le prenom de personne : ");
			ch15 prenom;
			scanf("%s",prenom);
			personne* nv=creerpersonne(nom,prenom);
			insererEnTeteDeListe   (li, nv);
			printf("la personne est inserer en tete de la liste");
			}break;
		case 2:{
				printf("donner le nom de personne : ");
			ch15 nom;
			scanf("%s",nom);
			printf("donner le prenom de personne : ");
			ch15 prenom;
			scanf("%s",prenom);
			personne* nv=creerpersonne(nom,prenom);
			insererenfindeliste   (li, nv);
			printf("la personne est inserer en fin de la liste");
			}break;
		case 3:{
			extraireEnTeteDeListe (li);
			printf("C'est fait avec succes");}
			break;
		case 4:{
			extraireEnFinDeListe(li);
			printf("C'est fait avec succes");}
			break;
		case 5:{
			printf("\t>>donner le nom et le prenom a extraire : ");
			ch15 nom; scanf ("%s", nom);
			ch15 prenom; scanf ("%s", prenom);
			personne* cherche = creerpersonne (nom, prenom);
 			personne* pp = (personne*) chercherUnObjet (li, cherche);
 			booleen extrait = extraireUnObjet (li, pp);
 			if (extrait) {
 				printf ("---->element %s %s extrait de la liste", pp->nom, pp->prenom);}
            else printf("---->element %s %s ne se trouve pas carement dans la liste pour l'extraire", pp->nom, pp->prenom);
			}
			break;
		case 6:
		    listerListe(li);
			break;
		case 7:{
			printf("\t>>donner le nom et le prenom a cherche : ");
			ch15 nom; scanf ("%s", nom);
			ch15 prenom; scanf ("%s", prenom);
			personne* pcherche=creerpersonne(nom,prenom);
			personne* pp = (personne*) chercherUnObjet (li, pcherche);
 			if (pp != NULL) {
 			printf ("---->%s %s se trouve dans la liste\n", pp->nom, pp->prenom);
 			} else {
 				printf ("---->%s inconnue dans la liste\n", nom);
			}}break;
		case 8:{
			detruireListe(li);
			printf("---->La liste est detruite avec succes");}
			break;
	}
		}while(cod!=0);
		return 0;
}
