// filename: clientprogram.cpp
// Alex Giacobbi and Jalen Tacsiat
// agiacobbi
// date: 11/20/18

// description: this is a client program that tests the cases and subcases of avltree and writes the pre and post trees to a file

#include <iostream>
#include <fstream>
#include "avltree.h"
using namespace std;

// adds a new entry to the AVLTree testing testACase
// pre: inputfile, string, and outputfile exists
// post: pre tree is displayed before case testACase and displays the post tree after the case testACase is done
// usage: testACase(inputfile, myString, outputfile)
void testACase(istream& input, string myCase, ofstream& output);

// tests the hasNoPivot with subcases
// pre: inputfile and outputfile exists
// post: pre tree is displayed before the case and displays the post tree after the case hasNoPivot is done
// usage: testHasNoPivot(inputfile, outputfile);
void testHasNoPivot(istream& input, ofstream& output);

// tests the isAddedShortside case with subcases
// pre: inputfile and outputfile exists
// post: pre tree is displayed before the case and displays the post tree after the case isAddedShortside is done
// usage: testIsAddedShortSide(inputfile, outputfile);
void testIsAddedShortSide(istream& input, ofstream& output);

// tests the SingleRotateLeft case with subcases
// pre: inputfile and outputfile exists
// post: pre tree is displayed before the case and displays the post tree after the case SingleRotateLeft is done
// usage: testSingleRotateLeft(inputfile, outputfile);
void testSingleRotateLeft(istream& input, ofstream& output);

// tests the SingleRotateRight case with subcases
// pre: inputfile and outputfile exists
// post: pre tree is displayed before the case and displays the post tree after the case SingleRotateRight is done
// usage: testSingleRotateRight(inputfile, outputfile);
void testSingleRotateRight(istream& input, ofstream& output);

// tests the DoubleRotateLeftRight case with subcases
// pre: inputfile and outputfile exists
// post: pre tree is displayed before the case and displays the post tree after the case DoubleRotateLeftRight is done
// usage: testDoubleRotateLeftRight(inputfile, outputfile);
void testDoubleRotateLeftRight(istream& input, ofstream& output);

// tests the DoubleRotateRightLeft case with subcases
// pre: inputfile and outputfile exists
// post: pre tree is displayed before the case and displays the post tree after the case DoubleRotateRightLeft is done
// usage: testDoubleRotateRightLeft(inputfile, outputfile);
void testDoubleRotateRightLeft(istream& input, ofstream& output);

// writes lines to divide each main case 
// pre: outputfile exists
// post: lines are printed to divide each case  
// usage: printDivide (outputfile)
void printDivide(ofstream& output);

int main()
{
	ifstream input;
	ofstream output;
	input.open("in.dat");
	output.open("avl.dat");
	
	testHasNoPivot(input, output);
	testIsAddedShortSide(input, output);
	testSingleRotateLeft(input, output);
	testSingleRotateRight(input, output);
	testDoubleRotateLeftRight(input, output);
	testDoubleRotateRightLeft(input, output);
	
	input.close();
	output.close();
	return 0;
}

// adds a new entry to the AVLTree testing testACase
// pre: inputfile, string, and outputfile exists
// post: pre tree is displayed before case testACase and displays the post tree after the case testACase is done
// usage: testACase(inputfile, myString, outputfile)
void testACase(istream& input, string myCase, ofstream& output)
{
	AVLTree myTree;
	int num;
	Item newGuy;
	input >> num;
	
	for (int i = 0; i < num - 1; i++)
	{
		input >> newGuy;
		try {
			myTree.addNewEntry(newGuy);	
		} catch (Exception e) {
			output << endl << e.what() << endl << endl;
		}
	}
	printDivide(output);
	output << myCase << endl << endl;
	output << "Pre Tree:" << endl << endl;
	myTree.prettyDisplay(output);
	
	input >> newGuy;
	output << endl << endl << "Adding " << newGuy << "..." << endl;
	
	output << endl << "Post Tree: " << endl;
	try {
		myTree.addNewEntry(newGuy);	
	} catch (Exception e) {
		output << endl << e.what() << endl << endl;
	}
	myTree.prettyDisplay(output);
	output << endl;
}

// tests the hasNoPivot with subcases
// pre: inputfile and outputfile exists
// post: pre tree is displayed before the case and displays the post tree after the case hasNoPivot is done
// usage: testHasNoPivot(inputfile, outputfile);
void testHasNoPivot(istream& input, ofstream& output)
{
	printDivide(output);
	output << endl << "CASE OF NO PIVOT" << endl << endl;
	printDivide(output);
	
	testACase(input, "CASE: Empty tree", output);
	testACase(input, "CASE: Added to tree of height 1 leftChild", output);
	testACase(input, "CASE: Added to tree of height 1 rightChild", output);
	testACase(input, "CASE: Added to tree of height 2 left side leftChild", output);
	testACase(input, "CASE: Added to tree of height 2 left side rightChild", output);
	testACase(input, "CASE: Added to tree of height 2 right side leftChild", output);
	testACase(input, "CASE: Added to tree of height 2 right side rightChild", output);
	input.ignore();
}

