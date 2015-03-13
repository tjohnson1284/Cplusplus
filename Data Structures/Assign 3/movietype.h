#ifndef __PERSON_H__
#define __PERSON_H__

#include <iostream>
#include <fstream>
using namespace std;	

class MovieType	
{
	friend ostream& operator<<(ostream& os, const MovieType& m);
	//  
	// Precondition: valid movietype passed, optional stream 
	// Postcondition: Either
	//	1.	Prints movie to given stream 
	friend bool operator==(const MovieType &m1, const MovieType &m2);
	//  
	// Precondition: valid movietypes passed to the function.
	// Postcondition: Either
	//	1.	Returns true if the movie titles are the same. 
	//	2.	Returns false if the movie titles are different. 
	friend bool operator!=(const MovieType &m1, const MovieType &m2);
	//  
	// Precondition: valid movietypes passed to the function.
	// Postcondition: Either
	//	1.	Returns true if the movie titles are not the same. 
	//	2.	Returns false if the movie titles are same.
	friend bool operator<(const MovieType &m1, const MovieType &m2);
	//  
	// Precondition: valid movietypes passed to the function.
	// Postcondition: Either
	//	1.	Returns true if the first movie title comes after the second. 
	//	2.	Returns false if the first movie title comes before the second.
	friend bool operator>(const MovieType &m1, const MovieType &m2);
	//  
	// Precondition: valid movietypes passed to the function.
	// Postcondition: Either
	//	1.	Returns true if the first movie title comes before the second. 
	//	2.	Returns false if the first movie title comes after the second.
	friend bool operator<=(const MovieType &m1, const MovieType &m2);
	//  
	// Precondition: valid movietypes passed to the function.
	// Postcondition: Either
	//	1.	Returns true if the first movie title comes after the second or they are the same. 
	//	2.	Returns false if the first movie title comes before the second..
	friend bool operator>=(const MovieType &m1, const MovieType &m2);
	//  
	// Precondition: valid movietypes passed to the function.
	// Postcondition: Either
	//	1.	Returns true if the first movie title comes before the second or they are the same. 
	//	2.	Returns false if the first movie title comes after the second.
private:
	string m_title, m_receipts, m_studio, m_stars[3];
	int m_year;
	
public:
	void Movietype(string title = "N/A", int year = 9999, string receipts = "N/A", string studio = "N/A", string star1 = "", string star2 = "", string star3 = "");
	//Set function to fill in fields for the user
	//Preconditions: none
	//Postconditions: Chosen fields filled in.
	MovieType();
	//default initializer for the class
	//Preconditions: none
	//Postconditions: all fields are initialized
	void StringSort(string &s1);
	// Takes a string of the movie studio and stars and separates it into two separate strings.
	//Preconditions: valid string given
	//Postcondition:strings separated then stored in their respective data field
	void Display(ostream& os = cout) const;
	// Prints a movie's data to the given stream
	// Precondition: A valid movie entered
	// Postcondition: Movie is displayed to the monitor
	int compareKeys(const MovieType& m2) const;
	// Compares movie titles
	// Precondition: Two valid movies
	// Postcondition: Returns 0, if the titles are the same. Returns 1, if movie one's title comes first. Returns -1, if movie two's title comes first
	bool ReadOneMovieFromFile(ifstream& fin);
	// Reads one movie from a file
	// Precondition: file opened and passed to the function
	// Postcondition: movie stored in variable.
	string getKey() const;
	string getstar(int index) const;
	//Returns stars
	// Precondition: Valid file, index valid
	// Postcondition: Returns star stored at that index.
} ;

#endif