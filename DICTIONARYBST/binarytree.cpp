//file binarytree.cpp
//Alex Giacobbi and Jalen Tacsiat
//agiacobbi
//date: 10/17/18
//implementation file for binarytree.cpp

//data object: a binary tree which is in the form of empty or 
//consists of a root with left and right trees that are binarytrees

//data structure: a linked binary tree which each node containing texting abbreviations 
//and their meanings and pointers to child nodes. 

/*
operations: This is the implementation file of the BinaryTree class. 
This file contains the headers and bodies of each function for the BinaryTree class. 
This data object is a BinaryTree that is implemented using a linked list. The traversal 
functions preorderTraverse, inorderTraverse, and postorderTraverse use a recursive helper 
function to display each item in the tree. There are two constructors the first constructor is 
used for setting the root equal to null pointer. The second constructor is used to copy a tree
to another tree. The destructor uses a recursive helper function to delete each node in 
the BinaryTree. The isEmpty function is used to check if a tree is empty, by checking to see if
the root is equal to null pointer. The equals operator is used to assign a tree to another tree.
The function prettyDisplay uses recursive helper function called writePretty to print out each 
texting abbreviation of each item in the tree. The makeFullTreeHeight3 method is used to create 
a full binary tree of height 3. The makeCompleteTreeHeight4 method is used to create a complete tree
of height 4. 
*/

#include "binarytree.h"
#include <iostream>
using namespace std;

// ***************** recursive helpers *****************

//Copies one binary tree to another
//pre oldtreep points to the root of a binary tree
//post: newtreep points to the root of a binary tree
//  that has copies of the nodes of oldtreep's tree
//usage: copyTree (newptr, oldptr);
void copyTree (TreeNode*& newtreep, TreeNode* oldtreep) throw (Exception)
{
    if (oldtreep != nullptr)
    {
        newtreep = new (nothrow) TreeNode(oldtreep->item, nullptr, nullptr);
        if (newtreep == nullptr)
            throw Exception("in BinaryTree: no memory from the heap available for new TreeNode");
        copyTree(newtreep->leftChild, oldtreep->leftChild);
        copyTree(newtreep->rightChild, oldtreep->rightChild);
    }
}

//Releases memory for a binary tree
//pre: treep points to the root of a binary tree
//post: releases all of the nodes in the tree pointed to by treep
//    and leaves treep empty.
//usage: destroyTree (mroot);
void destroyTree (TreeNode*& treep)
{
   if (treep != nullptr)
   {
      destroyTree(treep -> leftChild);
      destroyTree(treep -> rightChild);
      delete treep;
      treep = nullptr;
   }

}

// recursive helper for prettyDisplay. You do the doc
//Pre: treep points to the root of the binaryTree
//Post: Displays the contents of the binary tree
//Usage: writePretty(root, int)
void writePretty(TreeNode* treep, int level)
{
    Key abbreviation;

    if (treep != nullptr)
    {
        writePretty(treep->rightChild, level + 1);
        if (level == 0)
            cout << "root ->";
        for (int i = 0; i < level + 1; i++)
            cout << '\t' ;
        abbreviation = treep->item;
        cout << abbreviation << endl;
        writePretty(treep->leftChild, level + 1);
    }
}

// ********** recursive helpers for the traversals ****************
//pre: treep points to the root of a binary tree to be traversed
//post: prints the item objects in the nodes on the screen in the 
//     specified order. the items are separated by commas
//usage: preorder (mroot);   
//       similarly for the others
void preorder(TreeNode* treep)
{
    if (treep != nullptr)
    {
        cout << treep -> item << endl;
        preorder(treep -> leftChild);
        preorder(treep -> rightChild);
    }
}

// ********** recursive helpers for the traversals ****************
//pre: treep points to the root of a binary tree to be traversed
//post: prints the item objects in the nodes on the screen in the 
//     specified order. the items are separated by commas
//usage: inorder (mroot);   
void inorder(TreeNode* treep)
{
    if (treep != nullptr)
    {
        inorder(treep -> leftChild);
        cout << treep -> item << endl;
        inorder(treep -> rightChild);
    }
}

// ********** recursive helpers for the traversals ****************
//pre: treep points to the root of a binary tree to be traversed
//post: prints the item objects in the nodes on the screen in the 
//     specified order. the items are separated by commas
//usage: inorder(mroot);
void postorder(TreeNode* treep)
{
    if (treep != nullptr)
    {
        postorder(treep -> leftChild);
        postorder(treep -> rightChild);
        cout << treep -> item << endl;
    }
}

// **************************public methods************************


//creates an empty binary tree
//post: object is an empty binary tree
//usage: BinaryTree zags;
BinaryTree::BinaryTree()
{
    root = nullptr;
}

//creates a new binary tree that is a copy of an existing tree
//post: object is a copy of rightHandSideTree
//throws an exception if there is not enough room in the
//       heap to make the copied tree
//usage: BinaryTree zags (bulldog);
BinaryTree::BinaryTree(const BinaryTree& rightHandSideTree) throw (Exception)
{
    root = nullptr;
    copyTree(root, rightHandSideTree.root);
}

//releases the memory of a binary tree
//pre: object exists
//post: memory for the object has been released. object theoretically does not exist
//       but in practice, it is empty.
BinaryTree::~BinaryTree()
{
    destroyTree(root);
}

// ******************** member functions ********************************************
//@pre: binary tree object exists
// **********************************************************************************

