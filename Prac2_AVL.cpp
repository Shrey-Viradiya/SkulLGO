// Design a balanced binary search tree (AVL) using
// model 2 (node tree) structure

#include "AVL.h"
#include <iostream>

int main(){
    AVL data("Ajino Motado");
    
    // data.AddData("data.csv", 1);
    for (int i = 0; i < 10; i++)
    {
        data.insert(i,i*10);
        data.PrettyPrinting();
        std::cout << std::endl;
    }
    
    // data.traverse();
    // data.PrettyPrinting();

    // std::cout << "Searching" << std::endl;
    // std::cout << "================" << std::endl;
    // std::cout << data.search(809) << std::endl;

    std::cout << "After Deleting 1, 2 and 5" << std::endl;
    data.deleteKey(1);
    data.deleteKey(2);
    data.deleteKey(5);
    data.PrettyPrinting();

    return 0;
}