/*
 * This file: List.h
 * 
 * This file contains the declaration of the interface for a 
 * List container class. This list will be implemented as 
 * Sorted Circular Doubly Linked List using the code associated
 * with the Circular Doubly Linked List toolkit. It also declares
 * the interface of an iterator that can be used to traverse 
 * the list.
 *
 */

#ifndef _LIST_H
#define _LIST_H

#include <iostream>
#include <cstdlib>
#include "cdlist_node.h"

namespace UT_315 {
  /*
   * Forward declaration of the  List container class, implemented as a 
   * Sorted Circular Doubly Linked List. The Item type parameter 
   * represents the type of the elements to be stored in the list.
   */
  template <typename Item>
    class List;

  /*
   * List_Iterator is a class used to implement an external iterator
   * over the List container class. This iterator will be used
   * access and traverse the different the nodes in the list.
   * The Item type parameter  represents the type of the elements to 
   * be stored in the list. 
   */
  
  template <typename Item>
  class List_Iterator {
    // Declare List as a friend class so it can call the List_Iterator
    // constructor, and other private member functions.
    friend class List<Item>;
    
  public:
    // Determines if the iterator has data to return from 
    // its current position
    bool has_data() const;
   
    // Returns the data stored as the current position for this iterator.
    Item& get_data();
    
    // Advances the iterator to the next valid position on the list.
    void next();
    
    // Advances the iterator to the previous position with respect to 
    // the current position of the iterator on the list.
    void prev();
    
  private:
    // Head node pointer for the iterator
    cdlist_node<Item> *head;
    // Tail node pointer for the iterator
    cdlist_node<Item> *tail;
    // The current pointer for the iterator
    cdlist_node<Item> *current;
    // Mode for the iterator
    bool forward_iter;
    
    // Private default constructor, added mainly for convenience
    // so we can easily declare iterator variables
    // NOTE: This constructor does not produce valid iterators.
    List_Iterator() { head = tail = current = NULL; forward_iter = true;}
    
    // Constructor based on the first and last element over
    // which the iterator shall occurs. Both argument are assumed to be
    // non-NULL.
    // NOTE: This method is the method that the appropriate methods 
    // is class List must call in order to create iterators.
    List_Iterator(cdlist_node<Item> *init_head, cdlist_node<Item> *init_tail,
		  bool go_forward=false);
    
  };
  
  /*
   * Declaration of the  List container class, implemented as a 
   * Sorted Circular Doubly Linked List. The Item type parameter 
   * represents the type of the elements to be stored in the list.
   */
 
  template <typename Item>
  class List {
  public:
    // Define type for size of the list
    typedef std::size_t size_type;
    
    // Default constructor
    List();

    // Copy constructor
    List(const List& L);
    
    // Destructor
    ~List();
    
    // Copy assignment operator
    const List& operator=(const List& L);
    
    // Determines if the list is an empty list
    bool is_empty() const;
    
    // Makes the list an empty list
    void make_empty();
    
    // Returns an iterator to the first element of the list
    List_Iterator<Item> first() const;
    
    // Returns an iterator to the last element in the list
    List_Iterator<Item> last() const;
    
    // Finds an element in the list and returns an iterator to it.
    List_Iterator<Item> find(const Item& obj) const;

    // Insert a new element at the proper location in the list
    // so that the increasing order in the list is maintained.
    void insert(const Item& obj);
    
    // Removes an element from the list, and keep sorted order.
    bool erase(const Item& obj);
    
    // Returns the size of the list
    size_type size() const;
    
    // Prints the contents of the list in the forward direction.
    // NOTE: This method is mainly for debugging purposes
    void print_forward(ostream& out) const;
    
    // Prints the contents of the list in the backward direction.
    // NOTE: This method is mainly for debugging purposes
    void print_backward(ostream& out) const;
    
  private:
    // The head of the list
    cdlist_node<Item> *head;
  };
}
#endif
