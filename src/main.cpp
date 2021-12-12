#include "graphe.h"
#include <iostream>

using namespace std;
int main()
{
    graphe graphe1(10,10);
    //graphe1.initialiser_graphe_fichier("a");
    graphe1.initialiser_graphe();
   // graphe1.convert(20);
    graphe1.algoa(depart,arrive);
    
    graphe1.affichergraphe();

    //cout<<graphe1.dist(0,1)<<endl;
    //cout<<"case1"<<graphe1.dist(1,40)<<endl;
    //cout<<"case10"<<graphe1.dist(10,40)<<endl;

/*
    int a = graphe1.voisinscase(4,'N');
    int b = graphe1.voisinscase(4,'S');
    int c = graphe1.voisinscase(4,'O');
    int d = graphe1.voisinscase(4,'E');

    cout<<a<<endl;
    cout<<b<<endl;
    cout<<c<<endl;
    cout<<d<<endl;
    
   
    int a = graphe1.voisins(6,'N');
    int b = graphe1.voisins(6,'S');
    int c = graphe1.voisins(6,'O');
    int d = graphe1.voisins(6,'E');

    int a2 = graphe1.voisins(10,'N');
    int b2 = graphe1.voisins(10,'S');
    int c2 = graphe1.voisins(10,'O');
    int d2 = graphe1.voisins(10,'E');

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

    int dist = graphe1.dist(1,2);
    cout<<dist;

    cout<<endl;
    cout<<endl;



            //std::cout <<"\033[1;"<<31<<"m"<< "test" << "\033[0m";
            // On rÃ©cupÃ¨re l'indice n de la couleur d'affichage puis on affiche n

        std::cout << std::endl;
    
        /*
         for (i = 0; i < 11; i++) {
         for (j = 0; j < 10; j++) {
         n = 10*i + j; // Certaines valeurs de n correspondent Ã  des couleurs
         if (n > 108) break;
         std::printf("\033[%dm Couleur %3d\033[m",n,n);
         // On rÃ©cupÃ¨re l'indice n de la couleur d'affichage puis on affiche n
         }
         printf("\n");
         }
    }
    return 0;*/
}