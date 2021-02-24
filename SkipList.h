#include<iostream>
#include <cstring>
#include <cstdlib>

class SkipListNode{
        int key;
        int object;
    public:
        SkipListNode **forwards;
    
        SkipListNode() = delete;
        SkipListNode(int levels, int k, int o){
            forwards = new SkipListNode*[levels + 1];
            for (int i = 0; i <= levels; i++) forwards[i] = nullptr;
            key = k;
            object = o;
        }
        ~SkipListNode(){
            delete [] forwards;
        }
        int getKey(){
            return key;
        }
        int getObject(){
            return object;
        }
};

class SkipList{
    public:
        char name[50];
        const int level_limit;
        SkipListNode **InitialLinks;

        SkipList(const char nameinput[50], int limit);
        ~SkipList();
        int Search(int key);
        void insertNode(int key, int object);
        void deleteNode(int key);
        void Display();
};

SkipList::SkipList(const char nameinput[50], const int limit) : level_limit(limit){
    strcpy(name, nameinput);
    InitialLinks = new SkipListNode*[level_limit];
    for (int i = 0; i < level_limit; i++) InitialLinks[i] = nullptr;
}

SkipList::~SkipList(){
    delete [] InitialLinks;
    using namespace std;
    cout << "Memory Released of " << name << endl;
}

void SkipList::insertNode(int key, int object){

    // Keep a list of search path for updating
    SkipListNode **update;
    for (int i = 0; i < level_limit; i++) update[i] = nullptr;
    int upperLimit = 0;
    SkipListNode *iterator = nullptr;
    for (int i = level_limit - 1; i >= 0; i--)
    {
        if (InitialLinks[i] != nullptr && InitialLinks[i]->getKey() < key)
        {
            iterator = InitialLinks[i];
            upperLimit = i;
            break;
        }
        *update[i] = *InitialLinks[i];
    }

    if (iterator == nullptr)
    {
        int randomNumber = (int)((rand()*level_limit)/RAND_MAX);
        SkipListNode *newNode = new SkipListNode(randomNumber, key, object);
        
        for (int i = 0; i <= randomNumber; i++)
        {
            if (update[i] != nullptr){
                newNode->forwards[i] = update[i]->forwards[i];
                update[i]->forwards[i] = newNode;
            }
            else{
                newNode->forwards[i] = nullptr;
                update[i] = newNode;
            }
        }
    }
    else{
        for (int i = upperLimit; i >= 0; i--)
        {
            while (iterator->forwards[i] != nullptr && iterator->forwards[i]->getKey() < key)
            {
                iterator = iterator->forwards[i];
            }
            update[i] = iterator;
        }
        int randomNumber = (int)((rand()/RAND_MAX) * (level_limit));
        SkipListNode *newNode = new SkipListNode(randomNumber, key, object);

        for (int i = 0; i <= randomNumber; i++)
        {
            if (update[i] != nullptr){
                newNode->forwards[i] = update[i]->forwards[i];
                update[i]->forwards[i] = newNode;
            }
            else{
                newNode->forwards[i] = nullptr;
                update[i] = newNode;
            }
        }
    }
}

void SkipList::Display(){
    using namespace std;
    cout << "Skip List: " << name << endl;
    cout << "=================================" << endl;

    SkipListNode *iterator = InitialLinks[0];
    while (iterator != nullptr)
    {
        cout << "( "<< iterator->getKey() << ", " << iterator->getObject() << " ) -->" << endl;
    }
}