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
    itemFriendInputOutputTest();
    itemCopyConstructorTest();
    itemAssignTest();
    itemIsLessThanTest();
    itemIsEqualTest();
    itemConvertToIntTest();
    return 0;

}

void keyFriendInputOutputTest(){
	Key a, b, c;
	fstream inputFile, outputFile;
	cout << "Testing the input function, please enter 3 texting Abbreviations" << endl;
	cin  >> a >> b >> c;
	cout << "Testing the output function by displaying the output between the # signs" << endl;
	cout << "#" << a << "#" << b << "#" << c << "#" << endl;
	inputFile.open("in.dat");
	outputFile.open("out.dat");
	cout << "Testing to see if writing to a file works" << endl;
	inputFile >> a >> b >> c;
	outputFile << a << b << c << endl;

    // Testing ADT Item member functions
    itemFriendInputOutputTest();
    itemCopyConstructorTest();
    itemAssignTest();

    // Testing ADT Key member functions inherited by ADT Item
    itemIsEqualTest();
    itemIsLessThanTest();
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
	cout << endl << "Printing abbreviations between the # signs" << endl;
	cout << "#" << keyOne << "#" << keyTwo << "#" << keyThree << "#" << endl << endl;
	
	cout << "Testing the ADT Key friends operator>> and operator<< for files" << endl;
    cout << "Texting abbreviations from in.dat will be written to out.dat" << endl << endl;
	inputFile >> keyOne >> keyTwo >> keyThree;
	outputFile << keyOne << keyTwo << keyThree << endl;


	inputFile.close();
	outputFile.close();

}
void keyCopyConstructorTest(){

	Key text("lol");
	cout << "Testing constructor that assigns a texting abbreviation to key" << endl;
	cout << "Displaying the text \"lol\" between #s" <<endl;
	cout << "#"<<text<<"#" << endl;
}
void keyAssignTest(){
	Key keyOne, keyTwo, keyThree;
	cout << "Testing the assign by function by using cascading" << endl;
	cout << "Enter the first texting abbreviation" << endl;
	cin >> keyOne;
	cout << "Enter the second texting abbreviation" << endl;
	cin >> keyTwo;
	cout << "Enter the third texting abbreviation" << endl;
	cin >> keyThree;
	cout << "Cascading the texting abbreviation" << endl;
	keyOne = keyTwo = keyThree;
	cout << "Assignments after cascading:" << endl;
	cout << "First texting abbreviation after cascading: " << keyOne << endl;
	cout << "Second texting abbreviation after cascading: " << keyTwo << endl;
	cout << "Third texting abbreviation after cascading: " << keyThree << endl;
}
		
void keyIsEqualTest(){
	Key keyOne, rightHandSideKey;
	cout << "Testing to see if one texting abbreviation is equal to another" << endl;
	cout << "Enter another texting abbreviation" << keyOne << endl;
	cin >> keyOne;
	cout << "Enter another texting abbreviation" << rightHandSideKey << endl;
	cin >> rightHandSideKey;
	if (keyOne == rightHandSideKey) {
        cout << "Texting abbreviation are the same" << endl;
	}
	else {
	    cout << "Texting abbreviation are different" << endl;
	}

	Key keyOne("lol");

	cout << "---Testing constructor that initializes Key with a specified abbreviation---" << endl;
	cout << "keyOne is initialized to \"lol\"  and displayed between #s" <<endl;
	cout << "#" << keyOne << "#" << endl << endl;
}
void keyAssignTest(){
	Key keyOne, keyTwo, keyThree;

	cout << "---Testing operator= for ADT Key---" << endl;
	cout << "Enter a texting abbreviation for keyOne->";
	cin >> keyOne;

	cout << "Keys keyTwo and keyThree will be set equal to keyOne using operator=" << endl;
	keyThree = keyTwo = keyOne;

	cout << "Displaying keyOne, keyTwo and keyThree" << endl;
    cout << keyOne << endl << keyTwo << endl << keyThree << endl << endl;
}
		
