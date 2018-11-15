// file: avltree.h

#ifndef AVLTREE_H
#define AVLTREE_H

#include "binarysearchtree.h"

class AVLTree: public BinarySearchTree
{
public:

AVLTree();

~AVLTree();

void addNewEntry(const Item& newItem) throw (Exception);
};
#endif
