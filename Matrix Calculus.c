#include <stdio.h>
#include <stdlib.h>

 int main(){
    int i , j , k , option;
    int L , M  , N, O ;
    int M1[100][100] , M2[100][100] , P[100][100] , A[100][100];

        printf("\n*****Bienvenue au monde des matrices:*********\n\n");

        printf("\tSaisir le nombre des lignes de premiere matrice M1  :");
        scanf("%d",&L);

        printf("\tSaisir le nombre des  colonnes de premiere matrice M1  :");
        scanf("%d",&M);

        printf("\tSaisir le nombre des lignes de deuxieme matrice M2  :");
        scanf("%d",&N);

        printf("\tSaisir le nombre des colonnes de deuxieme matrice M2 :");
        scanf("%d",&O);


        printf("\n\tVeuillez saisir les elements du matrice M1 :\n");
        for(i=0;i<L;i++){
          for(j=0;j<M;j++){
            printf("\t\t>M1[%d][%d] = ", i+1 , j+1);
            scanf("%d", &M1[i][j]);
          }
        }
        printf("\n");

        printf("\n\tVeuillez saisir les elements du matrice M2 :\n");
        for(i=0;i<N;i++){
          for(j=0;j<O;j++){
            printf("\t\t>M2[%d][%d] = ", i+1 , j+1);
            scanf("%d", &M2[i][j]);
          }
        }
        printf("\n");

        printf("\t--------->Affichage de la matrice M1:\n");
        for(i=0;i<L;i++){
          for(j=0;j<M;j++){
            printf("\t%d\t",M1[i][j]);
          }
            printf("\n");
        }
        printf("\n");

        printf("\t--------->Affichage de la matrice M2:\n");
        for(i=0;i<N;i++){
          for(j=0;j<O;j++){
            printf("\t%d\t",M2[i][j]);
          }
            printf("\n");
        }
        printf("\n\n");
        printf("**************************************\n");
        printf("1-Additionner les deux matrices\n");
        printf("2-Multiplier les deux matrices\n");
        printf("Choisissez une option (1 ou 2):");
        scanf("%d",&option);

        switch(option){
               /*Addition*/
               case 1: {
                    if(L==N && M==O){
                       for(i = 0 ; i <L ; i++){
                           for(j=0;j<O;j++)
                             A[i][j] == 0 ;
                       }
                       for(i = 0 ; i < L ; i++){
                           for(j=0;j<O;j++){
                            A[i][j] = M1[i][j] + M2[i][j] ;
                           }
                       }
                       printf("\t--------->La somme des deux matrices est:\n");
                       for(i = 0 ; i < L ; i++){
                           for(j=0;j<O;j++){
                            printf("\t%d  ", A[i][j]);
                           }
                           printf("\n");
                       }
                    }
                    else {
                        printf(">>Attention!  L(M1) = L(M2) & C(M1) = C(M2)");
                    }
               }break;
               /*Multiplication*/
               case 2: {
                    if (M==N){
                        for(i = 0 ; i < L ; i++){
                            for(j=0;j<O;j++)
                                P[i][j] == 0 ;
                        }
                        for(i = 0 ; i < L ; i++){
                            for(j=0;j<O;j++){
                                 for(k=0 ; k<M ;k++)
                                    P[i][j] += M1[i][k] * M2[k][j] ;
                            }
                        }
                        printf("\t--------->Le produit des deux matrices est:\n");
                        for(i = 0 ; i < L ; i++){
                            for(j=0;j<O;j++){
                                printf("\t%d  ", P[i][j]);
                            }
                            printf("\n");
                        }
                     }
                     else {
                     printf(">>Attention ! le nbre de colonnes de M1  = le nbre de lignes de M2\n\n");
                     }
               }break;
               default: {
                      printf(">>Choisissez une option (1 ou 2):");
                      scanf("%d",&option);
               }break;
        }
    return 0;
 }

