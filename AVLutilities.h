#pragma once
#include<iostream>

struct AVLnode
{
    int key;
    int object;
    struct AVLnode *left = nullptr;
    struct AVLnode *right = nullptr;
    int balanceFactor;
};

int height(struct AVLnode* node){	
    if(node==nullptr)	
        return 0;	
    else	
    {	
        int lh = height(node->left);	
        int rh = height(node->right);	
        if (lh>rh)	
            return lh+1;	
        else	
            return rh+1;	
    }	
}

int balanceFactor(struct AVLnode* node)	
{	
    return (height(node->left)-height(node->right));	
}

void traversePreorder(struct AVLnode* rootNode){
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

struct AVLnode* rotateRight(struct AVLnode* node)	
{	
    struct AVLnode* newParent = node->left;	
    struct AVLnode* shift = newParent->right;	

    newParent->right =  node;	
    node->left = shift;	

    node->balanceFactor = balanceFactor(node);	
    newParent->balanceFactor = balanceFactor(newParent);	

    return newParent;	
}	

struct AVLnode* rotateLeft(struct AVLnode* node)	
{
    struct AVLnode* newParent = node->right;
    struct AVLnode* shift = newParent->left;	

    newParent->left = node;	
    node->right = shift;	

    node->balanceFactor = balanceFactor(node);	
    newParent->balanceFactor = balanceFactor(newParent);	

    return newParent;	
}

void releaseMemoryTree(struct AVLnode* rootNode){
    if (rootNode != nullptr){
        if (rootNode->left != nullptr)
        {
            releaseMemoryTree(rootNode->left);
        }
        if (rootNode->right != nullptr)
        {
            releaseMemoryTree(rootNode->right);
        }
        delete rootNode;
    }
}

struct AVLnode* insertObject(struct AVLnode* node , int key, int object)
{

    if(node == nullptr){
        node = new struct AVLnode;
        node->key = key;
        node->object = object;
        node->left = nullptr;
        node->right = nullptr;
        return node;
    }
    if(key > node->key )
        node->right = insertObject(node->right, key, object);
    else if (key < node->key )
        node->left = insertObject(node->left, key, object);
    else
    {
        node->object = object;
        std::cout << "Key Found, Object Updated" << std::endl;
        return node;
    }
    node->balanceFactor=balanceFactor(node);

    if(
        node->balanceFactor > 1 
        && 
        key < node->left->key 
        )
        return rotateRight(node);
    else if(
        node->balanceFactor <-1 
        && 
        key > node->right->key
        )
        return rotateLeft(node);
    else if(
        node->balanceFactor>1
        &&
        key > node->left->key
        )
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }    
    else if(
        node->balanceFactor<-1
        &&
        key > node->right->key
        )
    {
        node->left = rotateRight(node->right);
        return rotateLeft(node);
    }    

    return node;
}