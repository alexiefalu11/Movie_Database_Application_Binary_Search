/*
 * This file name: DataManager.h
 * This file contains the declaration of the interface for the
 * data manager class, used to manipulate the data in the 
 * movie database application.
 */

#ifndef _DATA_MANAGER_H
#define _DATA_MANAGER_H

#include <iostream>
#include <string>
#include "List.h"
#include "BinarySearchTree.h"
#include "Name.h"
#include "NameList.h"
#include "Movie.h"

namespace UT_315 {
  // Return codes for several of the class methods
  // Operation was OK
#define OK 0
  // Name was not found
#define NAME_NOT_FOUND -2
  // Name was already there
#define NAME_WAS_THERE -3
  // Movie was not found
#define MOVIE_NOT_FOUND -4
  // Movie was already there
#define MOVIE_WAS_THERE -5
  
  /*
   * This class is used to implement the operation necessary
   * to manipulate the movie list.
   *
   * NOTE: This class does not implement a destructor because
   * the default destructor correctly calls the destructor of 
   * each data member, and this will take care of deleting the
   * elements in the movie list field.
   */
  class DataManager {
  public:
    // Default Constructor
    DataManager();
    // Adds a new movie to the movie list
    int add_movie(const Movie& movie);
    // Adds a new member to the cast list of a given movie
    int add_new_cast(const string& title, const Name& name);
    // Deletes a movie from the movie list
    int delete_movie(const string& title);
    // Deletes a cast name from a movie
    int delete_cast(const string& title, const Name& name);
    // Finds movie information about a given movie
    int find_movie(const string& title, Movie& movie) const;
    // Finds movie information about movies made by a particular actor
    List<Movie> find_movies_of(const Name& name) const;
    // Finds movie information about movies with a given rating
    List<Movie> find_movies_rated(const string& rating) const;
    // Finds movie information about movies made a given year
    List<Movie> find_movies_released(int year) const;
    // Finds movie information about movies made in a given time period
    List<Movie> find_movies_between(int year1, int year2) const;
    // Print list of movies in order
    void print_movies_forward(ostream& out) const;
  
  private:
    BinarySearchTree<Movie,string> movie_bst;
    
    // prints the height of the tree (DO NOT MODIFY THIS FUNCTION)
    void print_tree_height() const;
  };
}
#endif
