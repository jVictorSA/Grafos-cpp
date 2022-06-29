#ifndef BFS_HPP
#define BFS_HPP

#include "grafo.h"
#include "fila.hpp"
#include <iostream>
#include <vector>

void BFS(grafo G, int v){
    int count = 0;
    std::vector<int> prev;

    for(int v = 0; v < G.nArest(); v++)
        prev.push_back(-1);
    
    fila<int*> F; 
    F.push(G.getFistVertex());
    prev[0] = count++;

    while(!F.empty())
        int* v = F.pop();

        for(int e = G.first(v); e < G.nArest(); e = G.next(v, e))
            if(prev[e] == -1){
                prev[e] = count++;
                F.push(G.getIndexVertex(e));
            }

    F.~fila();

    for(int v = 0; v < G.nVerts(); v++)
        std::cout << prev[v] << "\n";
}

#endif