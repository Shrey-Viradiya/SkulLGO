// Implement heap data structure using linked list structure. 
// The list should retrieve high priority object every time the extract operation is performed.

#include "MaxHeap.h"
#include <iostream>

int main(){

    MaxHeap data("Ajino Motado");

    for (int i = 0; i < 10; i++)
    {
        data.insert(i, i*10);
        data.PrettyPrinting();
    }

    return 0;
}