#include <iostream>
#include <fstream>
#include <string>
#include "binarysearchtree.h"
using namespace std;

void printMenu();
char getOption();
void executeOption(char option, BinarySearchTree& myDictionary);
void loadDictionary(BinarySearchTree& myDictionary);
void findItem(BinarySearchTree& myDictionary);
void insertItem(BinarySearchTree& myDictionary);
void listItems(BinarySearchTree& myDictionary);
void printDictionary(BinarySearchTree& myDictionary);
void rebalanceTree(BinarySearchTree& myDictionary);
void saveToFile();

int main()
{
    char option;
	BinarySearchTree myDictionary;
    printMenu();
    option = getOption();
	executeOption(option, myDictionary);
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
    char newline, userInput;
    cout << "Enter your option > ";
	cin.get(userInput);
    //cin.ignore(userInput);
	cin.get(newline);

    return userInput;
}

void executeOption(char option, BinarySearchTree& myDictionary)
{
    switch (option)
    {
        case 'f':
            findItem(myDictionary);
            break;
        case 'i':
            //insertItem();
            break;
        case 'l':
            //listItems();
            break;
        case 'p':
            //printDictionary();
            break;
        case 'r':
            //rebalanceTree();
            break;
        case 's':
            //saveToFile();
            break;
        case 'e':
            //saveToFile();
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
    inputFile.close();
}

void findItem(BinarySearchTree& myDictionary)
{
	Item anItem;
	Key aKey;
	bool isFound;
	
	//cout << "----- Testing searchForMeaning, searching for key 'lol' -----" << endl;
	cout << endl << "----- Please enter a testing abbreviation you would like to search for: " ;
	cin >> aKey; 
	cout << endl << "----- Searching for: " << aKey << endl; 
	myDictionary.searchForMeaning(aKey, anItem, isFound);

	if (isFound)
		cout << "Found: " << anItem << endl;
	else
		cout << "Not found" << endl;
}

void insertItem(BinarySearchTree& myDictionary)
{
	
}
