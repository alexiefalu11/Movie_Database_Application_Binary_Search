/*
 * This file name: BinarySearchTree.cpp
 *
 * This file contains the implementation of the Binary Search Tree
 * container class.
 */
 /*  Alexie R. Ortiz Falu
  #S00709543
  Prof: Yahya Masalma */

#include "BinarySearchTree.h"

namespace UT_315 {
  
  ////////////////////// BinarySearchTree Implementation ////////////////////


  /*********** DO NOT MODIFY THE FOLLLOWING TWO FUNCTIONS *****************/
  
  /*
   * This functions is used to print the elements in the tree
   * so as to mimic the actual structure of the tree.
   * It relies of the auxiliary function print_tree_aux().
   */
  template <typename BSTData, typename DataKey>
  void BinarySearchTree<BSTData,DataKey>::print_tree(ostream& out) {
    print_tree_aux(out, root, 0);
  }
  
  /*
   * This function is used to print the elements in the tree
   * in the following form:
   *    1) Print the right subtree.
   *    2) Print the root of the tree.
   *    3) Print the left subtree.
   * The parameter node is a pointer to the root of the tree
   * to be printed. The parameter n_space is used to print
   * blank spaces before printing the data contained on the 
   * root node.
   */
  template <typename BSTData, typename DataKey>
  void BinarySearchTree<BSTData,DataKey>::print_tree_aux
  (ostream& out, BSTNode<BSTData> *node, int n_space) {
    if (node != NULL){
      // print right child first
      print_tree_aux(out, node->right_child, n_space + 2);
      
      // print some space and then data in the root node
      for (int i=0; i < n_space; ++i){
	cout << " ";
      }
      cout << node->data << endl;
      
      // print left child
      print_tree_aux(out, node->left_child, n_space + 2);
    }
  }
  /************************************************************************/


  /************* START ADDING YOUR CODE HERE ******************************/
  /*
   * Default constructor. Creates an empty binary search tree, with 
   * a NULL root node and zero elements.
   */
  template <typename BSTData, typename DataKey>
  BinarySearchTree<BSTData,DataKey>::BinarySearchTree() {
    //Make root equal null with size 0
    root = NULL;
    t_size = 0;
  }
  
  /*
   * Copy constructor. Creates a new deep copy of the binary search tree 
   * passed as argument.
   * Parameter: T - the original BST
   */
  template <typename BSTData, typename DataKey>
  BinarySearchTree<BSTData,DataKey>::BinarySearchTree
  (const BinarySearchTree<BSTData,DataKey>& T){
    //Insert all data from T into this BST
    *this = T;
   
  }
  

  /*
   * Destructor. Makes the BST an empty tree by removing all the 
   * nodes, including the tree.
   */
  template <typename BSTData, typename DataKey>
  BinarySearchTree<BSTData,DataKey>::~BinarySearchTree(){
   //Erase this BST
   make_empty();
   root = NULL;

  }
  
  /*
   * Copy Assignment operator. Makes a deep copy of the source BST.
   * Parameter: T - original BST
   */
  template <typename BSTData, typename DataKey>
  const BinarySearchTree<BSTData,DataKey> &
  BinarySearchTree<BSTData,DataKey>::operator=
  (const BinarySearchTree<BSTData,DataKey> & T){
    t_size = T.size();
    BST_preorder_iterator<BSTData, DataKey> iter(T.root);
    while (iter.has_data())
    {
      insert(iter.get_data());
      iter.next();
    }
    
    return *this;
  }

  /*
   * Returns true if the tree is empty, or false otherwise. An empty
   * tree has a NULL root.
   * Output: true is the tree is empty, or false otherwise.
   */
  template <typename BSTData, typename DataKey>
  bool BinarySearchTree<BSTData,DataKey>::is_empty() const{
    // DO NOT MODIFY THIS FUNCTION
    return (root == NULL);
  }
  
  
  /*
   * Makes the BST an empty BST by erasing all the nodes, including the
   * root.
   */
  template <typename BSTData, typename DataKey>
  void BinarySearchTree<BSTData,DataKey>::make_empty(){
    //Erase root until it is Null
    if(root != NULL)
    {
      while(root->left_child != NULL)
      {
        erase(root->left_child->data.get_key());
      }
      while(root->right_child != NULL)
      {
        erase(root->right_child->data.get_key());
      }
    
    }
  }
  
