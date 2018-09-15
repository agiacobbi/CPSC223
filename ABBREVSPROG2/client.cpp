// client program of class Key
// following Homework

#include "key.h"
#include "item.h"
#include <iostream>
#include <fstream>
using namespace std;

void keyFriendInputTest();
void keyFriendOutputTest();
void keyCopyConstructorTest();
void keyAssignTest();
void keyIsEqualTest();
void keyIsLessThanTest();
void itemFriendInputTest();
void itemFriendOutputTest();
void itemCopyConstructorTest();
void itemAssignTest();
void itemIsLessThanTest();
void itemIsEqualTest();
void itemConvertToIntTest();

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
    cout << firstOne;
    cout << "#" << endl;
    cout << endl;

    cout << "Testing the operator>> and operator<<" << endl;
    cout << "Gets input from user and writes to the screen" << endl;
    cout << "Enter a texting abbreviations -> ";  // note the arrow to show the user where to type and left on same line
    cin >> firstOne;
    cout << "shows result between # signs" << endl;
    cout << "#";
    cout << firstOne;
    cout << "#" << endl;
    cout << endl;

    cout << "Testing the read from file in.dat and write to file out.dat" << endl;
    cout << "text in in.dat will be read to Key firstOne and written to out.dat" << endl;
    firstIn.open("in.dat");
    firstOut.open("out.dat");
    firstIn >> firstOne;
    firstOut << firstOne;
    firstIn.close();
    firstOut.close();

    //int main() is getting pretty big lets try to decompose these tests into functions

    /*
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
    */
    return 0;
}
	
