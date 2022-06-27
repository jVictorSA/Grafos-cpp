#include "grafo.h"
#include <iostream>
#include <vector>

void DFSrec(grafo G, int v, int &count, std::vector<int>& prev){
    prev[v] = count++;
    
    for(size_t e = G.first(v); e < G.nVerts(); e = G.next(v, e))
        if(prev[e] == -1)
            DFSrec(G, v, count, prev);
}

void DFS(grafo G){
    int count = 0;
    std::vector <int> prev;
    for(size_t v = 0; v < G.nVerts(); v++)
        prev.push_back(-1);

    for(size_t v = 0; v < G.nVerts(); v++){
        if(prev[v] == -1)
            DFSrec(G, v, count, prev);
    }
}

int main(){
    
    return 0;
}