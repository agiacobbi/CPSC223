//Implementation of ADT TreeNode
//file treenode.cpp
//author Dr. Y
//date October 17, 2018

//ADT TreeNode for a binary tree: 
//data object: a node with an item and a pointer to left and right children
//                            
// operations: constructors
/* This is the implementation file for class treenode. This file contains the
headers and bodies for each function of the treenode class. This file contains 
two constructors for the treenode class. The first constructor is used to set 
the left and right child to null pointer. The second constructor is used to create 
an item and their children. 
*/

#include "treenode.h"

//creates a treenode
//post: left and right child are set to null pointer
//usage TreeNode mytreeNode;    
TreeNode::TreeNode()
{
   leftChild = nullptr;
   rightChild = nullptr;
}

//creates a treenode
//post: item, leftChild, and rightChild are assigned
//usage: TreeNode myTree(anItem, treeLeft, treeRight);
TreeNode::TreeNode(const Item& newItem, TreeNode* theLeft, TreeNode* theRight)
{
   item = newItem;
   leftChild = theLeft;
   rightChild = theRight;
}
