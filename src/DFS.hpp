#ifndef DFS_HPP
#define DFS_HPP
#include "grafo.h"
#include <iostream>
#include <vector>

void DFSrec(grafo& G, int v, int &count, std::vector<int>& prev){
    prev[v] = count++;
        
    for(int e = G.first(v); e < G.nVerts(); e = G.next(v, e)){
        if(v == G.nVerts()){
            return;
        }
        if(prev[e] == -1){
            DFSrec(G, e, count, prev);
        }
    }
        return;
}

void DFS(grafo& G){
    //std::cout << "oi dfs\n";
    int count = 0;
    std::vector <int> prev;
    for(int v = 0; v < G.nVerts(); v++)
        prev.push_back(-1);
    //std::cout << prev.size() << G.nVerts()<<"\n";
    for(int v = 0; v < G.nVerts(); v++){
        //std::cout << "oi v: "<< v<< "\n";
        if(prev[v] == -1)
            DFSrec(G, v, count, prev);
    }
    //std::cout << "oi dfs3\n";
    for(int v = 0; v < G.nVerts(); v++)
        std::cout << prev[v] << "\n";
}

#endif