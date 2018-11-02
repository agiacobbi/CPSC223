#include "binarytree.h"
#include "binarysearchtree.h"
#include "exception.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

//tests searchForMeaning function of binary search tree
//pre aTree is a BinarySearchTree object
//post searches for key 'lol' and printss found if found
//     else prints not found
void testSearchForMeaning(BinarySearchTree& aTree);

//tests addNewEntry function of binary search tree
//pre aTree is a BinarySearchTree object
//post gets item from user to add and inserts it into the search tree
void testAddNewEntry(BinarySearchTree& aTree);

//tests rebalanceTree function of binary search tree
//pre aTree is a BinarySearchTree object
//post writes items in tree using BinarySearchTree's inorderTraverse
//     reads items from file and inserts into a balanced BinarySearchTree
void testRebalanceTree(BinarySearchTree& aTree);

//tests inorderTraverse function of binary search tree
//pre aTree is a BinarySearchTree object
//post writes items in tree to an output file 'testfile.dat' using 
//     BinarySearchTree's inorder traverse
void testInorderTraverse(BinarySearchTree& aTree);

int main()
{
	BinarySearchTree myBinarySearchTree;
	
	testRebalanceTree(myBinarySearchTree);
	testSearchForMeaning(myBinarySearchTree);
	testAddNewEntry(myBinarySearchTree);
	testInorderTraverse(myBinarySearchTree);
	testRebalanceTree(myBinarySearchTree);	
}

//tests searchForMeaning function of binary search tree
//pre aTree is a BinarySearchTree object
//post searches for key 'lol' and printss found if found
//     else prints not found
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

//tests addNewEntry function of binary search tree
//pre aTree is a BinarySearchTree object
//post gets item from user to add and inserts it into the search tree
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

//tests rebalanceTree function of binary search tree
//pre aTree is a BinarySearchTree object
//post writes items in tree using BinarySearchTree's inorderTraverse
//     reads items from file and inserts into a balanced BinarySearchTree
void testRebalanceTree(BinarySearchTree& aTree)
{
	ifstream inputFile;

	inputFile.open("testfile.dat");

	cout << "----- Testing rebalance function and printing balanced tree -----" << endl;
	aTree.rebalanceTree(inputFile);
	aTree.prettyDisplay();

	inputFile.close();
}

//tests inorderTraverse function of binary search tree
//pre aTree is a BinarySearchTree object
//post writes items in tree to an output file 'testfile.dat' using 
//     BinarySearchTree's inorder traverse
void testInorderTraverse(BinarySearchTree& aTree)
{
	ofstream outputFile;

	outputFile.open("testfile.dat");

	cout << "----- Testing inorder traversal and printing to screen and testfile.dat -----" << endl;
	aTree.inorderTraverse(cout);
	aTree.inorderTraverse(outputFile);

	outputFile.close();
}
