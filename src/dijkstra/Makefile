#Para compilar com Clang++ rode o execute o makefile apenas com o argumento "all"
#Para compilar com G++ rode o execute o makefile apenas com o argumento "all CC=g++"

#compilador padrão
CC = clang++

all: dijkstra

dijkstra: dijkstra.cpp grafo.hpp heaps.hpp
	$(CC) -o dijkstra.exe dijkstra.cpp -Wall -Wextra