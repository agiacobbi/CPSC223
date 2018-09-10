#include "key.h"
#include <iostream>
using namespace std;

// creates an empty key / texting abbreviation
Key::Key() {

}

//creates a specific texting abbreviation
//pre keyText is assigned a string that represents a texting abbreviation
//post Key object has a copy of the texting abbreviation in keyText
//usage Key akey("lol"); 
Key::Key(string keyText){
    textingAbbreviation = keyText;
}

// destroys a key
Key::~Key() {

}

//allows for input of a key object from either the standard input device or a file
//pre input has been opened or a prompt has been given
//post rightHandSideKey has been filled with a texting abbreviation
//usage cin >> mykey;
istream& operator>> (istream& input, Key& rightHandSideKey){
    input >> rightHandSideKey.textingAbbreviation;
}

//allows for the output of a key to the standard output device or a file
//pre rightHandSideKey has been filled with a texting abbreviation; output has been opened
//post rightHandSideKey has been written to the output device with no spaces before or after
//usage  outfile << mykey;
ostream& operator<< (ostream& output, const Key& rightHandSideKey){
    output << rightHandSideKey.textingAbbreviation;
}

//copies a texting abbreviation
//pre rightHandSideKey has been assigned a texting abbreviation
//post Key object has a copy of rightHandSideKey
//usage bkey = akey;
Key& Key::operator=(const Key& rightHandSideKey){
    textingAbbreviation = rightHandSideKey.textingAbbreviation;
}

// computes an integer from a texting abbreviation
int Key::convertToInteger() const {
	int sum = 0;
	for(int i = 0; i < textingAbbreviation.length(); i++)
		sum += textingAbbreviation.at(i);
	return sum;
}

//checks if two texting abbreviations are the same
//pre rightHandSideKey has been assigned
//post returns true if Key object is the same exact texting abbreviation as that in rightHandSideKey
//usage if (akey == bkey) { cout << "the texting abbreviations are the same" << endl;
bool Key::operator==(const Key& rightHandSideKey) const{
    if(textingAbbreviation == rightHandSideKey.textingAbbreviation)
        return true;
    return false;
}

//checks if one texting abbreviation is less than another
//pre rightHandSideKey has been assigned a texting abbreviation
//post returns true if Key object's texting abbreviation is less than (alphabetically) the one in rightHandSideKey
//usage if (akey < bkey) { cout << "left text is less than right text" << endl;
bool Key::operator<(const Key& rightHandSideKey) const{
    if(textingAbbreviation < rightHandSideKey.textingAbbreviation)
        return true;
    return false;
}