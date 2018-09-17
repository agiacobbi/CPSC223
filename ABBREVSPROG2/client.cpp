/*
Alex Giacobbi and Jalen Tacsiat
agiacobbi
17 September 2018
Description: This is a client program that tests the member functions of abstract data types Key and Item.
This program is broken into functions that each test a different member function. The program is designed
to walk the user through each function and show that each function works as documented.
*/

#include "key.h"
#include "item.h"
#include <iostream>
#include <fstream>
using namespace std;

void testKeyFriendInputOutput();
void testKeyCopyConstructor();
void testKeyAssign();
void testKeyIsEqual();
void testKeyIsLessThan();
void testItemFriendInputOutput();
void testItemCopyConstructor();
void testItemAssign();
void testItemIsLessThan();
void testItemIsEqual();
void testItemConvertToInteger();

int main()
{
    // Testing ADT Key member functions
    testKeyFriendInputOutput();
    testKeyCopyConstructor();
    testKeyAssign();
    testKeyIsEqual();
    testKeyIsLessThan();

    // Testing ADT Item member functions
    testItemFriendInputOutput();
    testItemCopyConstructor();
    testItemAssign();

    // Testing ADT Key member functions inherited by ADT Item
    testItemIsEqual();
    testItemIsLessThan();
    testItemConvertToInteger();

    return 0;
}

void testKeyFriendInputOutput()
{
	Key keyOne, keyTwo, keyThree;
	fstream inputFile, outputFile;

    inputFile.open("in.dat");
	outputFile.open("out.dat");

	cout << "---Testing the ADT Key friends operator>> and operator<<---" << endl;
    cout << "Enter three texting abbreviations using cascading input-> "; 
	cin  >> keyOne >> keyTwo >> keyThree; // cascading input
	cout << endl << "Printing abbreviations between the # signs" << endl;
	cout << "#" << keyOne << "#" << endl << "#" << keyTwo << "#" << endl << "#" << keyThree << "#" << endl << endl; // cascading output
	
	cout << "---Testing the ADT Key friends operator>> and operator<< for files---" << endl;
    cout << "Texting abbreviations from in.dat will be written to out.dat" << endl << endl;
	inputFile >> keyOne >> keyTwo >> keyThree;
	outputFile << keyOne << keyTwo << keyThree;

	inputFile.close();
	outputFile.close();

}
void testKeyCopyConstructor()
{
	Key keyOne("lol");

	cout << "---Testing constructor that assigns a texting abbreviation (lol) to key---" << endl;
	cout << "Displaying the texting abbreviation between #s" << endl;
	cout << "#" << keyOne << "#" << endl << endl;
}

void testKeyAssign()
{
	Key keyOne, keyTwo, keyThree;

	cout << "---Testing operator= for ADT Key---" << endl;
	cout << "Enter a texting abbreviation for keyOne-> ";
	cin >> keyOne;

	cout << "Keys keyTwo and keyThree will be set equal to keyOne using operator=" << endl;
	keyThree = keyTwo = keyOne;

	cout << "Displaying keyOne, keyTwo and keyThree between #s" << endl;
    cout << "#" << keyOne << "#" << endl << "#" << keyTwo << "#" << endl << "#" << keyThree << "#" << endl << endl;
}
		
void testKeyIsEqual()
{
	Key keyOne, keyTwo;

	cout << "---Testing the operator== for ADT Key---" << endl;
	cout << "Enter a texting abbreviation for keyOne-> ";
    cin >> keyOne;
	cout << "Enter a texting abbreviation for keyTwo-> ";
    cin >> keyTwo;

	if (keyOne == keyTwo) 
        cout << "keyOne = keyTwo" << endl << endl;
	else 
	    cout << "keyOne != keyTwo" << endl << endl;

}	
	
