#pragma once
#include <iostream>
#include <cstring>
#include <string>

class HeapNode
{
public:
    HeapNode *right, *left;
    int key;
    int object;

    HeapNode()
    {
        key = 0;
        object = 0;
        right = nullptr;
        left = nullptr;
    }
    HeapNode(int k, int o)
    {
        key = k;
        object = o;
        right = nullptr;
        left = nullptr;
    }

    ~HeapNode(){
        delete left;
        delete right;
    }
};

class MaxHeap{
    private:
        char name[50];
        HeapNode *root;

    public:
        MaxHeap(const char nameinput[50]);
        ~MaxHeap();
        void insert(int key, int object);
        void PrettyPrinting();
};

MaxHeap::MaxHeap(const char nameinput[50]){
    strcpy(name, nameinput);
    root = nullptr;
}

MaxHeap::~MaxHeap()
{
    using namespace std;
    delete root;
    cout << "Memory Released of " << name << endl;
}

int countNode(HeapNode *node){
    if (node == nullptr)
    {
        return 0;
    }
    else{
        return countNode(node->left) + countNode(node->right) + 1;
    }
}

void MaxHeap::insert(int key, int object){
    if (root == nullptr)
    {
        root = new HeapNode(key, object);
        return;
    }

    HeapNode *iter = root;

    while (iter != nullptr)
    {
        if (key > iter->key)
        {
            int tk, to;
            tk = iter->key;
            to = iter->object;
            iter->key = key;
            iter->object = object;
            key = tk;
            object = to;
        }
        
        if (iter->left == nullptr || iter->right == nullptr)
        {
            if (iter->left == nullptr)
            {
                iter->left = new HeapNode(key, object);
                return;
            }
            else{
                iter->right = new HeapNode(key, object);
                return;
            }
        }

        if (countNode(iter->left) >  countNode (iter->right))
        {
            iter = iter->right;
        }
        else{
            iter = iter->left;
        }        
    } 
}

void printBT(const std::string& prefix, const HeapNode* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;
        std::cout << "|" << std::endl;
        std::cout << prefix;
        std::cout << (isLeft ? "|--" : "'--" );

        // print the value of the node
        std::cout << node->key << "-->" << node->object << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "|   " : "    ") , node->left, true);
        printBT( prefix + (isLeft ? "|   " : "    ") , node->right, false);
    }
}

void MaxHeap::PrettyPrinting(){
    using namespace std;

    cout << "\n\nPrinting The MaxHeap: " << name << endl;
    cout << "===========================" << endl;
    printBT("", root, false);
}