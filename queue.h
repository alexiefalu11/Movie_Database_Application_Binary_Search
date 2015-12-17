/*
 * This file name: queue.h
 *
 * This file contains the declaration of interfaca for the queue 
 * container class. This class will be implemented with circular
 * linked list toolkit developed in project 3. But the que itself 
 * won't be circular, nor sorted.
 */

#ifndef _QUEUE_H
#define _QUEUE_H

#include <iostream>
#include <cstdlib>
#include <cassert>
#include "cdlist_node.h"

namespace UT_315 {
  /*
   * queue class container. This class implements an queue
   * (FIFO) data structure.
   * The Item type parameter represents the 
   * type of data being stored in the queue.
   */ 
  template <typename Item>
  class queue {
  public:
    // size type definition
    typedef std::size_t size_type;
    
    // Default constructor
    queue();
    
    // Copy constructor
    queue(const queue& Q);
    
    // Destructor
    ~queue();
    
    // Copy assignment operator
    const queue& operator=(const queue& Q);
  
    // Returns the element at the head of the queue
    Item& front() const;
    
    // Insert a new element at the tail of the queue
    void enqueue(const Item& obj);
    
    // Removes the element at the head of the queue
    void dequeue();
    
    // Determines if the queue is empty
    bool is_empty() const;
    
    // Make the queue empty
    void make_empty();
    
    // Returns the size of the queue
    size_type size() const;
    
    // Prints the contents of this queue.
    void print_queue(ostream& out);
   
  private:
    // front of the queue
    cdlist_node<Item> *q_front;
    // rear of the queue
    cdlist_node<Item> *q_rear;
    // size of the queue
    size_type q_size;
  };
}
#endif
  
