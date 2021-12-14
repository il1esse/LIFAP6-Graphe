#include "graphe.h"
#include <iostream>
#include <cstdio>
#include <fstream> //ifstream, ofstream
#include <cstdlib> //exit
#include <string>
#include <random>
#include <queue>

using namespace std;


struct OOrder
{
    bool operator()(const Noeud &n1, const Noeud &n2)
    {
        return n1.prio >= n2.prio;
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
        else if(couleur[i]==3)
        {
            std::cout <<"\033[1;"<<30<<"m"<< tabgraph[i] << " " << "\033[0m";
        }
        else
            cout<< tabgraph[i] << " ";
        if( ( (i+1) % nbcolonne ) ==0 )
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
    return 0;
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
    return 0;
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

    //int distance = sqrt( ((iarr-idep)*(iarr-idep)) + ((jarr-jdep)*(jarr-jdep)) ) ;
    
    int distance = sqrt (((iarr-idep)*(iarr-idep)) + ((jarr-jdep)*(jarr-jdep)) + ((aarr-adep)*(aarr-adep)));
    return distance;
}


void graphe::algoafinal(int depart, int arrive)
{
    priority_queue<Noeud, vector<Noeud>,OOrder> pqueue;
    float inf = std::numeric_limits<float>::infinity();
    
    for( int i = 0; i<maxtab; i++ )
    {
        pred[i]= -1;
        couleur[i]= 1;
        distance[i]= inf;
    }

    Noeud ndepart;
    ndepart.id = depart;
    ndepart.prio = 0 + dist(depart,arrive);

    distance[depart] = 0;

    pqueue.push(ndepart);

    couleur[depart] = 3;

    int case_actu = depart;
    
    
    while(case_actu != arrive)
    {
        Noeud temp; 
        temp = pqueue.top();
        pqueue.pop();


        case_actu = temp.id;
        
        int N=voisinscase(case_actu,'N');
        int S=voisinscase(case_actu,'S');
        int O=voisinscase(case_actu,'O');
        int E=voisinscase(case_actu,'E');

        //std::cout<<"tempid : "<<temp.id<<std::endl;
        //std::cout<<"case actu : "<<case_actu<<std::endl;
        std::cout<<"prio : "<<temp.prio<<std::endl;
        std::cout<<std::endl;
        std::cout<<N<<std::endl;
        std::cout<<S<<std::endl;
        std::cout<<O<<std::endl;
        std::cout<<E<<std::endl;
        std::cout<<std::endl;

        int dn = distance[case_actu];
        //cout<<dn<<endl;
        Noeud Nord;
        Nord.id = N;
        int dnv_N =  dist(case_actu,N);
        Nord.prio = dn + dnv_N + dist(case_actu,arrive);
        cout<<Nord.prio<<endl;
        if((N != -1) && ((dn + dnv_N) < distance[N]) )
            pqueue.push(Nord);
        if(couleur[N]  == 1)
        {
            pred[N]=case_actu;
            distance[N] = dn + dnv_N;
            couleur[N]=3;
        }
        else if (couleur[N]== 3)
        {
            if((dn + dnv_N) < distance[N])
            {
                pred[N]=case_actu;
                distance[N] = dn + dnv_N;
            }

        }
        

        Noeud Sud;
        Sud.id = S;
        int dnv_S =  dist(case_actu,S);
        Sud.prio = dn + dnv_S + dist(case_actu,arrive);
        cout<<Sud.prio<<endl;
        if((S != -1) && ((dn + dnv_S) < distance[S]))
            pqueue.push(Sud);
        if(couleur[S] == 1)
        {
            pred[S]=case_actu;
            distance[S] = dn + dnv_S;
            couleur[S]=3;
        }
        else if (couleur[S]== 3)
        {
            if((dn + dnv_S) < distance[S])
            {
                pred[S]=case_actu;
                distance[S] = dn + dnv_S;
            }

        }

        Noeud Ouest;
        Ouest.id = O;
        int dnv_O =  dist(case_actu,O);
        Ouest.prio = dn + dnv_O + dist(case_actu,arrive);
        if((O != -1) && ((dn + dnv_O) < distance[O]))
            pqueue.push(Ouest);
        if(couleur[O] == 1)
        {
            pred[O]=case_actu;
            distance[O] = dn + dnv_O;
            couleur[O]=3;
        }
        else if (couleur[O] == 3)
        {
            if((dn + dnv_O) < distance[O])
            {
                pred[O]=case_actu;
                distance[O] = dn + dnv_O;
            }

        }

        Noeud Est;
        Est.id = E;
        int dnv_E =  dist(case_actu,E);
        Est.prio = dn + dnv_E + dist(case_actu,arrive);
        if((E != -1) && ((dn + dnv_E) < distance[E]))
            pqueue.push(Est);

        if(couleur[E] == 1)
        {
            pred[E]=case_actu;
            distance[E] = dn + dnv_E;
            couleur[E]=3;
        }
        else if (couleur[E] == 3)
        {
            if((dn + dnv_E) < distance[E])
            {
                pred[E]=case_actu;
                distance[E] = dn + dnv_E;
            }

        }

        if(temp.id == arrive)
        {
            int k = temp.id;
            while ( pred[k] != -1)
            {
                couleur[k]=2;
                k=pred[k];
            }
            couleur[k]=2;
        }
    }
    cout<<endl;
    cout<<distance[arrive]<<endl;
    couleur[depart]=2;
     affichergraphe();
}