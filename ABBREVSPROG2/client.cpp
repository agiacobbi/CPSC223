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
    keyFriendInputOutputTest();
    keyCopyConstructorTest();
    keyAssignTest();
    keyIsEqualTest();
    keyIsLessThanTest();
    itemFriendInputOutputTest();
    itemCopyConstructorTest();
    itemAssignTest();
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
	cout << "#" << keyOne << "#" << endl;
}
void keyAssignTest(){
	Key a, b, c;

	cout << "---Testing the assign by function by using cascading---" << endl;
	cout << "Enter the first texting abbreviation" << endl;
	cin >> a;
	cout << "Enter the second texting abbreviation" << endl;
	cin >> b;
	cout << "Enter the third texting abbreviation" << endl;
	cin >> c;
	cout << "Cascading the texting abbreviation" << endl;
	a = b = c;
	cout << "Assignments after cascading:" << endl;
	cout << "First texting abbreviation after cascading: " << a;
	cout << "Second texting abbreviation after cascading: " << b;
	cout << "Third texting abbreviation after cascading: " << c;
}
		
void keyIsEqualTest(){
	Key keyOne, rightHandSideKey;
	cout << "Testing to see if one texting abbreviation is equal to another" << endl;
	cout << "Enter another texting abbreviation" << keyOne << endl;
	cout << "Enter another texting abbreviation" << rightHandSideKey << endl;
	if (keyOne == rightHandSideKey) {
        cout << "Texting abbreviation are the same" << endl;
	}
	else {
	    cout << "Texting abbreviation are different" << endl;
	}
}	
	
void keyIsLessThanTest(){
	Key keyOne, keyTwo;
	cout << "Enter the first texting abbreviation" <<endl;
	cin >> keyOne;
	cout<< " Enter the second texting abbreviation"<<endl;
	cin>> keyTwo;
	if (keyOne <  keyTwo){
		cout << "The first texting abbreviation is less than the second texting abbreviation" << endl;  
	}
	else {
		cout << "The second texting abbreviation is less than the first texting abbreviation" << endl;
	}
}

void itemFriendInputOutputTest()
{
    Item testItem1, testItem2, testItem3;
    fstream inputFile, outputFile;

    inputFile.open("in.dat");
    outputFile.open("out.dat");

    cout << "Testing the ADT Item friends operator>> and operator<<" << endl;
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
    cout << "Testing the copy constructor for ADT Item" << endl;
    cout << "Enter a texting abbreviation and meaning" << endl;
    cin >> itemOne;

    Item itemOneCopy(itemOne);
    
    cout << "Displaying the copied item" << endl;
    cout << itemOneCopy << endl;
}

void itemAssignTest()
{
    Item itemOne, itemTwo, itemThree;
    cout << "Testing operator= for ADT Item" << endl;
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
    cout << "Testing the operator< inherited from ADT Key for ADT Item" << endl;
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
    cout << "Testing the operator== inherited from ADT Key for ADT Item" << endl;
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
    cout << "Testing convertToInteger inherited from ADT Key for ADT Item" << endl;
    cout << "Enter a texting abbreviation and meaning" << endl;
    cin >> itemOne;
    cout << "itemOne converted to an integer is: " << itemOne.convertToInteger() << endl;
}
