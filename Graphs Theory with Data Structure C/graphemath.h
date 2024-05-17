#ifndef GRAPHE_H
#define GRAPHE_H
#include <stdio.h>
#define faux 0
#define vrai 1
#define INFINI INT_MAX

/*Définition de nouveaux types*/
typedef char NomSom[20]; // nom d'un sommet
typedef int booleen;
typedef int* Matrice;

//Structure d'un graphe
typedef struct {
 int n; // nombre de sommets
 int nMax; // nombre max de sommets
 booleen value; // graphe valué ou non
 NomSom* nomS; // noms des sommets
 Matrice element; // existence d'un arc (i, j)
 Matrice valeur; // cout de l'arc (i, j)
 booleen* marque; // sommet marqu� (visit�) ou non
} GrapheMat;


GrapheMat* creerGrapheMat (int nMax, int value);
void detruireGraphe (GrapheMat* graphe);
void ajouterUnSommet (GrapheMat* graphe, NomSom nom);
void ajouterUnArc (GrapheMat* graphe, NomSom somD, NomSom somA, int cout);
void ecrireGraphe (GrapheMat* graphe);
void parcoursProfond (GrapheMat* graphe);
void floyd (GrapheMat* graphe);
void ecrireEtape (Matrice , Matrice , int , int , int );
static void initFloyd (GrapheMat*, Matrice* , Matrice* );

#endif

