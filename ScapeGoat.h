#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <vector>
#include <stdexcept> // std::runtime_error
#include <sstream>
#include "ScapeGoatUtilities.h"
// This header file contains the code for ScapeGoat tree


class ScapeGoat
{
    private:
        char name[50];
        int n, q;
        ScapeGoatNode *root;
    public:
        ScapeGoat(const char n[50]);
        ~ScapeGoat();
        void AddData(std::string filename, int isHeading);
        void insert(int key, int object);
        void traverse(int mode);
        void deleteKey(int key);
        int search(int key);
        void PrettyPrinting();
};

ScapeGoat::ScapeGoat(const char n[50]){
    strcpy(name, n);
    n = 0;
    q = 0;
    root = nullptr;
}

ScapeGoat::~ScapeGoat()
{
    using namespace std;
    delete root;
    cout << "Memory Released of " << name << endl;
}

int ScapeGoat::search(int key){
    ScapeGoatNode* node = root;

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

void ScapeGoat::AddData(std::string filename, int isHeading = 1){
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

void ScapeGoat::traverse(int mode = 1){
    using namespace std;

    cout << "\n\nPrinting The ScapeGoatTree: " << name << endl;
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

void ScapeGoat::PrettyPrinting(){
    printBT("", root, false);
}

void ScapeGoat::insert(int k, int o){ 
    ScapeGoatNode *newnode = new ScapeGoatNode(k, o);

    ScapeGoatNode *iter = root;
    if (iter == nullptr)
    {
        root = newnode;
        n++;
        q++;
        return;
    }

    bool done = false;
    int d = 0;
    do
    {
        if (newnode->key < iter->key)
        {
            if (iter->left == nullptr)
            {
                iter->left = newnode;
                newnode->parent = iter;
                done = true;
            }
            else
            {
                iter= iter->left;
            }
        }
        else if (newnode->key > iter->key)
        {
            if (iter->right == nullptr)
            {
                iter->right = newnode;
                newnode->parent = iter;
                done = true;
            }
            else
            {
                iter = iter->right;
            }
        }
        else
        {
            iter->object = newnode->object;
            delete newnode;
            return;
        }
        d++;
    }
    while (!done);
    n++;
    q++;
    
    if (d > log32(q))
    {
        ScapeGoatNode *iter2 = newnode->parent;
        while (3 * size(iter2) <= 2 * size(iter2->parent))
            iter2 = iter2->parent;

        ScapeGoatNode *u = iter2->parent;
        int ns = size(u);
        ScapeGoatNode *p = u->parent;
        ScapeGoatNode **a = new ScapeGoatNode* [ns];
        packIntoArray(u, a, 0);
        if (p == nullptr)
        {
            root = buildBalanced(a, 0, ns);
            root->parent = nullptr;
        }
        else if (p->right == u)
        {
            p->right = buildBalanced(a, 0, ns);
            p->right->parent = p;
        }
        else
        {
            p->left = buildBalanced(a, 0, ns);
            p->left->parent = p;
        }
    }
}