// Specification of ADT Dictionary as ADT Binary Search Tree
//     data object: a bunch of texting abbreviations and their meanings 
//     operations: create, destroy
//                 search the dictionary for an item given its text
//                 insert a new item into the dictionary
//                 remove an item from the dictionary given its text
//   associated operations: input and output
// filename binarysearchtree.h
// date October 24, 2018


#include "binarysearchtree.h"

// recursive helper functions

// searches a binary search tree for a certain text
// pre: treep is assigned a pointer to a root node of a binary search tree
//      targetText is assigned
// post: if targetText is found in the tree whose root node is treep
//          then the item in the root node is copied into anItem and
//          returns true; otherwise, returns false
// usage: isFound = searchHelper(root, targetText, anItem);
bool searchHelper(TreeNode* treep, const Key& targetText, Item& anItem)
{
   if (treep != nullptr)
   {
      if (targetText == treep -> item)
      {
         anItem = treep -> item;
         return true;
      } else if (targetText < treep -> item) {
         return searchHelper(treep -> leftChild, targetText, anItem);
      } else {
         return searchHelper(treep -> rightChild, targetText, anItem);
      }
   } else {
      return false;
   }
}

void addHelper(TreeNode*& treep, const Item& newItem, int& numberOfEntries) throw (Exception)
{
    if (treep != nullptr)
    {
        if (newItem == treep->item)
        {
            throw Exception("already in tree");
        } else if (newItem < treep->item) {
            addHelper(treep->leftChild, newItem, numberOfEntries);
        } else {
            addHelper(treep->rightChild, newItem, numberOfEntries);
        }
    } else {
        treep = new (nothrow) TreeNode(newItem, nullptr, nullptr);
        if (treep == nullptr)
            throw Exception("not enough memory");
		else
			numberOfEntries++;
    }
}

void rebalanceTreeHelper(TreeNode*& treep, istream& input, int numberOfEntries)
{
	Item anItem;
	if (numberOfEntries > 0)
	{
		treep = new (nothrow) TreeNode(anItem, nullptr, nullptr);
		
		rebalanceTreeHelper(treep -> leftChild, input, numberOfEntries / 2);
		
		input >> treep -> item;
		
		rebalanceTreeHelper(treep -> rightChild, input, (numberOfEntries - 1) / 2);
		
	}
	
}



void inordertraverseHelper(TreeNode* treep,ostream& output)
{
	
	if (treep != nullptr)
	{
		
		inordertraverseHelper(treep -> leftChild, output);
		output << treep -> item << endl;
		inordertraverseHelper(treep -> rightChild, output);
	}
}

void outputHelper (TreeNode* treep, int level, ostream& output)
{
	if (treep != nullptr)
	{
		outputHelper(treep -> rightChild, level += 1, output);
		if (treep -> rightChild != nullptr)
		{
			for (int j = 0;j <= level;j++)
				output << '\t';
			output << "/" << endl;
		}
		if (level == 1)
			output << "root ->" ;
		else	
		{			
			for (int i = 0; i < level; i++)
				output << '\t' ;
		}
		Key text = treep -> item;
		output << "  " << text << endl;
		 if (treep -> leftChild != nullptr)
        {
            for (int i = 0; i <= level; i++)
                output << '\t';
            output << "\\" << endl;
			outputHelper(treep -> leftChild, level, output);
		}
	}		
}	

// displays a dictionary
// pre: output has been opened if it is a file
//      rightHandSideDictionary has been assigned items
// post: output contains each item on a separate line in the format with headings.

// usage: outfile << myDictionary;    
ostream& operator<< (ostream& output, const BinarySearchTree& rightHandSideDictionary)
{
	outputHelper(rightHandSideDictionary.root, 1 , output);
	return output;
}

// inputs items into a dictionary
// pre: input has been opened if it is a file
//      items are arranged in the following format
//      2
//      lol
//      laugh out loud
//      ttyl
//      talk to you later
// post: if there is room, 
//       all items in the input have been stored in rightHandSideDictionary
// usage: infile >> myDictionary;
istream& operator>> (istream& input, BinarySearchTree& rightHandSideDictionary)
{
	int numberToInsert;
	Item newItem;
	input >> numberToInsert;
	
	try
	{ 
		for (int i = 0; i < numberToInsert; i++)
		{
			input >> newItem;
			rightHandSideDictionary.addNewEntry(newItem);
			
		}
	
	}
	
	catch (Exception ex)
	{
		cout << ex.what() << endl << endl;
	}
	
	return input;
}

// creates a new dictionary
// post: BinarySearchTree object exists but is empty
// usage: BinarySearchTree myDictionary;	
BinarySearchTree::BinarySearchTree()
{
	numberOfEntries = 0;
}

// destroys a dictionary
// pre: BinarySearchTree object exists
// post: all memory for BinarySearchTree object has been freed
// usage: automatically done at the end of scope
BinarySearchTree::~BinarySearchTree()
{
	
}

// searchs for a meaning with a given text
// pre targetText has been assigned a value not already in the hash table
// post if an item with texting abbreviationthe same as targetText is found then
//          isFound is true and theItem is that item
//       else isFound is false
// usage  myDictionary.searchForMeaning(targetText, anItem, isFound);
void BinarySearchTree::searchForMeaning(const Key& targetText, Item& anItem, bool& isFound)
{
	isFound = searchHelper(root, targetText, anItem);
}

// inserts a new text' item into the dictionary
// pre: newItem has been assigned
// post: if there is room in the BinarySearchTree object and newItem's text
//            is not already there then newItem is appropriately added
//       else it throws an exception for either a full dictionary or
//            a message that it is already there
// usage: myDictionary.addNewEntry(myItem, isFull, isAlreadyThere);
void BinarySearchTree::addNewEntry(const Item& newItem) throw (Exception)
{  
    addHelper(root, newItem, numberOfEntries);   
}

// removes the item associated with a given text from the dictionary
// pre: targetText is assigned
// post: if BinarySearchTree object is not empty and 
//           targetText is found in Dictionary object, isFound is true
//           and the associated Item object (text and meaning) has been 
//           removed from the Dictionary object 
//       else throws an exception if key is not found or dictionary is empty
// usage: myDictionary.deleteEntry(myText, isEmpty, isFound);
void BinarySearchTree::deleteEntry(const Key& targetText) throw (Exception)
{
	
}

void BinarySearchTree::inorderTraverse(ostream &output)
{
	output << numberOfEntries << endl; 
	inordertraverseHelper(root, output);
}

void BinarySearchTree::rebalanceTree(istream& input)
{
	int num;
	
	input >> num;
	rebalanceTreeHelper(root, input, num);
}

