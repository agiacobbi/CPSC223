/*
Alex Giacobbi and Jalen Tacsiat
agiacobbi
7 September 2018
key.h
Description: Function prototypes and documentation for class Key
*/

#ifndef KEY_H
#define KEY_H

#include <string>
#include <iostream>
using namespace std;

class Key {
    public:
        // creates an empty key / texting abbreviation
        Key();

        // destroys a key
        ~Key();

        // reads a texting abbreviation from a file or the user
        void read(istream& inputstream);

        // writes a texting abbreviation to a file or the screen
        void write(ostream& outputstream);

        // computes an integer from a texting abbreviation
        int convertToInteger();

        // copies rightHandSideKey texting abbreviation to key object's texting abbreviation
        void assign(const Key& rightHandSideKey);

    private:
        string textingAbbreviation;
};

#endif
