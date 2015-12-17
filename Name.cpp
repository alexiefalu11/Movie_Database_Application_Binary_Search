/*
 * This file name: Name.cpp
 * This file contains the implementation of the methods for 
 * the name data type.
 */

#include "Name.h"
using namespace std;

namespace UT_315 {
  
  /*
   * Constructor based on the a first name and a last name.
   * Parameter: firstname_in - firts name field
   * Parameter: lastname_in - last name field
   */
  Name::Name(string firstname_in, string lastname_in)
    :lastname(lastname_in), firstname(firstname_in){
  }
  
  /*
   * Returns the first name part of this name.
   * Return: first name part of this name.
   */
  const string& Name::get_firstname() const{
    return firstname;
  }
  
  /*
   * Returns the last name part of this name.
   * Return: last name part of this name.
   */
  const string& Name::get_lastname() const{
    return lastname;
  }
  
  /*
   * Returns a string representing the full name in this name.
   * Return: full name represented by this name.
   */
  string Name::get_fullname() const{
    return firstname + " " + lastname;
  }
  
  /*
   * Returns a string representing the key in this name object
   * as the combination of lastname followed by first name.
   * Return: key represented as lastname followed by first name
   * associated with this name object
   */
  string Name::get_key() const {
    return lastname + " " + firstname;
  }
  
  
  /*
   * Determines if the argument name is lexicographically equal to 
   * this name.
   * Parameter: src - the source name
   * Return: true if the source name is equal to this name, or false
   * otherwise.
   */
  bool Name::operator == (const Name& src) const {
    return lastname == src.get_lastname() &&
      firstname == src.get_firstname();
  }
  
  /*
   * Determines if the argument is not lexicographically equal to
   * this name.
   * Parameter: src - the source name
   * Return: true if the source name is not equal to this name, or false
   * othewise.
   */
  bool Name::operator!=(const Name& src) const {
    return !(*this == src);
  }
  
  /*
   * Determines if the argument name is lexicographically less than
   * this name.
   * Parameter: src - the source name
   * Return: true if the source name is less than this name, or false 
   * otherwise.
   */
  bool Name::operator<(const Name& src) const {
    // tedious case search
  
    // Case 1: equal last names
    if (lastname == src.get_lastname()){
      
      // Determine what first names are
      if (firstname == src.get_firstname()){
	return false;
      }
      else if (firstname < src.get_firstname()){
	return true;
      }
      else {
	return false;
      }
    }
    // Case 2: less last name
    else if (lastname < src.get_lastname()){
      return true;
    }
    // Case 3: greater last name
    else {
      return false;
    }
  }
  
  /*
   * Determine if the argument is lexicographically greater than
   * this name.
   * Parameter: src - the source name
   * Return: true if the source name is less than this name, or false 
   * otherwise.
   */
  bool Name::operator>(const Name& src) const {
    // is this equal or less than the src?
    if ( (*this < src) || (*this == src) )      
      return false;
    else
      return true;
  }
  
  /*
   * Determines if the argument is lexicographically less or equal to
   * this name.
   * Parameter: src - the source name
   * Return: true if the source name is less or equal to this name, or false
   * otherwise.
   */
  bool Name::operator<=(const Name& src) const {
    return ((*this < src) || (*this == src));
  }
  
  /*
   * Determines if the argument is lexicographically greater or equal to
   * this name.
   * Parameter: src - the source name
   * Return: true if the source name is greater or equal to this name, 
   * or false otherwise.
   */
  bool Name::operator>=(const Name& src) const{
    return ((*this > src) || (*this == src));
  }
  
  /*
   * Reads the a name from an input stream, and stores its value in 
   * a name object.
   * Parameter: in - input stream
   * Parameter: obj - reference to the object where the name will 
   * be stored.
   * Return: reference to the argument input stream.
   */
  istream& operator>>(istream& in, Name& obj) {
    in >> obj.firstname >> obj.lastname;
    return in; 
  }
  
  /*
   * Writes a name to an output stream.
   * Parameter: out - output stream
   * Parameter: obj - reference to the object where the name is
   * being stored.
   * Return: reference to the argument output stream.
   */
  
  ostream& operator<<(ostream& out, const Name& obj){
    out << obj.firstname << ' ' << obj.lastname;
    return out;
  }

}
