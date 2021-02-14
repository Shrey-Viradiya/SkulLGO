#pragma once
#include <iostream>

// This header file contains the Stack Class implementation for the 
// self growable and self shrinking data structure
// with linked list

class GStack{
private:
    struct Node{
        int key;
        struct Node *next = nullptr;
    };

    int size;
    struct Node *stack;
public:
    GStack();
    ~GStack();
    void push(int n);
    int pop();
    void displayItems();
};

GStack::GStack(){
    size = 0;
    stack = nullptr;
}

GStack::~GStack(){
    while (stack != nullptr)
    {
        struct Node* temp;
        temp = stack;
        stack = stack->next;
        delete temp;
    }    
}

void GStack::push(int n){
    struct Node *newHead = new Node{n, stack};
    stack = newHead;
    ++size;
}

int GStack::pop(){
    using namespace std;
    if(stack == nullptr){
        cout << "Empty Stack... returning zero" << endl;
        return 0;
    }
    struct Node* temp = stack;
    stack = stack->next;
    int tempKey = temp->key;
    delete temp;
    --size;
    return tempKey;
}
 
void GStack::displayItems(){
    using namespace std;
    cout << "Stack \n------------------" << endl;
    cout << "Size: " << size << endl;
    cout << "Stack Elements \n------------------" << endl; 
    struct Node *iter = stack;
    while (iter != nullptr)
    {
        cout << iter->key << " ";
        iter = iter->next;
    }
    cout << "\n------------------\n\n" << endl;    
}