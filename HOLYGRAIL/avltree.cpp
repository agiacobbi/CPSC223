// file: avltree.cpp
// Alex Giacobbi and Jalen Tacsiat
// agiacobbi
// date: 11/20/18
// implementation file for avltree.cpp
// data object: an AVLTree which is in the form of empty or conists of a root with left and right trees that
//              are AVLTrees
// data structure: an AVLTree made of linked BinarySearchTrees and array that contains the search path of the avltree

/* operations: This is the implementation file of avltree class. This file contains the headers and bodies of the avltree
			   The addNewEntry method is used to add an Item to the AVLTree. The prettyDisplay is used to display the AVLTrees 
			   in pretty fashion. This file contains recursive helper functions to assist with the methods addNewEntry and prettyDisplay. The first
			   set of helper functions return booleans based on the direction of the searchPath.The helper function addNewEntryAndMakeSearchPath 
			   is used to add an item to the avltree and create the search path for an avltree. hasNoPivot is used to check if a search path has a 
			   pivot point. fixBalances is used to correct each node's balance and matches the definition of an avltree. isAddedToShortSide is used 
			   to check if an item is added to the short side of the tree. isSingleRotateLeft is used to check if the searchPath goes left. isSingleRotateRight 
			   is used to check if the search path goes right. isDoubleRotateLeftRight is used to check if a search path goes left then right. 
			   The next set of helpers functions are used to do the rotations. singleRotateLeft is used to rotate the avltree about the pivotpoint once to the left. 
			   singleRotateRight is used to rotate the avltree about the pivotpoint once to the right. doubleRotateLeftRight is used to rotate the avltree about the 
			   pivotpoint to the left and to the right. doubleRotateRightLeft is used to rotate the avltree about the pivotpoint to the right and to the left. the writePrettyWithBalances
			   helper is used to display the avltree with the amount of balances it has. 
*/

#include "avltree.h"

const int MAXHEIGHT = 15;

struct SearchPath
{
    TreeNode* path[MAXHEIGHT];
    int size;
    int pivotIndex;
    SearchPath();
};

SearchPath::SearchPath()
{
    size = 0;
    pivotIndex = -1;
    for (int i = 0; i < MAXHEIGHT; i++)
        path[i] = nullptr;
}

// ---------------  HELPER FUNCTIONS  ---------------

// recursive helper for prettyDisplay. You do the doc
// Pre: treep points to the root of the binaryTree
// Post: Displays the contents of the binary tree
// Usage: writePretty(root, int)
void writePrettyWithBalances(TreeNode* treep, int level, ostream& output)
{
    if (treep != nullptr)
	{
		writePrettyWithBalances(treep -> rightChild, level += 1, output);
			if (treep -> rightChild != nullptr)
			{
				for (int j = 0; j <= level; j++)
				output << "        ";
				output << "/" << endl;
			}
		if (level == 1)
			output << "root ->" ;
		else	
		{			
			for (int i = 0; i < level; i++)
				output << "        " ;
		}
		Key text = treep -> item;
		output << "  " << text << ": " << treep -> balance << endl;
		 if (treep -> leftChild != nullptr)
        {
            for (int i = 0; i <= level; i++)
                output << "        ";
            output << "\\" << endl;
			writePrettyWithBalances(treep -> leftChild, level, output);
		}
	}
}


// Helper function that adds new entry to the search tree
//		and creates a search path from root to new entry
// Pre: treeptr points an AVL tree, search is empty SearchPath
//		with size zero and newItem exists. 
// Post: newItem is added to the tree and 
//		search is a search path from root to new entry
//		with appropriate size
//		If newItem is already in the search tree or
//		there was no memory for new TreeNode exception
//		is thrown.
// Usage: addNewEntryAndMakeSearchPath(newItem, root, search);
void addNewEntryAndMakeSearchPath(const Item& newItem, TreeNode*& treeptr, SearchPath& search) throw (Exception)
{
	if (treeptr != nullptr)
	{
		search.path[search.size] = treeptr;
		search.size += 1;
		
		if (newItem == treeptr -> item)
		{
			throw Exception("That abbreviation is already in the dictionary.");
		} else if ( newItem < treeptr -> item) {
			addNewEntryAndMakeSearchPath(newItem, treeptr -> leftChild, search);
		} else {
			addNewEntryAndMakeSearchPath(newItem, treeptr -> rightChild, search);
		}
	} else {
		treeptr = new (nothrow) TreeNode(newItem, nullptr, nullptr);
		search.path[search.size] = treeptr;
		search.size += 1;
	} 
   
   if ( treeptr == nullptr )
	   throw Exception("There was not enough memory to add a new abbreviation.");
}