//checks for an empty tree
//post: returns true if the object is empty; else returns false
//usage: if (tree.isEmpty())
bool BinaryTree::isEmpty() const
{
    return (root == nullptr);
}

//copies one tree to another
//pre: rightHandSideTree is an assigned tree.
//post: object is a copy of rightHandSideTree
//throws an exception if there is not enough room in the
//       heap to make the copied tree
//usage: atree = btree = ctree;
BinaryTree& BinaryTree::operator=(const BinaryTree& rightHandSideTree) throw (Exception)
{
    destroyTree(root);
    copyTree(root, rightHandSideTree.root);
    return *this;
}

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
void BinaryTree::prettyDisplay()
{
    writePretty(root, 0);
}

// *************** on the following traversals

//post: prints the objects in the tree in order specified
//usage: tree.preorderTraverse();  
//similarly for the other traversals
// *****************************************************
void BinaryTree::preorderTraverse ()
{
    preorder(root);
}

//post: prints the objects in the tree in order specified
//usage: tree.inorderTraverse();  
//similarly for the other traversals
void BinaryTree::inorderTraverse ()
{
    inorder(root);
}

//post: prints the objects in the tree in order specified
//usage: tree.postorderTraverse();  
//similarly for the other traversals
void BinaryTree::postorderTraverse()
{
    postorder(root);
}

//makes a full binary tree of height 3
//pre input is either cin or an open file
//    input's pointer is before the first item
//post: object is a full binary tree of height 2
//throws an exception if there is not enough room in the
//       heap to make the tree
//usage: tree.makeFullTreeHeight3(inputstream);
void BinaryTree::makeFullTreeHeight3(istream& input) throw (Exception)
{
    Item newguy;
   
    input >> newguy;
    root = new (nothrow) TreeNode(newguy, nullptr, nullptr);
    if (root == nullptr)
        throw Exception("in BinaryTree: no memory from heap available for root item");

    input >> newguy;
    root->leftChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
    if (root->leftChild == nullptr)
        throw Exception("in BinaryTree: no memory from heap available for leftChild");

    input >> newguy;
    root->rightChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
    if (root->rightChild == nullptr)
        throw Exception("in BinaryTree: no memory from heap available for rightChild");

    input >> newguy;
    root->leftChild->leftChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
    if (root->leftChild->leftChild == nullptr)
        throw Exception("in BinaryTree: no memory from heap available for leftChild");

    input >> newguy;
    root->leftChild->rightChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
    if (root->leftChild->rightChild == nullptr)
        throw Exception("in BinaryTree: no memory from heap available for rightChild");

    input >> newguy;
    root->rightChild->leftChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
    if (root->rightChild->leftChild == nullptr)
        throw Exception("in BinaryTree: no memory from heap available for leftChild");

    input >> newguy;
    root->rightChild->rightChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
    if (root->rightChild->rightChild == nullptr)
        throw Exception("in BinaryTree: no memory from heap available for rightChild");
}

//makes a complete but not full binary tree of height 3 
//pre input is either cin or an open file
//    input's pointer is before the first item
//post: object is a complete but not full binary tree of height 4
//throws an exception if there is not enough room in the
//       heap to make the tree
//usage: tree.makeCompleteTreeHeight4(input);
void BinaryTree::makeCompleteTreeHeight4(istream& input) throw (Exception)
{
    Item newguy;
   
    input >> newguy;
    root = new (nothrow) TreeNode(newguy, nullptr, nullptr);
    if (root == nullptr)
        throw Exception("in BinaryTree: no memory from heap available for root item");

    input >> newguy;
    root->leftChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
    if (root->leftChild == nullptr)
        throw Exception("in BinaryTree: no memory from heap available for leftChild");

    input >> newguy;
    root->rightChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
    if (root->rightChild == nullptr)
        throw Exception("in BinaryTree: no memory from heap available for rightChild");

    input >> newguy;
    root->leftChild->leftChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
    if (root->leftChild->leftChild == nullptr)
        throw Exception("in BinaryTree: no memory from heap available for leftChild");

    input >> newguy;
    root->leftChild->rightChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
    if (root->leftChild->rightChild == nullptr)
        throw Exception("in BinaryTree: no memory from heap available for rightChild");

    input >> newguy;
    root->rightChild->leftChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
    if (root->rightChild->leftChild == nullptr)
        throw Exception("in BinaryTree: no memory from heap available for leftChild");

    input >> newguy;
    root->rightChild->rightChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
    if (root->rightChild->rightChild == nullptr)
        throw Exception("in BinaryTree: no memory from heap available for rightChild");

    input >> newguy;
    root->leftChild->leftChild->leftChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
    if (root->leftChild->leftChild->leftChild == nullptr)
        throw Exception("in BinaryTree: no memory from heap available for leftChild");

    input >> newguy;
    root->leftChild->leftChild->rightChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
    if (root->leftChild->leftChild->rightChild == nullptr)
        throw Exception("in BinaryTree: no memory from heap available for rightChild");

    input >> newguy;
    root->leftChild->rightChild->leftChild = new (nothrow) TreeNode(newguy, nullptr, nullptr);
    if (root->leftChild->rightChild->leftChild == nullptr)
        throw Exception("in BinaryTree: no memory from heap available for leftChild");

    if (root->leftChild->rightChild->leftChild != nullptr)
        throw Exception("I am throwing an exception at you, Dr. Y. Do you have your catcher’s mitt ready?");
}
