#include <iostream>
#include <fstream>
#include "binarytree.h"
using namespace std;

void makeFullTreeHeight3(BinaryTree& fullTree, ifstream& infile);
void makeDegenerateTreeHeight4(BinaryTree& degenerateTree, ifstream& infile);
void printTree(BinaryTree& tree);

int main()
{
    BinaryTree fullTree, degenerateTree;
    ifstream inputFile;

    inputFile.open("in.dat");

    makeFullTreeHeight3(fullTree, inputFile);
    makeDegenerateTreeHeight4(degenerateTree, inputFile);
    cout << endl << "Preorder" << endl;
    fullTree.preorder();
    degenerateTree.preorder();
/*
    cout << endl << "Inorder" << endl;
    fullTree.inorder();

    cout << endl << "Postorder" << endl;
    fullTree.postorder();
*/
    inputFile.close();
    return 0;
}

void makeFullTreeHeight3(BinaryTree& fullTree, ifstream& infile)
{
    Item inItem;

    for (int i = 0; i < 7;)
    {
        infile >> inItem;
        fullTree.insert(inItem, ++i, ++i);
    }

    for (int i = 0; i < 4; i++)
    {
        infile >> inItem;
        fullTree.insert(inItem, -1, -1);
    }

}

void makeDegenerateTreeHeight4(BinaryTree& degenerateTree, ifstream& infile)
{
    Item inItem;
    
    for (int i = 0; i < 4; i++)
    {
        infile >> inItem;
        degenerateTree.insert(inItem, i - 1, -1);
    }
}

void printTree(BinaryTree& tree)
{
    Item printItem;

    
}





