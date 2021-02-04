// Design a balanced binary search tree (AVL) using
// model 2 (node tree) structure

#include "AVL.h"
#include <iostream>

int main(){
    AVL data("Ajino Motado");
    
    data.AddData("data.csv", 1);
    data.traverse();
    data.PrettyPrinting();
    std::cout << data.search(1) << std::endl;
    return 0;
}