#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include "personne.h"

personne* creerpersonne(char* nom,char* prenom)
{
	personne* p=(personne*)malloc(sizeof(personne));
	strcpy (p->nom,nom);
	strcpy (p->prenom,prenom);
	return p;
}

char* ecrirepersonne (Objet* objet){
	personne* p=(personne*) objet;
	char* output = (char*)malloc(sizeof(personne));
	snprintf(output,sizeof(personne),"%s %s\n",p->nom,p->prenom);
	return output;

}

int comparerpersonne (Objet* objet1,Objet* objet2){
	personne* p1=(personne*) objet1;
	personne* p2=(personne*) objet2;
	return strcmp(p1->nom,p2->nom);
}


