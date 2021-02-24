// Skip list structure are used to retrieve the data faster.
// Implement the structure up to third level. Show the effect
// of insert and delete operation 

#include "SkipList.h"
#include <iostream>

int main(){
    SkipList data("SBI ki Line", 3);

    data.insertNode(3,5);
    data.insertNode(5,8);
    data.insertNode(10,5);
    data.insertNode(1,5);
    data.Display();

    return 0;
}