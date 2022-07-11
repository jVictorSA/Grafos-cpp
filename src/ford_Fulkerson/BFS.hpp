#ifndef BFS_HPP
#define BFS_HPP

#include "grafo.hpp"
#include "fila.hpp"
#include <iostream>
#include <vector>

bool BFS(grafo& G, int v, int dest, std::vector<int>& prev){
    std::vector<bool> visitado(G.nVerts(), false);
    int W;
    fila<int> F; 
    F.push(v);
    visitado[v] = true;

    while(!F.empty()){
        W = F.pop();

        for(int e = 0; e < G.nVerts(); e++){      
            if(visitado[e]==false && (G.getPeso(W, e) > 0)){

                if(e == dest){
                    prev[e] = W;
                    return true;
                }
                prev[e] = W;
                F.push(e);
                visitado[e] = true;
            }
        }
    }
    return false;
    //F.~fila(); Dealocar memória da fila
}

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