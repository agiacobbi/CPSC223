// file: avltree.h

// Alex Giacobbi and Jalen Tacsiat
// agiacobbi
// date: 11/20/18
// specification file for avltree clss
// data object: an AVLTree which is in the form of empty or conists of a root with left and right trees that
//              are AVLTrees
// data structure: an AVLTree made of linked BinarySearchTrees and array that contains the search path of the avltree
// operations: adds items to the avl tree and displays the avltree in pretty fashion

#ifndef AVLTREE_H
#define AVLTREE_H

#include "binarysearchtree.h"

class AVLTree: public BinarySearchTree
{
public:

AVLTree();

~AVLTree();

// adds and item to the AVLTree
// pre: Items Exists
// post: Item is added into the AVLTree
// usage: myAVLTree.addNewEntry(myItem);
void addNewEntry(const Item& newItem) throw (Exception);

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
void prettyDisplay(ostream& output);
};
#endif
