// Skip list structure are used to retrieve the data faster.
// Implement the structure up to third level. Show the effect
// of insert and delete operation 

#include "SkipList.h"
#include <iostream>

int main(){
    SkipList data("SBI ki Line", 5);

    data.AddData("data.csv", 1);
    data.Display();

    return 0;
}