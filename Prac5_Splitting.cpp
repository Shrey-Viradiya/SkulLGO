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

    for (int j = 0; j < 10; j++)
    {
        AVL data2("Carume Satado");

        for (int i = 0; i < 10; i++)
        {
            data2.insert(i, i*10);
        }

        data2.PrettyPrinting();

        std::pair<AVL*, AVL*> temp2 = data2.splitAtKey(j);

        std::cout << "Splitting at " << j << std::endl;
        temp2.first->PrettyPrinting();
        temp2.second->PrettyPrinting();

        delete temp2.first;
        delete temp2.second;
    }
    

    

    return 0;
}