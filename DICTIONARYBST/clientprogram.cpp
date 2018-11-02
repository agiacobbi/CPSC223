#include <iostream>
#include <fstream>
#include <string>
#include "binarysearchtree.h"
using namespace std;

void printBreakLine();
void printMenu();
char getOption();
bool isValidOption(char input, string restOfInput);
bool isValidKey(string restOfInput);
void printOptionHeader(char option);
void executeOption(char option, BinarySearchTree& aDictionary);
void loadDictionary(BinarySearchTree& aDictionary);
void deleteItem(BinarySearchTree& aDictionary);
void findItem(BinarySearchTree& aDictionary);
void insertItem(BinarySearchTree& aDictionary);
void listItems(BinaryTree aDictionary);
void printDictionary(BinarySearchTree& aDictionary);
void rebalanceTree(BinarySearchTree& aDictionary);
void saveToFile(BinarySearchTree& aDictionary);


int main()
{
    char option;
	BinarySearchTree userDictionary;
    
    loadDictionary(userDictionary);

    do
    {
		printBreakLine();
        option = getOption();
		printBreakLine();
        executeOption(option, userDictionary);		
    } while (option != 'e');

	cout << "Goodbye." << endl << endl;
	
    return 0;
}

void printBreakLine()
{
	for (int i = 0; i < 80; i++)
		cout << '-';
	cout << endl;
}

void printMenu()
{
    cout << "Your options are:" << endl <<  endl;
	cout << "d: delete an item from the tree given the text" << endl;
    cout << "f: find the meaning of a texting abbreviation, given the text" << endl;
    cout << "i: insert a new item (texting abbreviation and meaning) into the dictionary" << endl;
    cout << "l: list the items in the entire dictionary on the screen in inorder fashion" << endl;
    cout << "p: print the tree in pretty fashion (showing only the texts)" << endl;
    cout << "r: rebalance the tree" << endl;
    cout << "s: save the dictionary to the file in sorted order - inorder - ready to be read" << endl;
    cout << "e: exit the program which automatically does option s" << endl << endl;
}

char getOption()
{
    char userInput;
	string restOfInput;

	printMenu();
	cout << "Enter your option as a single character then press Enter" << endl;
	cout << "     EXAMPLE-> f\n" << endl;
	
    do {
        cout << "Enter your option > ";
        cin.get(userInput);
		getline(cin, restOfInput);
    } while (!isValidOption(userInput, restOfInput));
	
	cout << endl;

    return userInput;
}

bool isValidOption(char input, string restOfInput)
{
	if (restOfInput.length() > 1)
	{
		cout << endl << "ERROR: Input too long. Please enter one of the listed options as a SINGLE character" << endl << endl;
		return false;
	}
    switch (input)
    {
		case 'd':
			return true;
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
			cout << endl << "ERROR: Invalid input. Please enter one of the listed options as a SINGLE character" << endl << endl;
            return false;
    }
}

bool isValidKey(string restOfInput)
{
	if (restOfInput.length() > 1)
		return false;
	return true;
}

void printOptionHeader(char option)
{
	cout << "SELECTED OPTION: ";
	switch (option)
	{
		case 'd':
			cout << "Delete Entry" << endl << endl;
			break;
		case 'f':
			cout << "Find Item" << endl << endl;
			break;
		case 'l':
			cout << "List Items" << endl << endl;
			break;
		case 'p':
			cout << "Print Tree" << endl << endl;
			break;
		case 'r':
			cout << "Rebalance Tree" << endl << endl;
			break;
		case 's':
			cout << "Save Tree" << endl << endl;
			break;
		case 'e':
			cout << "Exit" << endl << endl;
			break;
		default:
			break;
	}
}

void executeOption(char option, BinarySearchTree& aDictionary)
{
    printOptionHeader(option);

    switch (option)
    {
		case 'd':
			deleteItem(aDictionary);
			break;
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
    inputFile.close();
}

void deleteItem(BinarySearchTree& aDictionary)
{
	Key delItem;
	string restOfInput;

	cout << endl << "What texting abbreviation would you like to delete?" << endl;
	cout << "Type a single abbreviation and press Enter" << endl;
	cout << "     EXAMPLE-> lol\n" << endl;

	do {
	cout << "Enter an item to delete > ";
	cin >> delItem;
	getline(cin, restOfInput);
	} while (!isValidKey(restOfInput));

	cout << endl << "Deleting " << delItem << "..."  << endl;

	try {
		aDictionary.deleteEntry(delItem);
	} catch (Exception e) {
		cout << endl << e.what() << endl << endl;
	}
}

void findItem(BinarySearchTree& aDictionary)
{
	Item anItem;
	Key aKey;
	bool isFound;
	string restOfInput;
	
	cout << endl << "What texting abbreviation would you like to search for?" << endl;
	cout << "Type a single abbreviation and press Enter" << endl;
	cout << "     EXAMPLE-> lol\n" << endl;
	
	do {
	cout << "Enter an abbreviation to search for > ";
	cin >> aKey;
	getline(cin, restOfInput);
	} while (!isValidKey(restOfInput));
	
	cout << endl << "Searching for " << aKey << "..." << endl; 
	aDictionary.searchForMeaning(aKey, anItem, isFound);

	if (isFound)
		cout << "Found: " << anItem << endl;
	else
		cout << aKey << " was not found in the dictionary" << endl;
}

void insertItem(BinarySearchTree& aDictionary)
{
	string restOfInput;	
	Item anItem;
	
	cout << "What item would you like to add to the dictionary" << endl;
	
	cout << "Type an abbreviation, followed by a space, followed by its meaning. When you are finished, press Enter" << endl;
	cout << "     EXAMPLE-> lol laugh out loud\n" << endl; 
	cout << "Enter an item to add > ";
	cin >> anItem;

	try {
		aDictionary.addNewEntry(anItem);
	} 
	catch(Exception e) {
		cout << endl << e.what() << endl << endl;
	}
}

void listItems(BinaryTree aDictionary)
{
	aDictionary.inorderTraverse();
}

void printDictionary(BinarySearchTree& aDictionary)
{
	cout << endl;
	aDictionary.prettyDisplay();
	cout << endl;
}

void rebalanceTree(BinarySearchTree& aDictionary)
{
	ifstream inputFile;
	ofstream outputFile;
	
	cout << endl << "Rebalancing the tree..." << endl << endl;
	
	outputFile.open("dictionary.dat");
	aDictionary.inorderTraverse(outputFile);
	outputFile.close();
	
	inputFile.open("dictionary.dat");
	aDictionary.rebalanceTree(inputFile);
	inputFile.close();
}

void saveToFile(BinarySearchTree& aDictionary)
{
	ofstream outputFile;
	
	cout << endl << "Saving to file dictionary.dat..." << endl << endl;
	
	outputFile.open("dictionary.dat");
	aDictionary.inorderTraverse(outputFile);
	outputFile.close();
}
