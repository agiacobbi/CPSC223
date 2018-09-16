// client program of class Key
// following Homework

#include "key.h"
#include "item.h"
#include <iostream>
#include <fstream>
using namespace std;

void keyFriendInputTest(istream& input);
void keyFriendOutputTest(ostream& output);
void keyCopyConstructorTest(string text);
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
    //Key firstOne;
    //Key secondOne;
    //ifstream firstIn;
    //ofstream firstOut;

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

void keyFriendInputOutputTest(){
	Key a, b, c;
	fstream inputFile, outputFile;
	cout << "Testing the input function, please enter 3 texting Abbreviations" << endl;
	cin  >> a >> b >> c;
	cout << "Testing the output function by displaying the output between the # signs" << endl;
	cout << "#" << a << "#" << b << "#" << c << "#" endl;
	inputFile.open("in.dat");
	outputFile.open("out.dat");
	cout << "Testing to see if writing to a file works" << endl;
	inputFile >> a >> b >> c;
	outputFile << a << b << c << endl;
	inputFile.close();
	outputFile.close();
}
void keyCopyConstructorTest(){
	Key text("lol");
	cout << "Testing constructor that assigns a texting abbreviation to key" << endl;
	cout << "Displaying the text "lol" between #s" <<endl;
	cout << "#"<<text<<"#" << endl;
}
void keyAssignTest(){
	Key a, b, c;
	cout << "Testing the assign by function by using cascading" << endl;
	cout << "Enter the first texting abbreviation" << endl;
	cin >> a;
	cout << "Enter the second texting abbreviation" << endl;
	cin >> b;
	cout >> "Enter the third texting abbreviation" << endl;
	cin >> c;
	cout << "Cascading the texting abbreviation" << endl;
	a = b = c;
	cout << "Assignments after cascading:" << endl;
	cout << "First texting abbreviation after cascading: " << a;
	cout << "Second texting abbreviation after cascading: " << b;
	cout << "Third texting abbreviation after cascading: " << c;
}
		
void keyIsEqualTest(){
	Key keyOne, rightHandSideKey
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
		cout<< "The second texting abbreviation is less than the first texting abbreviation << endl;
	}
}



	
