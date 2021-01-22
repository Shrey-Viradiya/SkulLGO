#pragma once
#include <iostream>

// This header file contains the code for AVL self balancing tree

struct AVLnode
{
    int key;
    int object;
    struct AVLnode *left = nullptr;
    struct AVLnode *right = nullptr;
    int height = 0;
};

void traverse(struct AVLnode* rootNode);

class AVL
{
public:
    struct AVLnode *root;
    AVL();
    ~AVL();
    void insert(int key, int object);
    void Preorder();
};

void AVL::insert(int key, int object){
    using namespace std;
    if (root == nullptr){
        root = new struct AVLnode;
        root->key = key;
        root->object = object;
        return;
    }

    // inserting other nodes remaining
}

AVL::AVL()
{
    root = nullptr;
}

AVL::~AVL()
{
    // to do
    // delete all the nodes
}

void traverse(struct AVLnode* rootNode){
    using namespace std;
    if (rootNode != nullptr)
    {
        cout << rootNode->key << "-->" << rootNode->object << endl;
        if (rootNode->left != nullptr)
        {
            traverse(rootNode->left);
        }
        if (rootNode->right != nullptr)
        {
            traverse(rootNode->right);
        }        
    } 
}

void AVL::Preorder(){
    using namespace std;

    cout << "Printing The AVL tree ... Preorder Traversal" << endl;
    traverse(root);
}