void testKeyIsLessThan()
{
	Key keyOne, keyTwo;

    cout << "---Testing the operator< for ADT Key---" << endl;
	cout << "Enter a texting abbreviation for keyOne-> ";
	cin >> keyOne;
	cout << "Enter a texting abbreviation for keyTwo-> ";
	cin >> keyTwo;

	if (keyOne <  keyTwo)
		cout << "keyOne < keyTwo" << endl << endl;  
	else 
		cout << "keyOne >= keyTwo" << endl << endl;
}

void testItemFriendInputOutput()
{
    Item itemOne, itemTwo, itemThree;
    fstream inputFile, outputFile;

    inputFile.open("in.dat");
    outputFile.open("out.dat");

    cout << "---Testing the ADT Item friends operator>> and operator<<---" << endl;
    cout << "Enter three texting abbreviations and meanings using cascading input-> ";
    cin >> itemOne >> itemTwo >> itemThree; // cascading input
    cout << "Displaying itemOne, itemTwo, and itemThree between #s" << endl;
    cout << "#" << itemOne << "#" << endl << "#" << itemTwo << "#" << endl << "#" << itemThree << "#" << endl << endl; // cascading output

    cout << "---Testing the ADT Item friends operator>> and operator<< for files---" << endl;
    cout << "Texting abbreviations from in.dat will be written to out.dat" << endl << endl;
    inputFile >> itemOne >> itemTwo >> itemThree;
    outputFile << itemOne << itemTwo << itemThree;

    inputFile.close();
    outputFile.close();
}

void testItemCopyConstructor()
{
    Item itemOne;

    cout << "---Testing the copy constructor for ADT Item---" << endl;
    cout << "Enter a texting abbreviation and meaning-> ";
    cin >> itemOne;

    Item itemOneCopy(itemOne);

    cout << endl << "Displaying the copied ADT Item between #s" << endl;
    cout << "#" << itemOneCopy << "#" << endl;
}

void testItemAssign()
{
    Item itemOne, itemTwo, itemThree;

    cout << "---Testing operator= for ADT Item---" << endl;
    cout << "Enter a texting abbreviation and meaning for itemOne-> ";
    cin >> itemOne;

    cout << endl << "Items itemTwo and itemThree will be set equal to itemOne using operator=" << endl;
    itemThree = itemTwo = itemOne;

    cout << "Displaying itemOne itemTwo and itemThree between the #s" << endl;
    cout << "#" << itemOne << "#" << endl << "#" << itemTwo << "#" << endl << "#" << itemThree << "#" << endl;
}

void testItemIsLessThan()
{
    Item itemOne, itemTwo;

    cout << "---Testing the operator< inherited from ADT Key for ADT Item---" << endl;
    cout << "Enter a texting abbreviation and meaning for itemOne-> ";
    cin >> itemOne;
    cout << "Enter a texting abbreviation and meaning for itemTwo-> ";
    cin >> itemTwo;

    if (itemOne < itemTwo)
        cout << "itemOne < itemTwo" << endl << endl;
    else
        cout << "itemOne >= itemTwo" << endl << endl;

}

void testItemIsEqual()
{
    Item itemOne, itemTwo;

    cout << "---Testing the operator== inherited from ADT Key for ADT Item---" << endl;
    cout << "Enter a texting abbreviation and meaning for itemOne-> ";
    cin >> itemOne;
    cout << "Enter a texting abbreviation and meaning for itemTwo-> ";
    cin >> itemTwo;

    if (itemOne == itemTwo)
        cout << "itemOne = itemTwo" << endl << endl;
    else
        cout << "itemOne != itemTwo" << endl << endl;

}

void testItemConvertToInteger()
{
    Item itemOne;

    cout << "---Testing convertToInteger inherited from ADT Key for ADT Item---" << endl;
    cout << "Enter a texting abbreviation and meaning for itemOne-> ";
    cin >> itemOne;
    cout << "itemOne converted to an integer is: " << itemOne.convertToInteger() << endl;
}
