// Rebalancing operation can be delayed until a certain threshold is attained. 
// Scapegoat tree uses partial rebuilding for balancing a search tree. 
// Implement scapegoat tree to demonstrate the partial rebuilding operation.

#include "ScapeGoat.h"
#include <iostream>

int main(){
    ScapeGoat data("Ajino Motado");
    
    data.AddData("data.csv", 1);
    // for (int i = 0; i < 10; i++)
    // {
    //     data.insert(i,i*10);
    //     data.PrettyPrinting();
    //     std::cout << std::endl;
    // }
    
    // data.traverse();
    data.PrettyPrinting();

    // std::cout << "Searching" << std::endl;
    // std::cout << "================" << std::endl;
    // std::cout << data.search(809) << std::endl;

    std::cout << "After Deleting Some Keys" << std::endl;
    data.deleteKey(896);
    data.deleteKey(529);
    data.deleteKey(40);
    data.deleteKey(254);
    data.PrettyPrinting();

    return 0;
}