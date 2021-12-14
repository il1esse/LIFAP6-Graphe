#ifndef _GRAPHE
#define _GRAPHE


const int maxtab=100;

const int arrive = 7;
const int depart = 7;


struct Noeud 
{
    int id; // noeud actuelle
    int prio;
};


class graphe
{
    public:
    graphe(int i,int j);
    void initialiser_graphe();
    void initialiser_graphe_fichier(const char * nomFichier);
    void algoafinal(int depart, int arrive);
    void affichergraphe();

    private:
    //~graphe();
    int voisinsvaleur(int cases,char choix);
    int voisinscase(int cases,char choix);
    int dist(int casedepart, int casearr); 
    void convert(int casedepart);

    int nbligne;
    int nbcolonne;
    int tabgraph[maxtab];
    int couleur[maxtab];
    int pred[maxtab];
    float distance[maxtab];


};
#endif