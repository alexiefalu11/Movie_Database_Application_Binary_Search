/*
 * This file: cdlist_node.cpp
 *
 * This file contains the implementation of the class cdlist_node
 * which represents a node in circular-doubly linked list. 
 * It also contains the implementations of a series of functions
 * that implemented a sorted circular-doubly linked list,
 * where nodes are inserted or deleted under the constrain
 * that a certain order must be maintained. The template parameter
 * Item is the type of object to be stored in the node. It is assumed 
 * that the object type stored in the nodes has overloaded the relational
 * comparison operators in order to determine the relative 
 * order of each item.
 */
 /*Alexie R. Ortiz Falu
  #S00709543
  Prof: Yahya Masalma */

#include "cdlist_node.h"

namespace UT_315 {

  
  /*
   * Removes a given element from the list. The argument is the 
   * pointer to the element to be removed from the list.
   * Parameter: target_ptr - pointer to target node (assumed not NULL)
   */
  template <typename Item>
  void list_remove(cdlist_node<Item>* target_ptr){
  //Make element prev, the prev element from the next element
   target_ptr->get_prev()->set_next(target_ptr->get_next());
   target_ptr->get_next()->set_prev(target_ptr->get_prev());
   target_ptr->set_next(NULL);
   target_ptr->set_prev(NULL);
   delete target_ptr;
  }
  
  /*
   * Inserts a new item into the linked list BEFORE the node pointed to
   * by the target_ptr paramter.
   * Parameter: obj - new object to be added into the list.
   * Parameter: target_ptr - pointer to a node, the new element will be added 
   *            before it. This pointer is assumed not NULL.
   */
  template <typename Item>
  void list_insert(cdlist_node<Item>* target_ptr, const Item& obj){

    cdlist_node<Item> *node_new = new cdlist_node<Item>(obj, target_ptr, target_ptr->get_prev());
    target_ptr->get_prev()->set_next(node_new);
    target_ptr->set_prev(node_new);

  }

  /*
   * This method inserts a new element after the node pointed to by 
   * argument target pointer.
   * Parameter: obj - new object to be added into the list.
   * Parameter: target_ptr - pointer to a node, the new element will be added 
   *            after it. This pointer is assumed not NULL.
   */
  template <typename Item>
  void list_insert_after(cdlist_node<Item> *target_ptr, const Item& obj){
     
      cdlist_node<Item> *node_new = new cdlist_node<Item>(obj, target_ptr->get_next(), target_ptr);
      target_ptr->get_next()->set_prev(node_new);
      target_ptr->set_next(node_new);

  }
  


  /*
   * Copy all elements from linked list into another linked list. This
   * is a deep copy operation.
   * NOTE: The destination list is assumed to be empty!!! Both pointers
   * are assumed not NULL.
   * Parameter: src_head_ptr - constant pointer to the head of source list.
   * Parameter: dst_head_ptr - pointer to the head of the target list.
   */
  template <typename Item>
  void list_copy(cdlist_node<Item>* src_head_ptr, 
		 cdlist_node<Item>* dst_head_ptr){
    
     cdlist_node<Item> *iter = src_head_ptr->get_next();
      while (iter != src_head_ptr) {
        list_insert_after(dst_head_ptr, iter->get_data());
        iter = iter->get_next();
      }
   
  }

  /*
   * Copy a range of elements from one linked list into another linked list.
   * This is a deep copy operation. The functions receives two pointers
   * delimiting the nodes to be copied:  src_head_ptr and  src_tail_ptr.
   * The function will copy all element in the range:
   * src_head_ptr->get_next() and src_tail_ptr->get_prev().
   *
   * NOTE: The destination list is assumed to be empty!!! All pointers
   * are assumed not NULL.
   * Parameter: src_head_ptr - constant pointer to the node before the 
   * first node of source list to be copied.
   * Parameter: src_tail_ptr - constant pointer to the node after the 
   * last node of source list to be copied.
   * Parameter: dst_head_ptr - pointer to the head of the target list.
   */
  template <typename Item>
  void list_copy(cdlist_node<Item> *src_head_ptr, 
		 cdlist_node<Item> *src_tail_ptr, 
		 cdlist_node<Item> *dst_head_ptr){
    
    cdlist_node<Item> *iter = src_head_ptr->get_next();
          while (iter != src_tail_ptr)
          {
          list_insert_after(dst_head_ptr, iter->get_data());
          iter = iter->get_next();
          }
  }
  
  /*
   * Removes all elements from the list, leaving it with only 
   * the header node. The parameter is the header of the list
   * to be cleared. 
   * NOTE: head_ptr is assumed to be non-NULL
   * Parameter: head_ptr - pointer to the header of the list
   */
  template <typename Item>
  void list_clear(cdlist_node<Item>* head_ptr){
    
   cdlist_node<Item> *iter = head_ptr->get_next();
      while (iter != head_ptr)
      {
        list_remove(iter);
        iter = head_ptr->get_next();
      }

  }
  
