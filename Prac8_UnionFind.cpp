#include "UnionFind.h"
#include <iostream>

int main(){
    using namespace std;
    UnionFind UF = UnionFind(10);

    // UF.printStructureArray();
    UF.printSet(1);

    cout << "\nJoining Element 1 and 2" << endl;
    UF.join(1,2);
    UF.printSet(1);
    // UF.printStructureArray();    

    cout << "\nJoining Element 3 and 4" << endl;
    UF.join(3,4);
    UF.printSet(3);
    // UF.printStructureArray();

    cout << "\nJoining Element 4 and 2" << endl;
    UF.join(4,2);
    UF.printSet(1);
    // UF.printStructureArray();

    return 0;
}