#pragma once
#include <iostream>
#include <cmath>

class ScapeGoatNode
{
    public:
    ScapeGoatNode *right, *left, *parent;
    int key;
    int object;

    ScapeGoatNode()
    {
        key = 0;
        object = 0;
        right = nullptr;
        left = nullptr;
        parent = nullptr;
    }
    ScapeGoatNode(int k, int o)
    {
        key = k;
        object = 0;
        right = nullptr;
        left = nullptr;
        parent = nullptr;
    }

    ~ScapeGoatNode(){
        delete left;
        delete right;
    }
};

void traversePreorder(ScapeGoatNode* rootNode){
    using namespace std;
    if (rootNode != nullptr)
    {
        cout << rootNode->key << " --> " << rootNode->object << endl;
        if (rootNode->left != nullptr)
        {
            traversePreorder(rootNode->left);
        }
        if (rootNode->right != nullptr)
        {
            traversePreorder(rootNode->right);
        }        
    } 
}

void traverseInorder(ScapeGoatNode* rootNode){
    using namespace std;
    if (rootNode != nullptr)
    {
        if (rootNode->left != nullptr)
        {
            traverseInorder(rootNode->left);
        }
        cout << rootNode->key << " --> " << rootNode->object << endl;
        if (rootNode->right != nullptr)
        {
            traverseInorder(rootNode->right);
        }        
    } 
}

void traversePostorder(ScapeGoatNode* rootNode){
    using namespace std;
    if (rootNode != nullptr)
    {
        if (rootNode->left != nullptr)
        {
            traversePostorder(rootNode->left);
        }
        if (rootNode->right != nullptr)
        {
            traversePostorder(rootNode->right);
        }
        cout << rootNode->key << " --> " << rootNode->object << endl;        
    } 
}

void printBT(const std::string& prefix, const ScapeGoatNode* node, bool isLeft)
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

/* Function to count number of nodes recursively */
int size(ScapeGoatNode *root)
{
    if (root == nullptr)
        return 0;
    else
    {
        int numbers = 1;
        numbers += size(root->left);
        numbers += size(root->right);
        return numbers;
    }
}

int const log32(int q)
{
    double const log23 = 2.4663034623764317;
    return (int)ceil(log23 * log(q));
}

ScapeGoatNode *buildBalanced(ScapeGoatNode **a, int i, int ns)
{
    if (ns == 0)
        return nullptr;
    int m = ns / 2;
    a[i + m]->left = buildBalanced(a, i, m);
    if (a[i + m]->left != NULL)
        a[i + m]->left->parent = a[i + m];
    a[i + m]->right = buildBalanced(a, i + m + 1, ns - m - 1);\
    if (a[i + m]->right != NULL)
        a[i + m]->right->parent = a[i + m];
    return a[i + m];
}

int packIntoArray(ScapeGoatNode *u, ScapeGoatNode *a[], int i)
{
    if (u == NULL)
    {
        return i;
    }
    i = packIntoArray(u->left, a, i);
    a[i++] = u;
    return packIntoArray(u->right, a, i);
}

