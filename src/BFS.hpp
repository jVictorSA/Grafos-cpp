#ifndef BFS_HPP
#define BFS_HPP

#include "grafo.h"
#include "fila.hpp"
#include <iostream>
#include <vector>

void BFS(grafo& G, int v){
    int count = 0;
    std::vector<int> prev;
    int W;
    for(int v = 0; v < G.nArest(); v++)
        prev.push_back(-1);
    
    fila<int> F; 
    F.push(v);
    prev[0] = count++;

    while(!F.empty()){
        W = F.pop();

        for(int e = G.first(W); e < G.nArest(); e = G.next(W, e)){      
            F.show();
            if(e == G.nVerts()){
                continue;
            }
            if(prev[e] == -1){
                prev[e] = count++;
                F.push(e);
            }
        }
    }

    F.~fila();

    for(int v = 0; v < G.nVerts(); v++)
        std::cout << prev[v] << "\n";
}

#endif