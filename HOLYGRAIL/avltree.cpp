// file: avltree.cpp

const int MAXHEIGHT = 15;

struct SearchPath
{
    TreeNode* path[MAXHEIGHT];
    int size;
    int pivotIndex;
    SearchPath();
}

SearchPath::SearchPath()
{
    size = 0;
    pivotIndex = -1;
    for (int i = 0; i < MAXHEIGHT; i++)
        path[i] = nullptr;
}

// ----------  RECURSIVE HELPERS  ----------
void writePrettyWithBalances(TreeNode* treep, int level)
{}

// ----------  MEMBER FUNCTIONS  ----------
AVLTree::AVLTree()
{}

AVLTree::~AVLTree()
{}

void AVLTree::addNewEntry(const Item& newItem) throw (Exception)
{
    SearchPath search;

    addNewEntryAndMakeSearchPath(root, newItem, search);
    if (hasNoPivot(search))
        fixBalances(search, 0);
    else if (isAddedToShortSide(search))
        fixBalances(search, search.pivotIndex)
    else if (isSingleRotateleft(search))
        //do singleLeftRotation
    else if (isSingleRotateRight(search))
        //do singleRightRotation
    else if (
}
