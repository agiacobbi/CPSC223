//file binarytree.h
//Alex Giacobbi and Jalen Tacsiat
//agiacobbi
//date: 11/1/18
//specification file for binarytree.cpp

//    data object: a binary tree which is in the form of empty or 
//                 consists of a root with left and right trees 
//                 that are binary trees
//    data structure: a linked binary tree which each node containing 
//                    texting abbreviations and their meanings and pointers 
//                    to left and right child nodes. 
//    operations:  The traversal functions preorderTraverse, inorderTraverse, 
//                 and postorderTraverse use a recursive helper function to display 
//                 items in the tree. There are two constructors. The first 
//                 constructor sets the root equal to null pointer. The copy constructor
//                 is used to copy in an existing tree. The destructor uses a recursive 
//                 helper function to delete each node in the BinaryTree. The isEmpty function
//                 is used to check if a tree is empty, by checking to see if the root is 
//                 equal to null pointer. The equals operator assigns a tree to another tree.
//                 The function prettyDisplay uses recursive helper function called writePretty 
//                 to print out each texting abbreviation of each item in the tree. The 
//                 makeFullTreeHeight3 method creates a full binary tree of height 3. The 
//                 makeCompleteTreeHeight4 method creates a complete tree of height 4. 

// Contract: Assumes the this class can access private data members of class Node.
//    Those data members are: Item item, Node* leftptr, Node* rightptr.
//    There is a constructor that allows caller to give item, left and right ptrs.

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "treenode.h"
#include "exception.h"
#include <iostream>
using namespace std;

class BinaryTree
{
public:
   //creates an empty binary tree
   //post: object is an empty binary tree
   //usage: BinaryTree zags;
   BinaryTree();

   //creates a new binary tree that is a copy of an existing tree
   //post object is a copy of rightHandSideTree
   //throws an exception if there is not enough room in the heap for
   //       an copied tree
   //usage: BinaryTree zags (bulldog);
   BinaryTree(const BinaryTree& rightHandSideTree) throw (Exception);

   //releases the memory of a binary tree
   //pre: object exists
   //post: memory for the object has been released. object theoretically does not exist
   //       but in practice, it is empty.
   ~BinaryTree();

   // ******************** member functions ********************************************
   //pre: binary tree object exists
   // **********************************************************************************
   //checks for an empty tree
   //post: returns true if the object is empty; else returns false
   //usage: if (tree.isEmpty())
   bool isEmpty() const;

   //copies one tree to another
   //pre: rhstree is an assigned tree.
   //post: object is a copy of rightHandSideTree
   //throws an exception if there is not enough room in the heap for
   //       an copied tree
   //usage: atree = btree = ctree;
   BinaryTree& operator=(const BinaryTree& rightHandSideTree) throw (Exception);

   //prints the tree to look like a computer science tree
   //post: outputs the tree as in the example below
   //
   //                        bar
   //                  foo
   //                        geeU
   //  root ->  queue
   //                        stack
   //                  list
   //                        array
   //nodes at the same level are indented the same.
   //Viewer must rotate head 90 degrees in order to look like a cs tree
   //usage: tree.prettyDisplay();
   void prettyDisplay();

   // *************** on the following traversals
   //uses: operator<< from class Item
   //post: prints the objects in the tree in order specified
   //usage: tree.preorderTraverse();  
   //similarly for the other traversals
   // *****************************************************
   void preorderTraverse ();
   void inorderTraverse ();
   void postorderTraverse();

   //makes a full binary tree of height 3
   //pre input is either cin or an open file
   //post: object is a full binary tree of height 3
   //throws an exception if there is not enough room in the
   //       heap to make the tree
   //usage: tree.makeFullTreeHeight3(infile);
   void makeFullTreeHeight3(istream& input) throw (Exception);

   //makes a complete binary tree of height 4
   //pre input is either cin or an open file
   //post: object is a complete binary tree of height 4  
   //throws an exception if there is not enough room in the
   //       heap to make the tree
   //usage: tree.makeCompleteTreeHeight4(infile);
   void makeCompleteTreeHeight4(istream& input) throw (Exception);

protected: 

    TreeNode* root;
};
#endif
