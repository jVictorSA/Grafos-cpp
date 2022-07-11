#ifndef FORDFULKERSON_HPP
#define FORDFULKERSON_HPP

#include "grafo.hpp"
#include "BFS.hpp"
#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>
#include <fstream>

//Parâmetros de entrada -i -l
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

//Parâmetros de entrada -i -l -o
void fordFulkerson(grafo& G, int source, int destination, char* file){
    std::vector<int> prev(G.nVerts(), -1);
    int maxVal = std::numeric_limits<int>::max();
    int maxFlow = 0;
    std::ofstream fWrite;
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

    fWrite.open(file);

    if(fWrite.is_open()){
        fWrite << maxFlow << "\n";
        fWrite.close();
    }
    std::cout << "O resultado do programa foi salvo no arquivo \"" << file << "\"" << "\n";
}

//Parâmetros de entrada -i -l -s
void fordFulkerson(grafo& G, int source, int destination, bool printSolution){
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

    std::vector<std::pair<int, int>> s;

    for(size_t i = 0; i < prev.size(); i++){
        if(prev[i] < static_cast<int>(i)){
            s.push_back(std::make_pair(prev[i]+1, i+1));
            s.push_back(std::make_pair(i+1, prev[i]+1));
        }else{
            s.push_back(std::make_pair(i+1, prev[i]+1));
            s.push_back(std::make_pair(prev[i]+1, i+1));
        }
    }
    
    std::sort(s.begin(), s.end());

    for(size_t i = 2; i < s.size(); i++){
        std::cout << "(" << s[i].first << "," << s[i].second <<") " 
                  << G.getPeso(s[i].first-1, s[i].second-1) << "\n";
    }
}

//Parâmetros de entrada -i -l -s -o
void fordFulkerson(grafo& G, int source, int destination, bool printSolution, char* file){
    std::vector<int> prev(G.nVerts(), -1);
    int maxVal = std::numeric_limits<int>::max();
    int maxFlow = 0;
    std::ofstream fWrite;
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
    
    std::vector<std::pair<int, int>> s;
    
    for(size_t i = 0; i < prev.size(); i++){
        if(prev[i] < static_cast<int>(i)){
            s.push_back(std::make_pair(prev[i]+1, i+1));
            s.push_back(std::make_pair(i+1, prev[i]+1));
        }else{
            s.push_back(std::make_pair(i+1, prev[i]+1));
            s.push_back(std::make_pair(prev[i]+1, i+1));
        }
    }
    
    std::sort(s.begin(), s.end());


    fWrite.open(file);

    while(fWrite.is_open()){
        for(size_t i = 2; i < s.size(); i++){
            fWrite << "(" << s[i].first << "," << s[i].second <<") " 
                  << G.getPeso(s[i].first-1, s[i].second-1) << "\n";
        }
        fWrite.close();
    }
    std::cout << "O resultado do programa foi salvo no arquivo \"" << file << "\"" << "\n";
}

#endif