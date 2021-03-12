#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <stdexcept> // std::runtime_error
#include <sstream>

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
        void AddData(std::string filename, int isHeading);
        void PrettyPrinting();
        std::pair<int, int> ExtractMax();
};

MaxHeap::MaxHeap(const char nameinput[50]){
    strcpy(name, nameinput);
    root = nullptr;
}

void deleteNode(HeapNode *node){
    if (node != nullptr)
    {
        deleteNode(node->left);
        deleteNode(node->right);
        delete node;
    }
}

MaxHeap::~MaxHeap()
{
    using namespace std;
    deleteNode(root);
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

std::pair <int, int> MaxHeap::ExtractMax(){
    if (root == nullptr) return {-1, -1};

    int key = root->key, object = root->object;

    HeapNode *iter = root;
    HeapNode *prev = nullptr;

    while (iter != nullptr)
    {
        if (iter->left != nullptr && iter->right != nullptr)
        {
            if (iter->left->key > iter->right->key)
            {
                iter->key = iter->left->key;
                iter->object = iter->left->object;
                prev = iter;
                iter = iter->left;
            }
            else
            {
                iter->key = iter->right->key;
                iter->object = iter->right->object;
                prev = iter;
                iter = iter->right;
            }
        }
        else
        {
            if (iter->left != nullptr)
            {
                iter->key = iter->left->key;
                iter->object = iter->left->object;
                prev = iter;
                iter = iter->left;
            }
            else if(iter->right != nullptr){
                iter->key = iter->right->key;
                iter->object = iter->right->object;
                prev = iter;
                iter = iter->right;
            }
            else{
                if (prev == nullptr)
                {
                    delete iter;
                    iter = nullptr;
                    root = nullptr;
                }
                else{
                    prev->left == iter ? (prev->left = nullptr) : (prev->right = nullptr);
                    delete iter;
                    iter = nullptr;
                }
            }
        }
    }
    return {key, object};
}

void MaxHeap::AddData(std::string filename, int isHeading = 1){
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