void keyIsEqualTest(){
	Key keyOne, keyTwo;

	cout << "---Testing the operator== for ADT Key---" << endl;
	cout << "Enter a texting abbreviation for keyOne->";
    cin >> keyOne;
	cout << "Enter a texting abbreviation for keyTwo->";
    cin >> keyTwo;

	if (keyOne == keyTwo) 
        cout << "keyOne = keyTwo" << endl <<endl;
	else 
	    cout << "keyOne != keyTwo" << endl << endl;

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


    cout << "---Testing the operator< for ADT Key---" << endl;
	cout << "Enter a texting abbreviation for keyOne->";
	cin >> keyOne;
	cout << "Enter a texting abbreviation for keyTwo->";
	cin >> keyTwo;

	if (keyOne <  keyTwo)
		cout << "keyOne < keyTwo" << endl << endl;  
	else 
		cout << "keyOne >= keyTwo" << endl << endl;

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


    inputFile.open("in.dat");
    outputFile.open("out.dat");

    cout << "---Testing the ADT Item friends operator>> and operator<<---" << endl;
    cout << "Enter three texting abbreviations and meanings" << endl;
    cin >> testItem1 >> testItem2 >> testItem3;
    cout << endl << "Printing items to screen" << endl;
    cout << testItem1 << testItem2 << testItem3 << endl;

    cout << "Testing the ADT Item friends operator>> and operator<< for files" << endl;
    cout << "Texting abbreviations from in.dat will be written to out.dat" << endl << endl;

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


    cout << "---Testing the copy constructor for ADT Item---" << endl;
    cout << "Enter a texting abbreviation and meaning->";
    cin >> itemOne;
    Item itemOneCopy(itemOne);
    
    cout << "Displaying the copied item" << endl;
    cout << endl << "Displaying the copied ADT Item" << endl;
    cout << itemOneCopy << endl;
}

void itemAssignTest()
{
    Item itemOne, itemTwo, itemThree;
    cout << "Testing operator= for ADT Item" << endl;
    cout << "Enter a texting abbreviation and meaning for itemOne" << endl;
    cin >> itemOne;

    cout << "Items itemTwo and itemThree will be set equal to itemOne using operator=" << endl;
    cout << "---Testing operator= for ADT Item---" << endl;
    cout << "Enter a texting abbreviation and meaning for itemOne->";
    cin >> itemOne;

    cout << endl << "Items itemTwo and itemThree will be set equal to itemOne using operator=" << endl;

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


    cout << "---Testing the operator< inherited from ADT Key for ADT Item---" << endl;
    cout << "Enter a texting abbreviation and meaning for itemOne->";
    cin >> itemOne;
    cout << "Enter a texting abbreviation and meaning for itemTwo->";
    cin >> itemTwo;

    if (itemOne < itemTwo)
        cout << "itemOne < itemTwo" << endl << endl;
    else
        cout << "itemOne >= itemTwo" << endl << endl;

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


    cout << "---Testing the operator== inherited from ADT Key for ADT Item---" << endl;
    cout << "Enter a texting abbreviation and meaning for itemOne->";
    cin >> itemOne;
    cout << "Enter a texting abbreviation and meaning for itemTwo->";
    cin >> itemTwo;

    if (itemOne == itemTwo)
        cout << "itemOne = itemTwo" << endl << endl;
    else
        cout << "itemOne != itemTwo" << endl << endl;

}

void itemConvertToIntTest()
{
    Item itemOne;

    cout << "Testing convertToInteger inherited from ADT Key for ADT Item" << endl;
    cout << "Enter a texting abbreviation and meaning" << endl;


    cout << "---Testing convertToInteger inherited from ADT Key for ADT Item---" << endl;
    cout << "Enter a texting abbreviation and meaning for itemOne->";

    cin >> itemOne;
    cout << "itemOne converted to an integer is: " << itemOne.convertToInteger() << endl;
}
