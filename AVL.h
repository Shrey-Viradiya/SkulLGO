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
        void traverse(int mode);
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

void AVL::traverse(int mode = 0){
    using namespace std;

    cout << "\n\nPrinting The AVL tree: " << name << endl;
    cout << "===========================" << endl;
    cout << "Key --> Value" << endl;
    cout << "===========================" << endl;
    if (mode == 0){
        cout << "Preorder" << endl;
        traversePreorder(root);
    }
    else if (mode == 1){
        cout << "Inorder" << endl;
        traverseInorder(root);
    }
    else if (mode == 2){
        cout << "Postorder" << endl;
        traversePostorder(root);
    }
    else{
        cout << "Invalid Mode" << endl;
        cout << "Inorder" << endl;
        traverseInorder(root);
    }
    cout << "===========================\n" << endl;
}
