#define faux   0
#define vrai   1
#define NONORDONNE  0
#define CROISSANT   1
#define DECROISSANT 2

//Définition des nouveaux types
typedef int  booleen;
typedef void Objet;

char*  afficher (Objet* objet);
int comparer(Objet* objet1, Objet* objet2);

// Structure du type élément de la liste
typedef struct element {
  Objet*  reference;
  struct element* suivant;
} Element;

// Structure du type liste
typedef struct {
  Element* premier;
  Element* dernier;
  Element* courant;
  int      nbElt;
  int      type;    // 0:simple, 1:croissant, 2:d�croissant
  char*    (*afficher) (Objet*);
  int      (*comparer) (Objet*, Objet*);
} Liste;

// Initialisation de la liste
void     initListe              (Liste* li, int type, char* (*afficher) (Objet*), int (*comparer) (Objet*, Objet*) );

// Création d'une liste
Liste*   creerListe             (int type, char* (*afficher) (Objet*), int (*comparer) (Objet*, Objet*) );

// Vérifier si la liste est vide ou non
booleen  listeVide              (Liste* li);

// Nbre d'éléments dans la liste
int      nbElement              (Liste* li);


//Insertion
void     insererEnTeteDeListe   (Liste* li, Objet* objet);
static void  insererapre(Liste* li,Element* precedent ,Objet* objet);
void insererenfindeliste(Liste* li,Objet* objet );

//Parcours de la liste
void ouvrirListe (Liste* li);
booleen finListe (Liste* li);
static Element* elementCourant (Liste* li);
Objet* objetCourant (Liste* li);
void listerListe (Liste* li) ;
Objet* chercherUnObjet (Liste* li, Objet* objetCherche);

//Extraction
Objet* extraireEnTeteDeListe (Liste* li);
Objet* extraireEnFinDeListe (Liste* li);
static Objet* extraireApres (Liste* li, Element* precedent);
booleen extraireUnObjet (Liste* li, Objet* objet);

//Destruction
void detruireListe (Liste* li);