  /*
   * Removes all elements between two positions from the list.
   * The functions receives two pointers
   * delimiting the nodes to be removed:  src_head_ptr and  src_tail_ptr.
   * The function will remove all elements in the range:
   * src_head_ptr->get_next() and src_tail_ptr->get_prev().
   *
   * NOTE: The destination list is assumed to be empty!!! All pointers
   * are assumed not NULL.
   * Parameter: src_head_ptr - constant pointer to the node before the 
   * first node of source list to be removed.
   * Parameter: src_tail_ptr - constant pointer to the node after the 
   * last node of source list to be removed.
   */
  template <typename Item>
  void list_clear(cdlist_node<Item> *head_ptr, 
		  cdlist_node<Item> *tail_ptr){

    cdlist_node<Item> *iter = head_ptr->get_next();
      while (iter != tail_ptr)
      {
        list_remove(iter);
        iter = head_ptr->get_next();
      }
  }
		  
  /*
   * Returns the length of this list. The parameter is the header
   * of the list. 
   * NOTE: head_ptr is assumed to be non-NULL
   * Parameter: head_ptr - pointer to the head of the list
   */ 
  template <typename Item>
  std::size_t list_length(cdlist_node<Item> *head_ptr){
    
    std::size_t result = 0;
    cdlist_node<Item> *iter = head_ptr->get_next();
        while (iter != head_ptr) 
        {
          result++;
          iter = iter->get_next();
        }
        return result;
  }
  
  /*
   * Counts all elements between two positions from the list.
   * The functions receives two pointers
   * delimiting the nodes to be count:  src_head_ptr and  src_tail_ptr.
   * The function will remove all elements in the range:
   * src_head_ptr->get_next() and src_tail_ptr->get_prev().
   *
   * Parameter: head_ptr - constant pointer to the node before the 
   * first node of source list to be counted.
   * Parameter: tail_ptr - constant pointer to the node after the 
   * last node of source list to be counted.
   */
  template <typename Item>
  std::size_t list_length(cdlist_node<Item> *head_ptr,
			  cdlist_node<Item> *tail_ptr){
     
    std::size_t result = 0;

    cdlist_node<Item> *iter = head_ptr->get_next();
    while (iter != tail_ptr) 
    {
        result++;
        iter = iter->get_next();
    }
    return result;
  }

  /*
   * Finds and returns the pointer to the node containing a given
   * object. The function receives the header of the list and the 
   * object to be found.
   * Parameter: head_ptr - pointer to the header of the list
   * Parameter: obj - the object to be found
   * NOTE: obj must have its operator == overloaded, and head_ptr is 
   * assumed to be non-NULL.
   */
  template <typename Item>
  cdlist_node<Item>* list_search(cdlist_node<Item> *head_ptr, 
				 const Item& obj){
    
    cdlist_node<Item> *iter = head_ptr->get_next();
      while (iter != head_ptr) 
      {
        if (iter->get_data() == obj)
        {
            return iter;
        }
        iter = iter->get_next();
      }
    return NULL;
  }
  
  /*
   * Finds and returns constant pointer to the node containing a given
   * object. The function receives the header of the list and the 
   * object to be found.
   * Parameter: head_ptr - pointer to the header of the list
   * Parameter: obj - the object to be found
   * NOTE: obj must have its operator == overloaded, and head_ptr is 
   * assumed to be non-NULL.
   */
 
  template <typename Item>
  const cdlist_node<Item>* list_search(const cdlist_node<Item> *head_ptr, 
				       const Item& obj){
    
    cdlist_node<Item> *iter = head_ptr->get_next();
    while (iter != head_ptr)
    {
      if (iter->get_data() == obj)
      {
        return iter;
      }
        iter = iter->get_next();
    }
  return NULL;
  }


  /*
   * Finds the location where a new element should go in order to 
   * keep an increasing sorted order. Returns the pointer to this
   * location.
   * Parameter: head_ptr - pointer to the head of the list
   * Parameter: obj - element which we want to location a position for
   * NOTE: obj must have its operators == and > overloaded, and
   * head_ptr cannot be NULL.
   */
  template <typename Item>
  cdlist_node<Item> *list_locate(cdlist_node<Item>* head_ptr,
				 const Item& obj){
     cdlist_node<Item> *iter = head_ptr->get_next();
        while (iter != head_ptr) 
        {
          if (obj < iter->get_data())
          {
            return iter;
          }
            iter = iter->get_next();
        }
    return head_ptr;
  }


  /*
   * Finds the location where a new element should go in order to 
   * keep an increasing sorted order. Returns a constant pointer 
   * to this location.
   * Parameter: head_ptr - pointer to the head of the list
   * Parameter: obj - element which we want to location a position for
   * NOTE: obj must have its operators == and > overloaded, and
   * head_ptr cannot be NULL.
   */
/*  template <typename Item>
  const cdlist_node<Item> *list_locate(cdlist_node<Item>* head_ptr){
    // ADD YOUR CODE HERE
    return NULL;
  } */
}
