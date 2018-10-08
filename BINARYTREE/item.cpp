/*
Alex Giacobbi and Jalen Tacsiat
agiacobbi
8 October 2018
Description: This is the implementation file for abstract data type Item. This file contains function headers and
bodies for the class Item's methods as well as documentation for each function. This data object is an Item which 
stores a texting abbreviation (inherited from Key) and an associated texting meaning. The class inherits functions 
and data members from class Key and has its own methods and friends that create, destroy, copy, assign, input, and 
output.
*/

#include "item.h"

//allows for input of an item from either the standard input device or a file
//pre input has been opened and readied for the input of
//    a texting abbreviation followed by newline and associated meaning with
//    spaces between words ending with a newline. For example:
//    lol
//    laugh out loud
//
//post rightHandSideItem has been filled with a texting abbreviation and its
//     associated meaning
//usage cin >> myItem;
istream& operator>> (istream& input, Item& rightHandSideItem)
{
	char newline;
	input >> rightHandSideItem.textingAbbreviation;
	input.get(newline);
	getline(input, rightHandSideItem.meaning); // extracts the newline
	return input;
}
 
//allows for the output of an item to the standard output device or a file
//pre rightHandSideItem has been filled with a texting abbreviation and
//    its associated meaning 
//    output has been opened
//post rightHandSideItem has been written to the output device
//     lol:  laugh out loud
//     there is no newline or eol after the meaning
//usage  outfile << myItem;
ostream& operator<< (ostream& output, const Item& rightHandSideItem)
{
	output << rightHandSideItem.textingAbbreviation << ": " << rightHandSideItem.meaning;
	return output;
}

//creates an empty item (texting abbreviation and its associated meaning)
//post Item object is an empty meaning
//usage Item aitem;
Item::Item()
{
	
}

//releases memory for a texting abbreviation and its associated meaning
//pre Item object exists
//post Item object no longer exists, memory has been freed
//usage automatically done at the end of scope
Item::~Item()
{
	
}

//creates a new item and copies the right hand side item into item
//pre rightHandSideItem exists and contains a texting abbreviation and its associated meaning
//post Item object is created and is a copy of rightHandSideItem
//usage  Item myItem(yourItem);
Item::Item(const Item& rightHandSideItem)
{
	textingAbbreviation = rightHandSideItem.textingAbbreviation;
	meaning = rightHandSideItem.meaning;
}

//copies a texting abbreviation and its associated meaning
//pre rightHandSideItem has been assigned a texting abbreviation and its associated meaning
//post Item object has a copy of rightHandSideItem
//usage bitem = aitem;
Item& Item::operator=(const Item& rightHandSideItem)
{
	if (this != &rightHandSideItem)
   {
		textingAbbreviation = rightHandSideItem.textingAbbreviation;
		meaning = rightHandSideItem.meaning;
   }
   return *this;
}