  /*
   * Insert a new element into the binary search tree. This function
   * must rely on the insert_aux function to use recursion to 
   * insert the new element at the proper subtree.
   * Parameter: obj - the new element to be added into the 
   * binary search tree (BST). 
   */
  template <typename BSTData, typename DataKey>
  void BinarySearchTree<BSTData,DataKey>::insert(const BSTData& obj){
    //Function insert_aux call
     if (root == NULL) {
        root = new BSTNode<BSTData>;
        root->data = obj;
        root->left_child = NULL;
        root->right_child = NULL;
    }
    else {
        insert_aux(obj, root);
    }
    t_size++;
  }
  

  /*
   * Auxiliary function used to insert a new elements on a BST
   * tree. The function MUST use recursion to find the right place to
   * insert the node, according to the insertion algorithm for 
   * Binary Search Trees. After the insert is completed, the size of the 
   * BST must be incremented by one.
   * Parameter: obj - the new object to be inserted in the tree.
   * Parameter: node - the reference of the pointer to the node that is 
   * the root of the sub-tree that we are exploring for insertion.
   * 
   */
  template <typename BSTData, typename DataKey>
  void BinarySearchTree<BSTData,DataKey>::insert_aux
  (const BSTData& obj, BSTNode<BSTData> * & node){
    //Insert in an empty BST
    if(obj < node->data){
        if (node->left_child == NULL) {
            BSTNode<BSTData> *node_new = new BSTNode<BSTData>;
            node_new->data = obj;
            node_new->left_child = NULL;
            node_new->right_child = NULL;
            node->left_child = node_new;
            return;
        }
        else {
            insert_aux(obj, node->left_child);
        }
    }
    else {
        if (node->right_child == NULL) {
            BSTNode<BSTData> *node_new = new BSTNode<BSTData>;
            node_new->data = obj;
            node_new->left_child = NULL;
            node_new->right_child = NULL;
            node->right_child = node_new;
            return;
        }
        else {
            insert_aux(obj, node->right_child);
        }
    }
  }
  

  
  /*
   * Creates a new in-order iterator with all the nodes in the
   * tree.
   */
  template <typename BSTData, typename DataKey>
  BST_inorder_iterator<BSTData,DataKey>
  BinarySearchTree<BSTData,DataKey>::get_in_order()const {
    // DO NOT MODIFY THIS FUNCTION
    return BST_inorder_iterator<BSTData,DataKey>(root);
  }
  
  /*
   * Create a new in-order iterator with all the nodes in the
   * subtree rooted at the node with holding a key value equal
   * to the paramter. If more that one exists, then the one
   * nearest to the root is found.
   * Parameter: key - the key of the target node. 
   */
  template <typename BSTData, typename DataKey>
  BST_inorder_iterator<BSTData,DataKey>
  BinarySearchTree<BSTData,DataKey>::get_in_order
  (const DataKey& key) const {
    
    return BST_inorder_iterator<BSTData,DataKey>(find_aux(key,root));
  }
  
  
  /*
   * Finds a given object in the tree, and returns a pre-order tree iterator
   * to it. This function MUST rely on function find_aux to recursively
   * search the element with the target key.
   * Parameter: key - the key of the object to be found.
   * Output: iterator to the node where the element with the argument 
   * key is found, or an empty iterator.
   */
  template <typename BSTData, typename DataKey>
  BST_preorder_iterator<BSTData,DataKey>
  BinarySearchTree<BSTData,DataKey>::find(const DataKey& key) const {
    
     BSTNode<BSTData> * temp = find_aux(key, root);
    if(temp != NULL) {
        return BST_preorder_iterator<BSTData, DataKey>(temp);
    }
    return BST_preorder_iterator<BSTData,DataKey>(NULL);
  }

