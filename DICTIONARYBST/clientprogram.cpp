// filename: clientprogram.cpp
// Alex Giacobbi and Jalen Tacsiat
// agiacobbi
// date: 11/1/18
// filename: clientprogram.cpp
// description: This is the client program that allows users to create and interact with a dictionary
//              of texting abbreviations. The dictionary's data structure is a BinarySearchTree object.
//              This will allow the user to insert, search, and delete items in logarithmic
//              time (very fast). When the program starts, a menus of options is displayed for the user.
//              The user is allowed to select an option by inputting a single character. When a 
//              good option is inputted, the program executes the option and walks the user through any
//              necessary steps. The items for the dictionary are loaded automatically at the beginning of
//              the program from the file dictionary.dat which contains the number of items at the top followed
//              by each item (one per line) in alphabetical order. When the program is closed, the 
//              updated dictionary is automatically written to dictionary.dat. All user inputs are validated
//              through error handling functions and give user-friendly errors. All exceptions are written
//              with user-friendly messages.

#include <iostream>
#include <fstream>
#include <string>
#include "binarysearchtree.h"
using namespace std;

// printing a line at the beginning of the screen to make the program easier to read
// pre: none
// post: a line is printed at theb top of the screen
// usage: printBreakLine(); 
void printBreakLine();

// prints the menu with the options the user can pick 
// pre: none
// post: menu is printed to the screen
// usage: printMenu();
void printMenu();

// gets the input from the user
// pre: user enters an option
// post: returns the char the user entered
// usage: getOption();
char getOption();

// checks to see if the user entered a valid option
// pre: user enters a character 
// post: returns true if the user entered a valid option
//       else: returns false and throws an error if userInput if the 
//             user enters more than 1 character or if they enter an invalid input
// usage: isValidOption(userInput, extraInputs)
bool isValidOption(char input, string restOfInput);

// checks to see if the user enters a single key and only a key 
// pre: rest of input is a string of characters following the first key entered
// post: returns false if the user enters characters other than the newline after key
// usage: isValidKey(extraCharacters); 
bool isValidKey(string restOfInput);

// prints out a header based on the option the user selects
// pre: option is a valid option
// post: header is printed to the screen. Example: 
//       SELECTED OPTION: Find Item
// usage: printOptionHeader(userOption);
void printOptionHeader(char option);

// executes option selected by the user 
// pre: option is a valid option and a dictionary is a binarysearchtree object
// post: executes the option selected by the user
// usage: executeOption(userOption, myDictionary);
void executeOption(char option, BinarySearchTree& aDictionary);

// loads the dictionary into the program
// pre: BinarySearchTree aDictionary object exists
// post: loads items from dictionary.dat into binarysearchtree object aDictionary 
//       creating a balanced binarysearchtree
// usage: loadDictionary(aDictionary);
void loadDictionary(BinarySearchTree& aDictionary);

// walks user through the delete process for the delete item option 
// pre: aDictionary exists and is a BinarySearchTree object
// post: deletes item specified by user and restricts user items that are leaves and items with 
// one child
// usage: deleteItem(aDictionary);
void deleteItem(BinarySearchTree& aDictionary);

// allows user to search for an item in the dictionary
// pre: aDictionary exists and is a BinarySearchTree object
// post: outputs the texting abbreviation and meaning if found in the dictionary else 
//       outputs not found
// usage: findItem(aDictionary);
void findItem(BinarySearchTree& aDictionary);

// allows user to insert an item continaing a texting abbreviation and its meaning
// pre: aDictionary exists and is a BinarySearchTree object
// post: the item specified by user is inserted into the dictionary else throws an exception
// usage: insertItem(aDictionary);
void insertItem(BinarySearchTree& aDictionary);

// lists the items in the dictionary in alphabetical order
// pre: aDictionary is a BinaryTree object that is equal to the dictionary binarysearchtree 
// post: items in a dictionary are printed using BinaryTree's inorderTraverse
// usage: listItems(myDictionary);
void listItems(BinaryTree aDictionary);

// prints the structure of the binarysearchtree in pretty fashion
// pre: aDictionary exists and is a BinarySearchTree object
// post: items in the dictionary are printed and structure is shown
// usage: printDictionary(aDictionary);
void printDictionary(BinarySearchTree& aDictionary);

// rebalances the binarysearchtree
// pre: aDictionary exists and is a BinarySearchTree object
// post: items in the dictionary are rebalanced
// usage: rebalanceTree(aDictionary);
void rebalanceTree(BinarySearchTree& aDictionary);

// saves the dictionary to a file
// pre: aDictionary exists and is a BinarySearchTree object
// post: dictionary is saved to a file
// usage: saveToFile(aDictionary);
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

