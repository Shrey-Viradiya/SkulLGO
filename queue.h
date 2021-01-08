#pragma once
#include <iostream>

class Queue
{
private:
    int *queue;
    int front, rear;
    int size;
public :
    Queue();
    Queue(int s);
    ~Queue();
    void enqueue(int n);
    int dequeue();
    void displayItems();
};

Queue::Queue(){
    front = 0;
    rear = 0;
    size = 5;
    queue = new int[size];
}

Queue::Queue(int s){
    front = 0;
    rear = 0;
    size = s;
    queue = new int[size];
}

Queue::~Queue(){ 
    delete[] queue; 
} 

void Queue::enqueue(int n){
    using namespace std;
    if (rear == size)
    {
        // cout << "Queue if Full" << endl;
        if ((rear-front) < size){
            int j = 0;
            for (int i = front; i < rear; i++)
            {
                queue[j++] = queue[i];
            }
            front = 0;
            rear = j;
        }
        else
        {
            // int sizeAdd;
            // do
            // {
            //     cout << "Enter the additional size (positive integer): " << endl;
            //     cin >> sizeAdd;
            // } while (sizeAdd <= 0);

            size += size;
            int *queueNew = new int[size];
            for (int i = front; i <= rear; i++)
            {
                queueNew[i] = queue[i];
            }
            delete[]queue;
            queue = queueNew;
        }
        
    }
    
    queue[rear++] = n;
}

int Queue::dequeue(){
    using namespace std;

    if (front == rear) { 
        cout << "Empty Queue... Returning 0" << endl;
        return 0; 
    } 
    return queue[++front];
}

void Queue::displayItems(){
    using namespace std;
    cout << "Queue \n------------------" << endl;
    cout << "Size: " << size << endl;
    cout << "No of Elements: " << rear-front << endl;
    cout << "Queue Elements \n------------------" << endl; 
    for (int i = front; i < rear; i++)
    {
        cout << queue[i] << " ";
    }    
    cout << "\n------------------\n\n" << endl;    
}