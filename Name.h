/*
 * This file name: Name.h
 * This file contains the declaration of the name data type.
 */

#ifndef _NAME_H
#define _NAME_H

#include <iostream>
#include <string>

using namespace std;
namespace UT_315 {
  class Name{
    
  public:
    // Default constructor
    Name(string firstname_in = "NONE", 
	 string lastname_in = "NONE");
    
    // Compare names for equality
    bool operator==(const Name& src) const;
    // Compate names for non-equality
    bool operator!=(const Name& src) const;
    // Lexicographically less than this name
    bool operator<(const Name& src) const;
    // Lexicographically greater than this name
    bool operator>(const Name& src) const; 
    // Lexicographically less or equal than this name
    bool operator<=(const Name& src) const;
    // Lexicographically greater or equal than this name
    bool operator>=(const Name& src) const; 
    
    // Return key for this name
    string get_key() const;
    
    // Returns the full name as string
    string get_fullname() const;
    
    // Returns the last name field
    const string& get_lastname() const;
    
    // Returns the firts name field
    const string& get_firstname()const;
    
    // Read the value for this name
    friend istream& operator>>(istream& input, Name &target);
    // Write the value this this name
    friend ostream& operator<<(ostream& output, const Name &src);
    
  private:
    // Last name 
    string lastname;  
    // First name 
    string firstname;
  };
}
#endif


