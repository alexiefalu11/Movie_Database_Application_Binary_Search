#include <string>
#include "Name.h"
#include "Movie.h"
#include "cdlist_node.cpp"
#include "List.cpp"
#include "queue.cpp"
#include "BinarySearchTree.cpp"

using namespace std;
using namespace UT_315;

// DO NOT MODIFY THIS FILE

// Explicit template class declaration
// Here we include all files with template declaration so
// they can be checked and bind by the C++ compiler


// Linked List of names 
template class List<Name>;

// Iterator for Linked list of names
template class List_Iterator<Name>;

// Linked list of movies
template class List<Movie>;

// Iterator for Linked list of movies
template class List_Iterator<Movie>;

// Binary Search Tree of movies
template class BinarySearchTree<Movie,string>;

// In-Order Tree iterator for Binary Search Tree of movies
template class BST_inorder_iterator<Movie,string>;

// Pre-Order Tree iterator for Binary Search Tree of movies
template class BST_preorder_iterator<Movie,string>;

