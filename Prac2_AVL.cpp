// Design a balanced binary search tree (AVL) using
// model 2 (node tree) structure

#include "AVL.h"
#include <iostream>

int main(){
    AVL data("Ajino Motado");
    data.insert(10,2);
    data.insert(5,5);
    data.insert(15,3);
    data.Preorder();
    data.insert(3,2);
    data.insert(2,10);
    data.Preorder();
    data.insert(1,2);
    data.Preorder();
    return 0;
}