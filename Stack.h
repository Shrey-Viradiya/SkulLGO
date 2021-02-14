#pragma once
#include <iostream>

// This header file contains the Stack Class implementation for the 
// self growable and self shrinking data structure
// with shadow copying

class Stack{
private:
    double threshold;
    int size;
    int top;
    int *stack;
public:
    Stack();
    Stack(int s);
    ~Stack();
    void push(int n);
    int pop();
    int isEmpty();
    int isFull();
    void setThreshold(double t);
    void displayItems();
};

Stack::Stack(){
        threshold = 0.75;
        size = 5;
        top = -1;
        stack = new int[size];
}

Stack::Stack(int s){
        threshold = 0.75;
        size = s;
        top = -1;
        stack = new int[size];
}

Stack::~Stack(){
    delete[]stack;
}

int Stack::isEmpty(){
    if(top==-1)
        return 1;
    else
        return 0;
}

void Stack::setThreshold(double t){
    threshold = t;
}

int Stack::isFull(){
    if(top==(size-1))
        return 1;
    else
        return 0;
}

void Stack::push(int n){
    using namespace std;
    if(top >= threshold*(size-1)){     
        size += size;
        int *stackNew = new int[size];
        for (int i = 0; i <= top; i++)
        {
            stackNew[i] = stack[i];
        }
        delete[]stack;
        stack = stackNew;
    }
    ++top;
    stack[top]=n;
}

int Stack::pop(){
    using namespace std;
    
    if(isEmpty()){
        cout << "Empty Stack.. Returning 0" << endl;
        return 0;
    }
    int temp = stack[top--];
    
    if(top < (1-threshold)*size){
        size = (size / 2) + 1;
        int *stackNew = new int[size];
        for (int i = 0; i <= top; i++)
        {
            stackNew[i] = stack[i];
        }
        delete[]stack;
        stack = stackNew;
    }
    return temp;
}
 
void Stack::displayItems(){
    using namespace std;
    cout << "Stack \n------------------" << endl;
    cout << "Size: " << size << endl;
    cout << "No of Elements: " << top+1 << endl;
    cout << "Stack Elements \n------------------" << endl; 
    for (int i = top; i >= 0; i--)
    {
        cout << stack[i] << " ";
    }    
    cout << "\n------------------\n\n" << endl;    
}
