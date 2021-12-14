#ifndef _GRAPHE
#define _GRAPHE

const int maxtab=100;

struct Noeud 
{
    int id; // noeud actuelle (identifiant de la case)
    int prio; // distance entre le depart et la case + l'approximation (distance a vol d'oiseau) avec l'arrivée
};


class graphe //classe graphe
{
    public:
    graphe(int i,int j); //constructeur de graphe avec i ligne et j colonne
    void initialiser_graphe(); //initialise le graphe avec des valeurs aléatoires
    void initialiser_graphe_fichier(const char * nomFichier); //initialise le graphe depuis un fichier
    void algoAstar(int depart, int arrive); //algorithme A*
    void affichergraphe(); //procédure d'affichage du graphe

    private:
    //~graphe();
    int voisinsvaleur(int cases,char choix); //fonction qui renvoie la valeur de la case en fonction du choix demandés (N,S,E,O)
    int voisinscase(int cases,char choix); //fonction qui renvoie le numero de la case en fonction du choix demandés (N,S,E,O)
    int distance2D(int case_depart, int case_arr); //fonction qui retourne la distance euclidienne 2D entre 2 cases
    int distance3D(int case_depart, int case_arr); //fonction qui retourne la distance euclidienne 3D entre 2 cases

    //données membres
    int nbligne;
    int nbcolonne;
    int tabgraph[maxtab];
    int couleur[maxtab];
    int pred[maxtab];
    float distance[maxtab];


};
#endif