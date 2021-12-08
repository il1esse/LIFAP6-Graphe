#ifndef _GRAPHE
#define _GRAPHE

enum Couleur{ blanc=0, grey, noir};
const int maxtab=100;

//enum Couleur toto=grey;

class graphe
{
    public:

    graphe(int i,int j);

    ~graphe();

    private:

    int nbligne;
    int nbcolonne;


    int tabgraph[maxtab];

    void initialiser_graphe();

    int voisins(int cases,char choix);


};
#endif _GRAPHE