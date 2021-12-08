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
        cout<< tabgraph[i] << " ";
        if( ( (i+1) % nbcolonne ) ==0 )
        {
            cout<<endl;
        }
    }
}

int graphe::voisins(int cases,char choix)
{
    int convertion_cases_i = cases / (nbligne-1);
    int conversion_cases_j = cases % (nbcolonne-1);
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
        if(cases < (conversion_cases_j == 0))
        {
            return -1; 
        }
        return tabgraph[cases-1];
    }

    if(choix == 'E')
    {
        if(cases > (conversion_cases_j == nbcolonne))
        {
            return -1; 
        }
        return tabgraph[cases+1];
    }
}

int graphe::distance(int casedepart, int casearr)
{ 
    int convertion_cases_idepart = casedepart / (nbligne-1); //1D --> 3D
    int conversion_cases_jdepart = casedepart  % (nbcolonne-1);

    int convertion_cases_iarrivee = casearr / (nbligne-1);
    int conversion_cases_jarrivee = casearr % (nbcolonne-1);
    int distance = sqrt( ((casearr - casedepart) * (casearr - casedepart))+ ( (tabgraph[casedepart] - tabgraph[casearr]) * (tabgraph[casedepart] - tabgraph[casearr]) ));

    return distance;
}