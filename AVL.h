#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <vector>
#include <stdexcept> // std::runtime_error
#include <sstream>
#include "AVLutilities.h"
// This header file contains the code for AVL self balancing tree

class AVL
{
    private:
        char name[50];
        struct AVLnode *root;
    public:
        AVL() = delete;
        AVL(const char n[50]);
        ~AVL();
        void AddData(std::string filename, int isHeading);
        void insert(int key, int object);
        void traverse(int mode);
        void deleteKey(int key);
        int search(int key);
        void PrettyPrinting();
        std::pair<AVL*, AVL* > splitAtRoot();
        std::pair<AVL*, AVL*> splitAtKey(int key);
        void setRoot(struct AVLnode *node);
};

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

void AVL::insert(int key, int object){
    root = insertObject(root, key, object);
}

int AVL::search(int key){
    struct AVLnode* node = root;

    while (node)
    {
        if (node->key == key)
        {
            return node->object;
        }
        else if(key < node->key){
            node = node->left;
        }
        else{
            node = node->right;
        }
    }
    return 0;    
}

void AVL::AddData(std::string filename, int isHeading = 1){
    using namespace std;
    // working with csv in CPP
    // https://www.gormanalysis.com/blog/reading-and-writing-csv-files-with-cpp/

    ifstream myFile(filename);
    // if(!myFile.is_open()) throw runtime_error("Could not open file");

    string line, word;
    int val;

    if (isHeading)  getline(myFile, line);

    // Read data, line by line
    while(getline(myFile, line))
    {
        // Create a stringstream of the current line
        stringstream ss(line);
        pair<int, int> data; 
        
        // add the column data 
        // of a row to a pair
        getline(ss, word, ',');
        data.first = stoi(word);

        getline(ss, word, ',');
        data.second = stoi(word);

        insert(data.first, data.second);
    }

    // Close file
    myFile.close();
}

void AVL::traverse(int mode = 1){
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

void AVL::PrettyPrinting(){
    std::cout << "---------------------------------" << std::endl;
    std::cout << "\t" << name << std::endl;
    std::cout << "---------------------------------" << std::endl;
    printBT("", root, false);
}

void AVL::deleteKey(int key){
    root = delete_node(root, key);
}

void AVL::setRoot(struct AVLnode *node){
    root = node;
}

std::pair<AVL*, AVL*> AVL::splitAtRoot(){
    struct AVLnode *leftTree = root->left;
    struct AVLnode *rightTree = root->right;

    char nameleft[50], nameright[50];

    int i=0;
    while (name[i]!='\0')
    {
        nameleft[i] = name[i];
        nameright[i] = name[i];
        i++;
    }
    nameleft[i] = ':';
    nameright[i] = ':';
    nameleft[i+1] = 'L';
    nameright[i+1] = 'R';
    nameleft[i+2] = '\0';
    nameright[i+2] = '\0';
    
    AVL *leftAVL = new AVL(nameleft);
    AVL *rightAVL = new AVL(nameright);
    leftAVL->setRoot(leftTree);
    rightAVL->setRoot(rightTree);

    root->left = nullptr;
    root->right = nullptr;

    leftAVL->insert(root->key, root->object);

    std::pair<AVL*, AVL*> returnPair(leftAVL, rightAVL);

    return returnPair;
}

std::pair<AVL*, AVL*> AVL::splitAtKey(int key){
    if(key == root->key){
        std::cout<<"Here"<<std::endl;
        return splitAtRoot();
    }

    AVLnode *lessThan[100];
    int lessThanTop = -1;
    AVLnode *greaterThan[100];
    int greaterThanTop = -1;

    AVLnode* iterator = root;
    
    while (iterator != nullptr && iterator->key != key)
    {
        if (iterator->key > key)
        {
            if (iterator->right != nullptr)
                greaterThan[++greaterThanTop] = iterator->right;
            iterator->right = nullptr;
            greaterThan[++greaterThanTop] = iterator;
            iterator = iterator->left;
            greaterThan[greaterThanTop]->left = nullptr;
        }
        else if(iterator->key < key)
        {
            if (iterator->left != nullptr)
                lessThan[++lessThanTop] = iterator->left;
            iterator->left = nullptr;
            lessThan[++lessThanTop] = iterator;
            iterator = iterator->right;
            lessThan[lessThanTop]->right = nullptr;
        }      
    }

    if (iterator != nullptr && iterator->key == key)
    {
        if (iterator->right != nullptr)
            greaterThan[++greaterThanTop] = iterator->right;
        if (iterator->left != nullptr)
            lessThan[++lessThanTop] = iterator->left;
        lessThan[++lessThanTop] = iterator;
        iterator->left = nullptr;
        iterator->right = nullptr;
    }

    AVLnode *leftTreeNode = nullptr;
    
    for (int i = 0; i <= lessThanTop; i++)
    {
        leftTreeNode = insertObjectDr(leftTreeNode, lessThan[i]);
    }

    AVLnode *rightTreeNode = nullptr;
    
    for (int i = 0; i <= greaterThanTop; i++)
    {
        rightTreeNode = insertObjectDr(rightTreeNode, greaterThan[i]);
    }

    char nameleft[50], nameright[50];

    int i=0;
    while (name[i]!='\0')
    {
        nameleft[i] = name[i];
        nameright[i] = name[i];
        i++;
    }
    nameleft[i] = ':';
    nameright[i] = ':';
    nameleft[i+1] = 'L';
    nameright[i+1] = 'R';
    nameleft[i+2] = '\0';
    nameright[i+2] = '\0';
    
    AVL *leftAVL = new AVL(nameleft);
    AVL *rightAVL = new AVL(nameright);
    leftAVL->setRoot(leftTreeNode);
    rightAVL->setRoot(rightTreeNode);

    root = nullptr;

    std::pair<AVL*, AVL*> returnPair(leftAVL, rightAVL);

    return returnPair;
}
