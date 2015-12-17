/*
 * This file name: NameList.cpp
 * This file contains the implementation of the methods 
 * for the class implementing a list of names. This class uses
 * the sorted doubly linked list class container to store the 
 * names.
 */

#include "List.h"
#include "NameList.h"

namespace UT_315 {
  /*
   * Default constructor used to create a new name list with no names
   * in it.
   */
  NameList::NameList(){
    names = List<Name>();
  }
  
  /*
   * Copy constructor used to create a deep copy of a given source
   * name list.
   * Parameter: L - the source name list
   */
  NameList::NameList(const NameList& L){
    names = L.names;
  }

  /*
   * Copy assignment operator used to create a deep copy of a given
   * source name list.
   * Parameter: L - the source name list
   * Return: constant reference to this name list.
   */
  const NameList& NameList::operator=(const NameList& L){
    if (this != &L){
      names = L.names;
    }
    return *this;
  }
  
  /*
   * Adds new name into the list of names at its proper location based
   * on increasing lexicographical order.
   * Parameter: name - the name to be added.
   */
  void NameList::add(const Name& name){
    names.insert(name);
  }
  
  /*
   * Determines if a name is currently being stored in the name list.
   * Parameter: name - the name to be added.
   * Return: true if the name is in the list, or false otherwise.
   */
  bool NameList::find(const Name& name) const{
    List_Iterator<Name> iter = names.find(name);
    return iter.has_data();
  }
  
  /*
   * Removes a name from the list of names, if the name is present.
   * Parameter: name - the name to be deleted.
   * Return: true if the element was found and deleted, or false 
   * otherwise (i.e. it was not in the list).
   */
  bool NameList::erase(const Name& name){
    return names.erase(name);
  }
  
  /*
   * Returns the number of elements in the name list.
   * Return: the number of elements in the list.
   */
  int NameList::size() const {
    return names.size();
  }
  
  /*
   * Determines if the list of names is empty.
   * Return: true if the list of names is empty, or false otherwise.
   */
  bool NameList::is_empty() const {
    return names.is_empty();
  }
  
  /*
   * Prints all the names to an output stream. Each name is printed
   * in a new line, with the a tab charected printed before it.
   * Parameter: out - output stream
   * Parameter: L - name list
   * Return: reference to the output stream.
   */
  ostream& operator<<(ostream& out, const NameList& L){
    L.names.print_forward(out);
    return out;
  }
  
  /*
   * Reads a list of names from an input stream. The names are assumed
   * to be given in the following format:
   * <number of names> <name 1> <name 2> ... <name n>
   * For example, the following will be a valid input sequence:
   * 3 Pedro Rossello Calos Romero Sila Calderon
   *
   * Parameter: in - input stream
   * Parameter: L - name list
   * Return: reference to the input stream
   */
  istream& operator>>(istream& in, NameList& L){
    int len =0, i =0;
    Name next;
    
    // clear the name list
    L.names.make_empty();
    // read the number of names
    in >> len;
    for (i=0; i < len; ++i){
      // read next name
      in >> next;
      // add it into the name list
      L.add(next);
    }
    return in;
  }
}
