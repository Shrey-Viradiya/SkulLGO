#pragma once
#include<iostream>
#include<utility>

class UnionFind
{
private:
    int elements;
    int *UnionFindArray;
public:
    UnionFind() = delete;
    UnionFind(int elements);
    ~UnionFind();
    int root(int element);
    void join( int x, int y );
    void printStructureArray();
    void printSet(int x);
};

UnionFind::UnionFind(int elements)
{
    this->elements = elements;
    UnionFindArray = new int[elements];
    for (int i = 0; i < elements; i++)
        UnionFindArray[i] = -1;
}

UnionFind::~UnionFind()
{
    delete[]UnionFindArray;
}

int UnionFind::root(int element){
    int root = element;

    /* Find root */
    while(UnionFindArray[root] >= 0)
        root = UnionFindArray[root];

    /* Compress path to root */
    while(UnionFindArray[element] >= 0) {
        int tmp = UnionFindArray[element];
        UnionFindArray[element] = root;
        element = tmp;
    }

    return root;
}

void UnionFind::join( int x, int y ) {
    x = root(x);
    y = root(y);

    if(x != y) {
        if(UnionFindArray[x] < UnionFindArray[y]) {
            UnionFindArray[x] += UnionFindArray[y];
            UnionFindArray[y] = x;
        }
        else {
            UnionFindArray[y] += UnionFindArray[x];
            UnionFindArray[x] = y;
        }
    }
}

void UnionFind::printStructureArray(){
    using namespace std;
    for (int i = 0; i < elements; i++)
        cout << UnionFindArray[i] << " ";
    cout << endl;
}

void UnionFind::printSet(int element){
    using namespace std;
    int r = root(element);
    cout << "Set containing " << element << ": " << endl;
    
    for (int i = 0; i < elements; i++)
        if(root(i) == r) cout << i << " ";
    cout << endl;    
}
