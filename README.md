# LIFAP6_GRAPHE

(Ce fichier est en .md pour profiter des balises Markdown je vous conseille de l'ouvrir avec vscode et d'appuyer sur ctrl+shift+V) 

Dans ce projet nous avons créé un graphe qui prend la forme d'une grille. A chaque case de la grille est associé une hauteur. Pour notre graphe on utilise l'algorithme A*. 

L’algorithme de recherche A* est une variante de Dijkstra qui se concentre sur la recherche
rapide d’un chemin raisonnablement court entre le sommet initial LYON et un sommet cible PARIS fourni par l’utilisateur. Le déroulement de cet algorithme vise à ce que la première solution
trouvée soit l’une des meilleures. C’est un algorithme qu’il convient d’utiliser dans des applications
privilégiant les temps de calcul plutôt que l’exactitude des résultats.
Comme Dijkstra, l’algorithme A* procède par exploration progressive des sommets autour du
sommet de départ LYON. L’algorithme A* maintient, pour chaque sommet n visité, une estimation de la longueur du meilleur chemin entre LYON et Paris en passant par n, en sommant la
longueur d’un chemin connu menant de LYON à n avec une estimation de la longueur restant à
parcourir entre n et PARIS.
Comme Dijkstra, l’algorithme A* procède par étapes successives au cours de chacune desquelles
il fige la situation pour un des sommets visités et procéde au relâchement des arcs/arêtes issues
de ce sommet : cela permet de découvrir de nouveaux sommets ou de diminuer la distance connue
de LYON à certains sommets. Dans Dijkstra, c’est le sommet visité non encore figé le plus proche
de LYON qui est choisi, alors que dans A* il s’agit cette fois-ci du sommet visité mais non encore
figé qui semble le plus apte à rapprocher la source de la destination finale qui est choisi, au sens
de l’estimation de la longueur totale du chemin.
Pour chaque sommet n visité, on stocke donc la distance connue le séparant de LYON (distance du chemin que l’on peut retrouver si on stocke l’information de prédécesseur) et on peut
également stocker, si on ne souhaite pas en refaire le calcul, l’approximation de la distance
restant à parcourir pour atteindre PARIS.
(Cf https://perso.liris.cnrs.fr/raphaelle.chaine/COURS/LIFAP6/tp09.pdf )

Il y a 2 moyens de déplacement possibles pour un voyageur : 

- Celui qui prend en compte la hauteur de sommets et donc qui essayera le plus possible de contourner les dénivelés qui lui feront perdre du temps. (utilisation d'une distance en 3D) 

- Celui qui passera par le chemin le plus proche de celui que pourrait réaliser un oiseau (tout droit). Il ne prend donc pas en compte la hauteur des sommets. (utilisation de la distance en 2D)



## Organisation des fichiers 



-**lifap6_graph/bin** : répertoire où l'exécutable compilé



-**lifap6_graph/data** : répertoire où se trouveront les txt representant des grilles déja rempli



-**lifap6_graph/obj** : répertoire comportant les compilations intermédiaires (.o)



-**lifap6_graph/src** : répertoire ou se trouvent les .cpp et les .h 



## Installation



Concernant l'installation il faut en premier lieu aller dans le répertoire global du programme et exécuter la commande :



```bash

make all

```  



Le fichier makefile va alors s'occuper des compilations et éditions de liens de tous les fichiers du programme. Elle va aussi créer dans le dossier bin/ l'exécutable dont on a besoin :

main.ex permet la création d'un graphe soit à partir d'un fichier contenant déjà des données soit de manière aléatoire. Comme dit précédemment chaque case comporte une hauteur. La grille sera affichée avec les sommets par lequel le voyageur passe écrit en rouge et ce dont on a exploré les voisins en gris. Le programme réalise un chemin entre le départ et l'arrivée choisi lors de l'execution du main.ex par l'utilisateur et de la façon choisi dans le graph.h (soit en prenant compte la hauteur soit pas). On aura aussi la longeur du chemin affiché. Plusieurs fonctions/procédures sont à disposition : 

- graphe(int i, int j) prend en paramètre la longueur et la largeur de la grille voulue (il faut qu'elle coïncide avec le maxtab présent dans le graph.h. (Par défaut grille 10x10).
- void initialiser_graphe() qui initialise un graphe avec des valeurs aléatoires dedans. 
- void initialiser_graphe_fichier(const char * nomFichier) qui initialise un graphe mais cette fois à partir des données présentes dans un fichier donné. 
- void algoAstar(int depart, int arrive) qui calcule sur le graphe le chemin le plus court selon la méthode choisie (en fonction de la distance 3D ou 2D dans le graphe.h). 
- void affichergraphe() affiche le graphe avec le chemin le plus court en rouge et ce dont on a exploré les voisins en gris. On aura aussi l'affichage de la longueur final du chemin.


## Exigences



Aucune exigence particulière.



## Usage



Pour utiliser l'exécutable après l'avoir créés avec la fonction make on utilise

```c++

./bin/main.ex		//Pour construire la grille avec les cases coloriés selon le chemin.


```



## Auteurs



VINCENT/Yann/11906701



LARIBI/Iliesse/11911241
