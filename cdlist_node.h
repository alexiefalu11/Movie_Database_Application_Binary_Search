/*
 *  File: cdlist_node.h
 * 
 * This file contains the declaration of the class cdlist_node
 * which represents a node in circular-doubly linked list. 
 * It also contains the declarations of a series of functions
 * that implemented a sorted circular-doublu linked list,
 * where nodes are inserted or deleted under the constrain
 * that a certain order must be maintained. The template parameter
 * Item is the type of object to be stored in the node. It is assumed 
 * that the object type stored in the nodes has overloaded the relational
 * comparison operators in order to determine the relative 
 * order of each item.
 */

#ifndef _CDLIST_NODE_H
#define _CDLIST_NODE_H

#include <iostream>
#include <cstdlib>

using namespace std;


namespace UT_315 {
  /*
   * Circular doubly linked list interface.
   */
  
  /*
   * This class represents a node in a circular doubly linked list.
   */
  template <typename Item>
  class cdlist_node{
  public:
    // Default constructor
    cdlist_node(const Item& init_data = Item(), 
		cdlist_node *init_next = NULL, 
		cdlist_node *init_prev = NULL)
      {data = init_data; link_next = init_next; link_prev = init_prev;}
    
    // Accessor methods (ALL INLINE IMPLEMENTATIONS)
    
    // Get the data item (non-const version)
    Item& get_data() { return data; }

    // Get the data item (const version)
    const Item& get_data() const{ return data; }
    
    // Get the next link (non-const version)
    cdlist_node* get_next() { return link_next; }

    // Get the next link (const version)
    const cdlist_node* get_next() const { return link_next; }
    
   // Get the prev link (non-const version)
    cdlist_node* get_prev()  { return link_prev; }

    // Get the prev link (const version)
    const cdlist_node* get_prev() const { return link_prev; }
    
    // MUTATOR METHODS
    
    // Set the data value
    void set_data(const Item& new_data) { data = new_data; }
    
    // Set the next link
    void set_next(cdlist_node* new_link) { link_next = new_link; }
    
    // Set the previous link
    void set_prev(cdlist_node* new_link) { link_prev = new_link; }
   
  private:
    // Data Field for the node
    Item data;
    // Link to next node
    cdlist_node *link_next;
    // Link to prevoius node
    cdlist_node *link_prev;
  };

  // FUNCTIION TO MANIPULATE THE CIRCULAR DOUBLY LINKED LIST

  // Clear the list, leaving only the header node
  template <typename Item>
    void list_clear(cdlist_node<Item> *head_ptr);

  // Clear all elements between two positions
  template <typename Item>
    void list_clear(cdlist_node<Item> *head_ptr,
		    cdlist_node<Item> *tail_ptr);
  
  // Copy the list (Deep Copy of list structure only!)
  template <typename Item>
    void list_copy(cdlist_node<Item> *src_head_ptr, 
		   cdlist_node<Item> *dst_head_ptr);

  // Copy a group of contigous elements (Deep Copy of list structure);
  template <typename Item>
    void list_copy(cdlist_node<Item> *src_head_ptr, 
		   cdlist_node<Item> *src_tail_ptr,
		   cdlist_node<Item> *dst_head_ptr);
  
  
  // Insert a new element into the list
  template <typename Item>
    void list_insert(cdlist_node<Item> *target_ptr, const Item& obj);
  
  // Inserts a new element into the list inmediately after a given
  // target pointer.
  template <typename Item>
    void list_insert_after(cdlist_node<Item> *target_ptr, const Item& obj);
  

  // Removes an element from the list
  template <typename Item>
    void list_remove(cdlist_node<Item>* target_ptr);
  
  // Get the length of the list
  template <typename Item>
    std::size_t list_length(cdlist_node<Item> *head_ptr);

  // Get the number of elements between two positions
  template <typename Item>
    std::size_t list_length(cdlist_node<Item> *head_ptr, 
			    cdlist_node<Item> *tail_ptr);

  // Find an element in the list
  template <typename Item>
    cdlist_node<Item>* list_search(cdlist_node<Item> *head_ptr, 
				   const Item& obj);
  
  // Find an element in the list (const version)
  template <typename Item>
    const cdlist_node<Item>* list_search(const cdlist_node<Item> *head_ptr, 
					 const Item& obj);


  // Get the position where an element should go in the order
  template <typename Item>
    cdlist_node<Item>* list_locate(cdlist_node<Item>* head_ptr, 
				   const Item& obj);
  // Get the position where an element should go in the order (const-version)
  template <typename Item>
    const cdlist_node<Item>* list_locate(const cdlist_node<Item>* head_ptr, 
					 const Item& obj);
}
#endif
