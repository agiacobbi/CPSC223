//filename: clientprogram.cpp
// Alex Giacobbi and Jalen Tacsiat
// agiacobbi
// date: 11/18/18
#include <iostream>
#include <fstream>
#include <string>
#include "avltree.h"
using namespace std;



void testAddNewEntry(AVLTree& myAvlTree, ifstream& inputfile);

int main()
{
	Item testItems;
	ifstream inputfile;
	
	inputfile.open("in.dat");
	inputfile >> testItems;
	inputfile.close();
	
	AVLTree myAvlTree;
	testAddNewEntry(myAvlTree, inputfile);
	
}

void testAddNewEntry(AVLTree& myAvlTree, ifstream& inputfile)
{
	Item testItems;
	inputfile >> testItems;
	myAvlTree.addNewEntry(testItems);
	inputfile >> testItems;
	myAvlTree.addNewEntry(testItems);
}