/*
Alex Giacobbi and Jalen Tacsiat
agiacobbi
8 October 2018
Description: This is the header file for abstract data type BinaryTree. This file contains function prototypes and
documentation for the class BinaryTree's methods. This data object is a Binary Tree implemented using an array. The 
traversal functions will use recursion to display the elements in the tree. The class has methods that create,
destroy, insert a new node, traversals: preorder, inorder, postorder
*/

#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include "treenode.h"
#include "item.h"

const int MAXITEMS = 20;

class BinaryTree
{
public:

//creates an empty binary tree
//post an empty BinaryTree object exists
BinaryTree();

//releases a binary tree
//pre a BinaryTree object exists
//post the BinaryTree object no longer exists
~BinaryTree();

//inserts a new node into a binary tree
//pre BinaryTree object exists. newItem, left, right are assigned
//post a node containing newItem with children left and right 
//     has been added to the BinaryTree object
//usage tree.insert(myItem, 1, 2);
void insert(const Item& newItem, int left, int right);

//performs a Pre-Order traversal of a binary tree
//pre BinaryTree object exists
//post the items of the BinaryTree object are printed in Pre-Order
//     with items separated by a semi-colon
//usage tree.preorder();
void preorder();

//performs an In-Order traversal of a binary tree
//pre BinaryTree object exists
//post the items of the BinaryTree object are printed in Pre-Order
//     with items separated by a semi-colon
//usage tree.preorder();
void inorder();

//performs a Post-Order traversal of a binary tree
//pre BinaryTree object exists
//post the items of the BinaryTree object are printed in Pre-Order
//     with items separated by a semi-colon
//usage tree.preorder();
void postorder();

private:
 
int root;
int numberOfItems;
TreeNode binaryTree[MAXITEMS];

};

#endif
