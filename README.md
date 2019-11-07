# CPSC 223 Algorithms and Abstract Data Structures
A series of programs from CPSC 223 demonstrating implementations of different common data structures to store
texting abbreviations and their meaning

## ABBREVSPROG1 and KEYSPROG2
Create some starter classes for a texting abbreviation and a key. These will be what we are storing in different data structures.
Review of operator overloading with C++

## DICTIONARYHASH
An implementation of a hash table using an array and linear probing to handle collisions. Items are hashed using a simple
hash method and stored in an array. Lookup, add, and delete are O(1) but degenerate to linear time with many collisions.

## DICTIONARYCHAINING
An implemenatation of a hash table using chaining to handle collisions. Items are hashed then stored at the end of a linked list
at the proper address. Lookup, add, and delete are O(1) but degenerate to linear time with many collisions.

## BINARYTREE
An implementation of a binary tree using a static array of TreeNodes. TreeNodes are structs containing an Item and indexes for
left and right children. 

## LINKEDBINARYTREE
A dynamic implementation of a binary tree using TreeNodes and pointers to identify children. Implementation can only create full
trees of height 2 or 3 since adding is done in fixed method

## BINARYSEARCHTREE
An improvement of linkned binary tree that inserts based on item value in alphabetical order. Searching is efficient, O(log n) at best, 
and entries remain sorted on insert. However, search, add, and remove degenerate to O(n) if tree is degenerate.

## HOLYGRAIL (AVL Tree)
The most efficient implementation of a binary tree. This tree balances itself as items are added using rotations. This keeps search,
add, and delete complexity at O(log n).

## 234TREE
A different tree structure that has 2, 3, or 4 children per node. When a node has too many children, tree is rebalanced to accomodate 
next add.
