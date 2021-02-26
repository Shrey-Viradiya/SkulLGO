// Write a program to split a balance search tree at
// i. Root
// ii. A given point of split.

#include "AVL.h"
#include <iostream>

int main(){

    AVL data("Ajino Motado");

    for (int i = 0; i < 10; i++)
    {
        data.insert(i, i*10);
    }

    data.PrettyPrinting();

    std::pair<AVL*, AVL*> temp = data.splitAtRoot();

    temp.first->PrettyPrinting();
    temp.second->PrettyPrinting();

    delete temp.first;
    delete temp.second;

    return 0;
}