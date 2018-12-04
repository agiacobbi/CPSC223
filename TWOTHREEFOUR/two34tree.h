// Specification of ADT 2-3-4 Tree
//     data object: a 2-3-4 tree (a tree containing 2-nodes,
//                  3-nodes, and 4-nodes) where a k-node has
//                  k children
// note: this is not the formal definition that takes 2 pages in textbook
//     operations: create, destroy, insert, display
// Programmer: dr y     Date: April 16, 2002
// Filename: two34tree.h
//
// class Two34TreeNode specifies and implements a node for a
//    2-3-4 tree with room for 1-3 data items from class citem and
//    0-4 children

#ifndef TWO34TREE_H
#define TWO34TREE_H

#include "two34treenode.h"
#include <iostream>
using namespace std;

class Two34Tree
{
public:
   // creates an empty 2-3-4 Tree
   // post: object is empty
   Two34Tree();

   // destroys a 2-3-4 Tree
   // pre: object exists
   // post: object does not exist, all pre-memory released
   ~Two34Tree();

   // adds a new key into the tree
   // pre: tree object exists. text is assigned.
   // post: text is placed in the appropriately sorted
   //       position in the 2-3-4 tree object
   // usage: tree.addNewEntry(mytext);
   void addNewEntry(const Key& text);

   // displays a tree in one of two formats
   // pre: which is either 'i' or 'p'
   //      output is open
   // post: if which is 'i' the tree is displayed inorder
   //       else the tree is displayed showing its tree
   //       structure
   // usage: tree.display (cout, 'p');
   void display(ostream& output, char which);

private:
   Two34TreeNode* root;
};
#endif
