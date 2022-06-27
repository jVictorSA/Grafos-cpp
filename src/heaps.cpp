#include "heaps.h"

using std::cout;

int main (){
    //std::vector <int> vetor = {16,4,10,14,7,9,3,2,8,1};
    std::vector <int> vetor = {4,1,3,2,16,9,10,14,8,7};
    minHeap h(vetor);

    h.print();
    //h.buildMinHeap();
    h.minHeapify(0);
    h.print();
    cout << h.getMin() << "\n";
    cout << h.removeMin() << "\n";
    h.print();
    h.decreaseKey(7, 1);
    h.print();
    h.decreaseKey(3, -5);
    h.print();
    h.insert(19);
    //h.heapSort();
    h.print();
}