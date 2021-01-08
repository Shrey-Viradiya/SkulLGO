#include "stack.h"
#include "queue.h"
#include <iostream>

int main(){
    using namespace std;

    cout << "-----------Stack-----------" << endl;
    
    Stack s;
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);
    s.push(25);
    s.displayItems();
    s.pop();
    s.pop();
    s.displayItems();
    s.push(255);
    s.push(365);
    s.push(785);
    s.displayItems();

    cout << "-----------Queue-----------" << endl;

    Queue q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);
    q.enqueue(25);
    q.displayItems();
    q.dequeue();
    q.dequeue();
    q.displayItems();
    q.enqueue(255);
    q.enqueue(365);
    q.enqueue(785);
    q.displayItems();
    return 0;
}