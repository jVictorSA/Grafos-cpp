#include <iterator>
#include <vector>
#include <cstddef>

#define NAOVISITADO -1

class grafo{
    private:
        static int vertices, arestas;        
        static int **indices;
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

        //Iterator do grafo, para uso no padrão idiomático do C++11
        //Particularmente achei uma adição interessante na implementação
        struct Iterator{
            using iteratorCategory  = std::forward_iterator_tag;
            using differencetype    = std::ptrdiff_t;
            using valueType         = int;
            using pointer           = int**;
            using reference         = int&;

            //Construtor
            Iterator(pointer ptr) : gPtr(ptr){}
            Iterator(pointer *ptr) : gPtr(*ptr){}
            
            reference operator*() const {return **gPtr;}
            pointer operator->() {return gPtr;}

            //Pré-incremento
            Iterator& operator++() {gPtr++; return *this;}

            //Pós-incremento
            Iterator& operator++(int) {Iterator temp = *this; ++(*this); return temp;}

            friend bool operator==(const Iterator& a, const Iterator& b) {return a.gPtr==b.gPtr;}
            friend bool operator!=(const Iterator& a, const Iterator& b) {return a.gPtr!=b.gPtr;}

            Iterator begin() {return Iterator(&indices);}
            Iterator end() {return Iterator(&indices[nVerts()]);}

            private:
                pointer gPtr;
        };

        static int nVerts() {return vertices;}
        int nArest() {return arestas;}
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
        void setAresta(int v1, int v2, int peso){
            
        }
        void delAresta(int v1, int v2) {}
        bool haAresta(int v1, int v2) {return indices[v1][v2] != 0;}
        int getPeso(int v1, int v2) {return indices[v1][v2];}
        int getMark(int v) {return mark[v];}
        void setMark(int v, int valor) {mark[v] = valor;}
};