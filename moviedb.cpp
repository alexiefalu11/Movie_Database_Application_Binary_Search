/*
 * This file name: moviedb.cpp
 * This file contains the implementation of the main program 
 * used to implement the movie database application.
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include "List.h"
#include "Name.h"
#include "DataManager.h"
#include "moviedb.h"

using namespace std;
using namespace UT_315;

int main(){
  int opt=0;
  DataManager data_manager;
  
  cout << "Welcome to the movie information database program." << endl;
  do {
    print_menu();
    opt = get_option();
    switch(opt){
    case MOVIE_ADD:
      add_movie(data_manager);
      break;
    case MOVIE_DEL:
      delete_movie(data_manager);
      break;
    case ADD_CAST:
      add_cast(data_manager);
      break;
    case DEL_CAST:
      delete_cast(data_manager);
      break;
    case FIND_MOVIE:
      find_movie(data_manager);
      break;
    case FIND_MOVIE_ACTOR:
      find_movies_of(data_manager);
      break;
    case FIND_MOVIE_RATING:
      find_movies_rating(data_manager);
      break;
    case FIND_MOVIE_YEAR:
      find_movies_year(data_manager);
      break;
    case FIND_MOVIE_PERIOD:
      find_movies_period(data_manager);
      break;
    case PRINT_MOVIE_FOR:
      print_movies_order(data_manager);
      break;
    case MOVIE_EXIT:
      break;
    default:
      cout << "Unknown option: " << opt << endl; 
    }
  }
  while(opt != MOVIE_EXIT);
  cout << "Thanks for using movie information database program!" << endl;
  exit(0);
}

void print_menu(){
  cout << "********************************" << endl;
  cout << "Available Operations:"<< endl;
  cout << "\t 1.  Add movie" << endl;
  cout << "\t 2.  Delete movie" << endl;
  cout << "\t 3.  Add cast name to movie" << endl;
  cout << "\t 4.  Delete cast name from movie" << endl;
  cout << "\t 5.  Find movie" << endl;
  cout << "\t 6.  Find movies by actor name" << endl;
  cout << "\t 7.  Find movies by rating" << endl;
  cout << "\t 8.  Find movies by year" << endl;
  cout << "\t 9.  Find movies by time period" << endl;
  cout << "\t 10. Print movies in order" << endl;
  cout << "\t 11. Exit" << endl;
  cout << "********************************" << endl;  
}

int get_option(){
  int num = 0;
  cout << "Enter your option number: ";
  cin >> num;
  if (num == 11){
    return 0;
  }
  else {
    return num;
  }
}

void add_movie(DataManager& data_manager){
  Movie movie;
  
  cout << "Enter the movie information" << endl;
  cin >> movie;
  cout << "Movie informaiton to be added: " << endl;
  cout << movie;
  if (data_manager.add_movie(movie) == MOVIE_WAS_THERE){
    cout << "Movie was not added because it was already there." << endl;
  }
  else {
    cout << "Movie was successfully added." << endl;
  }
}

void delete_movie(DataManager& data_manager){
  string title;
  
  cout << "Enter the movie title" << endl;
  cin >> title;
  cout << "Searching for movie: " << title << endl;
  if (data_manager.delete_movie(title) == MOVIE_NOT_FOUND){
    cout << "Movie " << title << " was not found for deletion." << endl;
  }
  else {
    cout << "Movie " << title << " was successfully deleted." << endl;
  }
}

void add_cast(DataManager& data_manager){
  Name name;
  string title;
  int res = 0;
  
  cout << "Enter the movie title: ";
  cin >> title;
  cout << "Enter the cast name: ";
  cin >> name;
  cout << "Adding cast name " << name << " to movie " << title << endl;
  res = data_manager.add_new_cast(title, name);
  
  if (res == MOVIE_NOT_FOUND){
    cout << "Movie  " << title << " was not found." << endl;
  }
  else if (res == NAME_WAS_THERE){
    cout << "Name " << name << " was already in the cast list for " 
	 << "movie " << title << "."  << endl;
  }
  else {
    cout << "Name " << name << " was successfully added to the cast list " <<
      "for movie " << title << "." << endl;
  }
}


void delete_cast(DataManager& data_manager){
  Name name;
  string title;
  int res = 0;
  
  cout << "Enter the movie title: ";
  cin >> title;
  cout << "Enter the cast name: ";
  cin >> name;
  cout << "Deleting cast name " << name << " from movie " << title << endl;

  res = data_manager.delete_cast(title, name);
  
  if (res == MOVIE_NOT_FOUND){
    cout << "Movie  " << title << " was not found." << endl;
  }
  else if (res == NAME_NOT_FOUND){
    cout << "Name " << name << " was not found in the cast list for " 
	 << "movie " << title << "."  << endl;
  }
  else {
    cout << "Name " << name << 
      " was successfully deleted from the cast list " <<
      "for movie " << title << "." << endl;
  }
}

void find_movie(DataManager& data_manager){
  Movie movie;
  string title;
  
  cout << "Enter the movie title: ";
  cin >> title;
  cout << "Finding movie: " << title << endl; 
  if (data_manager.find_movie(title, movie) == MOVIE_NOT_FOUND){
    cout << "Movie " << title << " was not found." << endl;
  }
  else {
    cout << movie << endl;
  }
}

void find_movies_of(DataManager& data_manager){
  Name name;
  List<Movie> L;
  
  cout << "Enter the actor name: ";
  cin >> name;
  cout << "Finding movies by actor: " << name << endl;
  L = data_manager.find_movies_of(name);
  if (L.is_empty()){
    cout << "No movies found by actor: " << name << endl;
  }
  else {
    cout << "List of movies by actor: " << name << endl;
    L.print_forward(cout);
  }
}

void find_movies_rating(DataManager& data_manager){
  string rating;
  List<Movie> L;
  
  cout << "Enter the movie rating: ";
  cin >> rating;
  cout << "Finding movies rated: " << rating << endl;
  L = data_manager.find_movies_rated(rating);
  if (L.is_empty()){
    cout << "No movies found for rating: " << rating << endl;
  }
  else {
    cout << "List of movies for rating: " << rating << endl;
    L.print_forward(cout);
  }
}

void find_movies_year(DataManager& data_manager){
  int year = 0;
  List<Movie> L;
  
  cout << "Enter the movie year: ";
  cin >> year;
  cout << "Finding movies made in the year: " << year << endl;
  L = data_manager.find_movies_released(year);
  if (L.is_empty()){
    cout << "No movies found for year: " << year << endl;
  }
  else {
    cout << "List of movies for year: " << year << endl;
    L.print_forward(cout);
  }
}

void find_movies_period(DataManager& data_manager){
  int year1 = 0, year2 = 0;
  List<Movie> L;
  
  cout << "Enter the first year: ";
  cin >> year1;
  cout << "Enter the second year: ";
  cin >> year2;
  cout << "Finding movies maded between the years " << year1 <<
    " and " << year2 << endl;

  L = data_manager.find_movies_between(year1, year2);
  if (L.is_empty()){
    cout << "No movies found between the years " << year1 << 
      "and " << year2 << "." << endl;
  }
  else {
    cout << "List of movies released between years " << year1 <<
      " and " << year2 << "." << endl;
    L.print_forward(cout);
  }
}

void print_movies_order(DataManager& data_manager){
  cout << "List of movies (in order): " << endl;
  data_manager.print_movies_forward(cout);
}
