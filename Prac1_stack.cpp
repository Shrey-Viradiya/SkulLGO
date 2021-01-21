#include "Stack.h"
#include "GStack.h"
#include <iostream>

int main(){
    using namespace std;

    cout << "-----------Stack-----------" << endl;
    cout << "-----------Shadow Copy-----------" << endl;
    
    Stack s;
    cout << "-----------Normal Push-----------" << endl;
    s.push(5);
    s.push(10);
    s.push(15);
    s.push(20);
    s.displayItems();
    cout << "-----------Crossing Threshold-----------" << endl;
    s.push(25);
    cout << "-----------Displaying-----------" << endl;
    s.displayItems();
    cout << "-----------Pop-----------" << endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout << "-----------Underflow-----------" << endl;
    s.pop();
    s.displayItems();
    s.push(255);
    s.push(365);
    s.push(785);
    s.push(856);
    s.displayItems();
    s.push(999);
    s.push(1000);
    s.push(9658);
    s.push(2511);
    s.displayItems();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.displayItems();

    cout << "-----------Stack-----------" << endl;
    cout << "-----------Self Growing-----------" << endl;
    
    GStack gs;
    gs.push(5);
    gs.push(10);
    gs.push(15);
    gs.push(20);
    gs.push(25);
    gs.displayItems();
    gs.pop();
    gs.pop();
    gs.pop();
    gs.pop();
    gs.displayItems();
    gs.push(255);
    gs.push(365);
    gs.push(785);
    gs.push(856);
    gs.displayItems();
    gs.push(999);
    gs.push(1000);
    gs.push(9658);
    gs.displayItems();
    gs.pop();
    gs.pop();
    gs.pop();
    gs.pop();
    gs.pop();
    gs.displayItems();

    return 0;
}