  /*
   * Auxiliary function used to find the pointer to the BSTNode that
   * contains an element with a key equal to the argument key. This
   * function MUST use recursion to find the node with the argument key.
   * Parameter: key - the key of the object to be found.
   * Parameter: node - the root of the sub-tree currently being searched.
   * Output: pointer to the first occurrence of a node containing a data
   * element with a key equal to the argument key.
   */
  template <typename BSTData, typename DataKey>
  BSTNode<BSTData> *BinarySearchTree<BSTData,DataKey>::find_aux
  (const DataKey& key, BSTNode<BSTData> *node) const {
    
    if (node != NULL) {
        if (node->data < key) {
            return find_aux(key, node->right_child);
        }
        else if (node->data > key) {
            return find_aux(key, node->left_child);
        }
        else if(node->data == key) {
            return node;
        }
    }
    else {
        return NULL;
    }
  }
  
  
  /*
   * Removes an element with a given key from the Binary Search Tree (BST).
   * If multiple copies of the same key exist, then the first one that 
   * is found is deleted. This function must rely on function erase_aux()
   * to recursively 
   * Parameter: key - the key of the node to be searched.
   */
  template <typename BSTData, typename DataKey>
  bool BinarySearchTree<BSTData,DataKey>::erase(const DataKey& key) {
    

     if (erase_aux(key, root)) {
        t_size--;
        return true;
    }
    return false;
  }
  
  /*
   * This is an auxiliary function used to remove an node from the 
   * tree. The functions must use recursion to traverse the tree 
   * and find the node to be deleted. The function must follow
   * the Binary Search Tree Deletion algorithm. If more than one
   * node exist with the given key, then the first one found is the 
   * one deleted.
   * Parameter: key - the key of the node to be deleted.
   * Parameter: node - a reference to the pointer of the node
   * that is the root of the subtree being inspected.
   */
  template <typename BSTData, typename DataKey>
  bool BinarySearchTree<BSTData,DataKey>::erase_aux
  (const DataKey& key, BSTNode<BSTData> * & node){
    BSTNode<BSTData> *temp = NULL;

     if (node != NULL) {
        if (node->data < key) {
            temp = node->right_child;
            if (temp->data == key) {
                if(temp->right_child == NULL && temp->left_child == NULL){
                    node->right_child = NULL;
                    delete temp;
                    return true;
                }
            }
            return erase_aux(key, node->right_child);
        }
        else if (node->data > key) {
            temp = node->left_child;
            if (temp->data == key) {
                if(temp->right_child == NULL && temp->left_child == NULL){
                    node->left_child = NULL;
                    delete temp;
                    return true;
                }
            }
            return erase_aux(key, node->left_child);
        }
        else if(node->data == key) {
            if (node->left_child != NULL && node->right_child != NULL) {
                temp = find_min_aux(node->right_child);
                node->data = temp->data;
                if (node->right_child->data == temp->data) {
                    if (temp->right_child == NULL && temp->left_child == NULL) {
                        node->right_child = NULL;
                        delete temp;
                        return true;
                    }
                }
                return erase_aux(temp->data.get_key(), node->right_child);
            }
            else {
                if(node->right_child != NULL){
                    temp = node->right_child;
                    node->data = temp->data;
                    node->left_child = temp->left_child;
                    node->right_child = temp->right_child;
                    temp->right_child = NULL;
                    temp->left_child = NULL;
                    delete temp;
                    return true;
                }
                else {
                    temp = node->left_child;
                    node->data = temp->data;
                    node->left_child = temp->left_child;
                    node->right_child = temp->right_child;
                    temp->right_child = NULL;
                    temp->left_child = NULL;
                    delete temp;
                    return true;
                }
            }
        }
    }
    return false;
  }

  /*
   * This is an auxiliary function used to find a pointer to the node
   * with the minimum key value on a tree. The functions receives as
   * parameter a pointer to the root of the tree.
   * Parameter: node - pointer to the root of the tree to be searched.
   */
  template <typename BSTData, typename DataKey>
  BSTNode<BSTData>* BinarySearchTree<BSTData,DataKey>::find_min_aux
  (BSTNode<BSTData> *node) const{
    
    while (node->left_child != NULL) {
        node = node->left_child;
    }
    return node;
  }
  
  
  /*
   * Returns the size of the tree as the number of elements it
   * currently holds.
   * Output: number of elements in the tree.
   */
  template <typename BSTData, typename DataKey>
  int BinarySearchTree<BSTData,DataKey>::size() const {
    // DO NOT MODIFY THIS FUNCTION
    return t_size;
  }
  
