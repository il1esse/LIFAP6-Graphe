#include "graphe.h"
#include <iostream>
#include <cstdio>
#include <fstream> //ifstream, ofstream
#include <cstdlib> //exit
#include <string>
#include <random>
#include <queue>

struct Order //structure order pour gérer l'ordre dans la file de priorité
{
    bool operator()(const Noeud &n1, const Noeud &n2)
    {
        return n1.prio >= n2.prio;
    }
};

graphe::graphe(int i,int j) //constructeur graphe qui crée un graphe avec i ligne et j colonne
{
    nbligne = i; 
    nbcolonne = j;
}

void graphe::initialiser_graphe() //procédure pour initialiser le graphe avec des valeurs aléatoires
{
    for(int i=0;i<maxtab;i++) //boucle "for" pour parcourir l'ensemble du graphe
    {
        int r = rand()%101; //variable r avec une valeu aléatoire
        tabgraph[i] = r; //insérer la valeur dans le graphe
    } 
}

void graphe::initialiser_graphe_fichier(const char * nomFichier)
//preconditions : nomFichier chaine de caracteres designant le nom d'un fichier
//                contenant des entiers separes par des caracteres d'espacement
//postcondition : ajout du contenu du fichier dans le tabgraph
{
  std::ifstream ifs;
  ifs.open(nomFichier); //ouverture du fichier
  if(ifs.bad()) //test pour vérifier si on a réussit à ouvrir le fichier
  {
      std::cout<<"Impossible d'ouvrir le fichier "<<nomFichier<<" en lecture \n"; exit(1); //si on n'y est pas arrivé afficher "impossible d'ouvrir le fichier" 
  } 
  int temp;
  int i=0;
  while(ifs >> temp) //lecture du contenu du fichier
  { 
      tabgraph[i] = temp; //ajout du contenu lu dans le tabgraph
      i=i+1;
  }
  ifs.close(); //fermeture du fichier
}

void graphe::affichergraphe()
{
    std::cout<<"Voici le graphe avec "<<nbligne <<" lignes et "<<nbcolonne<<" colonnes :"<<std::endl;

    for(int i=0; i <maxtab;i++) //parcours du tableau de couleur
    {
        if(couleur[i]==2) //si la valeur dans le tableau est 2 (correspond au noir)
        {
            std::cout <<"\033[1;"<<31<<"m"<< tabgraph[i] << " " << "\033[0m"; //on change la couleur du caractère afficher correspondant dans le
            // tabgraph, ici le rouge correspond à la couleur noir
        }
        else if(couleur[i]==3) //si la valeur dans le tableau est 3 (correspond au gris)
        {
            std::cout <<"\033[1;"<<30<<"m"<< tabgraph[i] << " " << "\033[0m"; //on change la couleur du caractère afficher correspondant dans le
            // tabgraph, icien gris
        }
        else
            std::cout<< tabgraph[i] << " ";
        if( ( (i+1) % nbcolonne ) ==0 )
        {
            std::cout<<std::endl;
        }
    }

}

