#include <iostream>
#include <fstream>
#include "two34tree.h"
using namespace std;

void testACase(istream& input, ostream& output);
void caseInsertToRoot(istream& input, ostream& output);
void caseSplitRootNode(istream& input, ostream& output);
void caseSplitLevelTwoNode(istream& input, ostream& output);
void printBreakLine(ostream& output);

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
	output << endl << "PRE TREE ----------------------" << endl;
	myTree.display(output, 'p');
	
	input >> newGuy;
	output << endl << "Adding " << newGuy << "..." << endl;
	myTree.addNewEntry(newGuy);
	output << endl << "POST TREE ---------------------" << endl;
	myTree.display(output, 'p');
	
	printBreakLine(output);
	output << endl;
	
}

void caseInsertToRoot(istream& input, ostream& output)
{
	printBreakLine(output);
	output << endl << "CASE: NEWGUY IS INSERTED INTO ROOT" << endl;
	printBreakLine(output);
	for (int i = 0; i < 6; i++)
		testACase(input, output);
}

void caseSplitRootNode(istream& input, ostream& output)
{
	printBreakLine(output);
	output << endl << "CASE: NEWGUY CAUSES A SPLIT OF ROOT" << endl;
	printBreakLine(output);
	for (int i = 0; i < 4; i++)
		testACase(input, output);
}

void caseSplitLevelTwoNode(istream& input, ostream& output)
{
	printBreakLine(output);
	output << endl << "CASE: NEWGUY IS INSERTED INTO LEVEL 2 TREENODE" << endl;
	printBreakLine(output);
	for (int i = 0; i < 10; i++)
		testACase(input, output);
}

void printBreakLine(ostream& output)
{
	for (int i = 0; i < 60; i++)
		output << '-';
}