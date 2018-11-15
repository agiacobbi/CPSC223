// section 1

// Harley Davis, Parker Mooseker, James Stevenson

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

// Team members: Jackson Ricks, Nathan Flack, Lotan Mizrahi, Max Nelson

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

// Alex Giacobbi, Eric Av, Elizabeth Larson, Michael Peters

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

// Members: Ian Gioffre, Nick Kenworthy, Daniel Weaver, Vincent Rettke, Jackson Lindsay

// tells whether the new item has been added to the short or tall side
// pre: SearchPath object exists
// post: returns true if added to the short side, false if added to the tall side
// usage: if(isAddedToShortSide(search))
bool isAddedToShortSide(const SearchPath& search)
{
	return ((search.path[search.pivotIndex] -> balance == -1 && search.path[search.pivotIndex + 1] == search.path[search.pivotIndex] -> rightChild)
	      ||(search.path[search.pivotIndex] -> balance ==  1 && search.path[search.pivotIndex + 1] == search.path[search.pivotIndex] -> leftChild));
}

//Team members: Allison Hayes, Tommy Engels, Maximillian Marciel, Tim Rodriguez

//Tests whether or not the AVL tree needs a right rotation.
//Pre: Search exists/ is initialized
//Post: Returns true if a right rotation is needed in the AVL tree.
//Usage: isSingleRotateRight(mySearchPath);
bool isSingleRotateRight(const SearchPath& search)
{
	return ((search.path[search.pivotIndex + 1] == search.path[search.pivotIndex] -> leftChild) &&
				(search.path[search.pivotIndex + 2] == search.path[search.pivotIndex + 1] -> leftChild));
}

// authors: Cade Newell, Jared Elliott, Sean Letts, Han Tang, Carlos Vazquez Baur

//	This function starts at the pivot and returns true if the search.path is the right right case
//  	and decides whether it needs a single left rotation
//	Pre: the AVL tree is populated with items and pivot index is assigned in the tree
//	Post: the function returns true if the search path goes right twice in a row
//		  and returns false otherwise
//	usage: isSingleRotateLeft(search);
bool isSingleRotateLeft(const SearchPath& search)
{
	if ((search.path[search.pivotIndex]->rightChild == search.path[search.pivotIndex + 1]) && (search.path[search.pivotIndex]->rightChild->rightChild == search.path[search.pivotIndex + 2]))
		return true;
	else
		return false;
}

// Names: Ghar Pautz, Jalen Tacsiat, Nicholas Lathan, Win Todd, Joey Turii

// goes to the pivot and checks to see if the avl tree goes left then right 
// pre: SearchPath exists
// post: returns true if search path goes left then right and false otherwise
// usage: isDoubleRotateLeftRight(SearchPath& mySearchPath);
bool isDoubleRotateLeftRight(const SearchPath& search)
{
	if (search.path[search.pivotIndex] -> leftChild == search.path[search.pivotIndex + 1])
	{
		if(search.path[search.pivotIndex + 1] -> rightChild == search.path[search.pivotIndex + 2])
			return true;
	}
	return false;
}
