#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char ch15 [16];
typedef void Objet;

typedef struct {
      ch15 nom;
      ch15 prenom;
    } personne;

personne* creerpersonne (char* nom,char* prenom);
char* ecrirepersonne (Objet* Objet);
int  comparerpersonne (Objet* objet1, Objet* objet2);
