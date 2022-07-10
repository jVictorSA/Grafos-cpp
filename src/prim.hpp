#ifndef PRIM_HPP
#define PRIM_HPP

#include "grafo.hpp"
#include "heaps.hpp"
#include <limits>
#include <vector>
#include <utility>
#include <algorithm>
#include <fstream>

//Parâmetros de entrada: -i
void prim(grafo& G, int source){
    std::vector<int> dist(G.nVerts(), std::numeric_limits<int>::max()), prev(G.nVerts(), 0), vertices;

    for(int i = 0; i < G.nVerts(); i++){ vertices.push_back(i); }

    dist[source] = 0;

    djikstraHeap Q(vertices, dist, G.nVerts());

    while (!Q.empty()){
        std::pair<int, int> u = Q.removeMin();

        for(int i = G.first(u.first); i < G.nVerts(); i = G.next(u.first, i)){
            if (Q.has(i) && dist[i] > G.getPeso(u.first, i)){
                dist[i] = G.getPeso(u.first, i);
                prev[i] = u.first;
                Q.decreaseKey(i, dist[i]);
            }
        }
    }

    int res = 0;
    for(size_t i = 0; i < prev.size(); i++){
        res += dist[i];
    }

    std::cout << res << "\n";
}

//Parâmetros de entrada: -i -l
void prim(grafo& G, int source, int destination){
    std::vector<int> dist(G.nVerts(), std::numeric_limits<int>::max()), prev(G.nVerts(), 0), vertices;

    for(int i = 0; i < G.nVerts(); i++){ vertices.push_back(i); }

    dist[source] = 0;

    djikstraHeap Q(vertices, dist, G.nVerts());

    while (!Q.empty()){
        std::pair<int, int> u = Q.removeMin();
        for(int i = G.first(u.first); i < G.nVerts(); i = G.next(u.first, i)){
            if (Q.has(i) && dist[i] > G.getPeso(u.first, i)){
                dist[i] = G.getPeso(u.first, i);
                prev[i] = u.first;
                Q.decreaseKey(i, dist[i]);
            }
        }
    }

    int res = 0;
    for(int i = destination; i != source; i = prev[i]){
        if(dist[i]){            
            res += dist[i];
        }
    }

    std::cout << res << '\n';

}

//Parâmetros de entrada: -i -s
void prim(grafo& G, int source, bool solution){
    std::vector<int> dist(G.nVerts(), std::numeric_limits<int>::max()), prev(G.nVerts(), 0), vertices;
    std::ofstream fWrite;

    for(int i = 0; i < G.nVerts(); i++){ vertices.push_back(i); }

    dist[source] = 0;

    djikstraHeap Q(vertices, dist, G.nVerts());

    while (!Q.empty()){
        std::pair<int, int> u = Q.removeMin();

        for(int i = G.first(u.first); i < G.nVerts(); i = G.next(u.first, i)){
            if (Q.has(i) && dist[i] > G.getPeso(u.first, i)){
                dist[i] = G.getPeso(u.first, i);
                prev[i] = u.first;
                Q.decreaseKey(i, dist[i]);
            }
        }
    }

    std::vector<std::pair<int, int>> s;

    for(size_t i = 0; i < prev.size(); i++){
        if(prev[i] < static_cast<int>(i)){
            s.push_back(std::make_pair(prev[i]+1, i+1));
        }else{
            s.push_back(std::make_pair(i+1, prev[i]+1));
        }
    }
    
    std::sort(s.begin(), s.end());

    for(size_t i = 1; i < s.size(); i++){
        std::cout << "(" << s[i].first << "," << s[i].second <<") ";
    }
}

//Parâmetros de entrada: -i -o
void prim(grafo& G, int source, char* file){
    std::vector<int> dist(G.nVerts(), std::numeric_limits<int>::max()), prev(G.nVerts(), 0), vertices;
    std::ofstream fWrite;

    for(int i = 0; i < G.nVerts(); i++){ vertices.push_back(i); }

    dist[source] = 0;

    djikstraHeap Q(vertices, dist, G.nVerts());

    while (!Q.empty()){
        std::pair<int, int> u = Q.removeMin();

        for(int i = G.first(u.first); i < G.nVerts(); i = G.next(u.first, i)){
            if (Q.has(i) && dist[i] > G.getPeso(u.first, i)){
                dist[i] = G.getPeso(u.first, i);
                prev[i] = u.first;
                Q.decreaseKey(i, dist[i]);
            }
        }
    }

    int res = 0;
    fWrite.open(file);

    while (fWrite.is_open()){
        for(size_t i = 0; i < prev.size(); i++){
            res += dist[i];
        }
        fWrite << res << "\n";
        fWrite.close();
    }
    std::cout << "O resultado do programa foi salvo no arquivo \"" << file << "\"" << "\n";
}

//Parâmetros de entrada: -i -l -o
void prim(grafo& G, int source, int destination, char* file){
    std::vector<int> dist(G.nVerts(), std::numeric_limits<int>::max()), prev(G.nVerts(), 0), vertices;
    std::ofstream fWrite;

    for(int i = 0; i < G.nVerts(); i++){ vertices.push_back(i); }

    dist[source] = 0;

    djikstraHeap Q(vertices, dist, G.nVerts());

    while (!Q.empty()){
        std::pair<int, int> u = Q.removeMin();

        for(int i = G.first(u.first); i < G.nVerts(); i = G.next(u.first, i)){
            if (Q.has(i) && dist[i] > G.getPeso(u.first, i)){
                dist[i] = G.getPeso(u.first, i);
                prev[i] = u.first;
                Q.decreaseKey(i, dist[i]);
            }
        }
    }

    int res = 0;
    for(int i = destination; i != source; i = prev[i]){
        if(dist[i]){
            res += dist[i];
        }
    }

    fWrite.open(file);

    fWrite << res << '\n';

    fWrite.close();

    std::cout << "O resultado do programa foi salvo no arquivo \"" << file << "\"" << "\n";

}

//Parâmetros de entrada: -i -s -o
void prim(grafo& G, int source, bool solution, char* file){
    std::vector<int> dist(G.nVerts(), std::numeric_limits<int>::max()), prev(G.nVerts(), 0), vertices;
    std::ofstream fWrite;

    for(int i = 0; i < G.nVerts(); i++){ vertices.push_back(i); }

    dist[source] = 0;

    djikstraHeap Q(vertices, dist, G.nVerts());

    while (!Q.empty()){
        std::pair<int, int> u = Q.removeMin();
        for(int i = G.first(u.first); i < G.nVerts(); i = G.next(u.first, i)){
            if (Q.has(i) && dist[i] > G.getPeso(u.first, i)){
                dist[i] = G.getPeso(u.first, i);
                prev[i] = u.first;
                Q.decreaseKey(i, dist[i]);
            }
        }
    }

    std::vector<std::pair<int, int>> s;
    
    for(size_t i = 0; i < prev.size(); i++){
        if(prev[i] < static_cast<int>(i)){
            s.push_back(std::make_pair(prev[i]+1, i+1));
        }else{
            s.push_back(std::make_pair(i+1, prev[i]+1));
        }
    }
    
    std::sort(s.begin(), s.end());

    fWrite.open(file);
    
    while(fWrite.is_open()){        
        for(size_t i = 1; i < s.size(); i++){
            fWrite << "(" << s[i].first << "," << s[i].second <<") ";;
        }
        fWrite.close();
    }

    std::cout << "O resultado do programa foi salvo no arquivo \"" << file << "\"" << "\n";
}

#endif