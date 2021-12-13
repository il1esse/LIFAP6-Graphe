#include "graphe.h"
#include <iostream>
#include <cstdio>
#include <fstream> //ifstream, ofstream
#include <cstdlib> //exit
#include <string>
#include <random>
#include <queue>

using namespace std;

/*using astar = std::pair<int,float>;// ID , distance + heurisique
    static auto cmp = [](const astar& a,const astar& b) {
        return a.second > b.second;
    };
    std::priority_queue<astar, std::vector<astar>, decltype(cmp)> Q(cmp);
*/

//typedef pair<int,int> pi;

struct OOrder
{
    bool operator()(const Noeud &n1, const Noeud &n2)
    {
        return n1.heuristique >= n2.heuristique;
    }
};



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

/*
bool graphe::compare2Noeuds(Noeud n1, Noeud n2)
{
    int distancen1 = dist(n1.caseactu,arrive);
    int distancen2 = dist(n2.caseactu,arrive);
    if(distancen1 < distancen2)
        return true;

}*/

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

void graphe::convert(int casedepart)
{
    int convertion_cases_idepart = casedepart / (nbligne); //1D --> 3D
    int conversion_cases_jdepart = casedepart  % (nbcolonne);
    cout<<"je suis la valeur i (ligne) "<<convertion_cases_idepart <<endl;
    cout<<"je suis la valeur j(colonne) "<<conversion_cases_jdepart<<endl;
}

int graphe::dist(int casedepart, int casearr)
{ 
    int idep = casedepart / (nbligne); //1D --> 3D
    int jdep = casedepart  % (nbcolonne);

    int iarr = casearr / (nbligne);
    int jarr = casearr % (nbcolonne);

    int adep = tabgraph[casedepart];
    int aarr = tabgraph[casearr];
    //((iarr-idep)*(iarr-idep)) + ((jarr-jdep)*(jarr-jdep))
    
    //int distance = sqrt( ((iarr-idep)*(iarr-idep)) + ((jarr-jdep)*(jarr-jdep)) + ( (tabgraph[casearr] - tabgraph[casedepart]) * (tabgraph[casearr] - tabgraph[casedepart]) ));

    int distance = sqrt( ((iarr-idep)*(iarr-idep)) + ((jarr-jdep)*(jarr-jdep)) ) ;
    
    //int distance = sqrt (((iarr-idep)*(iarr-idep)) + ((jarr-jdep)*(jarr-jdep)) + ((aarr-adep)*(aarr-adep)));
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

void graphe::algoa(int depart, int arrive) // blanc = 1 // 2 = rouge(noir) // 3 = gris
{
    
    priority_queue<Noeud, vector<Noeud>,OOrder> pqueue;
    //int min;
    //int actu=depart;
    int actu;
    //min = dist(depart,arrive);

    Noeud ndepart;
    ndepart.caseactu=depart;
    ndepart.distanceavecledepart=0;
    ndepart.heuristique = dist(ndepart.caseactu, arrive);
    pqueue.push(ndepart);

    for( int i = 0; i<maxtab; i++ )
    {
        couleur[i]=1;
    }
    while(actu != arrive)
    {
        Noeud n;
        n = pqueue.top();
        
        couleur[n.caseactu]=2;
        
        pqueue.pop();
        actu = n.caseactu;
        
        //couleur[actu]=2;
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

        Noeud n1;
        n1.caseactu=N;
        n1.distanceavecledepart=dist(n1.caseactu,depart);
        n1.heuristique = dist(n1.caseactu, arrive);
        //n1.pred = actu; 
        if(couleur[n1.caseactu] !=2)
            couleur[n1.caseactu]=3;

        Noeud n2;
        n2.caseactu=S;
        n2.distanceavecledepart=dist(n2.caseactu,depart);
        n2.heuristique= dist(n2.caseactu, arrive);
        //n2.pred = actu; 
        //couleur[n2.caseactu]=3;
        if(couleur[n2.caseactu] !=2)
            couleur[n2.caseactu]=3;

        Noeud n3;
        n3.caseactu=O;
        n3.distanceavecledepart=dist(n3.caseactu,depart);
        n3.heuristique = dist(n3.caseactu, arrive);
        //n3.pred = actu; 
        //couleur[n3.caseactu]=3;
        if(couleur[n3.caseactu] !=2)
            couleur[n3.caseactu]=3;

        Noeud n4;
        n4.caseactu=E;
        n4.distanceavecledepart=dist(n4.caseactu,depart);
        n4.heuristique = dist(n4.caseactu, arrive);
        //n4.pred = actu; 
        //couleur[n4.caseactu]=3;
        if(couleur[n4.caseactu] !=2)
            couleur[n4.caseactu]=3;

        if((n1.caseactu != -1)&&(couleur[n1.caseactu] !=2))
            pqueue.push(n1);
        if((n2.caseactu != -1)&&(couleur[n2.caseactu] !=2))
            pqueue.push(n2);
        if((n3.caseactu != -1)&&(couleur[n3.caseactu] !=2))
            pqueue.push(n3);
        if((n4.caseactu != -1)&&(couleur[n4.caseactu] !=2))
            pqueue.push(n4);
        //pqueue.pop();


        
        

        /*if(actu == arrive)
        {
            int temp = actu;
            while (temp !=depart)
            {
                couleur[temp]=2;
                temp = n.pred;
            }
            
        }*/
        
        affichergraphe();
    }

}
