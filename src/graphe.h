#ifndef _GRAPHE
#define _GRAPHE

enum Couleur{ blanc=0, grey, noir};
const int maxtab=100;

//enum Couleur toto=grey;

class graphe
{
    public:

    graphe(int i,int j);

    //~graphe();
    void initialiser_graphe();
    void affichergraphe();
    int voisins(int cases,char choix);
    int dist(int casedepart, int casearr); 
    void initialiser_graphe_fichier(const char * nomFichier);

    void dijkstra(int depart,int arrive);


    private:

    int nbligne;
    int nbcolonne;

    
    int tabgraph[maxtab];
    int couleur[maxtab];

    


};
#endif