#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <vector>

#define NAOVISITADO -1

class grafo{
    private:
        int vertices, arestas;        
        int **indices;
        int *mark;


    public:
        grafo(int verts){
            int i;
            vertices = verts;
            arestas = 0;
            mark = new int[verts];

            for(i = 0; i < verts; i++)
                mark[i] = NAOVISITADO;

            indices = (int**) new int*[verts];

            for(i = 0; i < verts; i++)
                indices[i] = new int[verts];

            for(i = 0; i < verts; i++)
                for(int j = 0; j < verts; j++)
                    indices[i][j] = 0;
        }

        ~grafo(){
            delete [] mark;
            for(int i = 0; i < arestas; i++)
                delete [] indices[i];
            delete [] indices;
        }

        
        inline int* getFistVertex(){ return indices[0]; }
        inline int* getIndexVertex(int v){ return indices[v]; }
        inline int nVerts() { return vertices; }
        inline int nArest() {return arestas;}
        int first(int v) {
            for (int i = 0; i < vertices; i++)
                if (indices[v][i] != 0) {return i;}
            
            return vertices;
        }
        int next(int v1, int v2) {
            for (int i = v2+1; i < vertices; i++)
                if (indices[v1][i] != 0) {return i;}

            return vertices;
        }
        std::vector<int> getNeighbours(int v){
            std::vector<int> vec;
            for (int i = 0; i < vertices; i++)
                if (indices[v][i] != 0) {
                    vec.push_back(i);
                }

            return vec;
        }
        void setAresta(int v1, int v2, int peso){
            if(indices[v1][v2] == 0){
                arestas++;
                indices[v1][v2] = peso;
            }
        }
        //inline void delAresta(int v1, int v2) {}
        inline bool haAresta(int v1, int v2) {return indices[v1][v2] != 0;}
        inline int getPeso(int v1, int v2) {return indices[v1][v2];}
        inline int getMark(int v) {return mark[v];}
        inline void setMark(int v, int valor) {mark[v] = valor;}
};

#endif