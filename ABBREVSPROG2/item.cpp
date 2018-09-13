//filename key.cpp
//author  Dr. Y
//date September 7, 2018
//Implementation of Abstract Data Type Key
//
//   data object: a key which is a texting abbreviation
//   operations: create, destroy, copy, 
//               input, output, assign
//               check if same, check if less than, 
//               convert to an integer

#include "key.h"
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

}
 
//allows for the output of an item to the standard output device or a file
//pre rightHandSideItem has been filled with a texting abbreviation and
//    its associated meaning 
//    output has been opened
//post rightHandSideItem has been written to the output device
//     lol:  laugh out loud
// 
//usage  outfile << myItem;
ostream& operator<< (ostream& output, const Item& rightHandSideItem)
{
    
}

//creates an empty item
//post Item object is an empty texting meaning
//usage Item itemA();
Item::Item()
{
   
}

//creates a specific texting meaning
//pre rightHandSideItem is an Item assigned a string that represents a texting meaning
//post Item object has a copy of the texting meaning in rightHandSideItem
//usage Item myItem(yourItem); 
Item::Item(const Item& rightHandSideItem)
{
    
}

//releases memory for a texting abbreviation
//pre Key object exists
//post Key object no longer exists, memory has been freed
//usage automatically done at the end of scope
Item::~Item()
{
   
}

//copies a texting meaning
//pre rightHandSideItem has been assigned a texting meaning
//post Item object has a copy of rightHandSideItem
//usage aItem = bItem;
Item& Item::operator=(const Item& rightHandSideItem)
{

}