#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <limits>

using std::cout;

class minHeap{
    private:
        std::vector <int> array;
        int tam, tamHeap;

    public:
        minHeap(std::vector <int> V){
            array = V;
            tamHeap = tam = V.size();
        }

        int parent(int i) {return i/2;}
        int left(int i) {return 2*i + 1;}
        int right (int i) {return 2*i + 2;}
        void print(){
            for (int x : array){
                cout << x << " ";
            }
            cout << "\n";
        }

        void minHeapify(int i){
            int l, r, menor;
            l = r = -1;
            if (left(i) < tamHeap){
                l = left(i);
            }
            if (right(i) < tamHeap){
                r = right(i);
            }
            if(l != -1 && l <= tam && array[l] < array[i]){
                menor = l;
            }else{
                menor =i;
            }
            if(r != -1 && r <= tam && array[r] < array[menor]){
                menor = r;
            }
            if(menor != i){
                int temp = array[i];
                array[i] = array[menor];
                array[menor] = temp;
                minHeapify(menor);
            }
        }
        void buildMinHeap(){
            for(int i = tam/2; i >= 0; i--){
                minHeapify(i);
            }
        }
        int getMin() {return array[0];}
        void insert(int value){
            tam = tamHeap += 1;
            array.push_back(std::numeric_limits<int>::max());
            decreaseKey(tam-1, value);
        }
        int removeMin(){
            if(tamHeap < 1){
                std::cout << "Tamanho minimo do heap\n";
                return -1;
            }
            int min = array[0];
            array[0] = array[tamHeap-1];
            tam = tamHeap -= 1;
            array.pop_back();
            minHeapify(0);
            return min;
        }
        void decreaseKey(int i, int value){
            if(value > array[i]){
                std::cout << "Valor maior que o atual! \n";
                return;
            }
            array[i] = value;
            while(i > 0 && array[parent(i)] > array[i]){
                int temp = array[i];
                array[i] = array[parent(i)];
                array[parent(i)]  = temp;
                i = parent(i);
            }
        }
};

class maxHeap{
    private:
        std::vector <int> array;
        int tam, tamHeap;

    public:
        maxHeap(std::vector <int> V){
            array = V;
            tamHeap = tam = V.size();
        }

        int parent(int i) {return i/2;}
        int left(int i) {return 2*i + 1;}
        int right (int i) {return 2*i + 2;}
        void print(){
            for (int x : array){
                cout << x << " ";
            }
            cout << "\n";
        }

        void maxHeapify(int i){
            int l,  r,  maior;
            r = l = -1;
            if (left(i) < tamHeap){
                l = left(i);
            }
            if (right(i) < tamHeap){
                r = right(i);
            }
            if(l != -1 && l <= tamHeap && array[l] > array[i]){
                maior = l;
            }else{
                maior = i;
            }

            if(r != -1 && r <= tamHeap && array[r] > array[maior]){
                maior = r;
            }

            if(maior != i){
                int temp = array[i];
                array[i] = array[maior];
                array[maior] = temp;
                maxHeapify(maior);
            }
        }

        void buildMaxHeap(){
            for(int i = (tam-1)/2; i >= 0; i--){
                maxHeapify(i);
            }
        }

        void heapSort(){
            buildMaxHeap();
            for (int i = tam - 1; i >= 1; i--){
                int temp = array[0];
                array[0] = array[i];
                array[i] = temp;
                tamHeap--;
                maxHeapify(0);
            }
            tamHeap = tam;
        }

        int getMax(){return array[0];}
        void insert(int value){
            tam = tamHeap +=  1;
            cout << "tam eh: " << tam << "\n";
            array.push_back(std::numeric_limits <int>::min());
            increaseKey((tam-1), value);
        }

        int removeMax(){
            if(tamHeap < 1){
                cout << "Nao eh possivel remover itens do heap!\n"
                     << "O heap só tem um elemento.'\n";
                     return -1;
            }
            int max = array[0];
            array[0] = array[tamHeap-1];
            array.pop_back(); 
            tam = tamHeap -= 1;
            maxHeapify(0);
            return max;
        }

        void increaseKey(int i, int value){
            if(array[i] > value){
                cout << "Valor no elemento " << i << " possui um valor maior que " << value << "\n";
                return;
            }
            array[i] = value;

            while(i>0 && array[parent(i)] < array[i]){
                int temp = array[i];
                array[i] = array[parent(i)];
                array[parent(i)]  = temp;
                i = parent(i);
            }
        }
};