/*
 * This file name: NameList.h
 * This file contains the declaration of the interface
 * for a list of names, which uses the sorted doubly 
 * linked list class container to store the names.
 */

#ifndef _NAME_LIST_H
#define _NAME_LIST_H

#include <iostream>
#include "Name.h"
#include "List.h"

namespace UT_315 {
  /*
   * Class NameList is used to implemet a sorted list of names.
   * It uses the sorted doubly linked list class container to 
   * store the names.
   *
   * NOTE: For this class no destructor is implemented because
   * the default constructor correctly calls the destructor 
   * for the linked list, and this will take care of deleting
   * the elements in the list.
   */
  class NameList {
  public:
    // Default constructor
    NameList();
    // Copy constructor
    NameList(const NameList& L);
    // Copy assignment operator
    const NameList& operator=(const NameList& L);
    
    // Adds a new name to the list
    void add(const Name& name);
    // Determines if a name is in the list
    bool find(const Name& name) const;
    // Erases a nane from the list
    bool erase(const Name& name);
    // Returns the size of the name list
    int size() const;
    // Determines if the list is empty
    bool is_empty() const;
    
    // Prints all the names to an output stream
    friend ostream& operator<<(ostream& out, const NameList& L);
    
    // Reads a group of names from the input stream
    friend istream& operator>>(istream& in, NameList& L);
    
  private:
    // Linked list of names
    List<Name> names;
  };
}
#endif
  
