// filename: binarysearchtree.cpp
// Alex Giacobbi and Jalen Tacsiat
// agiacobbi
// date: 11/1/18
// implementation file for binarysearchtree.cpp
// Specification of ADT Dictionary as ADT Binary Search Tree
// 
// data object: a binarysearchtree which is in the form of empty or consists of a root 
//              with left and right trees that are binarysearchtrees
//    
// data structure: a linked binarysearchtree with each node containing items with texting 
//                 abbreviations, their meanings, and pointers to the left and right child nodes 

/* operations: This is the implementation of the binarysearchtree class. 
               This file contains the headers and bodies of the binarysearchtree
               class. The constructor for this file is used to create a new dictionary. 	
               This file contains recursive helper functions used for each method. searchHelper
			   is used for searching for a specific testing abbreviation which returns true if 
			   the target texting abbreviation is found within the tree. searchHelper is called by 
			   the method searchForMeaning which is used to search for a meaning. The addHelper 
			   functionis used to add an item to the binarysearchtree. addHelper is called by by 
			   the method addNewEntry, which is used to add an item to the dictionary. rebalanceTreeHelper 
			   is used to reblance the tree. rebalanceTreeHelper is called by the method rebalanceTree, 
			   which is used to rebalance the tree. The inorderTraverseHelper is used to list the 
			   binarysearchtree in order alphabetically. inorderTraverseHelper helper is called by the 
			   method inorderTraverse, which is used to output the items in the dictionary in alphabetical 
			   order. The deleteHelper function is used for deleting a node in the binarysearchtree. 
			   deleteHelper is called by the method deleteEntry, which is used to delete an entry in the 
			   binarysearchtree. 			   
*/   



#include "binarysearchtree.h"

// recursive helper functions

// searches a binary search tree for a certain text
// pre: treep is assigned a pointer to a root node of a binary search tree
//      targetText is assigned
// post: if targetText is found in the tree whose root node is treep
//          then the item in the root node is copied into anItem and
//          returns true; otherwise, returns false
// usage: isFound = searchHelper(root, targetText, anItem);
bool searchHelper(TreeNode* treep, const Key& targetText, Item& anItem)
{
   if (treep != nullptr)
   {
      if (targetText == treep -> item)
      {
         anItem = treep -> item;
         return true;
      } else if (targetText < treep -> item) {
         return searchHelper(treep -> leftChild, targetText, anItem);
      } else {
         return searchHelper(treep -> rightChild, targetText, anItem);
      }
   } else {
      return false;
   }
}


// adds an Item containing a texting abbreviation and its meaning to the binarysearchtree
// pre: treep is assigned a pointer to a root node of a binary search tree
//      and newItem is not in treep 
// post: if newItem is not found in tree a new TreeNode is created containing the newItem
//       
// usage: addHelper(root, newItem, numberOfEntries);
void addHelper(TreeNode*& treep, const Item& newItem, int& number) throw (Exception)
{
    if (treep != nullptr)
    {
        if (newItem == treep->item)
        {
            throw Exception("ERROR: Oops, looks like that item is already in the tree.");
        } else if (newItem < treep->item) {
            addHelper(treep->leftChild, newItem, number);
        } else {
            addHelper(treep->rightChild, newItem, number);
        }
    } else {
        treep = new (nothrow) TreeNode(newItem, nullptr, nullptr);
        if (treep == nullptr)
            throw Exception("ERROR: Oops, looks like there is no more room for this item. Your dictionary is full.");
		else
			number++;
    }
}

// rebalances the tree 
// pre: number of items in the tree is greater than 0
// post: tree is rebalanced 
// usage: rebalanceTreeHelper(TreePtr, inputfile, numberOfItems)
void rebalanceTreeHelper(TreeNode*& treep, istream& input, int number)
{
	Item anItem;

	if (number > 0)
	{
		treep = new (nothrow) TreeNode(anItem, nullptr, nullptr);
		
		rebalanceTreeHelper(treep -> leftChild, input, number / 2);
		input >> treep -> item;
		rebalanceTreeHelper(treep -> rightChild, input, (number - 1) / 2);	
	}
	
}

//Releases memory for a binary tree
//pre: treep points to the root of a binary tree
//post: releases all of the nodes in the tree pointed to by treep
//    and leaves treep empty.
//usage: destroyTree (mroot);
void destroyBinaryTree (TreeNode*& treep)
{
   if (treep != nullptr)
   {
      destroyBinaryTree(treep -> leftChild);
      destroyBinaryTree(treep -> rightChild);
      delete treep;
      treep = nullptr;
   }

}

