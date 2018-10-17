//file binarytree.cpp
//Alex Giacobbi and Jalen Tacsiat
//agiacobbi
//date: 10/17/18
//This is a client file

/*
This file will test the functions implemented in the binaryTree class. This file creates 
two trees one full tree of height 3 and another complete tree of height 4. First, a full tree will be 
displayed on screen showing its structure, then each item will be displayed by the traversals preorder, inorder, 
and postorder. Next, the complete tree of height 4 will be displayed on screen showing its structure, 
then each item will be displayed by the traversals preorder, inorder, and postorder. Finally, one tree will be set
equal to the other, and both trees will be displayed to demonstrate the equals operation was successful.  
*/

#include "binarytree.h"
#include "exception.h"
#include <string>
#include <fstream>
using namespace std;

//opens an input file with a chosen name
//pre: filename is assigned
//post: if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file 
//      else an error message is printed
//usage: openInputFile(infile, filename);
void openInputFile(ifstream& inputFile, string filename);

//prints an exception message
//pre: except has been thrown
//post: except is printed to the screen with two newlines before and after
//usage: PrintExceptionMessage(except);
void printExceptionMessage(const Exception& except);

//makes a full binaryTree of height 3
//pre: a tree is a binaryTree and infile is opened
//post: Full BinaryTree is filled with items
//usage: makeFullTreeHeight3(mytree, infile);     
void makeFullTreeHeight3(BinaryTree& aTree, istream& infile);

//makes a complete binaryTree of height 4
//pre: a tree is a binaryTree and infile is opened
//post: Complete BinaryTree is filled with items
//usage: makeCompleteTreeHeight4(mytree, infile);   
void makeCompleteTreeHeight4(BinaryTree& aTree, istream& infile);

//prints a binaryTree
//pre: aTree exists
//post: contents of binaryTree are displayed on screen
//usage: printBinaryTree(mytree);
void printBinaryTree(BinaryTree& aTree);

//prints a binaryTree traverals (preorder, inorder, postorder)
//pre: aTree exists
//post: contents of binaryTree are displayed on screen by using traverals
//usage: printTraversals(mytree);
void printTraversals(BinaryTree& aTree);

//tests the operator= for binaryTree
//pre: firstTree and secondTree exist
//post: firstTree is set equal to secondTree
//usage: testEqualsOperator(aTree, otherTree);
void testEqualsOperator(BinaryTree& firstTree, BinaryTree& secondTree); 

int main()
{
    BinaryTree fullTree, completeTree;
    ifstream infile;

	cout << endl << endl;
	
    openInputFile(infile, "in.dat");
    
	cout << "---- Testing printing and traversal of Full Tree of Height 3 ----" << endl;
	makeFullTreeHeight3(fullTree, infile);
	
    printBinaryTree(fullTree);
    printTraversals(fullTree);
	
	cout << "---- Testing printing and traversal of Complete Tree of Height 4 ----" << endl;
	makeCompleteTreeHeight4(completeTree, infile);
	
    printBinaryTree(completeTree);
    printTraversals(completeTree);
 
	testEqualsOperator(fullTree, completeTree);
	
	
    return 0;
}

//opens an input file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file 
//      else an error message is printed
//usage openInputFile(infile, filename);
void openInputFile(ifstream& inputFile, string filename) 
{
    inputFile.open(filename);
    if (inputFile.fail())
    {
      cout << "File failed to open!!!!" << endl;
      exit(1);
    }
}

//prints an exception message
//pre except has been thrown
//post except is printed to the screen with two newlines before and after
//usage PrintExceptionMessage(except);
void printExceptionMessage(const Exception& except)
{
    cout << endl << endl;
    cout << except.what();
    cout << endl << endl;
}

//makes a full binaryTree of height 3
//pre: a tree is a binaryTree and infile is opened
//post: Full BinaryTree is filled with items
//usage: makeFullTreeHeight3(mytree, infile); 
void makeFullTreeHeight3(BinaryTree& aTree, istream& infile)
{
    try {
        aTree.makeFullTreeHeight3(infile);
    }
        catch (Exception except)
    {
        printExceptionMessage(except);
    }
}

//makes a complete binaryTree of height 4
//pre: a tree is a binaryTree and infile is opened
//post: Complete BinaryTree is filled with items
//usage: makeCompleteTreeHeight4(mytree, infile);  
void makeCompleteTreeHeight4(BinaryTree& aTree, istream& infile)
{
    try {
        aTree.makeCompleteTreeHeight4(infile);
    }
        catch (Exception except)
    {
        printExceptionMessage(except);
    }
}

//prints a binaryTree
//pre: aTree exists
//post: contents of binaryTree are displayed on screen
//usage: printBinaryTree(mytree);
void printBinaryTree(BinaryTree& aTree)
{
    cout << endl;
    aTree.prettyDisplay();
    cout << endl;
}

//prints a binaryTree traverals (preorder, inorder, postorder)
//pre: aTree exists
//post: contents of binaryTree are displayed on screen by using traverals
//usage: printTraversals(mytree);
void printTraversals(BinaryTree& aTree)
{
    cout << endl << "Preorder Traversal:" << endl << endl;
    aTree.preorderTraverse();
    cout << endl << "Inorder Traversal:" << endl << endl;
    aTree.inorderTraverse();
    cout << endl << "Postorder Traversal:" << endl << endl;
    aTree.postorderTraverse();
    cout << endl;
}

//tests the operator= for binaryTree
//pre: firstTree and secondTree exist
//post: firstTree is set equal to secondTree
//usage: testEqualsOperator(aTree, otherTree);
void testEqualsOperator(BinaryTree& firstTree, BinaryTree& secondTree)
{
	cout << "----Testing = operator by setting completeTree to fullTree and printing both trees after operation----" << endl;
	firstTree = secondTree;
	printBinaryTree(secondTree);
	printBinaryTree(firstTree);
}	
   

   