// Detects whether the AVLTree has a pivot and assigns pivotIndex to 
//		the location of the node containing the pivot
// Pre: SearchPath has been declared, AVLTree exists
// Post: If there is a pivot, pivot index is assigned in search 
// 			to the location of the node containing the pivot and we return false, 
//			else return true
// usage: bool pivot = hasNoPivot(search);
bool hasNoPivot(SearchPath& search)
{
   int index = search.size - 1;
   while(index >= 0)
   {
      if(search.path[index] -> balance != 0)
	  {
		 search.pivotIndex = index;
	     return false;
	  }
	  index--;		
   }
   return true;
}

// Changes the balances along the search path
// Pre search path is on an existing AVL tree, but the balances are not correct
// Post each node's balance is correct and fits the definition of an AVL tree
// usage: fixBalances(search, start);
void fixBalances(const SearchPath& search, int start)
{
	while (start < search.size - 1)
	{
		if (search.path[start] -> leftChild == search.path[start + 1])
			search.path[start] -> balance--;
		else if (search.path[start] -> rightChild == search.path[start + 1])
			search.path[start] -> balance++;
		else
			search.path[start] -> balance = 0;
		start++;
	}
}

// tells whether the new item has been added to the short or tall side
// pre: SearchPath object exists
// post: returns true if added to the short side, false if added to the tall side
// usage: if(isAddedToShortSide(search));
bool isAddedToShortSide(const SearchPath& search)
{
	return ((search.path[search.pivotIndex] -> balance == -1 && search.path[search.pivotIndex + 1] == search.path[search.pivotIndex] -> rightChild) ||
            (search.path[search.pivotIndex] -> balance ==  1 && search.path[search.pivotIndex + 1] == search.path[search.pivotIndex] -> leftChild));
}

// Tests whether or not the AVL tree needs a right rotation.
// Pre: Search exists/ is initialized
// Post: Returns true if a right rotation is needed in the AVL tree.
// Usage: isSingleRotateRight(mySearchPath);
bool isSingleRotateRight(const SearchPath& search)
{
	return ((search.path[search.pivotIndex + 1] == search.path[search.pivotIndex] -> leftChild) &&
			(search.path[search.pivotIndex + 2] == search.path[search.pivotIndex + 1] -> leftChild));
}

//	This function starts at the pivot and returns true if the search.path is the right right case
//  	and decides whether it needs a single left rotation
//	Pre: the AVL tree is populated with items and pivot index is assigned in the tree
//	Post: the function returns true if the search path goes right twice in a row
//		  and returns false otherwise
//	usage: isSingleRotateLeft(search);
bool isSingleRotateLeft(const SearchPath& search)
{
	return ((search.path[search.pivotIndex]->rightChild == search.path[search.pivotIndex + 1]) && 
            (search.path[search.pivotIndex]->rightChild->rightChild == search.path[search.pivotIndex + 2]));
}

// goes to the pivot and checks to see if the avl tree goes left then right 
// pre: SearchPath exists
// post: returns true if search path goes left then right and false otherwise
// usage: isDoubleRotateLeftRight(SearchPath& mySearchPath);
bool isDoubleRotateLeftRight(const SearchPath& search)
{
	return (search.path[search.pivotIndex] -> leftChild == search.path[search.pivotIndex + 1]) &&
	       (search.path[search.pivotIndex + 1] -> rightChild == search.path[search.pivotIndex + 2]);
}

<<<<<<< HEAD
// does a single rotation to the left at the pivot point
// pre: SearchPath and TreeNode root exists 
// post: pivot point is rotated once to the left
// usage: singleRotateLeft(mysearchpath, myroot);
void singleRotateLeft(SearchPath& search, TreeNode*& root)
{
	TreeNode* prev = search.path[search.pivotIndex - 1];
	TreeNode* pivot = search.path[search.pivotIndex];
	TreeNode* child = search.path[search.pivotIndex + 1];
	
	if (search.pivotIndex != 0)
	{
		if (prev -> leftChild == pivot)
			prev -> leftChild = child;
		else
			prev -> rightChild =  child;
	}
	else
		root = child;
	pivot -> rightChild = child -> leftChild;
	child -> leftChild = pivot;
	
	search.size--;
}

