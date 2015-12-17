/*
 * This file name: Movie.h 
 * This file contains the declaration of the interface
 * for the movie data type, which is implemented in 
 * class Movie.
 */

#ifndef _MOVIE_H
#define _MOVIE_H

#include <iostream>
#include <string>
#include "NameList.h"

namespace UT_315 {
// Declaration of Movie rating indices
#define NR 0
#define G 1
#define PG 2
#define PG13 3
#define R 4
#define NC17 5

// Declaration of Movie ratings
#define NR_R "NR"
#define G_R  "G"
#define PG_R "PG"
#define PG13_R "PG-13"
#define R_R "R"
#define NC17_R "NC-17"

  // array with the valid movie ratings
  static string movie_ratings[] = {NR_R, G_R, PG_R, PG13_R, R_R, NC17_R};
  
  // Dirty macro used to determine if a rating is a valid movie rating
  // The \ is used to indicate that the macro definition continues on 
  // the next line (by default macros are one-liners).
#define valid_rating(rate) ((rate == movie_ratings[NR]) || \
			    (rate == movie_ratings[G]) || \
			    (rate == movie_ratings[PG]) || \
			    (rate == movie_ratings[PG13]) || \
			    (rate == movie_ratings[R])  || \
			    (rate == movie_ratings[NC17]))


  /*
   * Movie is a class used to implement the movie data type.
   *
   * NOTE: This class does not implement a destructor because
   * the default destructor correctly calls the destructor of 
   * each data member, and this will take care of deleting the
   * elements in the NameList field.
   */
  class Movie {
  public:
    // Default constructor
    Movie(const string& title_in = "NONE", int year_in = 0, 
	  int duration_in = 0, const string& rating_in = "NR",
	  const NameList& castlist_in = NameList());
    
    // Returns the key for this movie
    string get_key() const;
    // Returns the title for this movie
    string get_title() const;
    // Returns the year for this movie
    int get_year() const;
    // Returns the duration (in minutes) for this movie
    int get_duration() const;
    // Returns the rating for this movie
    string get_rating() const;
    // Returns the Namelist with the cast for this movie
    const NameList& get_cast_list() const;
    // Determines if a name is in the cast member list
    bool is_cast_member(const Name& name) const;
    
    // Sets the title for this movie
    void set_title(const string& new_title);
    // Sets the year for this movie
    void set_year(int new_year);
    // Sets the duration for this movie
    void set_duration(int new_duration);
    // Sets the rating for this movie
    void set_rating(const string& new_rating);
    // Sets the cast name list for this movie
    void set_cast_list(const NameList& L);
    
    // Adds a new name to the cast list, if not already there
    bool add_cast_member(const Name& name);
    // Removes a name from the cast list
    bool erase_cast_member(const Name& name);
    
    // Determines if another movie has a key equal to this movie's key 
    bool operator==(const Movie& src) const;
    // Determines if another movie has a key not equal to this movie's key 
    bool operator!=(const Movie& src) const;
    // Determines if another movie has a key less than this movie's key 
    bool operator<(const Movie& src) const;
    // Determines if another movie has a key greater than this movie's key 
    bool operator>(const Movie& src) const; 
    // Determines if another movie has a key less than or equal to 
    // this movie's key 
    bool operator<=(const Movie& src) const;
    // Determines if another movie has a key greater than or equal to 
    // this movie's key 
    bool operator>=(const Movie& src) const; 
    
    // Reads this movie info from an input stream
    friend istream& operator>>(istream& in, Movie& obj);
    // Writes this movie info to an output stream
    friend ostream& operator<<(ostream& out, const Movie& obj); 
    
  private:
    // Movie title
    string title;
    // Movie release year
    int year;
    // Movie duration (in minutes)
    int duration;
    // Movie rating(G, PG, PG-13, R, NC-17, NR)
    string rating;
    // List with the names of the cast members
    NameList castlist;
  };
}
#endif
