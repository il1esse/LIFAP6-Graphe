#include "graphe.h"
#include <iostream>
#include <string>
#include <random>

GRAPHE::graphe(int i,int j)
{
    nbligne = i;
    nbcolonne = j;

}

GRAPHE::initialiser_graphe()
{
    for(i=0;i<maxtab;i++)
    {
        int r = rand%101;
        tabgraph[i] = r;
    } 
}

int GRAPHE::voisins(int case,char choix)
{
    convertion_case_i = case / (nbligne-1)
    conversion_case_j = case % (nbcolonne-1);
    if(choix == 'N')
    {
        if(case < nbcolonne)
        {
            return -1; 
        }
        return (case-nbcolonne);
    }

    if(choix == 'S')
    {
        if(case > (nbcolonne*nbligne-1))
        {
            return -1; 
        }
        return (case+nbcolonne);
    }

    if(choix == 'O')
    {
        if(case < (conversion_case_j == 0))
        {
            return -1; 
        }
        return (case-1);
    }

    if(choix == 'E')
    {
        if(case < (conversion_case_j == nbcolonne))
        {
            return -1; 
        }
        return (case+1);
    }
}
