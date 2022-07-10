#Para compilar com Clang++ rode o execute o makefile apenas com o argumento "all"
#Para compilar com G++ rode o execute o makefile apenas com o argumento "all CC=g++"

#compilador padrão
CC = clang++

all: bellmanFord prim dijkstra fordFulkerson

bellmanFord: bellmanFord.cpp grafo.hpp
	$(CC) -o bellmanFord.exe bellmanFord.cpp -Wall -Wextra

prim.exe: prim.cpp grafo.hpp heaps.hpp
	$(CC) -o prim.exe prim.cpp -Wall -Wextra

dijkstra: dijkstra.cpp grafo.hpp heaps.hpp
	$(CC) -o dijkstra.exe dijkstra.cpp -Wall -Wextra

fordFulkerson: fordFulkerson.cpp grafo.hpp BFS.hpp fordFulkerson.hpp fila.hpp
	$(CC) -o fordFulkerson.exe fordFulkerson.cpp -Wall -Wextra