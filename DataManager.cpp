/*
 * This file name: DataManager.cpp
 * This file contains the implementation of the methods for the
 * data manager class, used to manipulate the data in the 
 * movie database application.
 */
 /*  Alexie R. Ortiz Falu
  #S00709543
  Prof: Yahya Masalma */

#include "DataManager.h"

namespace UT_315 {
  ////////////////////////// DO NOT MODIFY THIS FUNCTION !!! /////////////////
  void DataManager::print_tree_height() const {
    cout << "BST Height: " << movie_bst.height() << endl;
  }
  ///////////////////////////////////////////////////////////////////////////

  /***************** START ADDING YOUR CODE HERE **************************/

  /*
   * Constructor for the DataManager class. This constructor creates
   * an empty binary search tree (BST) to hold up the information 
   * about the movies.
   */
  DataManager::DataManager(){
    // DO NOT MODIFY THIS FOLLOWING LINE
    movie_bst = BinarySearchTree<Movie,string>();
  }
  
  /*
   * Adds a new movie to the movie database, but only if the 
   * movie is not already there.  The function must return
   * a code indicating if the movie was added or not.
   * Parameter: movie - new movie to be added
   * Return: 
   *     OK - if the movie was added
   *     MOVIE_WAS_THERE - if the movie was already in the movie list
   */
  int DataManager::add_movie(const Movie& movie){
    // DO NOT MODIFY THIS FOLLOWING LINE
    print_tree_height();
    
    if(movie_bst.find(movie.get_key()).has_data())
    {
      return MOVIE_WAS_THERE;
    }
    
    movie_bst.insert(movie);
       return OK;
    
  }

  /*
   * Adds a new cast name to the cast list for a given movie.
   * This function must first find the record with the movie
   * information, and then add the new cast name to the cast list.
   * Parameter: title - movie title to be searched
   * Parameter: name - new cast name.
   * Return:
   *     OK - if the new cast name is added.
   *     MOVIE_NOT_FOUND - if no movie with the argument title is found.
   *     NAME_WAS_THERE - cast name was already in the cast list for the movie.
   */
  int DataManager::add_new_cast(const string& title, const Name& name){
    // DO NOT MODIFY THIS FOLLOWING LINE
    print_tree_height();
    
     BST_preorder_iterator<Movie, string> iter = movie_bst.find(title);
    if (iter.has_data()) 
    {
      if (!(iter.get_data().is_cast_member(name))) 
      {
          iter.get_data().add_cast_member(name);
      }
      else 
      {
          return NAME_WAS_THERE;
      }
    }
    else 
    {
      return MOVIE_NOT_FOUND;
    }
  return OK;
    
  }
  
  /*
   * Deletes a movie from the movie database. The function searches
   * for a movie with a given title, and if found, deletes that movie.
   * Paramater: title - movie title for the movie to be deleted.
   * Return:
   *     OK - if the movie is deleted.
   *     MOVIE_NOT_FOUND - if the movie was not found in the list.
   */
  int DataManager::delete_movie(const string& title){
    // DO NOT MODIFY THIS FOLLOWING LINE
    print_tree_height();
    
   if (movie_bst.find(title).has_data()) 
   {
      movie_bst.erase(title);
    }
    else 
    {
      return MOVIE_NOT_FOUND;
    }
  return OK;
  }
  
  /*
   * Deletes a cast name from the cast list of a movie. The function
   * must first find the movie, and then delete the name from the 
   * cast list.
   * Parameter: title - movie title for the target movie.
   * Parameter: name - cast name to be deleted
   * Return:
   *     OK - if the cast name is deleted.
   *     MOVIE_NOT_FOUND - no movie with the argument title was found.
   *     NAME_NOT_FOUND - the cast name was not found in the list.
   */
  int DataManager::delete_cast(const string& title, const Name& name){
    // DO NOT MODIFY THIS LINE
    print_tree_height();
    
    BST_preorder_iterator<Movie, string> iter = movie_bst.find(title);
        if (iter.has_data())
        {
          if (iter.get_data().is_cast_member(name))
          {
              iter.get_data().erase_cast_member(name);
          }
          else 
          {
             return NAME_NOT_FOUND;
          }
        }
        else 
        {
          return MOVIE_NOT_FOUND;
        }
    return OK;
  }
  
  
  /*
   * Finds the information about a movie from the movie database. 
   * The functions receives two parameters: the title for the movie
   * and a buffer to store the movie information. The function 
   * must return the code MOVIE_NOT_FOUND if no movie with the 
   * given title is found.
   * Parameter: title - the title for the movie to be found.
   * Parameter: movie - buffer to store the movie information.
   */
 