// lists the tree in alphabetical order (a-z)
// pre: TreeNode pointer is assigned a pointer to a root node of a binary search tree
// post: Tree is listed in alphabetical order
// usage: inorderTraverseHelper(TreePtr, outputFile)
void inorderTraverseHelper(TreeNode* treep, ostream& output)
{
	if (treep != nullptr)
	{
		
		inorderTraverseHelper(treep -> leftChild, output);
		output << treep -> item << endl;
		inorderTraverseHelper(treep -> rightChild, output);
	}
}

// delete a node in the tree  
// pre: TreeNode pointer is assigned a pointer to a root node of a binary search tree 
// post: if targetText is found delete its node and sets it to nullptr
//       and if targetText is not found within the tree throw an excepetion saying targetText is not found
// usage: deleteHelper(TreeNodePtr, targetText, numberOfEntries);
void deleteHelper(TreeNode*& treep, const Key& targetText, int& numberOfItems) throw (Exception)
{
	if (treep != nullptr)
	{
		if (targetText == treep -> item)
		{
			if (treep -> leftChild ==  nullptr && treep -> rightChild == nullptr)
			{
				delete treep;
				treep = nullptr;
				numberOfItems--;
			}
			else if (treep -> leftChild != nullptr && treep -> rightChild == nullptr)
			{
				TreeNode* deletePtr = treep;
				treep = treep -> leftChild;
				deletePtr -> leftChild = nullptr;
				delete deletePtr;
				numberOfItems--;
			}
			else if (treep -> leftChild == nullptr && treep -> rightChild != nullptr)
			{
				TreeNode* deletePtr = treep;
				treep = treep -> rightChild;
				deletePtr -> rightChild = nullptr;
				delete deletePtr;
				numberOfItems--;
			}
			
			else 
			{
				throw Exception ("ERROR: Oops, two-child deletion is not yet supported. Sorry!");
			}
			
		}
		else if (targetText < treep -> item)
		{
			return deleteHelper(treep -> leftChild, targetText, numberOfItems);
		}
		else 
		{
			return deleteHelper(treep -> rightChild, targetText, numberOfItems);
		}
	}
	else
	{
		throw Exception("ERROR: Oops, we couldn't find that item in the dictionary.");
	}
}	


// creates a new dictionary
// post: BinarySearchTree object exists but is empty
// usage: BinarySearchTree myDictionary;	
BinarySearchTree::BinarySearchTree()
{
	numberOfEntries = 0;
}

// destroys a dictionary
// pre: BinarySearchTree object exists
// post: all memory for BinarySearchTree object has been freed
// usage: automatically done at the end of scope
BinarySearchTree::~BinarySearchTree()
{
	
}

// searches for a meaning with a given text
// pre: targetText has been assigned a value not already in the hash table
// post: if an item's texting abbreviation is the same as the targetText 
//          isFound is true and theItem is the targetText item
//      
// usage: myDictionary.searchForMeaning(targetText, anItem, isFound);
void BinarySearchTree::searchForMeaning(const Key& targetText, Item& anItem, bool& isFound)
{
	isFound = searchHelper(root, targetText, anItem);
}

// inserts a new text' item into the dictionary
// pre: newItem has been assigned
// post: if there is room in the BinarySearchTree object and newItem's text
//            is not already there then newItem is appropriately added
//       else it throws an exception for either a full dictionary or
//            a message that it is already there
// usage: myDictionary.addNewEntry(myItem, isFull, isAlreadyThere);
void BinarySearchTree::addNewEntry(const Item& newItem) throw (Exception)
{  
    addHelper(root, newItem, numberOfEntries);
}

// removes the item associated with a given text from the dictionary
// pre: targetText is assigned
// post: if BinarySearchTree object is not empty and 
//           targetText is found in Dictionary object, isFound is true
//           and the associated Item object (text and meaning) has been 
//           removed from the Dictionary object 
//       else throws an exception if key is not found or dictionary is empty
// usage: myDictionary.deleteEntry(myText, isEmpty, isFound);
void BinarySearchTree::deleteEntry(const Key& targetText) throw (Exception)
{
	deleteHelper(root, targetText, numberOfEntries);
}

// puts the items in the dictionary in alphabetical order
// pre: Tree exists with items in it 
// post: Items of tree are listed in order 
// usage: myBinarySearchTree.inorderTraverse(outputFile)
void BinarySearchTree::inorderTraverse(ostream& output)
{
	output << numberOfEntries << endl; 
	inorderTraverseHelper(root, output);
}

// rebalances the tree 
// pre: tree exists
// post: tree is rebalanced 
// usage: myBinarySearchTree.rebalanceTree(inputFile)
void BinarySearchTree::rebalanceTree(istream& input)
{
    int num;

	destroyBinaryTree(root);
    input >> num;
    rebalanceTreeHelper(root, input, num);
	
	numberOfEntries = num;
}