// does a single rotation to the right at the pivot point
// pre: SearchPath and TreeNode root exists 
// post: pivot point is rotated once to the right
// usage: singleRotateRight(mysearchpath, myroot);
void singleRotateRight(SearchPath& search, TreeNode*& root)
{
	TreeNode* prev = search.path[search.pivotIndex - 1];
	TreeNode* pivot = search.path[search.pivotIndex];
	TreeNode* child = search.path[search.pivotIndex + 1];
	
	if (search.pivotIndex != 0)
	{
		if (prev -> leftChild == pivot)
			prev -> leftChild = child;
		else
			prev -> rightChild =  child;
	}
	else
		root = child;
	pivot -> leftChild = child -> rightChild;
	child -> rightChild = pivot;
	
	search.size--;
}

// does a double rotation to the left and right at the pivot point
// pre: SearchPath and TreeNode root exists 
// post: pivot point is rotated to the left and to the right
// usage: doubleRotateLeftRight(mysearchpath, myroot);
void doubleRotateLeftRight(SearchPath& search, TreeNode*& root)
{
	TreeNode* prev = search.path[search.pivotIndex - 1];
	TreeNode* pivot = search.path[search.pivotIndex];
	TreeNode* child = pivot -> leftChild;
	TreeNode* grandchild = child -> rightChild;
	
	if (search.pivotIndex != 0)
	{
		if (prev -> leftChild == pivot)
			prev -> leftChild = grandchild;
		else
			prev -> rightChild =  grandchild;
	}
	else
		root = grandchild;
	child -> rightChild = grandchild -> leftChild;
	pivot -> leftChild = grandchild -> rightChild;
	grandchild -> leftChild = child;
	grandchild -> rightChild = pivot;
}

// does a double rotation to the right and left at the pivot point
// pre: SearchPath and TreeNode root exists 
// post: pivot point is rotated to the right and to the left
// usage: doubleRotateRightLeft(mysearchpath, myroot);
void doubleRotateRightLeft(SearchPath& search, TreeNode*& root)
{
	TreeNode* prev = search.path[search.pivotIndex - 1];
	TreeNode* pivot = search.path[search.pivotIndex];
	TreeNode* child = pivot -> rightChild;
	TreeNode* grandchild = child -> leftChild;
	
	if (search.pivotIndex != 0)
	{
		if (prev -> leftChild == pivot)
			prev -> leftChild = grandchild;
		else
			prev -> rightChild =  grandchild;
	}
	else
		root = grandchild;
	child -> leftChild = grandchild -> rightChild;
	pivot -> rightChild = grandchild -> leftChild;
	grandchild -> rightChild = child;
	grandchild -> leftChild = pivot;

// ---------------  MEMBER FUNCTIONS  ---------------
AVLTree::AVLTree()
{
    
}

AVLTree::~AVLTree()
{

}

// adds and item to the AVLTree
// pre: Items Exists
// post: Item is added into the AVLTree
// usage: myAVLTree.addNewEntry(myItem);
void AVLTree::addNewEntry(const Item& newItem) throw (Exception)
{
    SearchPath search;

    addNewEntryAndMakeSearchPath(newItem, root, search);
    if (hasNoPivot(search)) {
        fixBalances(search, 0);
    } else if (isAddedToShortSide(search)) {
        fixBalances(search, search.pivotIndex);
    } else if (isSingleRotateLeft(search)) {
        singleRotateLeft(search, root);
		fixBalances(search, search.pivotIndex + 2);
		search.path[search.pivotIndex] -> balance--;
	} else if (isSingleRotateRight(search)) {
        singleRotateRight(search, root);
		fixBalances(search, search.pivotIndex + 2);
		search.path[search.pivotIndex] -> balance++;
    } else if (isDoubleRotateLeftRight(search)) {
		doubleRotateLeftRight(search, root);
		fixBalances(search, search.pivotIndex + 2);
		search.path[search.pivotIndex] -> balance++;
	} else {
		doubleRotateRightLeft(search, root);
		fixBalances(search, search.pivotIndex + 2);
		search.path[search.pivotIndex] -> balance--;
	}
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
void AVLTree::prettyDisplay(ostream& output)
{
    writePrettyWithBalances(root, 0, output);
}
