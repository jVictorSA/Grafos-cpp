#Para compilar com Clang++ rode o execute o makefile apenas com o argumento "all"
#Para compilar com G++ rode o execute o makefile apenas com o argumento "all CC=g++"

#compilador padrão
CC = clang++

all: fordFulkerson

fordFulkerson: fordFulkerson.cpp grafo.hpp BFS.hpp fordFulkerson.hpp fila.hpp
	$(CC) -o fordFulkerson.exe fordFulkerson.cpp -Wall -Wextra