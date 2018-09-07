/*
Alex Giacobbi and Jalen Tacsiat
agiacobbi
7 September 2018
key.cpp
Description: Implementation file of class Key
*/

#include "key.h"
#include <iostream>
using namespace std;

// creates an empty key / texting abbreviation
Key::Key() {

}

// destroys a key
Key::~Key() {

}

// reads a texting abbreviation from a file or the user
void Key::read(istream& inputstream) {
	inputstream >> textingAbbreviation;
}

// writes a texting abbreviation to a file or the screen
void Key::write(ostream& outputstream) {
	outputstream << textingAbbreviation;
}

// computes an integer from a texting abbreviation
int Key::convertToInteger() {
	int sum = 0;
	for(int i = 0; i < textingAbbreviation.length(); i++)
		sum += textingAbbreviation.at(i);
	return sum;
}

//copies rightHandSideKey texting abbreviation to key object's texting abbreviation
void Key::assign(const Key& rightHandSideKey) {
	textingAbbreviation = rightHandSideKey.textingAbbreviation;
}