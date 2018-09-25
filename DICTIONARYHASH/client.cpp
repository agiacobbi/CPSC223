#include <iostream>
#include <fstream>
#include "key.h"
#include "item.h"
#include "dictionary.h"
using namespace std;

int main()
{
    Dictionary myDictionary;
    Item itemOne;
    fstream inputfile;
    bool isFull = false;
    bool isAlreadyThere = false;

    inputfile.open("in.dat");
    inputfile >> myDictionary;
    cout << myDictionary;
    inputfile >> itemOne;
    cout << itemOne << endl;
    myDictionary.addNewEntry(itemOne, isFull, isAlreadyThere);
    cout << myDictionary;
    inputfile.close();

    return 0;
}