int graphe::voisinsvaleur(int cases,char choix)//Fonction qui retourne la valeur de la case voisine d'une case donnée. On choisit la direction dans le paramètre choix ( case au nord avec N sud avec S etc)
{
    int conversion_cases_j = (cases+1) % nbcolonne; //Recupere l'indice de colonne d'un tableau 2D dans un tableau 1D
    if(choix == 'N') //si le choix est le Nord
    {
        if(cases < nbcolonne) //Si la case demandé n'existe pas (bords de la grille) on retourne -1
        {
            return -1; 
        }
        return tabgraph[cases-nbcolonne]; //valeur de la case corepondante dans le tableau tabgraph
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

int graphe::voisinscase(int cases,char choix) //Fonction qui retourne la case voisine d'une case donnée. On choisit la direction dans le paramètre choix ( case au nord avec N sud avec S etc)
{
    int conversion_cases_j = (cases+1) % nbcolonne;
    if(choix == 'N') //Cas pour Nord
    {
        if(cases < nbcolonne)
        {
            return -1; 
        }
        return cases-nbcolonne; //case corepondante dans le tableau tabgraph
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

int graphe::distance2D(int case_depart, int case_arr)
{
    int idep = case_depart / (nbligne); //1D --> 3D donne la ligne de la case départ dans le graphe en 3D
    int jdep = case_depart  % (nbcolonne); //1D --> 3D donne la colonne de la case départ dans le graphe en 3D

    int iarr = case_arr / (nbligne); //1D --> 3D donne la ligne de la case arrivée dans le graphe en 3D
    int jarr = case_arr % (nbcolonne); //1D --> 3D donne la ligne de la case arrivée dans le graphe en 3D

    return sqrt(((iarr-idep)*(iarr-idep)) + ((jarr-jdep)*(jarr-jdep))); //retourne la distance euclidienne 2D entre 2 cases
}

int graphe::distance3D(int case_depart, int case_arr)
{
    int idep = case_depart / (nbligne); //1D --> 3D donne la ligne de la case départ dans le graphe en 3D
    int jdep = case_depart  % (nbcolonne); //1D --> 3D donne la colonne de la case départ dans le graphe en 3D

    int iarr = case_arr / (nbligne); //1D --> 3D donne la ligne de la case arrivée dans le graphe en 3D
    int jarr = case_arr % (nbcolonne); //1D --> 3D donne la ligne de la case arrivée dans le graphe en 3D

    int adep = tabgraph[case_depart]; // valeur qui est dans la case départ
    int aarr = tabgraph[case_arr]; // valeur qui est dans la case arrivée

    //return sqrt(((iarr-idep)*(iarr-idep)) + ((jarr-jdep)*(jarr-jdep))); //distance 2d
    return sqrt (((iarr-idep)*(iarr-idep)) + ((jarr-jdep)*(jarr-jdep)) + ((aarr-adep)*(aarr-adep))); //retourne la distance euclidienne 3D entre 2 cases
}

void graphe::algoAstar(int depart, int arrive)
{
    std::priority_queue<Noeud, std::vector<Noeud>,Order> pqueue; //definition de la priority queue qui vient de la STL
    float inf = std::numeric_limits<float>::infinity(); //valeur infini
    
    for( int i = 0; i<maxtab; i++ ) //initialisation des tableaux de couleurs, predecesseurs et distance
    {
        pred[i]= -1;
        couleur[i]= 1;
        distance[i]= inf;
    }

    Noeud ndepart; //Creation du noeud de la case départ
    ndepart.id = depart; //affectation de la case départ à son ID
    ndepart.prio = 0 + distance3D(depart,arrive); //heuristique ( distance entre le depart et la case + l'approximation (distance a vol d'oiseau) avec l'arrivée)

    distance[depart] = 0; //la distance avec le départ du départ est 0

    pqueue.push(ndepart); //ajoue du noeud départ dans la priority queue

    couleur[depart] = 3; //on donne la couleur grise au départ

    int case_actu = depart;
    
    while(case_actu != arrive) //tant que l'on est pas à l'arrivée le programme tourne
    {
        Noeud temp;  //Création d'un noeud temporaire
        temp = pqueue.top(); //Récupération du noeud en tete de la priority queue
        pqueue.pop(); //Libération du noeud en tete 
        case_actu = temp.id; //la case actuelle devient la case temporaire
        
        int N=voisinscase(case_actu,'N'); //voisin Nord de la case actuelle
        int S=voisinscase(case_actu,'S'); //voisin Sud de la case actuelle
        int O=voisinscase(case_actu,'O'); //voisin Ouest de la case actuelle
        int E=voisinscase(case_actu,'E'); //voisin Est de la case actuelle

        int dn = distance[case_actu]; //distance totale entre le départ et la case actuelle
        
        Noeud Nord; //Création d'un nouveau noeud
        Nord.id = N;
        int dnv_N =  distance3D(case_actu,N); //distance entre la case actuelle et son voisin nord
        Nord.prio = dn + dnv_N + distance3D(case_actu,arrive); //heuristique(pour gérer sa place dans la priority queue)
        if((N != -1) && ((dn + dnv_N) < distance[N]) ) //si le voisin nord existe (!= -1) et que sa distance avec le depart est inférieur avec sa
        //distance avec le départ déjà enregistré
            pqueue.push(Nord); //ajout du noeud dans la priority queue
        if(couleur[N]  == 1) //si le voisin est de couleur blanc 
        {
            pred[N]=case_actu; //son predecesseur est la case actuelle
            distance[N] = dn + dnv_N; //sa distance correspond à la distance totale actuelle + la distance entre la case actuelle et le voisin nord
            couleur[N]=3; //il devient gris
        }
        else if (couleur[N]== 3) //si le voisin est de couleur grise
        {
            if((dn + dnv_N) < distance[N]) //si la distance totale + la distance entre la case actuelle et le voisin nord  est inférieur à
            // la distance déjà enregistré dans le tableau de distance
            {
                pred[N]=case_actu; //on change son prédecesseur et celui ci devient la case actuelle
                distance[N] = dn + dnv_N; //sa distance devient la distance entre la case actuelle et le voisin nord
            }

        }
        

        Noeud Sud; //même chose que le Nord (resp. Sud)
        Sud.id = S;
        int dnv_S =  distance3D(case_actu,S);
        Sud.prio = dn + dnv_S + distance3D(case_actu,arrive);
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

        Noeud Ouest;  //même chose que le Nord (resp. Ouest)
        Ouest.id = O;
        int dnv_O =  distance3D(case_actu,O);
        Ouest.prio = dn + dnv_O + distance3D(case_actu,arrive);
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

        Noeud Est;  //même chose que le Nord (resp. Est)
        Est.id = E;
        int dnv_E =  distance3D(case_actu,E);
        Est.prio = dn + dnv_E + distance3D(case_actu,arrive);
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

        if(temp.id == arrive) //si la case actuelle est l'arrivée
        {
            int k = temp.id; //affecte le numero de case à une variable k
            while ( pred[k] != -1) //tant que la valeur dans k est différente de -1 (départ)
            {
                couleur[k]=2; //on met la couleur à noir
                k=pred[k]; //et k prend la valeur du predecesseur
            }
            couleur[k]=2; //change la couleur de l'arrivée
        }
        
    }
    std::cout<<"la distance totale du chemin est : "<<distance[arrive]<<std::endl;
    std::cout<<std::endl;
    couleur[depart]=2;
    affichergraphe();
}