// tests the isAddedShortside case with subcases
// pre: inputfile and outputfile exists
// post: pre tree is displayed before the case and displays the post tree after the case isAddedShortside is done
// usage: testIsAddedShortSide(inputfile, outputfile);
void testIsAddedShortSide(istream& input, ofstream& output)
{
	printDivide(output);
	output << endl << "CASE OF ADDED TO SHORT SIDE" << endl << endl;
	printDivide(output);
	
	testACase(input, "CASE: Added to tree of height 1 leftChild", output);
	testACase(input, "CASE: Added to tree of height 1 rightChild", output);
	testACase(input, "CASE: Added to tree of height 2 left side leftChild", output);
	testACase(input, "CASE: Added to tree of height 2 left side rightChild", output);
	testACase(input, "CASE: Added to tree of height 2 right side leftChild", output);
	testACase(input, "CASE: Added to tree of height 2 right side rightChild", output);
	input.ignore();
}

// tests the SingleRotateLeft case with subcases
// pre: inputfile and outputfile exists
// post: pre tree is displayed before the case and displays the post tree after the case SingleRotateLeft is done
// usage: testSingleRotateLeft(inputfile, outputfile);
void testSingleRotateLeft(istream& input, ofstream& output)
{
	printDivide(output);
	output << endl << "CASE OF SINGLE ROTATE LEFT" << endl << endl;
	printDivide(output);
	
	testACase(input, "CASE: Root is pivot and T1-3 are height 0", output);
	testACase(input, "CASE: Root is pivot and T1-3 are height 1", output);
	testACase(input, "CASE: Pivot is leftChild of cloud and T1-3 are height 0", output);
	testACase(input, "CASE: Pivot is leftChild of cloud and T1-3 are height 1", output);
	testACase(input, "CASE: Pivot is rightChild of cloud and T1-3 are height 0", output);
	testACase(input, "CASE: Pivot is rightChild of cloud and T1-3 are height 1", output);
	input.ignore();
}

// tests the SingleRotateRight case with subcases
// pre: inputfile and outputfile exists
// post: pre tree is displayed before the case and displays the post tree after the case SingleRotateRight is done
// usage: testSingleRotateRight(inputfile, outputfile);
void testSingleRotateRight(istream& input, ofstream& output)
{
	printDivide(output);
	output << endl << "CASE OF SINGLE ROTATE RIGHT" << endl << endl;
	printDivide(output);
	
	testACase(input, "CASE: Root is pivot and T1-3 are height 0", output);
	testACase(input, "CASE: Root is pivot and T1-3 are height 1", output);
	testACase(input, "CASE: Pivot is leftChild of cloud and T1-3 are height 0", output);
	testACase(input, "CASE: Pivot is leftChild of cloud and T1-3 are height 1", output);
	testACase(input, "CASE: Pivot is rightChild of cloud and T1-3 are height 0", output);
	testACase(input, "CASE: Pivot is rightChild of cloud and T1-3 are height 1", output);
	input.ignore();
}

// tests the DoubleRotateLeftRight case with subcases
// pre: inputfile and outputfile exists
// post: pre tree is displayed before the case and displays the post tree after the case DoubleRotateLeftRight is done
// usage: testDoubleRotateLeftRight(inputfile, outputfile);
void testDoubleRotateLeftRight(istream& input, ofstream& output)
{
	printDivide(output);
	output << endl << "CASE OF DOUBLE ROTATE LEFT RIGHT" << endl << endl;
	printDivide(output);
	
	testACase(input, "CASE: Root is pivot and T1-4 are height 0", output);
	testACase(input, "CASE: Root is pivot and T1T4 are height 1 and T2T3 are height 0", output);
	testACase(input, "CASE: Pivot is leftChild of cloud and T1-4 are height 0", output);
	testACase(input, "CASE: Pivot is leftChild of cloud and T1T4 are height 1 and T2T3 are height 0", output);
	testACase(input, "CASE: Pivot is rightChild of cloud and T1-4 are height 0", output);
	testACase(input, "CASE: Pivot is rightChild of cloud and T1T4 are height 1 and T2T3 are height 0", output);
	input.ignore();
}

// tests the DoubleRotateRightLeft case with subcases
// pre: inputfile and outputfile exists
// post: pre tree is displayed before the case and displays the post tree after the case DoubleRotateRightLeft is done
// usage: testDoubleRotateRightLeft(inputfile, outputfile);
void testDoubleRotateRightLeft(istream& input, ofstream& output)
{
	printDivide(output);
	output << endl << "CASE OF DOUBLE ROTATE RIGHT LEFT" << endl << endl;
	printDivide(output);
	
	testACase(input, "CASE: Root is pivot and T1-4 are height 0", output);
	testACase(input, "CASE: Root is pivot and T1T4 are height 1 and T2T3 are height 0", output);
	testACase(input, "CASE: Pivot is leftChild of cloud and T1-4 are height 0", output);
	testACase(input, "CASE: Pivot is leftChild of cloud and T1T4 are height 1 and T2T3 are height 0", output);
	testACase(input, "CASE: Pivot is rightChild of cloud and T1-4 are height 0", output);
	testACase(input, "CASE: Pivot is rightChild of cloud and T1T4 are height 1 and T2T3 are height 0", output);
	input.ignore();
}

// writes the pre and post trees of each case to the file avl.dat
// pre: outputfile exists
// post: pre and post trees are written to a file 
// usage: printDivide (outputfile)
void printDivide(ofstream& output)
{
	for (int i = 0; i < 80; i++)
		output << '-';
	output << endl;
}


