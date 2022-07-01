#ifndef BELLMANFORD_HPP
#define BELLMANFORD_HPP

#include "grafo.hpp"
#include <vector>
#include <limits>

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
        std::cout << "Vertice "<< i << " e " << dist[i] <<'\n';
    }
}

#endif