#include "binarytree.h"
#include "binarysearchtree.h"
#include "exception.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

void testSearchForMeaning(BinarySearchTree& aTree);
void testAddNewEntry(BinarySearchTree& aTree);
void testRebalanceTree(BinarySearchTree& aTree);
void testInputOperator(BinarySearchTree& aTree);
void testInorderTraverse(BinarySearchTree& aTree);

int main()
{
	BinarySearchTree myBinarySearchTree;
	
	testInputOperator(myBinarySearchTree);
	testSearchForMeaning(myBinarySearchTree);
	testAddNewEntry(myBinarySearchTree);
	testInorderTraverse(myBinarySearchTree);
	testRebalanceTree(myBinarySearchTree);	
}

void testSearchForMeaning(BinarySearchTree& aTree)
{
	Item anItem;
	Key aKey("lol");
	bool isFound;
	
	cout << "----- Testing searchForMeaning, searching for key 'lol' -----" << endl;
	aTree.searchForMeaning(aKey, anItem, isFound);

	if (isFound)
		cout << "Found: " << anItem << endl;
	else
		cout << "Not found" << endl;
}

void testAddNewEntry(BinarySearchTree& aTree)
{
	Item anItem;
	
	cout << "---- Testing addNewEntry ---" << endl;
	cout << "Enter an item to add -> ";
	cin >> anItem;

	try {
		aTree.addNewEntry(anItem);
	} 
	catch(Exception e) {
		cout << endl << e.what() << endl << endl;
	}
}

void testRebalanceTree(BinarySearchTree& aTree)
{
	ifstream inputFile;

	inputFile.open("testfile.dat");

	cout << "----- Testing rebalance function and printing balanced tree -----" << endl;
	aTree.rebalanceTree(inputFile);
	cout << aTree << endl;

	inputFile.close();
}

void testInputOperator(BinarySearchTree& aTree)
{
	ifstream inputFile;

	inputFile.open("dictionary.dat");

	cout << "----- Testing the input operator and printing the tree -----" << endl;
	inputFile >> aTree;
	cout << aTree << endl;

	inputFile.close();
}

void testInorderTraverse(BinarySearchTree& aTree)
{
	ofstream outputFile;

	outputFile.open("testfile.dat");

	cout << "----- Testing inorder traversal and printing to screen and testfile.dat -----" << endl;
	aTree.inorderTraverse(cout);
	aTree.inorderTraverse(outputFile);

	outputFile.close();
}
