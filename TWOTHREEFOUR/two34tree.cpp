// two34tree.cpp
// Implementation of ADT 2-3-4 Tree
//     data object: a 2-3-4 tree (a tree containing 2-nodes,
//                  3-nodes, and 4-nodes) where a k-node has
//                  k children
//     data structure: a linked 2-3-4 tree
// note: this is not the formal definition that takes 2 pages in textbook
//     operations: create, destroy, insert, display
// Programmer: dr y     Date: November 28, 2018
// Filename: two34tree.cpp
//
// class Two34TreeNode specifies and implements a node for a
//    2-3-4 tree with room for 1-3 data items from class citem and
//    0-4 children

#include "two34tree.h"
#include <iostream>
using namespace std;
// helpers ----------------------------------------------------------

// frees the heap memory of a tree
// pre: treep is assigned but may be empty
// post: all nodes in the tree with root treep
//       have been released back to the heap and
//       treep is empty
// usage: destroyTree (mroot);
void destroyTree(Two34TreeNode*& treep)
{
	if (treep != nullptr)
	{
		destroyTree(treep -> kids[0]);
		destroyTree(treep -> kids[1]);
		destroyTree(treep -> kids[2]);
		destroyTree(treep -> kids[3]);
		delete treep;
		treep = nullptr;
	}
}

// shows the data in the tree in inorder
// pre: treep is assigned but may be empty
//      output is open
// post: the data items in the nodes of treep's tree
//       are printed to output in inorder
void inorder(ostream& output, Two34TreeNode* treep)
{
	if (treep != nullptr)
	{
		inorder(output, treep -> kids[0]);
		output << theTexts[0] << endl;
		inorder(output, treep -> kids[1]);
		output << theTexts[1] << endl;
		inorder(output, treep -> kids[2]);
		output << theTexts[2] << endl;
		inorder(output, treep -> kids[3]);
	}
}

// shows the data in the tree in its tree structure
// pre: output is open. treep is assigned a tree.
//      level is assigned
// post: the data items of the nodes of treep at level
//       in the tree are printed to output with spacing
//       to denote the level.
// usage: pretty (output, mroot, 1);
void pretty(ostream& output, Two34TreeNode* treep, int level)
{
	if (treep != nullptr)
	{
		pretty(output, treep -> kids[3], level + 1);
		for (int i = 0; i < level; i++)
			cout << '\t' << endl;
		cout << theTexts[2] << endl;
		pretty(output, treep -> kids[2], level + 1);
		for (int i = 0; i < level; i++)
			cout << '\t' << endl;
		cout << theTexts[1] << endl;
		pretty(output, treep -> kids[1], level + 1);
		for (int i = 0; i < level; i++)
			cout << '\t' << endl;
		cout << theTexts[0] << endl;
		pretty(output, treep -> kids[0], level + 1);
	}		
}

// member functions or methods --------------------------------------

// creates an empty 2-3-4 Tree
// post: object is empty
Two34Tree::Two34Tree()
{
	root = nullptr;
}

// destroys a 2-3-4 Tree
// pre: object exists
// post: object does not exist, all pre-memory released
Two34Tree::~Two34Tree()
{
	destroyTree(root);
}

// adds a new key into the tree
// pre: tree object exists. text is assigned.
// post: text is placed in the appropriately sorted
//       position in the 2-3-4 tree object
// usage: tree.addNewEntry(mytext);
void Two34Tree::addNewEntry(const Key& text)
{
	two34TreeNode* treep = root;
	
	while (kids[0] != nullptr and kids[1] != nullptr and kids[2] != nullptr and kids[3] != nullptr)
	{
		if (treep -> numberOfKeys == 3)
			split(treep, root);
		if (text < treep -> theTexts[0])
			treep = treep -> kids[0];
		else if (text < treep -> theTexts[1] and treep -> numberOfKeys > 1)
			treep = treep -> kids[1];
		else
			treep = treep -> kids[2];
	}
	
	if (root == nullptr) {
		root = new Two34TreeNode(text);
		treep -> numberOfKeys++;
	}
	else (
}

// displays a tree in one of two formats
// pre: which is either 'i' or 'p'
//      output is open
// post: if which is 'i' the tree is displayed inorder
//       else the tree is displayed showing its tree
//       structure
// usage: tree.display (cout, 'p');
void Two34Tree::display(ostream& output, char which)
{
	if (which == 'i')
		inorder(output, root);
	else
		pretty(output, root, 0);
}