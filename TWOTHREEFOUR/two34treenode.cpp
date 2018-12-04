// Implementation of ADT 2-3-4 Tree Node
//    data object: a node in a 2-3-4 Tree
//        contains room for 1-3 data items (just using keys)
//        contains room for 0-4 children
//    data structure: a static array for the data items and
//                    a static array for the children
//    operations: several creates, destroy, 
//       cleanUpNode,
// Built on class Key 

// This class will be used by class Two34Tree.
//     All members are public to give Two34Tree access.
// Alternatively, we could make Two34Tree a friend class
//     of this class and all members would be private.
// Programmer: dr y    Date: November 28, 2018
// Filename: two34treenode.cpp

#include "two34treenode.h"

// Creates an empty node
// post: node object is empty
// usage: Two34TreeNode node;
Two34TreeNode::Two34TreeNode ()
{
	for (int index = 0; index < 4; index++)
	   kids[index] = nullptr;
	
}

// Creates a leaf node with one item
// pre: newText is assigned.
// post: newText is in a 2-3-4 Tree Node with empty children
// usage: root = new Two34TreeNode (newText);
Two34TreeNode::Two34TreeNode (const Key& newText)
{
	theTexts[0] = newText;
	for (int index = 0; index < 4; index++)
	   kids[index] = nullptr;
	numberOfKeys = 1;
}
  
// Creates a non-leaf 2-node
// pre: newText, left and right are assigned
// post: newText is in a 2-3-4 Tree Node (like a binary tree)
//       with children left and right
// usage: mroot = new Two34TreeNode (newText, leftchild, rightchild);
Two34TreeNode::Two34TreeNode (const Key& newText, Two34TreeNode* left, Two34TreeNode* right)
{
	theTexts[0] = newText;
	kids[0] = left;
    kids[1] = right;
	numberOfKeys = 1;
}

// Destroys a node
// pre: node exists
// post: node does not exist
// usage: automatically called at the end of scope
Two34TreeNode::~Two34TreeNode()
{
   	
}

// Cleans up a node to become a 2-node
// pre: the node exists with an item
//    in leftmost position and left,right children
//    in leftmost positions and others
// Calls emptyIt from class Key
// post: the node's two data rightmost positions
//    have been emptied and two rightmost children
//    have been given away by social services.
// usage: treep -> cleanUpNode();
void Two34TreeNode::cleanUpNode()
{
	theTexts[1].emptyIt();
	theTexts[2].emptyIt();
	kids[2] = nullptr;
	kids[3] = nullptr;
	numberOfKeys = 1;
}


