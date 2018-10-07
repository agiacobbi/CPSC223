//file binarytree.cpp
//author Dr. Y
//date October 1, 2018

//Specification of ADT Binary Tree
//     Data object: a binary tree which is either empty or
//                  in the form of     r
//                                  /    \
//                                TL     TR
//                  where TL and TR are binary trees
//     Data Structure: 

//     Operations: create, destroy, insert a new node, 
//                 traversals: preorder, inorder, postorder
#include <iostream>
#include "binarytree.h"
using namespace std;

//recursive helper
void preorderHelper(TreeNode tree[], int myroot)
{
    int left = tree[myroot].getLeftChild();
    int right = tree[myroot].getRightChild();
    Item outItem;

    if (myroot != -1)
    {
        tree[myroot].getItem(outItem);
        cout << '\t' << outItem << endl;
        preorderHelper(tree, left);
        preorderHelper(tree, right);
    }
}

//recursive helper
void inorderHelper(TreeNode tree[], int myroot)
{
    int left = tree[myroot].getLeftChild();
    int right = tree[myroot].getRightChild();
    Item outItem;

    if (myroot != -1)
    {
        inorderHelper(tree, left);
        tree[myroot].getItem(outItem);
        cout << '\t' << outItem << endl;
        inorderHelper(tree, right);
    }
}

//recursive helper
void postorderHelper(TreeNode tree[], int myroot)
{
    int left = tree[myroot].getLeftChild();
    int right = tree[myroot].getRightChild();
    Item outItem;

    if (myroot != -1)
    {
        postorderHelper(tree, left);
        postorderHelper(tree, right);
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
        root = numberOfItems;
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

void BinaryTree::inorder()
{
    inorderHelper(binaryTree, root); 
    cout << endl;
}

void BinaryTree::postorder()
{
    postorderHelper(binaryTree, root); 
    cout << endl;
}


