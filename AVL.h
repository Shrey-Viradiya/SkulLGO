#pragma once
#include <iostream>
#include <cstring>
#include "AVLutilities.h"
// This header file contains the code for AVL self balancing tree

class AVL
{
    private:
        char name[50];
        struct AVLnode *root;
    public:
        AVL(const char n[50]);
        ~AVL();
        void insert(int key, int object);
        void Preorder();
};

void AVL::insert(int key, int object){
    root = insertObject(root, key, object);
}

AVL::AVL(const char n[50])
{
    strcpy(name, n);
    root = nullptr;
}

AVL::~AVL()
{
    using namespace std;
    releaseMemoryTree(root);
    cout << "Memory Released of " << name << endl;
}

void AVL::Preorder(){
    using namespace std;

    cout << "Printing The AVL tree: " << name << " (Preorder Traversal)" << endl;
    cout << "===========================" << endl;
    cout << "Key --> Value" << endl;
    cout << "===========================" << endl;
    traversePreorder(root);
    cout << "===========================" << endl;
}
