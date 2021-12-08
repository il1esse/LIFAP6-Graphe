#include "graphe.h"
#include <iostream>
#include <string>
#include <random>

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
        return (cases-nbcolonne);
    }

    if(choix == 'S')
    {
        if(cases > (nbcolonne*nbligne-1))
        {
            return -1; 
        }
        return (cases+nbcolonne);
    }

    if(choix == 'O')
    {
        if(cases < (conversion_cases_j == 0))
        {
            return -1; 
        }
        return (cases-1);
    }

    if(choix == 'E')
    {
        if(cases < (conversion_cases_j == nbcolonne))
        {
            return -1; 
        }
        return (cases+1);
    }
}
