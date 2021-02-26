#pragma once
#include <iostream>
#include <stdexcept> // std::runtime_error
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>

class Node
{
public:
    Node* next = nullptr;
    int key;
    int object;
    ~Node(){
        delete next;
    }
};

class LinkedList
{
public:
    int length;
    Node* head;

    LinkedList();
    ~LinkedList();
    void add(int key, int object);
    void print();
    int search(int key);
    void AddData(std::string filename, int isHeading);
};

LinkedList::LinkedList(){
    this->length = 0;
    this->head = nullptr;
}

LinkedList::~LinkedList(){
    delete head;
    std::cout << "LIST DELETED" << std::endl;
}

void LinkedList::add(int key, int object){
    Node* node = new Node();
    node->key = key;
    node->object = object;
    node->next = nullptr;
    
    if (this->head == nullptr)
    {
        this->head = node;
        head->next = nullptr;
    }
    else if(this->head->next == nullptr ){
        if (this->head->key >= key)
        {
            node->next = head;
            head = node;
        }
        else{
            head->next = node;
        }      
    }
    else{        
        Node* iter = this->head;
        while (iter->next != nullptr && iter->next->key < key)
        {
            iter = iter->next;
        }
        if (iter == head && head->key >= key)
        {
            node->next = head;
            head = node;
            length++;
            return;
        }

        node->next = iter->next;
        iter->next = node;       
    }    

    this->length++;
}

int LinkedList::search(int key){
    Node* head = this->head;
    
    while (head->key < key)
    {
        head = head->next;
    }
    if(head == nullptr){
        return -1;
    }
    if (head->key == key)
    {
        return head->object;
    }
    else{
        return -1;
    }
    
}

void LinkedList::print(){
    Node* head = this->head;
    while(head){
        std::cout << "( " << head->key << ", " << head->object << " ) -->";
        head = head->next;
    }
    std::cout << std::endl;
}

void LinkedList::AddData(std::string filename, int isHeading){
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

        add(data.first, data.second);
    }

    // Close file
    myFile.close();
}