  int DataManager::find_movie(const string& title, Movie& movie) const{
    // DO NOT MODIFY THIS FOLLOWING LINE
    print_tree_height();
    
     BST_preorder_iterator<Movie, string> iter = movie_bst.find(title);
        if (iter.has_data())
        {
          movie = iter.get_data();
        }
        else 
        {
          return MOVIE_NOT_FOUND;
        }
    return OK;
  }
  
  /*
   * This function is used to find all the names in which a given
   * appears. The function returns a list with all the movies
   * found, or an empty list if the actor does not appears in 
   * the cast for any movie.
   * Parameter: name - the name of the actor.
   * 
   */
  List<Movie> DataManager::find_movies_of(const Name& name) const{
    // DO NOT MODIFY THIS FOLLOWING LINE
    print_tree_height();
    
    
    List<Movie> result;
     BST_inorder_iterator<Movie, string> iter = movie_bst.get_in_order();
        while (iter.has_data()) 
        {
          if (iter.get_data().is_cast_member(name))
          {
              result.insert(iter.get_data());
          }
          iter.next();
        }
    return result;
  }
  

  /*
   * This function is used to find all the movies with a given
   * rating. It returns a list with all the movies found, or
   * an empty list if no movie has the given rating.
   * Paramter: rating - the movie rating being searched for.
   */
  List<Movie> DataManager::find_movies_rated(const string& rating) const{
    // DO NOT MODIFY THIS FOLLOWING LINE
    print_tree_height();
    
    
   List<Movie> result;
   BST_inorder_iterator<Movie, string> iter = movie_bst.get_in_order();
        while (iter.has_data()) 
        {
          if (iter.get_data().get_rating() == rating) 
          {
            result.insert(iter.get_data());
          }
          iter.next();
        }
    return result;
  }
  
  
  /*
   * This function is used to find all the movies relase on a given
   * year. It returns a list with all the movies found, or
   * an empty list if  no movie was relased on the  given year.
   * Paremeter: year - the year of release being searched for.
   */
  List<Movie> DataManager::find_movies_released(int year) const{
    // DO NOT MODIFY THIS FOLLOWING LINE
    print_tree_height();
    
    
    List<Movie> result;
    BST_inorder_iterator<Movie, string> iter = movie_bst.get_in_order();
        while (iter.has_data())
        {
          if (iter.get_data().get_year() == year)
          {
              result.insert(iter.get_data());
          }
          iter.next();
        }
    return result;
  }
  

  /*
   * This function is used to find all the movies relased between two 
   * years: year1 and year2. All movies for which its release year Y, 
   * satisfies: year1 <= Y <= year2, will go in the result. 
   * The function returns a list with all the movies found, or
   * an empty list if  no movie was relased during the  given time period.
   * Parameter: year1 - first year in the time period.
   * Parameter: year2 - second year in the time period.
   */
  List<Movie> DataManager::find_movies_between(int year1, int year2) const{
    // DO NOT MODIFY THIS FOLLOWING LINE
    print_tree_height();
    
    
    List<Movie> result;
    BST_inorder_iterator<Movie, string> iter = movie_bst.get_in_order();
        while (iter.has_data())
        {
          if (year1 <= iter.get_data().get_year() && iter.get_data().get_year() <= year2)
          {
              result.insert(iter.get_data());
          }
          iter.next();
        }
    return result;
  }

  /*
   * Prints all movies based on alphabetical order of the movie title
   * (i.e. following an in-order traversal.).
   * Parameter: out - the output stream to print the movie information.
   */
  
  void DataManager::print_movies_forward(ostream& out) const{
    // DO NOT MODIFY THIS FOLLOWING LINE
    print_tree_height();
    
     BST_inorder_iterator<Movie, string> iter = movie_bst.get_in_order();
        while (iter.has_data())
        {
          cout << iter.get_data();
          iter.next();
        }
  }
}
