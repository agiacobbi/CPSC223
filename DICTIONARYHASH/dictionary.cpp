// Implementation of ADT Dictionary
//     data object: a bunch of texting abbreviations and their meanings 
//     operations: create, destroy
//                 search the dictionary for an item given its text
//                 insert a new item into the dictionary
//                 remove an item from the dictionary given its text
//   associated operations: input and output
// filename dictionary.cpp
// authors: CPSC 223 class members section 1 and 2 and a few changes by Dr. Y
// date September 14, 2018

#include "dictionary.h"
#include <iomanip>
using namespace std;

const int TABLESIZE = 7;

struct DictionaryRecord
{
   Item* hashTablePtr;
   int numberStored;
};

int hashFunction(const Key& theText)
{
   return theText.convertToInteger() % TABLESIZE;
}

// displays a dictionary
// pre: output has been opened if it is a file
//      rightHandSideDictionary has been assigned items
// post: output contains each item on a separate line in the format with headings.
//       for example
//       address    text       meaning
//          0        lol       laugh out loud
//          1        ttyl      talk to you later
// usage: outfile << myDictionary;    
ostream& operator<< (ostream& output, const Dictionary& rightHandSideDictionary)
{

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
istream& operator>> (istream& input, Dictionary& rightHandSideDictionary)
{
 
   return input;
}

// creates a new dictionary
// post: Dictionary object exists but is empty
// usage: Dictionary myDictionary;
Dictionary::Dictionary()
{
   dictionaryPtr = new DictionaryRecord;
   dictionaryPtr -> numberStored = 0;
   dictionaryPtr -> hashTablePtr = new Item [TABLESIZE];
}

// destroys a dictionary
// pre: Dictionary object exists
// post: all memory for Dictionary object has been freed
// usage: automatically done at the end of scope
Dictionary::~Dictionary()
{
 
}

// you finish by copy pasting from dictionary.h