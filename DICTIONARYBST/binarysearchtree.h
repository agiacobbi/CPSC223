// Specification of ADT Dictionary as ADT Binary Search Tree
//     data object: a bunch of texting abbreviations and their meanings 
//     operations: create, destroy
//                 search the dictionary for an item given its text
//                 insert a new item into the dictionary
//                 remove an item from the dictionary given its text
//   associated operations: input and output
// filename binarysearchtree.h
// date October 24, 2018

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "item.h"
#include "treenode.h"
#include "binarytree.h"
#include "exception.h"

class BinarySearchTree: public BinaryTree
{
// displays a dictionary
// pre: output has been opened if it is a file
//      rightHandSideDictionary has been assigned items
// post: output contains each item on a separate line in the format with headings.

// usage: outfile << myDictionary;    
friend ostream& operator<< (ostream& output, const BinarySearchTree& rightHandSideDictionary);

// inputs items into a dictionary
// pre: input has been opened if it is a file
//      items are arranged in the following format
//      2
//      lol
//      laugh out loud
//      ttyl
//      talk to you later
// post: if there is room, 
//       all items in the input have been stored in rightHandSideDictionary
// usage: infile >> myDictionary;
friend istream& operator>> (istream& input, BinarySearchTree& rightHandSideDictionary);

public:

// creates a new dictionary
// post: BinarySearchTree object exists but is empty
// usage: BinarySearchTree myDictionary;	
BinarySearchTree();

// destroys a dictionary
// pre: BinarySearchTree object exists
// post: all memory for BinarySearchTree object has been freed
// usage: automatically done at the end of scope
~BinarySearchTree();

// searchs for a meaning with a given text
// pre targetText has been assigned a value not already in the hash table
// post if an item with texting abbreviationthe same as targetText is found then
//          isFound is true and theItem is that item
//       else isFound is false
// usage  myDictionary.searchForMeaning(targetText, anItem, isFound);
void searchForMeaning(const Key& targetText, Item& anItem, bool& isFound);

// inserts a new text' item into the dictionary
// pre: newItem has been assigned
// post: if there is room in the BinarySearchTree object and newItem's text
//            is not already there then newItem is appropriately added
//       else it throws an exception for either a full dictionary or
//            a message that it is already there
// usage: myDictionary.addNewEntry(myItem, isFull, isAlreadyThere);
void addNewEntry(const Item& newItem) throw (Exception);

// removes the item associated with a given text from the dictionary
// pre: targetText is assigned
// post: if BinarySearchTree object is not empty and 
//           targetText is found in Dictionary object, isFound is true
//           and the associated Item object (text and meaning) has been 
//           removed from the Dictionary object 
//       else throw an excpetion if not found or if empty
// usage: myDictionary.deleteEntry(myText);
void deleteEntry(const Key& targetText) throw (Exception);

void inorderTraverse(ostream& output);

void rebalanceTree(istream& input);



private:
   int numberOfEntries;
};
#endif

