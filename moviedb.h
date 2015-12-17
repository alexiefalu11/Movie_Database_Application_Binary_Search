/*
 * This file name: moviedb.h
 * This file contains the declaration of the interface for 
 * the main program used to implement the movie database application.
 */
#ifndef _MOVIEDB_H
#define _MOVIEDB_H

using namespace std;
using namespace UT_315;

// Possible option
#define MOVIE_EXIT 0
#define MOVIE_ADD 1
#define MOVIE_DEL 2
#define ADD_CAST 3
#define DEL_CAST 4
#define FIND_MOVIE 5
#define FIND_MOVIE_ACTOR 6
#define FIND_MOVIE_RATING 7
#define FIND_MOVIE_YEAR  8
#define FIND_MOVIE_PERIOD 9
#define PRINT_MOVIE_FOR 10


void print_menu();
int get_option();
void add_movie(DataManager& data_manager);
void delete_movie(DataManager& data_manager);
void add_cast(DataManager& data_manager);
void delete_cast(DataManager& data_manager);
void find_movie(DataManager& data_manager);
void find_movies_of(DataManager& data_manager);
void find_movies_rating(DataManager& data_manager);
void find_movies_year(DataManager& data_manager);
void find_movies_period(DataManager& data_manager);
void print_movies_order(DataManager& data_manager);

#endif
