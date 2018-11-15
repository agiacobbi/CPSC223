// file: avltree.cpp

#include "avltree.h"

const int MAXHEIGHT = 15;

struct SearchPath
{
    TreeNode* path[MAXHEIGHT];
    int size;
    int pivotIndex;
    SearchPath();
}

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
void writePrettyWithBalances(TreeNode* treep, int level)
{
    if (treep != nullptr)
	{
		writePretty(treep -> rightChild, level += 1);
			if (treep -> rightChild != nullptr)
			{
				for (int j = 0; j <= level; j++)
				cout << '\t';
				cout << "/" << endl;
			}
		if (level == 1)
			cout << "root ->" ;
		else	
		{			
			for (int i = 0; i < level; i++)
				cout << '\t' ;
		}
		Key text = treep -> item;
		cout << "  " << text << ": " << treep -> balance << endl;
		 if (treep -> leftChild != nullptr)
        {
            for (int i = 0; i <= level; i++)
                cout << '\t';
            cout << "\\" << endl;
			writePretty(treep -> leftChild, level);
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
void addnewEntryAndMakeSearchPath(const Item& newItem, TreeNode*& treeptr, SearchPath& search) throw (Exception)
{
	if (treeptr != nullptr)
	{
		search.path[search.size] = treeptr;
		search.size += 1;
		
		if (newItem == treeptr -> item)
		{
			throw Exception("That abbreviation is already in the dictionary.");
		} else if ( newItem < treeptr -> item) {
			addnewEntryAndMakeSearchPath(newItem, treeptr -> leftChild, search);
		} else {
			addnewEntryAndMakeSearchPath(newItem, treeptr -> rightChild, search);
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
		else
			search.path[start] -> balance++;
		start++;
	}
}

// tells whether the new item has been added to the short or tall side
// pre: SearchPath object exists
// post: returns true if added to the short side, false if added to the tall side
// usage: if(isAddedToShortSide(search))
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
            (search.path[search.pivotIndex]->rightChild->rightChild == search.path[search.pivotIndex + 2]))
}

// goes to the pivot and checks to see if the avl tree goes left then right 
// pre: SearchPath exists
// post: returns true if search path goes left then right and false otherwise
// usage: isDoubleRotateLeftRight(SearchPath& mySearchPath);
bool isDoubleRotateLeftRight(const SearchPath& search)
{
	return (search.path[search.pivotIndex] -> leftChild == search.path[search.pivotIndex + 1]) &&
	       (search.path[search.pivotIndex + 1] -> rightChild == search.path[search.pivotIndex + 2])
}

// ---------------  MEMBER FUNCTIONS  ---------------
AVLTree::AVLTree()
{
    
}

AVLTree::~AVLTree()
{

}

void AVLTree::addNewEntry(const Item& newItem) throw (Exception)
{
    SearchPath search;

    addNewEntryAndMakeSearchPath(root, newItem, search);
    if (hasNoPivot(search))
        fixBalances(search, 0);
    else if (isAddedToShortSide(search))
        fixBalances(search, search.pivotIndex)
    else if (isSingleRotateleft(search))
        //do singleLeftRotation
    else if (isSingleRotateRight(search))
        //do singleRightRotation
    else if (
}
