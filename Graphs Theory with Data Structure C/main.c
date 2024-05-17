#include "graphemath.h"
#include <stdio.h>
#define faux 0
#define vrai 1
#define INFINI INT_MAX
int menu(){
    printf ("\n\***********Graphes**************\n");
    printf (" -------\n\n");
    printf (" 0 - Fin du programme\n");
    printf (" 1 - Creer la graphe\n");
    printf (" 2 - Detruire la graphe\n");
    printf (" 3 - Ajouter un sommet\n");
    printf (" 4 - Ajouter un arc\n");
    printf (" 5 - Ecrire graphe\n");
    printf (" 6 - Parcourir en profondeur\n");
    printf (" 7 - Floyd\n");
    printf ("\n --------------------------------- \n");
    printf ("\n Votre choix : ");
    int choix;
    scanf ("%d", &choix);
    getchar();
    printf ("\n\n");
    return choix;
}
int main(){
    GrapheMat* graphe;
    booleen fini = faux;
    while(!fini){
        switch(menu()){
            case 0:{
                fini=vrai;
                break;
            }
            case 1:
                printf("veuillez saisir le nombre maximal: ");
                int nMax;
                scanf("%d", &nMax);
                graphe=creerGrapheMat(nMax, 100);
                break;

            case 2:
                detruireGraphe(graphe);
                break;

            case 3:
                printf(" Donner le nom du sommet\n");
                NomSom nom;
                gets(nom);
                ajouterUnSommet(graphe, nom);
                break;

            case 4:
                printf("donnez le premier sommet: ");
                NomSom somD;
                gets(somD);
                printf("donnez le deuxieme sommet: ");
                NomSom somA;
                gets(somA);
                printf("Donnez le cout de l arc: ");
                int cout;
                scanf("%d", &cout);
                ajouterUnArc(graphe, somD, somA, cout);
                break;

            case 5:
                ecrireGraphe(graphe);
                break;

            case 6:
                parcoursProfond (graphe);
                break;
            case 7:
                floyd(graphe);
                break;
        }
    }
}
