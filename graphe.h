#ifndef _GRAPHE
#define _GRAPHE

enum Couleur{ blanc=0, grey, noir};


//enum Couleur toto=grey;

class GRAPHE
{
    public:

    graphe();

    ~graphe();

    private:

    int nbligne;
    int nbcolonne;
    int maxtab=nbligne*nbcolonne;

    int tabgraph[maxtab];

    initialiser_graphe()


};