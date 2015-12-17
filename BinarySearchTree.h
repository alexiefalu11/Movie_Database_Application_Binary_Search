/*
 * This file name: BinarySearchTree.h
 * 
 * This file contains the declaration of the interface for
 * the binary search tree (BST).
 */

#ifndef _BINARY_SEARCH_TREE_H
#define _BINARY_SEARCH_TREE_H

#include <iostream>
#include <cassert>

// include the queue interface
#include "queue.h"

namespace UT_315 {
  /*
   * Template for a node in binary search tree.
   * The BSTData represents the data is being
   * stored in the search tree.
   */
  template <typename BSTData>
    struct BSTNode {
      // Data stored in the BST 
      BSTData data; 
      // Left child
      BSTNode *left_child;
      // Right Child
      BSTNode *right_child;
    };
  
  /*
   * Forward declaration of the Binary Search Tree (BST) class.
   * This is done so that the Binart Search Tree iterator class
   * can be declared without getting error from the C++ compiler.
   * The BSTData represents the data is being stored in the 
   * search tree. The DataKey type parameter represents the key
   * (identifier) of an object being stored in the tree.
   */
  template <typename BSTData, typename DataKey>
    class BinarySearchTree;
  
  
  /*
   * Binary Search Tree In-order Iterator class. 
   * This class is used to perform
   * an inorder tree traversal of the binary search tree.
   * The BSTData represents the data is being stored in the 
   * search tree. The DataKey type parameter represents the key
   * (identifier) of an object being stored in the tree.
   */
  template <typename BSTData, typename DataKey>
  class BST_inorder_iterator{
    // Declare BinarySearchTree as a frienc class so 
    // it can access the constructor of the iterator
    friend class BinarySearchTree<BSTData,DataKey>;
    
  public:
    // Type for a pointer to  a BST Node 
    typedef BSTNode<BSTData>* BSTNodePtr;
    

    // Determines if the iterator has data to be returned from
    // the current position in the tree.
    bool has_data() const;
    
    // Returns the data stored at the current position.
    // This method throws an assertion if there is no data
    // to be returned from the current node
    BSTData& get_data() const;
    
    // Advances the iterator to the next node in the tree  with
    // respect to the in-order traversal. No action is taken if
    // there is not a next node.
    void next();
    
    // Resets the iterator to its original initial position.
    void reset();
    
  private:
    // The initial node for the iterator
    BSTNodePtr root;
    
    // Queue containing the nodes in-order.
    // The current node for the iterator is the node at the
    // front of the queue.
    // Notice that queue actually stored the POINTERS to the 
    // nodes, rather than nodes themselves.
    queue<BSTNodePtr> order_queue;
    
    // constructor
    BST_inorder_iterator(BSTNodePtr the_root = NULL);
    
    // queue filler
    void queue_filler(BSTNodePtr node, queue<BSTNodePtr>& Q);
  };
  
  /*
   * Binary Search Tree Pre-order Iterator class. 
   * This class is used to perform
   * an preorder tree traversal of the binary search tree.
   * The BSTData represents the data is being stored in the 
   * search tree. The DataKey type parameter represents the key
   * (identifier) of an object being stored in the tree.
   */
  template <typename BSTData, typename DataKey>
  class BST_preorder_iterator{
    // Declare BinarySearchTree as a frienc class so 
    // it can access the constructor of the iterator
    friend class BinarySearchTree<BSTData,DataKey>;
    
  public:
    // Type for a pointer to a BST Node 
    typedef BSTNode<BSTData>* BSTNodePtr;
    
    // Determines if the iterator has data to be returned from
    // the current position in the tree.
    bool has_data() const;
    
    // Returns the data stored at the current position.
    // This method throws an assertion if there is no data
    // to be returned from the current node
    BSTData& get_data() const;
    
    // Advances the iterator to the next node in the tree  with
    // respect to the in-order traversal. No action is taken if
    // there is not a next node.
    void next();
    
    // Resets the iterator to its original initial position.
    void reset();
    
  private:
    // The initial node for the iterator
    BSTNodePtr root;
    
    // Queue containing the nodes in-order
    // The current node for the iterator is the node at the
    // front of the queue.
    queue<BSTNodePtr > order_queue;
    
    // constructor
    BST_preorder_iterator(BSTNodePtr the_root = NULL);
    
    // queue filler
    void queue_filler(BSTNodePtr node, queue<BSTNodePtr>& Q);
  };
  
  /*
   * Binary Search Tree class.
   * The BSTData represents the data is being stored in the 
   * search tree. The DataKey type parameter represents the key
   * (identifier) of an object being stored in the tree.
   */
  template <typename BSTData, typename DataKey>  
  class BinarySearchTree {
  public:
    // Default constructor
    BinarySearchTree();
    
    // Copy Constructor
    BinarySearchTree(const BinarySearchTree& T);
    
    // Destructor
    ~BinarySearchTree();
    
    // Copy assignment operator
    const BinarySearchTree& operator=(const BinarySearchTree& T);
    
    // Determines if the tree is empty
    bool is_empty() const;
    
    // Makes the tree an empty tree
    void make_empty();
    
    // Inserts a new node in the binary search tree
    void insert(const BSTData& obj);
    
    // Removes an element from the binary search tree based on its key 
    bool erase(const DataKey& key);
    
    // Finds an element in the BST based on its key, and returns 
    // an in-order iterator in which the first element is the element 
    // being searched
    BST_preorder_iterator<BSTData,DataKey> find(const DataKey& key) const;
    
    // Returns the number of items in the tree
    int size() const;
    
    // Returns the height of the tree
    int height() const;
    
    // Returns an in-order tree iterator from the root
    BST_inorder_iterator<BSTData,DataKey> get_in_order() const;
    
    // Returns an in-order tree iterator from a given node
    BST_inorder_iterator<BSTData,DataKey> 
      get_in_order(const DataKey& key) const;
    
    // Utility function used to print the nodes in the tree.
    // This routing is can be used for debugging purposes.
    void print_tree(ostream& out);
    
  private:
    // Root of the tree
    BSTNode<BSTData> *root;
    // Number of elements in the tree
    int t_size;
    
    // Auxiliary routines (Got to implement them!)
    
    // auxiliary insert routine
    void insert_aux(const BSTData& obj, BSTNode<BSTData> * & node);
    
    // auxiliary find routine
    BSTNode<BSTData> 
      *find_aux(const DataKey& key, BSTNode<BSTData> *node) const;
    
    // auxiliary find maximum routine
    BSTNode<BSTData> *find_min_aux(BSTNode<BSTData> *node) const;
    
    // auxiliary erase routine
    bool erase_aux(const DataKey& key, BSTNode<BSTData> * & node);
    
    // auxiliary height
    int height_aux(BSTNode<BSTData> *node) const; 
    
    // auxiliary print tree routine
    void print_tree_aux(ostream& out, BSTNode<BSTData> *node, int n_space);
  };
}
#endif
  
  
