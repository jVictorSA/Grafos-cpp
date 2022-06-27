#include "grafo.h"
#include <iostream>
#include <vector>

//FAZER UMA ESTRUTURA DE FILA

void BFS(grafo G, int v){
    int count = 0;
    std::vector<int> prev;

    for(size_t v = 0; v < G.nArest(); v++)
        prev.push_back(-1);
    
    //FILA F; F.push(vertice0);
    prev[0] = count++;

    while(!F.empty())
        int v = F.pop();

        for(size_t e = G.first(v); e < G.nArest(); e = G.next(v, e))
            if(prev[e] == -1){
                prev[e] = count++;
                F.push(e);
            }

    //Dealocar a FILA            
}