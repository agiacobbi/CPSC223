#include <iostream>
#include <fstream>
#include "two34tree.h"
using namespace std;

void testACase(istream& input, ostream& output);
void caseInsertToRoot(istream& input, ostream& output);
void caseSplitRootNode(istream& input, ostream& output);
void caseSplitLevelTwoNode(istream& input, ostream& output);

int main()
{
	ifstream inputFile;
	ofstream outputFile;
	
	inputFile.open("in.dat");
	outputFile.open("two.dat");
	
	caseInsertToRoot(inputFile, outputFile);
	caseSplitRootNode(inputFile, outputFile);
	caseSplitLevelTwoNode(inputFile, outputFile);
	
	return 0;
}

void testACase(istream& input, ostream& output)
{
	Key newGuy;
	Two34Tree myTree;
	int numberToEnter;
	
	input >> numberToEnter;
	for (int i = 0; i < numberToEnter - 1; i++)
	{
		input >> newGuy;
		myTree.addNewEntry(newGuy);
	}
	output << endl << "---------- Pre Tree ----------" << endl;
	myTree.display(output, 'p');
	
	input >> newGuy;
	myTree.addNewEntry(newGuy);
	output << endl << "---------- Post Tree ----------" << endl;
	myTree.display(output, 'p');
}

void caseInsertToRoot(istream& input, ostream& output)
{
	
}

void caseSplitRootNode(istream& input, ostream& output)
{
	
}

void caseSplitLevelTwoNode(istream& input, ostream& output)
{
	
}