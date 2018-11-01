#include <iostream>
#include "binarysearchtree.h"
using namespace std;

void printMenu();
char getOption();
void executeOption(char option, BinarySearchTree& aDictionary);
void loadDictionary(BinarySearchTree& aDictionary);
void findItem(BinarySearchTree& aDictionary);
void insertItem(BinarySearchTree& aDictionary);
void listItems(BinarySearchTree& aDictionary);
void printDictionary(BinarySearchTree& aDictionary);
void rebalanceTree(BinarySearchTree& aDictionary);
void saveToFile(BinarySearchTree& aDictionary);

int main()
{
    char option;
    BinarySearchTree userDictionary;

    loadDictionary(userDictionary);

    while (option != 'e')
    {
        printMenu();
        option = getOption();
        executeOption(e);
    }
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

    do {
        cout << "Enter your option > ";
        getline(cin, userInput);
        cin.get(newline);
    } while (!isValidInput(userInput));

    return userInput;
}

bool isValidInput(char input)
{
    switch (input)
    {
        case 'f':
            return true;
        case 'i':
            return true;
        case 'l':
            return true;
        case 'p':
            return true;
        case 'r':
            return true;
        case 's':
            return true;
        case 'e':
            return true;
        default:
            return false;
    }
}

void executeOption(char option, BinarySearchTree& aDictionary)
{
    switch (option)
    {
        case 'f':
            findItem(aDictionary);
            break;
        case 'i':
            insertItem(aDictionary);
            break;
        case 'l':
            listItems(aDictionary);
            break;
        case 'p':
            printDictionary(aDictionary);
            break;
        case 'r':
            rebalanceTree(aDictionary);
            break;
        case 's':
            saveToFile(aDictionary);
            break;
        case 'e':
            saveToFile(aDictionary);
            break;
        default:
            break;
    }
}

void loadDictionary(BinarySearchTree& aDictionary)
{
    ifstream inputFile;

    inputFile.open("dictionary.dat");
    aDictionary.rebalanceTree(inputFile);
    inputfile.close();
}

void findItem(BinarySearchTree& aDictionary)
{

}

void insertItem(BinarySearchTree& aDictionary)
{

}

void listItems(BinarySearchTree& aDictionary)
{

}

void printDictionary(BinarySearchTree& aDictionary)
{

}

void rebalanceTree(BinarySearchTree& aDictionary)
{

}

void saveToFile(BinarySearchTree& aDictionary)
{

}