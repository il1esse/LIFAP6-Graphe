#include "graphe.h"
#include <iostream>

using namespace std;
int main()
{
    graphe graphe1(10,10);
    graphe1.initialiser_graphe_fichier("b.txt");
    //graphe1.affichergraphe();
    int a = graphe1.voisins(0,'N');
    int b = graphe1.voisins(0,'S');
    int c = graphe1.voisins(0,'E');
    int d = graphe1.voisins(0,'O');

    int a2 = graphe1.voisins(99,'N');
    int b2 = graphe1.voisins(99,'S');
    int c2 = graphe1.voisins(99,'E');
    int d2 = graphe1.voisins(99,'O');

    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;

    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<d<<endl;

    cout<<endl;
    cout<<endl;

    cout<<a2<<endl;
    cout<<b2<<endl;
    cout<<c2<<endl;
    cout<<d2<<endl;

    
    cout<<endl;
    cout<<endl;

    int dist = graphe1.distance(1,2);
    cout<<dist;

    cout<<endl;
    cout<<endl;
    return 0;
}