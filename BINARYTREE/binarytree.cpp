/*
Alex Giacobbi and Jalen Tacsiat
agiacobbi
8 October 2018
Description: This is the implementation file for abstract data type BinaryTree. This file contains function headers and
bodies for the class BinaryTree's methods as well as documentation for each function. This data object is a Binary Tree
that implemented using an array. The traversal functions use recursion to display the elements in the tree. The class 
has methods that create, destroy, insert a new node, traversals: preorder, inorder, postorder
*/

#include <iostream>
#include "binarytree.h"
using namespace std;

//recursive helper for preorder
void preorderHelper(TreeNode tree[], int myroot)
{
    Item outItem;

    if (myroot != -1)
    {
        tree[myroot].getItem(outItem);
        cout << '\t' << outItem << endl;
        preorderHelper(tree, tree[myroot].getLeftChild());
        preorderHelper(tree, tree[myroot].getRightChild());
    }
}

//recursive helper inorder
void inorderHelper(TreeNode tree[], int myroot)
{
    Item outItem;

    if (myroot != -1)
    {
        inorderHelper(tree, tree[myroot].getLeftChild());
        tree[myroot].getItem(outItem);
        cout << '\t' << outItem << endl;
        inorderHelper(tree, tree[myroot].getRightChild());
    }
}

//recursive helper postorder
void postorderHelper(TreeNode tree[], int myroot)
{
    Item outItem;

    if (myroot != -1)
    {
        postorderHelper(tree, tree[myroot].getLeftChild());
        postorderHelper(tree, tree[myroot].getRightChild());
        tree[myroot].getItem(outItem);
        cout << '\t' << outItem << endl;
    }
}

//creates an empty binary tree
//post an empty BinaryTree object exists
BinaryTree::BinaryTree()
{
    root = -1;
    numberOfItems = 0;
}

//releases a binary tree
//pre a BinaryTree object exists
//post the BinaryTree object no longer exists

BinaryTree::~BinaryTree()
{
    root = -1;
    numberOfItems = 0;
}

//inserts a new node into a binary tree
//pre BinaryTree object exists. newItem, left, right are assigned
//post a node containing newItem with children left and right 
//     has been added to the BinaryTree object
//usage tree.insert(myItem, 1, 2);
void BinaryTree::insert(const Item& newItem, int left, int right)
{
    if (numberOfItems < MAXITEMS)
    {
        binaryTree[numberOfItems].setNode(newItem, left, right);
        if (numberOfItems == 0)
        {
            root = 0;
        }
        numberOfItems++;
    }
}

//performs a Pre-Order traversal of a binary tree
//pre BinaryTree object exists
//post the items of the BinaryTree object are printed in Pre-Order
//     with items separated by a semi-colon
//     There is a newline after the last one
//usage tree.preorder();
void BinaryTree::preorder()
{
    preorderHelper(binaryTree, root); 
    cout << endl;
}

//performs an In-Order traversal of a binary tree
//pre BinaryTree object exists
//post the items of the BinaryTree object are printed in In-Order
//     with items separated by a semi-colon
//     There is a newline after the last one
//usage tree.inorder();
void BinaryTree::inorder()
{
    inorderHelper(binaryTree, root); 
    cout << endl;
}

//performs a Post-Order traversal of a binary tree
//pre BinaryTree objext exists
//post the items of the BinaryTree object are printed in Post-Order
//     with items separated by a semi-colon
//     There is a newline after the last one
//usage tree.postorder();
void BinaryTree::postorder()
{
    postorderHelper(binaryTree, root); 
    cout << endl;
}


