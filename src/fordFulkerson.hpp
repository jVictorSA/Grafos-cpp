#ifndef FORDFULKERSON_HPP
#define FORDFULKERSON_HPP

#include "grafo.hpp"
#include "BFS.hpp"
#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>

void fordFulkerson(grafo& G, int source, int destination){
    std::vector<int> prev(G.nVerts(), -1);
    int maxVal = std::numeric_limits<int>::max();
    int maxFlow = 0;
    prev[0] = 0;
    
    while(BFS(G, source, destination, prev)){
        int pathFlow = maxVal;
        for (int v = destination; v != source; v = prev[v]){
            int u = prev[v];
            pathFlow = std::min(pathFlow, G.getPeso(u, v));            
        }        
        
        for (int v = destination; v != source; v = prev[v]){
            int u = prev[v];
            G.setAresta(u, v, (G.getPeso(u,v) - pathFlow));
            G.setAresta(v, u, (G.getPeso(v,u) + pathFlow));            
        }        
        maxFlow += pathFlow;        
    }
    std::cout << maxFlow << "\n";
}

#endif