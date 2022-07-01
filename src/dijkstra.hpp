#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "grafo.hpp"
#include "heaps.hpp"
#include <vector>
#include <limits>

void dijkstra(grafo& G, int source){
    std::vector<int> dist, prev, vertices;

    for(int i = 0; i < G.nVerts(); i++){
        dist.push_back(std::numeric_limits<int>::max());
        prev.push_back(-1);
        vertices.push_back(i);
    }

    dist[source] = prev[source] = 0;

    djikstraHeap H(vertices, dist, G.nVerts());

    while(!H.empty()){
        std::pair<int, int> u = H.removeMin();

        for (int v = G.first(u.first); v < G.nVerts(); v = G.next(u.first, v)){
            if (dist[v] > dist[u.first] + G.getPeso(u.first, v)){
                dist[v] = dist[u.first] + G.getPeso(u.first, v);
                prev[v] = u.first;
                H.decreaseKey(v, dist[v]);
            }
        }
    }

    for(int i = 0; i < prev.size(); i++){
        std::cout << "Vertice "<< i << " " << prev[i] << " e " << dist[i] <<'\n';
    }


}

#endif