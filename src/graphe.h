#ifndef _GRAPHE
#define _GRAPHE

enum Couleur{ blanc=0, grey, noir};


//enum Couleur toto=grey;

class graphe
{
    public:

    graphe(int i,int j);

    ~graphe();

    private:

    int nbligne;
    int nbcolonne;
    int maxtab=nbligne*nbcolonne;

    int tabgraph[100000000];

    void initialiser_graphe();

    int voisins(int cases,char choix);


};
#endif _GRAPHE