#include <iostream>
#include "binarysearchtree.h"
using namespace std;

void printMenu();
char getOption();
void executeOption(char option);
void loadDictionary(BinarySearchTree& myDictionary);
void findItem();
void insertItem();
void listItems();
void printDictionary();
void rebalanceTree();
void saveToFile();

int main()
{
    char option;

    printMenu();
    option = getOption();
    return 0;
}

void printMenu()
{
    cout << endl << endl << "Your options are:" << endl <<  endl;
    cout << "f: find" << endl;
    cout << "i: insert" << endl;
    cout << "l: list" << endl;
    cout << "p: print" << endl;
    cout << "r: rebalance" << endl;
    cout << "s: save" << endl;
    cout << "e: exit" << endl << endl;
}

char getOption()
{
    char userInput, newline;

    cout << "Enter your option > ";
    getline(cin, userInput);
    cin.get(newline);

    return userInput;
}

void executeOption(char option)
{
    switch (option)
    {
        case 'f':
            findItem();
            break;
        case 'i':
            insertItem();
            break;
        case 'l':
            listItems();
            break;
        case 'p':
            printDictionary();
            break;
        case 'r':
            rebalanceTree();
            break;
        case 's':
            saveToFile();
            break;
        case 'e':
            saveToFile();
            break;
        default:
            break;
    }
}

void loadDictionary(BinarySearchTree& myDictionary)
{
    ifstream inputFile;

    inputFile.open("dictionary.dat");
    inputFile >> myDictionary;
    inputfile.close();
}
