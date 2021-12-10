#include "graphe.h"
#include <iostream>
#include <cstdio>
#include <fstream> //ifstream, ofstream
#include <cstdlib> //exit
#include <string>
#include <random>

using namespace std;
graphe::graphe(int i,int j)
{
    nbligne = i;
    nbcolonne = j;

}

void graphe::initialiser_graphe()
{
    for(int i=0;i<maxtab;i++)
    {
        int r = rand()%101;
        tabgraph[i] = r;
    } 
}

void graphe::initialiser_graphe_fichier(const char * nomFichier)
//preconditions : nomFichier chaine de caracteres designant le nom d'un fichier
//                contenant des entiers separes par des caracteres d'espacement
//postcondition : affichage du contenu du fichier sur la sortie standard
{
  std::ifstream ifs;
  ifs.open(nomFichier);
  if(ifs.bad())
    {std::cout<<"Impossible d'ouvrir le fichier "<<nomFichier<<" en lecture \n"; exit(1);} 
  int temp;
  int i=0;
  while(ifs >> temp)
  {
      //cout<<temp;
      tabgraph[i] = temp;
      i=i+1;
  }
  ifs.close();
}

void graphe::affichergraphe()
{
    cout<<"Voici le graphe avec "<<nbligne <<" lignes et "<<nbcolonne<<" colonnes :"<<endl;

    for(int i=0; i <maxtab;i++)
    {
        if(couleur[i]==2)
        {
            std::cout <<"\033[1;"<<31<<"m"<< tabgraph[i] << " " << "\033[0m";
        }
        else
            cout<< tabgraph[i] << " ";
        if( ( (i+1) % nbcolonne ) ==0 )
        {
            cout<<endl;
        }
    }
    cout<<endl;
    cout<<endl;
    cout<<endl;
    
    for(int j=0; j <maxtab;j++)
    {

        cout<< couleur[j] << " ";
        if( ( (j+1) % nbcolonne ) ==0 )
        {
            cout<<endl;
        }
    }
}

int graphe::voisinsvaleur(int cases,char choix)
{
    //int convertion_cases_i = cases / (nbligne-1);
    int conversion_cases_j = (cases+1) % nbcolonne;
    if(choix == 'N')
    {
        if(cases < nbcolonne)
        {
            return -1; 
        }
        return tabgraph[cases-nbcolonne];
    }

    if(choix == 'S')
    {
        if(cases > (nbcolonne*(nbligne-1)))
        {
            return -1; 
        }
        return tabgraph[cases+nbcolonne];
    }

    if(choix == 'O')
    {
        if(conversion_cases_j == 1)
        {
            return -1; 
        }
        return tabgraph[cases-1];
    }

    if(choix == 'E')
    {
        if(conversion_cases_j == 0)
        {
            return -1; 
        }
        return tabgraph[cases+1];
    }
}

int graphe::voisinscase(int cases,char choix)
{
    //int convertion_cases_i = cases / (nbligne-1);
    int conversion_cases_j = (cases+1) % nbcolonne;
    if(choix == 'N')
    {
        if(cases < nbcolonne)
        {
            return -1; 
        }
        return cases-nbcolonne;
    }

    if(choix == 'S')
    {
        if(cases >= (nbcolonne*(nbligne-1)))
        {
            return -1; 
        }
        return cases+nbcolonne;
    }

    if(choix == 'O')
    {
        if(conversion_cases_j == 1)
        {
            return -1; 
        }
        return cases-1;
    }

    if(choix == 'E')
    {
        if(conversion_cases_j == 0)
        {
            return -1; 
        }
        return cases+1;
    }
}

int graphe::dist(int casedepart, int casearr)
{ 
    //int convertion_cases_idepart = casedepart / (nbligne-1); //1D --> 3D
    //int conversion_cases_jdepart = casedepart  % (nbcolonne-1);

    //int convertion_cases_iarrivee = casearr / (nbligne-1);
    //int conversion_cases_jarrivee = casearr % (nbcolonne-1);
    int distance = sqrt( ((casearr - casedepart) * (casearr - casedepart))+ ( (tabgraph[casedepart] - tabgraph[casearr]) * (tabgraph[casedepart] - tabgraph[casearr]) ));

    return distance;
}

void graphe::dijkstra(int depart, int arrive) // blanc = 1 // 2 = rouge // 3 = gris
{
    int min;
    int actu=depart;
    min = dist(depart,arrive);

    for( int i = 0; i<maxtab; i++ )
    {
        couleur[i]=1;
    }
    while(actu != arrive)
    {
        couleur[actu]=2;
        int N=voisinscase(actu,'N');
        int S=voisinscase(actu,'S');
        int O=voisinscase(actu,'O');
        int E=voisinscase(actu,'E');

        std::cout<<std::endl;
        std::cout<<N<<std::endl;
        std::cout<<S<<std::endl;
        std::cout<<O<<std::endl;
        std::cout<<E<<std::endl;
        std::cout<<std::endl;

        int min2;
        if(N !=-1 && couleur[N] != 2)
        {
            min2 = dist(N,arrive);
        }
        else if (S !=-1 && couleur[S] != 2)
        {
            min2 = dist(S,arrive);
        }
        else if (O !=-1 && couleur[O] != 2)
        {
            min2 = dist(O,arrive);
        }
        else if (E !=-1 && couleur[E] != 2)
        {
            min2 = dist(E,arrive);
        }



        if(N !=-1 && couleur[N] != 2 && (dist(N,arrive)<=min2 ))
        {
            actu = N;
            min2=dist(N,arrive);
            cout<<actu<<endl;
        }
        if(S !=-1 && couleur[S] != 2 && (dist(S,arrive)<=min2))
        {
            actu = S;
            min2=dist(S,arrive);
            cout<<actu<<endl;
        }
        if(O !=-1 && couleur[O] != 2 && (dist(O,arrive)<=min2))
        {
            actu = O;
            min2=dist(O,arrive);
            cout<<actu<<endl;
        }
        if(E !=-1 && couleur[E] != 2 && (dist(E,arrive)<=min2))
        {
            actu = E;
            min2=dist(E,arrive);
            cout<<actu<<endl;
        }
        couleur[actu]=2;
    }


}