  /*
   * Returns the height of the tree, defined as:
   * a) 0 if the tree is empty.
   * b) 1 + MAX(height(left_child), height(right_child)), otherwise
   *
   * This function should rely on function height_aux() to recursively compute
   * the height of the tree.
   * Output: the height of the tree. 
   */
  template <typename BSTData, typename DataKey>
  int BinarySearchTree<BSTData,DataKey>::height() const {

    
    return 1 + height_aux(root);
  }
  
  /*
   * Auxiliary function used to compute the height of a tree.
   * The height is defined as:
   * a) 0 if the tree is empty.
   * b) 1 + MAX(height(left_child), height(right_child)), otherwise
   *
   * This function receives as argument the node that is the root
   * of the sub-tree being searched. The function MUST use recursion 
   * to traverse the tree, and compute the height.
   * Input: node  - pointer to the node that is the root of the sub-tree
   * currently being explored.
   * Output: height of the sub-tree. 
   */
  template <typename BSTData, typename DataKey>
  int BinarySearchTree<BSTData,DataKey>::height_aux
  (BSTNode<BSTData> *node) const{
    
    int left_H = 0, right_H = 0;
    if(node != NULL)
    {
      if(node->right_child != NULL)
      {
        right_H++;
        right_H += height_aux(node->right_child);
      }
      if(node->left_child != NULL)
      {
        left_H++;
        left_H += height_aux(node->left_child);
      }
      if(left_H > right_H)
      {
        return left_H;
      }
      else if(right_H > left_H)
      {
        return right_H;
      }
      else
      {
        return left_H;
      }
    }
   return 0;
  }
  

  
  ////////////////////////////////////////////////////////////////////////////
  
  /////////////////// BST_inorder_iterator Implementation ////////////////////

  /*
   * Default constructor. This method creates a new BST_inorder_iterator class,
   * that can be used to perform an in-order tree traversal. The argument
   * is the root of the tree (sub-tree) to be iterated over. 
   * If the argument is not NULL, then this method MUST use method 
   * queue_filler() to fill-in the order_queue data member with the 
   * pointers to the nodes in the tree, and these node pointers must be 
   * added into the queue following  the in-order traversal ordering.
   * Parameter: the_root - pointer to the node that is the root of the tree 
   * (sub-tree) to be iterated over.
   */
  template <typename BSTData, typename DataKey>
  BST_inorder_iterator<BSTData,DataKey>::BST_inorder_iterator
  (BSTNodePtr the_root) {
    
     if (the_root != NULL) {
        queue_filler(the_root, order_queue);
        root = order_queue.front();
    }
  }
  
  /*
   * Method used to add tree node ptr in a queue following an in-order tree
   * traversal.
   * Input: the_root - pointer to the node that is the root of the tree 
   * (sub-tree) to be iterated over.
   * Input: Q - the queue used to hold the nodes in the tree following an
   * in-order ordering.
   */
  template <typename BSTData, typename DataKey>
  void BST_inorder_iterator<BSTData,DataKey>::queue_filler
  (BSTNodePtr node, queue<BSTNodePtr>& Q){
    
     if (node->left_child != NULL) {
        queue_filler(node->left_child, Q);
    }
    if (node->right_child != NULL) {
        Q.enqueue(node);
        queue_filler(node->right_child, Q);
    }
    else {
        Q.enqueue(node);
    }
  }
  
  /*
   * Determines if the iterator has data to be returned from 
   * its current position.
   * Output: true if the iterator has data to be returned or 
   * false otherwise.
   */
  template <typename BSTData, typename DataKey>
  bool BST_inorder_iterator<BSTData,DataKey>::has_data() const{
    
    return !(order_queue.is_empty());
  }
  
