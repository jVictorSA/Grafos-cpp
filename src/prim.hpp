#ifndef PRIM_HPP
#define PRIM_HPP

#include "grafo.hpp"
#include "heaps.hpp"
#include <limits>
#include <vector>
#include <utility>
#include <algorithm>

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
    std::vector<std::pair<int, int>> s;
    for(size_t i = 0; i < dist.size(); i++){
        res += dist[i];
        //std::cout << "Vertice "<< i+1 << " " << prev[i]+1 << " e " << dist[i] <<'\n';
    }

    for(size_t i = 0; i < prev.size(); i++){
        if(prev[i] < static_cast<int>(i)){
            s.push_back(std::make_pair(prev[i]+1, i+1));
        }else{
            s.push_back(std::make_pair(i+1, prev[i]+1));
        }
    }

    std::cout << res << '\n';
    
    std::sort(s.begin(), s.end());

    for(size_t i = 1; i < s.size(); i++){
        std::cout << "(" << s[i].first << "," << s[i].second << ") ";
    }

}

#endif