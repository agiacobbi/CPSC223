/*
Alex Giacobbi and Jalen Tacsiat
agiacobbi
7 September 2018
testingclient.cpp
Description: Program to test member function of class Key
*/

#include "key.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    Key firstOne;
    Key secondOne;
    ifstream firstIn;
    ofstream firstOut;

    cout << endl << endl;    // to move first output away from command prompt 

    cout << "Testing the constructor" << endl;
    cout << "string is empty and show nothing between # signs" << endl;
    cout << "#";
    firstOne.write(cout);
    cout << "#" << endl;
    cout << endl;

    cout << "Testing the read from a user and write to the screen " << endl;
    cout << "Enter a texting abbreviations -> ";  // note the arrow to show the user where to type and left on same line
    firstOne.read(cin);
    cout << "shows result between # signs" << endl;
    cout << "#";
    firstOne.write(cout);
    cout << "#" << endl;
    cout << endl;

    cout << "Testing the read from file in.dat and write to file out.dat" << endl;
    cout << "text in in.dat will be read to Key firstOne and written to out.dat" << endl;
    firstIn.open("in.dat");
    firstOut.open("out.dat");
    firstOne.read(firstIn);
    firstOne.write(firstOut);
    firstIn.close();
    firstOut.close();

    cout << "shows result between # signs" << endl;
    cout << "#";
    firstOne.write(cout);
    cout << "#" << endl;
    cout << endl;

    cout << "Testing the convertToInteger and shows result to the screen" << endl;
    cout << firstOne.convertToInteger() << endl << endl;

    cout << "Testing the assign on secondOne and shows result to the screen" << endl;
    cout << "string is empty and show nothing between # signs" << endl;
    cout << "#";
    secondOne.write(cout);
    cout << "#" << endl;
    cout << endl;

    secondOne.assign(firstOne);

    cout << "assign funciton is called and secondOne shows between # signs" << endl;
    cout << "#";
    secondOne.write(cout);
    cout << "#" << endl;
    cout << endl;

    return 0;
}
