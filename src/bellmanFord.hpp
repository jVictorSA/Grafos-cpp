#ifndef BELLMANFORD_HPP
#define BELLMANFORD_HPP

#include "grafo.hpp"
#include <vector>
#include <limits>
#include <iostream>
#include <fstream>

//Parâmetros de entrada: -i -s
void bellmanFord(grafo& G, int source){
    std::vector<int> dist(G.nVerts(), std::numeric_limits<int>::max());
    dist[source] = 0;

    for(int i = 0; i < G.nVerts()-1; i++){
        for(int j = G.first(i); j < G.nVerts(); j = G.next(i, j)){
            if (dist[i] != std::numeric_limits<int>::max() && dist[i] + G.getPeso(i,j) < dist[j]){
                dist[j] = dist[i] + G.getPeso(i,j);
            }
        }
    }

    //implementar detecção de ciclos negativos

    for(size_t i = 0; i < dist.size(); i++){
        std::cout << i+1 << ":" << dist[i] << " ";
    }
}

//Parâmetros de entrada: -i -s -o
void bellmanFord(grafo& G, int source, char* file){
    std::vector<int> dist(G.nVerts(), std::numeric_limits<int>::max());
    dist[source] = 0;
    std::ofstream fWrite;

    for(int i = 0; i < G.nVerts()-1; i++){
        for(int j = G.first(i); j < G.nVerts(); j = G.next(i, j)){
            if (dist[i] != std::numeric_limits<int>::max() && dist[i] + G.getPeso(i,j) < dist[j]){
                dist[j] = dist[i] + G.getPeso(i,j);
            }
        }
    }

    //implementar detecção de ciclos negativos

    fWrite.open(file);
    
    while(fWrite.is_open()){
        for(size_t i = 0; i < dist.size(); i++){
            fWrite << i+1 << ":" << dist[i] << " ";
        }
        fWrite.close();
    }
    
    std::cout << "O resultado do programa foi salvo no arquivo \"" << file << "\"" << "\n";
}

//Parâmetros de entrada: -i -l -o
void bellmanFord(grafo& G, int source, int destination, char* file){
    std::vector<int> dist(G.nVerts(), std::numeric_limits<int>::max());
    dist[source] = 0;
    std::ofstream fWrite;

    for(int i = 0; i < G.nVerts()-1; i++){
        for(int j = G.first(i); j < G.nVerts(); j = G.next(i, j)){
            if (dist[i] != std::numeric_limits<int>::max() && dist[i] + G.getPeso(i,j) < dist[j]){
                dist[j] = dist[i] + G.getPeso(i,j);
            }
        }
    }

    //implementar detecção de ciclos negativos

    fWrite.open(file);
    
    while(fWrite.is_open()){        
        fWrite << dist[destination];
        
        fWrite.close();
    }
    
    std::cout << "O resultado do programa foi salvo no arquivo \"" << file << "\"" << "\n";
}

//Parâmetros de entrada: -i -l
void bellmanFord(grafo& G, int source, int destination){
    std::vector<int> dist(G.nVerts(), std::numeric_limits<int>::max());
    dist[source] = 0;

    for(int i = 0; i < G.nVerts()-1; i++){
        for(int j = G.first(i); j < G.nVerts(); j = G.next(i, j)){
            if (dist[i] != std::numeric_limits<int>::max() && dist[i] + G.getPeso(i,j) < dist[j]){
                dist[j] = dist[i] + G.getPeso(i,j);
            }
        }
    }

    //implementar detecção de ciclos negativos
    
    std::cout << dist[destination];            
}
#endif