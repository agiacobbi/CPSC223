/*
Alex Giacobbi and Jalen Tacsiat
agiacobbi
8 October 2018
Description: This is a client program that tests the member functions of abstract 
data type BinaryTree. This program is broken into functions that each test a different 
member function. The program takes input from file in.dat to walk the user through each 
function and show that each function works as documented.
*/

#include <iostream>
#include <fstream>
#include "binarytree.h"
using namespace std;

void makeFullTreeHeight3(BinaryTree& fullTree, ifstream& infile);
void makeDegenerateTreeHeight4(BinaryTree& degenerateTree, ifstream& infile);
void printFullTree();
void printDegenerateTree();
void testPreorderInorderPostorder(BinaryTree& tree);
void openFile(ifstream& infile);

int main()
{
    BinaryTree fullTree, degenerateTree;
    ifstream inputFile;

    openFile(inputFile);

    makeFullTreeHeight3(fullTree, inputFile);
    makeDegenerateTreeHeight4(degenerateTree, inputFile);

    printFullTree();
    testPreorderInorderPostorder(fullTree);

    printDegenerateTree();
    testPreorderInorderPostorder(degenerateTree);

    inputFile.close();

    return 0;
}

void makeFullTreeHeight3(BinaryTree& fullTree, ifstream& infile)
{
    Item inItem;

    for (int i = 1; i < 7; i += 2)
    {
        infile >> inItem;
        fullTree.insert(inItem, i, i + 1);
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
    
    for (int i = 0; i < 3; i++)
    {
        infile >> inItem;
        degenerateTree.insert(inItem, i + 1, -1);
    }

    infile >> inItem;
    degenerateTree.insert(inItem, -1, -1);
}

void printFullTree()
{
    cout << endl << endl;
    cout << "--- A full binary tree of height 3 ---";
    cout << endl  << endl;

    cout << "                            lol: laugh out loud                               " << endl;
    cout << "                             /               \\                               " << endl;
    cout << "             brb: be right back             ttyl: talk to you later           " << endl;
    cout << "                /         \\                      /            \\             " << endl;
    cout << "   gtg: got to go  btw: by the way       op: original poster  eol: end of line" << endl << endl;
}

void printDegenerateTree()
{
    cout << endl << endl;
    cout << "--- A degenerate binary tree of height 4 ---";
    cout << endl << endl;

    cout << "                          afk: away from keyboard" << endl;
    cout << "                            /                    " << endl;
    cout << "                 idk: i dont know                " << endl;
    cout << "                   /                             " << endl;
    cout << "         rn: right now                           " << endl;
    cout << "          /                                      " << endl;
    cout << "   tmi: too much information                     " << endl << endl;
}

void testPreorderInorderPostorder(BinaryTree& tree)
{
    cout << "Preorder Traversal:" << endl;
    tree.preorder();

    cout << "Inorder Traversal:" << endl;
    tree.inorder();

    cout << "Postorder Traversal:" << endl;
    tree.postorder();
}

void openFile(ifstream& infile)
{
    infile.open("in.dat");
    if (infile.fail())
    {
        cout << "ERROR: cannot open in.dat BOLTING" << endl;
        exit(1);
    }
}