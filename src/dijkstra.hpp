#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include "grafo.hpp"
#include "heaps.hpp"
#include <vector>
#include <limits>
#include <iostream>
#include <fstream>

//Parâmetros de entrada: -i -s
void dijkstra(grafo& G, int source){
    std::vector<int> dist(G.nVerts(), std::numeric_limits<int>::max()), prev(G.nVerts(), -1), vertices;

    for(int i = 0; i < G.nVerts(); i++){
        vertices.push_back(i);
    }

    dist[source] = prev[source] = 0;

    djikstraHeap H(vertices, dist, G.nVerts());

    while(!H.empty()){
        std::pair<int, int> u = H.removeMin();
        for (int v = G.first(u.first); v < G.nVerts(); v = G.next(u.first, v)){
            if (dist[v] > dist[u.first] + G.getPeso(u.first, v)){
                dist[v] = dist[u.first] + G.getPeso(u.first, v);
                prev[v] = u.first;
                H.decreaseKey(v, dist[v]);
            }
        }
    }
    
    for(size_t i = 0; i < prev.size(); i++){
        std::cout << i+1 << ":" << dist[i] << " ";
    }

}

//Parâmetros de entrada: -i -s -o
void dijkstra(grafo& G, int source, char* file){
    std::vector<int> dist(G.nVerts(), std::numeric_limits<int>::max()), prev(G.nVerts(), -1), vertices;
    std::ofstream fWrite;

    for(int i = 0; i < G.nVerts(); i++){
        vertices.push_back(i);
    }

    dist[source] = prev[source] = 0;

    djikstraHeap H(vertices, dist, G.nVerts());

    while(!H.empty()){
        std::pair<int, int> u = H.removeMin();
        for (int v = G.first(u.first); v < G.nVerts(); v = G.next(u.first, v)){
            if (dist[v] > dist[u.first] + G.getPeso(u.first, v)){
                dist[v] = dist[u.first] + G.getPeso(u.first, v);
                prev[v] = u.first;
                H.decreaseKey(v, dist[v]);
            }
        }
    }

    
    fWrite.open(file);

    while(fWrite.is_open()){
        for(size_t i = 0; i < prev.size(); i++){
            fWrite << i+1 << ":" << dist[i] << " ";
        }
        fWrite << "\n";
        fWrite.close();
    }

    std::cout << "O resultado do programa foi salvo no arquivo \"" << file << "\"" << "\n";
}


//Parâmetros de entrada: -i -l -o
void dijkstra(grafo& G, int source, int destination, char* file){
    std::vector<int> dist(G.nVerts(), std::numeric_limits<int>::max()), prev(G.nVerts(), -1), vertices;
    std::ofstream fWrite;

    for(int i = 0; i < G.nVerts(); i++){
        vertices.push_back(i);
    }

    dist[source] = prev[source] = 0;

    djikstraHeap H(vertices, dist, G.nVerts());

    while(!H.empty()){
        std::pair<int, int> u = H.removeMin();

        for (int v = G.first(u.first); v < G.nVerts(); v = G.next(u.first, v)){
            if (dist[v] > dist[u.first] + G.getPeso(u.first, v)){
                dist[v] = dist[u.first] + G.getPeso(u.first, v);
                prev[v] = u.first;
                H.decreaseKey(v, dist[v]);
            }
        }
    }
    
    fWrite.open(file);

    while(fWrite.is_open()){
        fWrite << dist[destination] << "\n";
        fWrite.close();
    }

    std::cout << "O resultado do programa foi salvo no arquivo \"" << file << "\"" << "\n";
}

//Parâmetros de entrada: -i -l
void dijkstra(grafo& G, int source, int destination){
    std::vector<int> dist(G.nVerts(), std::numeric_limits<int>::max()), prev(G.nVerts(), -1), vertices;

    for(int i = 0; i < G.nVerts(); i++){
        vertices.push_back(i);
    }

    dist[source] = prev[source] = 0;

    djikstraHeap H(vertices, dist, G.nVerts());

    while(!H.empty()){
        std::pair<int, int> u = H.removeMin();

        for (int v = G.first(u.first); v < G.nVerts(); v = G.next(u.first, v)){
            if (dist[v] > dist[u.first] + G.getPeso(u.first, v)){
                dist[v] = dist[u.first] + G.getPeso(u.first, v);
                prev[v] = u.first;
                H.decreaseKey(v, dist[v]);
            }
        }
    }
    
    std::cout << dist[destination] << "\n";
}

#endif