/*
Alex Giacobbi and Nathan Flack
agiacobbi
25 September 2018
Description: This is the header file for abstract data type Item. This file contains function prototypes
and documentation for the methods of class Dictionary. Abstract data type Dictionary will store Items in
a hash table. This file contains protypes for member functions and friends that handle the following 
operations: create, destroy, search for an item, insert an item, remove an item, check if dictionary is
full, check if empty, return number of entries, input, and output.
*/

#ifndef DICTIONARY_H
#define  DICTIONARY_H

#include "item.h"

struct DictionaryRecord;

class Dictionary
{
// displays a dictionary
// pre: output has been opened if it is a file
//      rightHandSideDictionary has been assigned items
// post: output contains each item on a separate line in the format with headings.
//       for example
//       address    text       meaning
//          0        lol       laugh out loud
//          1        ttyl      talk to you later
// usage: outfile << myDictionary;       
friend ostream& operator<< (ostream& output, const Dictionary& rightHandSideDictionary);

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
friend istream& operator>> (istream& input, Dictionary& rightHandSideDictionary);

public:

// creates a new dictionary
// post: Dictionary object exists but is empty
// usage: Dictionary myDictionary;	
Dictionary();

// destroys a dictionary
// pre: Dictionary object exists
// post: all memory for Dictionary object has been freed
// usage: automatically done at the end of scope
~Dictionary();

// searchs for a meaning with a given text
// pre targetText has been assigned 
// post if an item with texting abbreviation the same as targetText is found then
//          isFound is true and anItem is that item
//       else isFound is false
// usage  myDictionary.searchForMeaning(targetText, anItem, isFound);
void searchForMeaning(const Key& targetText, Item& anItem, bool& isFound);

// inserts a new text' item into the dictionary
// pre: newItem has been assigned
// post: if there is room in the Dictionary object and newItem's text
//            is not already there  isFull is false and isAlreadyThere is false
//            and newItem is appropriately added
//       else either isFull is true or isAlreadyThere is true, depending
// usage: myDictionary.addNewEntry(myItem, isFull, isAlreadyThere);
void addNewEntry(const Item& newItem, bool& isFull, bool& isAlreadyThere);

// removes the item associated with a given text from the dictionary
// pre: targetText is assigned
// post: if Dictionary object is not empty and 
//           targetText is found in Dictionary object, isFound is true
//           and the associated Item object (text and meaning) has been 
//           removed from the Dictionary object 
//       else isFound is false or isEmpty is true depending
// usage: myDictionary.deleteEntry(myText, isEmpty, isFound);
void deleteEntry(const Key& targetText, bool& isEmpty, bool& isFound);

// checks if the dictionary is empty
// pre: none
// post: if Dictionary object is empty function returns true
//       else function will return false
// usage: myDictionary.isEmpty();
bool isEmpty();

// checks if the dictionary is full
// pre: none
// post: if Dictionary object is full function returns true
//       else function will return false
// usage: myDictionary.isFull();
bool isFull();

// tells user how many items are in dictionary object
// pre: none
// post: returns the number of entries in the dictionary as an integer
// usage: myDictionary.getNumberOfEntries();
int getNumberOfEntries();

private:
   DictionaryRecord* dictionaryPtr;
};
#endif

