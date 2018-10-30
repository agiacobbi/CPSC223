#include "binarytree.h"
#include "binarysearchtree.h"
#include "exception.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;


void testSearchForMeaning(BinarySearchTree& aTree);

void testAddNewEntry(BinarySearchTree& aTree);



int main()
{
	ifstream inputfile;
	BinarySearchTree aTree;
	inputfile.open("dictionary.dat");
	
	inputfile >> aTree;
	testSearchForMeaning(aTree);
	testAddNewEntry(aTree);
	
	cout << aTree << endl;
	aTree.inorderTraverse(cout);
	
	inputfile.close();
}

void testSearchForMeaning(BinarySearchTree& aTree)
{
	Item anItem;
	Key aKey("lol");
	bool isFound;
	
	cout << "------ Testing searchForMeaning, searching for key lol -------" << endl;
	aTree.searchForMeaning(aKey, anItem, isFound);
	if (isFound)
	{
		cout << "Found it" << endl;
	}
	else
	{
		cout << "Not found" << endl;
	}
}

void testAddNewEntry(BinarySearchTree& aTree)
{
	Item anItem;
	
	cout << "---- Testing addNewEntry ---" << endl;
	cout << "enter an item to add -> ";
	cin >> anItem;
	try
	{
		aTree.addNewEntry(anItem);
	}
	catch(Exception e)
	{
		cout << endl << e.what() << endl << endl;
	}
}