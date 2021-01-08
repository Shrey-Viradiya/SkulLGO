#pragma once
#include <iostream>

class Stack{
private:
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
    void displayItems();
};

Stack::Stack(){
        size = 5;
        top = -1;
        stack = new int[size];
}

Stack::Stack(int s){
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

int Stack::isFull(){
    if(top==(size-1))
        return 1;
    else
        return 0;
}

void Stack::push(int n){
    using namespace std;
    if(isFull()){
        cout << "Stack is Full" << endl;
        // int sizeAdd;
        // do
        // {
        //     cout << "Enter the additional size (positive integer): " << endl;
        //     cin >> sizeAdd;
        // } while (sizeAdd <= 0);
        
        
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
    return stack[top--];
}
 
void Stack::displayItems(){
    using namespace std;
    cout << "Stack \n------------------" << endl;
    cout << "Size: " << size << endl;
    cout << "No of Elements: " << top+1 << endl;
    cout << "Stack Elements \n------------------" << endl; 
    for (int i = 0; i <= top; i++)
    {
        cout << stack[i] << " ";
    }    
    cout << "\n------------------\n\n" << endl;    
}