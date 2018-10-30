#include "binarytree.h"
#include "binarysearchtree.h"
#include "exception.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;


void testSearchForMeaning(BinarySearchTree& aTree);

void testAddNewEntry(BinarySearchTree& aTree);

void testRebalanceTree(BinarySearchTree& aTree, istream& input);


int main()
{
	ofstream output;
	ifstream inputfile;
	BinarySearchTree aTree;
	inputfile.open("dictionary.dat");
	
	inputfile >> aTree;
	testSearchForMeaning(aTree);
	inputfile.close();
	testAddNewEntry(aTree);
	output.open("testfile.dat");
	cout << aTree << endl;
	aTree.inorderTraverse(output);
	output.close();
	inputfile.open("testfile.dat");
	testRebalanceTree(aTree, inputfile);
	cout << aTree << endl;
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

void testRebalanceTree(BinarySearchTree& aTree, istream& input)
{
	
	cout << "testing RebalanceTreeFunction" << endl;
	aTree.rebalanceTree(input);
}