// printing a line at the beginning of the screen to make the program easier to read
// pre: none
// post: a line is printed at theb top of the screen
// usage: printBreakLine(); 
void printBreakLine()
{
	for (int i = 0; i < 80; i++)
		cout << '-';
	cout << endl;
}

// prints the menu with the options the user can pick 
// pre: none
// post: menu is printed to the screen
// usage: printMenu();
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

// gets the input from the user
// pre: user enters an option
// post: returns the char the user entered
// usage: getOption();
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

// checks to see if the user entered a valid option
// pre: user enters a character 
// post: returns true if the user entered a valid option
//       else: returns false and throws an error if userInput if the 
//             user enters more than 1 character or if they enter an invalid input
// usage: isValidOption(userInput, extraInputs)
bool isValidOption(char input, string restOfInput)
{
	if (restOfInput.length() > 1)
	{
		cout << endl << "ERROR: Uh-oh, looks like that input is too long.\nPlease enter one of the listed options as a SINGLE character" << endl << endl;
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
			cout << endl << "ERROR: Uh-oh, that wasn't one of the options.\nPlease enter one of the listed options as a SINGLE character" << endl << endl;
            return false;
    }
}

// checks to see if the user enters a single key and only a key 
// pre: rest of input is a string of characters following the first key entered
// post: returns false if the user enters characters other than the newline after key
// usage: isValidKey(extraCharacters); 
bool isValidKey(string restOfInput)
{
	if (restOfInput.length() > 1)
	{
		cout << endl << "ERROR: Uh-oh, looks like there is some extra text after that abbreviation.\nPlease enter a single texting abbreviation only." << endl << endl;
		return false;
	}
	return true;
}

// prints out a header based on the option the user selects
// pre: option is a valid option
// post: header is printed to the screen. Example: 
//       SELECTED OPTION: Find Item
// usage: printOptionHeader(userOption);
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

// executes option selected by the user 
// pre: option is a valid option and a dictionary is a binarysearchtree object
// post: executes the option selected by the user
// usage: executeOption(userOption, myDictionary);
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

// loads the dictionary into the program
// pre: BinarySearchTree aDictionary object exists
// post: loads items from dictionary.dat into binarysearchtree object aDictionary 
//       creating a balanced binarysearchtree
// usage: loadDictionary(aDictionary);
void loadDictionary(BinarySearchTree& aDictionary)
{
    ifstream inputFile;

    inputFile.open("dictionary.dat");
    aDictionary.rebalanceTree(inputFile);
    inputFile.close();
}

// walks user through the delete process for the delete item option 
// pre: aDictionary exists and is a BinarySearchTree object
// post: deletes item specified by user and restricts user items that are leaves and items with 
// one child
// usage: deleteItem(aDictionary);
void deleteItem(BinarySearchTree& aDictionary)
{
	Key delItem;
	string restOfInput;

	cout << endl << "What texting abbreviation would you like to delete?" << endl;
	cout << "NOTE: You can only delete an item that has 0 or 1 child" << endl;
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

// allows user to search for an item in the dictionary
// pre: aDictionary exists and is a BinarySearchTree object
// post: outputs the texting abbreviation and meaning if found in the dictionary else 
//       outputs not found
// usage: findItem(aDictionary);
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

// allows user to insert an item continaing a texting abbreviation and its meaning
// pre: aDictionary exists and is a BinarySearchTree object
// post: the item specified by user is inserted into the dictionary else throws an exception
// usage: insertItem(aDictionary);
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

// lists the items in the dictionary in alphabetical order
// pre: aDictionary is a BinaryTree object that is equal to the dictionary binarysearchtree 
// post: items in a dictionary are printed using BinaryTree's inorderTraverse
// usage: listItems(myDictionary);
void listItems(BinaryTree aDictionary)
{
	aDictionary.inorderTraverse();
}

// prints the structure of the binarysearchtree in pretty fashion
// pre: aDictionary exists and is a BinarySearchTree object
// post: items in the dictionary are printed and structure is shown
// usage: printDictionary(aDictionary);
void printDictionary(BinarySearchTree& aDictionary)
{
	cout << endl;
	aDictionary.prettyDisplay();
	cout << endl;
}

// rebalances the binarysearchtree
// pre: aDictionary exists and is a BinarySearchTree object
// post: items in the dictionary are rebalanced
// usage: rebalanceTree(aDictionary);
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

// saves the dictionary to a file
// pre: aDictionary exists and is a BinarySearchTree object
// post: dictionary is saved to a file
// usage: saveToFile(aDictionary);
void saveToFile(BinarySearchTree& aDictionary)
{
	ofstream outputFile;
	
	cout << endl << "Saving to file dictionary.dat..." << endl << endl;
	
	outputFile.open("dictionary.dat");
	aDictionary.inorderTraverse(outputFile);
	outputFile.close();
}
