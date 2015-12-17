/*
 * This file name: queue.cpp
 *
 * This file contains the implementation of the queue container
 * class implemented with the cdlist_node toolkit for circular 
 * doubly linked lists.
 */


#include "queue.h"

namespace UT_315 {

  ///////////////////// DO NOT MODIFY THIS FUNCTION ///////////////////////
  /*
   * Prints the contents of this queue.
   * Mainly for debugging purposes. This method assumes
   * that the Item data type has overloaded the operator <<
   */
  template <typename Item>
  void queue<Item>::print_queue(ostream& out){
    cdlist_node<Item> *cursor = NULL;
    for (cursor = q_front->get_next(); 
	 cursor != q_rear;
	 cursor = cursor->get_next()){
      out << cursor->get_data() << endl;
    }
  }
  /////////////////////////////////////////////////////////////////////////
  
  ////////////////////// START ADDING YOUR CODE HERE //////////////////////
  /*
   * Default constructor. Creates a new empty queue by
   * making the front and read be two dummy headers.
   * In the q_front node, the next field points to the 
   * rear node, and the prev field points to NULL.
   * Likewise, in the q_rear node, the prev field points
   * to the q_front field, and the next field points to
   * NULL.
   */
  template <typename Item>
  queue<Item>::queue(){
    
    //Declares everything in queue
        q_size = 0;
        q_front = new cdlist_node<Item>();
        q_rear = new cdlist_node<Item>();
        q_front->set_next(q_rear);
        q_rear->set_prev(q_front);
  }
  

  /*
   * Copy constructor. Creates a new deep copy of the queue 
   * passed as parameter. This functions copies all the elements
   * between the front and the rear of the source queue.
   * Parameter: Q - the source queue to be copied.
   */
  template <typename Item>
  queue<Item>::queue(const queue<Item>& Q){
    
    *this = Q;
  }

  
  /*
   * This destructor erases all the nodes between the front
   * and the rear of the queue, and then deletes the 
   * front and rear pointer.
   */
  template <typename Item>
  queue<Item>::~queue(){
   
   make_empty();
   delete q_front;
   delete q_rear;
    
  }
  
  /*
   * Copy assignment operator. Makes a deep copy of the queue 
   * passed as parameter. This functions copies all the elements
   * between the front and the rear of the source queue.
   * Parameter: Q - the source queue to be copied.
   */
  template <typename Item>
  const queue<Item>& queue<Item>::operator=(const queue<Item>& Q){

        q_size = Q.size();
        q_front = new cdlist_node<Item>();
        q_rear = new cdlist_node<Item>();
        q_front->set_next(q_rear);
        q_rear->set_prev(q_front);
        list_copy(Q.q_front, Q.q_rear, q_front);
        return *this;
  }


  /*
   * Returns a reference to the element at the front of the queue.
   */
  template <typename Item>
  Item& queue<Item>::front() const{
    
    return q_front->get_next()->get_data();
  }

  /*
   * Inserts a new element into the queue by adding the new element
   * in before the queue rear pointer, and increase the queue size 
   * by one.
   * Parameter: obj - the new value to be added.
   */
  template <typename Item>
  void queue<Item>::enqueue(const Item& obj){
  //Insert element after rear and make that element rear
    list_insert(q_rear, obj);
    q_size++;
      
  }
  
  /*
   * Removes the element at the front of the queue, and decrease
   * the queue size by one.
   */
  template <typename Item>
  void queue<Item>::dequeue(){
  //Make second element front and delete firts element
     list_remove(q_front->get_next());
     q_size--;

  }

  /*
   * Determines if the queue is empty. An empty queue has size zero
   * and the next pointer of the q_front is equal to q_rear.
   */
  template <typename Item>
  bool queue<Item>::is_empty() const{
   
     if (q_front->get_next() == q_rear) {
            return true;
        }
    return false;
  }
  

  /*
   * Makes the queue an empty queue by remove all elements.
   */
  template <typename Item>
  void queue<Item>::make_empty(){
  //Dequeue while is not empty  
     list_clear(q_front, q_rear);
      q_size = 0;
  }
  
  /*
   * Returns the size of the queue.
   */
  template <typename Item>
 typename  queue<Item>::size_type queue<Item>::size() const{
    // DO NOT MODIFY THIS FUNCTION
    return q_size;
  }

}
