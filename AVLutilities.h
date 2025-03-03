#pragma once
#include<iostream>
#include<utility>

struct AVLnode
{
    int key;
    int object;
    struct AVLnode *left = nullptr;
    struct AVLnode *right = nullptr;
    int balanceFactor = 0;
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

void traverseInorder(struct AVLnode* rootNode){
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

void traversePostorder(struct AVLnode* rootNode){
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

struct AVLnode* insertObjectDr(struct AVLnode* node , struct AVLnode* nodeInsert)
{

    if(node == nullptr){
        node = nodeInsert;
        return node;
    }
    if(nodeInsert->key > node->key)
        node->right = insertObjectDr(node->right, nodeInsert);
    else if (nodeInsert->key < node->key )
        node->left = insertObjectDr(node->left, nodeInsert);

    node->balanceFactor=balanceFactor(node);

    if(
        node->balanceFactor > 1 
        && 
        nodeInsert->key < node->left->key 
        )
        return rotateRight(node);
    else if(
        node->balanceFactor <-1 
        && 
        nodeInsert->key > node->right->key
        )
        return rotateLeft(node);
    else if(
        node->balanceFactor>1
        &&
        nodeInsert->key > node->left->key
        )
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }    
    else if(
        node->balanceFactor<-1
        &&
        nodeInsert->key < node->right->key
        )
    {
        node->right  = rotateRight(node->right);
        return rotateLeft(node);
    }    

    return node;
}

std::pair<int, int> findMin(struct AVLnode* root)
{
    while(root->left != nullptr) 
        root = root->left;
    std::pair<int, int> k {root->key, root->object};
    return k;
}

struct AVLnode* delete_node(struct AVLnode* node, int key)
{
    if(node==nullptr)  {
        std::cout << "Tree is empty" << std::endl;
        return node;
    }
    else if (key < node->key)
    {
        node->left = delete_node(node->left, key);
    }
    else if(key > node->key)
    {
        node->right = delete_node(node->right, key);
    }
    else  // value found
    {
        if( (node->left == nullptr) || 
            (node->right == nullptr) )  
        {  
            struct AVLnode * temp = node->left ?  
                         node->left :  
                         node->right;  
  
            if (temp == nullptr)  
            {  
                temp = node;  
                node = nullptr;  
            }  
            else 
            *node = *temp; 
            free(temp);  
        }  
        else
        {
            std::pair<int, int> minimum = findMin(node->right);
            node->key = minimum.first;
            node->object = minimum.second;
            node->right = delete_node(node->right, minimum.first);
        }
    }

    if (node == nullptr) 
      return node; 
   
    node->balanceFactor=balanceFactor(node);

    int balance = node->balanceFactor;

    if(
        balance>1
        &&
        (node->left)->balanceFactor>=0         
    )
    {
        return rotateRight(node);
    }
        
    else if(
            balance<-1
            &&
            (node->right)->balanceFactor<=0 
        ){
            return rotateLeft(node);
        }
        
    else if(
        balance > 1
        &&
        (node->left)->balanceFactor<0       
        )
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }    
    else if(
        balance <-1
        &&
        (node->right)->balanceFactor>0
        )
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }    
        return node;
}

void printBT(const std::string& prefix, const AVLnode* node, bool isLeft)
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