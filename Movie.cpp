/*
 * This file name: Movie.cpp
 * This file contains the implementation of the methods
 * associated with the movie data type, which is implemented 
 * in class Movie.
 */

#include "Movie.h"
 #include <cassert>
namespace UT_315 {
  
  /*
   * Constructor for the class, it creates a new movie from a 
   * title, release year, duration, rating and cast name list.
   * Parameter: title_in - movie title
   * Parameter: year_in - release year
   * Parameter: duration_in - movie duration (minutes)
   * Parameter: rating_in - rating for the movie.
   * Parameter: castlist_in - cast name list
   */
  Movie::Movie(const string& title_in, int year_in, int duration_in,
	       const string& rating_in, const NameList& castlist_in)
    :title(title_in), year(year_in), duration(duration_in),
     rating(rating_in), castlist(castlist_in){
    
    // make sure rating is valid!
    assert(valid_rating(rating));
  }
  
  /*
   * Returns the key for this movie, which is the movie title.
   * Return: title for this movie as its key.
   */
  string Movie::get_key() const {
    return get_title();
  }
  
  /*
   * Returns the title for this movie.
   * Return: string representing title for this movie.
   */
  string Movie::get_title() const {
    return title;
  }
  
  /*
   * Returns the year of release for this movie.
   * Return: year of release for this movie.
   */
  int Movie::get_year() const {
    return year;
  }
  
  /*
   * Returns the duration (in minutes) for this movie.
   * Return: duration for this movie.
   */
  int Movie::get_duration() const {
    return duration;
  }
  
  /*
   * Returns the rating for this movie.
   * Return: string representing the rating  for this movie.
   */
  string Movie::get_rating() const {
    return rating;
  }
  
  /*
   * Returns the name list containing the cast of this movie.
   * Return: name list for the cast of this movie.
   */
  const NameList& Movie::get_cast_list() const {
    return castlist;
  }
  
  /*
   * Determines if an actor name is in the cast list of this movie.
   * Parameter: name - cast member to be searched for.
   * Return: true if the name is in the cast list, or false otherwise.
   */
  bool Movie::is_cast_member(const Name& name) const {
    return castlist.find(name);
  }
  
  /*
   * Sets a new title for this movie.
   * Parameter: new_title - new movie title.
   */
  void Movie::set_title(const string& new_title){
    title = new_title;
  }
  
  /*
   * Sets a new year of release for this movie.
   * Parameter: new_year - new year of release.
   */
  void Movie::set_year(int new_year){
    year = new_year;
  }
  
  /*
   * Sets a new duration for this movie. The function
   * assumes that the duration is at least 1 minute.
   * Parameter: new_duration - new duration for the movie.
   */
  void Movie::set_duration(int new_duration){
    duration = new_duration;
  }
  
  /*
   * Sets a new rating for this movie. The function asserts
   * that the rating is valid.
   * Parameter: new_rating - new rating for this movie. 
   */
  void Movie::set_rating(const string& new_rating) {
    assert(valid_rating(new_rating));
    rating = new_rating;
  }
  
  /*
   * Sets the cast name list for this movie.
   * Parameter: new_castlist - new cast list for this movie.
   */
  void Movie::set_cast_list(const NameList& new_castlist){
    castlist = new_castlist;
  }
  
  /*
   * Adds a new member to the cast members of this movie.
   * Paramater: name  - new name to be added to cast list.
   * Return: true if the name is added, or false if the name is
   * already there.
   */
  bool Movie::add_cast_member(const Name& name) {
    if (!castlist.find(name)){
      castlist.add(name);
      return true; // name added
    }
    else {
      return false; // name already there
    }
  }
  
  /*
   * Removes a cast name from the cast list, if the name is there.
   * Parameter: name - name to be deleted.
   * Return: true if the name is found and deleted, or false if
   * the name is not found.
   */
  bool Movie::erase_cast_member(const Name& name){
    return castlist.erase(name);
  }
  
  /*
   * Determines if the key for another movie is equal to this movie's key.
   * Parameter: src - the movie to be compared.
   * Return: true if the key of the source movie is equal to this movie's
   * key, or false otherwise.
   */
  bool Movie::operator==(const Movie& src) const{
    return (this->get_key() == src.get_key());
  }
  
  /*
   * Determines if the key for another movie is not equal to this movie's key.
   * Parameter: src - the movie to be compared.
   * Return: true if the key of the source movie is not equal to this movie's
   * key, or false otherwise.
   */
  bool Movie::operator!=(const Movie& src) const{
    return (this->get_key() != src.get_key());
  }
  
  /*
   * Determines if the key for another movie is less than this movie's key.
   * Parameter: src - the movie to be compared.
   * Return: true if the key of the source movie is less than this movie's
   * key, or false otherwise.
   */
  bool Movie::operator<(const Movie& src) const{
    return (this->get_key() < src.get_key());
  }
  
  /*
   * Determines if the key for another movie is less than or equal to 
   * this movie's key.
   * Parameter: src - the movie to be compared.
   * Return: true if the key of the source movie is less than or equal to
   * this movie's key, or false otherwise.
   */
  bool Movie::operator<=(const Movie& src) const{
    return (this->get_key() <= src.get_key());
  }
  
  /*
   * Determines if the key for another movie is greater than this movie's key.
   * Parameter: src - the movie to be compared.
   * Return: true if the key of the source movie is greater than this movie's
   * key, or false otherwise.
   */
  bool Movie::operator>(const Movie& src) const{
    return (this->get_key() > src.get_key());
  }

  /*
   * Determines if the key for another movie is greater than or equal to 
   * this movie's key.
   * Parameter: src - the movie to be compared.
   * Return: true if the key of the source movie is greater than or equal to
   * this movie's key, or false otherwise.
   */
  bool Movie::operator>=(const Movie& src) const{
    return (this->get_key() >= src.get_key());
  }
  
  /*
   * Reads the movie info from the input stream.
   * Parameter: in - input stream
   * Parameter: movie - to movie in which to store the info being read.
   * Return: the reference to the input stream.
   */
  istream& operator>>(istream& in, Movie& movie){
    string title, rating;
    int year = 0, duration = 0;
    NameList castlist;
    
    // Read the stuff
    cout << "Enter the movie title: ";
    in >> title;
    cout << "Enter the movie year: ";
    in >> year;
    cout << "Enter the movie duration: ";
    in >> duration;
    cout << "Enter the movie rating: ";
    in >> rating;
    cout << "Enter the cast name list: ";
    in >> castlist;
    
    // Update the movie info
    movie.set_title(title);
    movie.set_year(year);
    movie.set_duration(duration);
    movie.set_rating(rating);
    movie.set_cast_list(castlist);
    
    return in;
  }
  
  /*
   * Writes the information about a movie to an output stream.
   * Parameter: out - output stream.
   * Parameter: movie - movie whose information is to be printed.
   * Return: reference to the output stream.
   */
  ostream& operator<<(ostream& out, const Movie& movie){
    out << "***** Movie Info *****" << endl;
    out << "Movie title: " << movie.get_title() << endl;
    out << "Movie year: " << movie.get_year() << endl;
    out << "Movie duration: " << movie.get_duration() << endl;
    out << "Movie rating: " << movie.get_rating() << endl;
    out << "Movie cast: " << endl;
    out << movie.get_cast_list();  
    out << "**********************" << endl;
    return out;
  }
}
