//Specification of ADT TreeNode
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
#ifndef TREENODE_H
#define TREENODE_H

#include <cstdlib>
#include "item.h"
using namespace std;

class TreeNode
{
public:
 
//creates a treenode
//post: left and right child are set to null pointer
//usage TreeNode mytreeNode; 
TreeNode();

//creates a treenode
//post: item, leftChild, and rightChild are assigned
//usage: TreeNode myTree(anItem, treeLeft, treeRight);
TreeNode(const Item& newItem, TreeNode* theLeft, TreeNode* theRight);
   
Item item;
TreeNode* leftChild;
TreeNode* rightChild;

};
#endif


