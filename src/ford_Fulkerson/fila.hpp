#ifndef FILA_HPP
#define FILA_HPP

#include <iostream>

template <typename T>
class fila{
    private:
        T* lista;
        int primeiro, ultimo, tamMax, tamAtual;
    
    public:
        inline fila() { lista = new T[10]; tamMax = 10; tamAtual = primeiro = ultimo = 0; }
        inline fila (int n) { lista = new T[n]; tamMax = n; tamAtual = primeiro = ultimo = 0; }
        inline ~fila() { delete [] lista; }
        
        void push(T item){
            if(ultimo != primeiro){
                lista[ultimo] = item;
                tamAtual = ultimo++;
                return;
            }
            lista[ultimo] = item;
            tamAtual = ultimo++;
        }

        T pop(){
            T item = lista[primeiro];
            primeiro++;
            tamAtual--;
            return item;
        }

        inline bool empty(){ return ultimo==primeiro; }

        void show(){
            for(int i = primeiro; i < tamAtual; i++){
                std::cout << "Item: " << lista[i] << "\n"; 
            }
        }
};

#endif