// Skip list structure are used to retrieve the data faster.
// Implement the structure up to third level. Show the effect
// of insert and delete operation 

#include "SkipList.h"
#include <iostream>

int main(){
    SkipList data("SBI ki Line", 5);

    // data.AddData("data.csv", 1);
    data.insertNode(241,3472);
    data.insertNode(238,3038);
    data.insertNode(849,4886);
    data.insertNode(231,3404);
    data.insertNode(492,4891);
    data.insertNode(893,1531);
    data.insertNode(433,3703);
    data.insertNode(239,4056);
    data.insertNode(406,2890);
    data.insertNode(455,4604);
    data.insertNode(541,4113);
    data.insertNode(285,2508);
    data.insertNode(529,2689);
    data.insertNode(718,4044);
    data.insertNode(220,2134);
    data.insertNode(643,3733);
    data.Display();

    data.deleteNode(220);
    data.deleteNode(718);
    data.deleteNode(406);

    data.Display();

    return 0;
}