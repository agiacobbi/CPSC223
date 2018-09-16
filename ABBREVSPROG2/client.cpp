// client program of class Key
// following Homework

#include "key.h"
#include "item.h"
#include <iostream>
#include <fstream>
using namespace std;

void keyFriendInputOutputTest();
void keyCopyConstructorTest();
void keyAssignTest();
void keyIsEqualTest();
void keyIsLessThanTest();
void itemFriendInputOutputTest();
void itemCopyConstructorTest();
void itemAssignTest();
void itemIsLessThanTest();
void itemIsEqualTest();
void itemConvertToIntTest();

int main()
{
    // Testing ADT Key member functions
    keyFriendInputOutputTest();
    keyCopyConstructorTest();
    keyAssignTest();
    keyIsEqualTest();
    keyIsLessThanTest();

    // Testing ADT Item member functions
    itemFriendInputOutputTest();
    itemCopyConstructorTest();
    itemAssignTest();

    // Testing ADT Key member functions inherited by ADT Item
    itemIsLessThanTest();
    itemIsEqualTest();
    itemConvertToIntTest();

    return 0;
}

void keyFriendInputOutputTest(){
	Key keyOne, keyTwo, keyThree;
	fstream inputFile, outputFile;

    inputFile.open("in.dat");
	outputFile.open("out.dat");

	cout << "---Testing the ADT Key friends operator>> and operator<<---" << endl;
    cout << "Enter three texting abbreviations" << endl;
	cin  >> keyOne >> keyTwo >> keyThree;
	cout << "Printing abbreviations between the # signs" << endl;
	cout << "#" << keyOne << "#" << keyTwo << "#" << keyThree << "#" << endl;
	
	cout << "Testing the ADT Key friends operator>> and operator<< for files" << endl;
    cout << "Texting abbreviations from in.dat will be written to out.dat" << endl;
	inputFile >> keyOne >> keyTwo >> keyThree;
	outputFile << keyOne << keyTwo << keyThree << endl;

	inputFile.close();
	outputFile.close();
}
void keyCopyConstructorTest(){
	Key keyOne("lol");

	cout << "---Testing constructor that initializes Key with a specified abbreviation---" << endl;
	cout << "keyOne is initialized to \"lol\"  and displayed between #s" <<endl;
	cout << "#" << keyOne << "#" << endl << endl;
}
void keyAssignTest(){
	Key keyOne, keyTwo, keyThree;

	cout << "---Testing operator= for ADT Key---" << endl;
	cout << "Enter a texting abbreviation for keyOne" << endl;
	cin >> keyOne;

	cout << "Keys keyTwo and keyThree will be set equal to keyOne using operator=" << endl;
	keyOne = keyTwo = keyThree;

	cout << "Displaying keyOne, keyTwo and keyThree" << endl;
    cout << keyOne << endl << keyTwo << endl << keyThree << endl;
}
		
void keyIsEqualTest(){
	Key keyOne, keyTwo;

	cout << "---Testing the operator== for ADT Key---" << endl;
	cout << "Enter a texting abbreviation->";
    cin >> keyOne;
	cout << "Enter a texting abbreviation->";
    cin >> keyTwo;

	if (keyOne == keyTwo) 
        cout << "Texting abbreviations are the same" << endl;
	else 
	    cout << "Texting abbreviations are different" << endl;
}	
	
void keyIsLessThanTest(){
	Key keyOne, keyTwo;

    cout << "---Testing the operator< for ADT Key---" << endl;
	cout << "Enter a texting abbreviation->";
	cin >> keyOne;
	cout<< " Enter a texting abbreviation->";
	cin>> keyTwo;

	if (keyOne <  keyTwo)
		cout << "The first texting abbreviation is less than the second texting abbreviation" << endl;  
	else 
		cout << "The first texting abbreviation is not less than the second texting abbreviation" << endl;
}

void itemFriendInputOutputTest()
{
    Item testItem1, testItem2, testItem3;
    fstream inputFile, outputFile;

    inputFile.open("in.dat");
    outputFile.open("out.dat");

    cout << "---Testing the ADT Item friends operator>> and operator<<---" << endl;
    cout << "Enter three texting abbreviations and meanings" << endl;
    cin >> testItem1 >> testItem2 >> testItem3;
    cout << "Printing items to screen" << endl;
    cout << testItem1 << testItem2 << testItem3 << endl;

    cout << "Testing the ADT Item friends operator>> and operator<< for files" << endl;
    inputFile >> testItem1 >> testItem2 >> testItem3;
    outputFile << testItem1 << testItem2 << testItem3;

    inputFile.close();
    outputFile.close();
}

void itemCopyConstructorTest()
{
    Item itemOne;

    cout << "---Testing the copy constructor for ADT Item---" << endl;
    cout << "Enter a texting abbreviation and meaning" << endl;
    cin >> itemOne;

    Item itemOneCopy(itemOne);
    
    cout << "Displaying the copied item" << endl;
    cout << itemOneCopy << endl;
}

void itemAssignTest()
{
    Item itemOne, itemTwo, itemThree;

    cout << "---Testing operator= for ADT Item---" << endl;
    cout << "Enter a texting abbreviation and meaning for itemOne" << endl;
    cin >> itemOne;

    cout << "Items itemTwo and itemThree will be set equal to itemOne using operator=" << endl;
    itemThree = itemTwo = itemOne;
    cout << "Displaying itemOne itemTwo and itemThree" << endl;
    cout << itemOne << itemTwo << itemThree << endl;
}

void itemIsLessThanTest()
{
    Item itemOne, itemTwo;

    cout << "---Testing the operator< inherited from ADT Key for ADT Item---" << endl;
    cout << "Enter two texting abbreviations and meanings for itemOne and itemTwo" << endl;
    cin >> itemOne >> itemTwo;

    if (itemOne < itemTwo)
        cout << "itemOne < itemTwo" << endl;
    else
        cout << "itemOne > itemTwo" << endl;
}

void itemIsEqualTest()
{
    Item itemOne, itemTwo;

    cout << "---Testing the operator== inherited from ADT Key for ADT Item---" << endl;
    cout << "Enter two texting abbreviations and meanings for itemOne and itemTwo" << endl;
    cin >> itemOne >> itemTwo;

    if (itemOne == itemTwo)
        cout << "itemOne = itemTwo" << endl;
    else
        cout << "itemOne != itemTwo" << endl;
}

void itemConvertToIntTest()
{
    Item itemOne;

    cout << "---Testing convertToInteger inherited from ADT Key for ADT Item---" << endl;
    cout << "Enter a texting abbreviation and meaning" << endl;
    cin >> itemOne;
    cout << "itemOne converted to an integer is: " << itemOne.convertToInteger() << endl;
}
