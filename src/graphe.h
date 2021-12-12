#ifndef _GRAPHE
#define _GRAPHE

enum Couleur{ blanc=0, grey, noir};
const int maxtab=100;

const int arrive = 98;
const int depart = 0;
//enum Couleur toto=grey;
struct Noeud 
{
    int caseactu; // noeud actuelle
    int distanceavecledepart; // distance aentre le noeud actuelle et le depart
    int heuristique;
    int pred;
    
};

class graphe
{
    public:

    graphe(int i,int j);

    //~graphe();
    void initialiser_graphe();
    void affichergraphe();
    int voisinsvaleur(int cases,char choix);
    int voisinscase(int cases,char choix);
    int dist(int casedepart, int casearr); 
    void initialiser_graphe_fichier(const char * nomFichier);
    void convert(int casedepart);
    void dijkstra(int depart,int arrive);
    void algoa(int depart, int arrive);
    bool compare2Noeuds(Noeud n1, Noeud n2);
    private:

    int nbligne;
    int nbcolonne;

    
    int tabgraph[maxtab];
    int couleur[maxtab];

    


};
#endif