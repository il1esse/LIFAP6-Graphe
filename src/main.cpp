#include "graphe.h"
#include <iostream>

int main()
{
    graphe graphe1(10,10);
    graphe1.initialiser_graphe_fichier("data/graphe.txt");
    
    
    //graphe1.affichergraphe();
    int depart = -1;
    int arrive = -1;
    while(depart<0 || depart > 99)
    {
        std::cout<<"Choisir une valeur de départ entre 0 et 99 (sachant que dans le graphe 0 correspond à l'angle supérieur gauche,"<<std::endl;
        std::cout<<"9 l'angle supérieur droit, 90 l'angle inférieur gauche et 99 l'angle inférieur droit."<<std::endl;
        std::cin>>depart;
        std::cout<<std::endl;
    }
    while(arrive<0 || arrive > 99)
    {
        std::cout<<"Choisir une valeur d'arrivée entre 0 et 99"<<std::endl;
        std::cin>>arrive;
        std::cout<<std::endl;
    }
    graphe1.algoAstar(depart,arrive);
}