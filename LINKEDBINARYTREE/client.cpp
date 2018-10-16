//clientguy

#include "binarytree.h"
#include "exception.h"
#include <string>
#include <fstream>
using namespace std;

//opens an input file with a chosen name
//pre filename is assigned
//post if filename exists in the same directory as the program, it is opened
//      with its file pointer at the beginning of the file 
//      else an error message is printed
//usage openInputFile(infile, filename);
void openInputFile(ifstream& inputFile, string filename);

//prints an exception message
//pre except has been thrown
//post except is printed to the screen with two newlines before and after
//usage PrintExceptionMessage(except);
void printExceptionMessage(const Exception& except);

void makeFullTreeHeight3(BinaryTree& aTree, istream& infile);

void makeCompleteTreeHeight4(BinaryTree& aTree, istream& infile);

void printBinaryTree(BinaryTree& aTree);

void printTraversals(BinaryTree& aTree);

int main()
{
    BinaryTree fullTree, completeTree;
    ifstream infile;

    openInputFile(infile, "in.dat");
   
    makeFullTreeHeight3(fullTree, infile);
    makeCompleteTreeHeight4(completeTree, infile);

    printBinaryTree(fullTree);
    printTraversals(fullTree);

    printBinaryTree(completeTree);
    printTraversals(completeTree);
 
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

void printBinaryTree(BinaryTree& aTree)
{
    cout << endl;
    aTree.prettyDisplay();
    cout << endl;
}

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
   

   