  /*
   * Returns the data at the current node in the tree being traversed.
   * Output: data at the current node in the tree being traversed.
   */
  template <typename BSTData, typename DataKey>
  BSTData& BST_inorder_iterator<BSTData,DataKey>::get_data() const{
    // DO NOT MODIFY THIS FUNCTION
    return order_queue.front()->data;
  }

  /*
   * Advances the iterator to the next node in the tree  with
   * respect to the in-order traversal. No action is taken if
   * there is not a next node.
   */
  template <typename BSTData, typename DataKey>
  void BST_inorder_iterator<BSTData,DataKey>::next(){
    
    order_queue.dequeue();
    root = order_queue.front();
  }
  
  /*
   * Resets the iterator to its original state.
   */
  template <typename BSTData, typename DataKey>
  void BST_inorder_iterator<BSTData,DataKey>::reset(){
    // DO NOT MODIFY THIS FUNCTION
    order_queue.make_empty();
    queue_filler(root, order_queue);
  }
  ////////////////////////////////////////////////////////////////////////////

  /////////////////// BST_preorder_iterator Implementation ///////////////////

  /*
   * Default constructor. This method creates a new BST_preorder_iterator 
   * that can be used to perform a pre-order tree traversal. The argument
   * is the root of the tree (sub-tree) to be iterated over. 
   * If the argument is not NULL, then this method MUST use method 
   * queue_filler() to fill-in the order_queue data member with the pointers
   * to the nodes in the tree, and these node pointers must be added into
   * the queue following  the pre-order traversal ordering.
   * Input: the_root - pointer to the node that is the root of the tree 
   * (sub-tree) to be iterated over.
   */
  template <typename BSTData, typename DataKey>
  BST_preorder_iterator<BSTData,DataKey>::BST_preorder_iterator
  (BSTNodePtr the_root) {
    
    if (the_root != NULL) {
        queue_filler(the_root, order_queue);
        root = order_queue.front();
    }
    else {
        order_queue = queue<BSTNodePtr>();
    }
  }
  
  /*
   * Method used to add tree node in a queue following an pre-order tree
   * traversal.
   * Input: the_root - pointer to the node that is the root of the tree 
   * (sub-tree) to be iterated over.
   * Input: Q - the queue used to hold the nodes in the tree following an
   * in-order ordering.
   */
  template <typename BSTData, typename DataKey>
  void BST_preorder_iterator<BSTData,DataKey>::queue_filler
  (BSTNodePtr node, queue<BSTNodePtr>& Q){
    //If node is not empty will enqueue the root, left and right child
    Q.enqueue(node);
    if (node->left_child != NULL) {
        queue_filler(node->left_child, Q);
    }
    if (node->right_child != NULL) {
        queue_filler(node->right_child, Q);
    }

  }
  
  /*
   * Determines if the iterator has data to be returned from 
   * its current position.
   * Output: true if the iterator has data to be returned or 
   * false otherwise.
   */
  template <typename BSTData, typename DataKey>
  bool BST_preorder_iterator<BSTData,DataKey>::has_data() const{
    
    //Return true if iterator is not empty
    return !(order_queue.is_empty());
  }
  
  /*
   * Returns the data at the current node in the tree being traversed.
   * Output: data at the current node in the tree being traversed.
   */
  template <typename BSTData, typename DataKey>
  BSTData& BST_preorder_iterator<BSTData,DataKey>::get_data() const{
    // DO NOT MODIFY THIS FUNCTION
    return order_queue.front()->data;
  }
  
  /*
   * Advances the iterator to the next node in the tree  with
   * respect to the pre-order traversal. No action is taken if
   * there is not a next node.
   */
  template <typename BSTData, typename DataKey>
  void BST_preorder_iterator<BSTData,DataKey>::next(){
   
   if (order_queue.is_empty()) {
        order_queue.dequeue();
        root = order_queue.front();
    }
  }
  
  /*
   * Resets the iterator to its original state.
   */
  template <typename BSTData, typename DataKey>
  void BST_preorder_iterator<BSTData,DataKey>::reset(){
    // DO NOT MODIFY THIS FUNCTION
    order_queue.make_empty();
    queue_filler(root, order_queue);
  }
  ///////////////////////////////////////////////////////////////////////////
}
