all: bin/main.ex

bin/main.ex: obj/main.o obj/graphe.o
	g++ -ggdb obj/main.o obj/graphe.o -o bin/main.ex

obj/main.o: src/main.cpp src/graphe.h
	g++ -ggdb -Wall -c src/main.cpp -o obj/main.o

obj/graphe.o : src/graphe.cpp src/graphe.h
	g++ -ggdb -Wall -c src/graphe.cpp -o obj/graphe.o


clean :
	-rm obj/*.o 
	-rm bin/*.ex


