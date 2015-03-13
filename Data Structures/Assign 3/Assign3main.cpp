#include <iostream>
#include <string>
#include <iomanip>
#include "movietype.h"
#include "SortedMovieList.h"
using namespace std;
int main () {
 
	sList<ListItemType> movies;
	MovieType search, add;
	string option, name, studio, stars, boxoffice;
	int year;
	char selection = 'Y';
	
	cout << "Welcome to the Aperture Science's Movie Storage-9000." << endl << endl;
	if(!movies.ReadAllMoviesFromFile())
	{
		return 0;
	}
	else 
	{
		

		while (selection != 'Q' && selection != 'q')
		{
			cout << endl << "Your options are as follows." << endl << endl;
			cout << "Press V to view every movie in the list." << endl;
			cout << "Press S to search for a particular movie in the list." << endl;
			cout << "Press D to delete a movie from the list." << endl;
			cout << "Press A to add a movie to the list." << endl; 
			cout << "Press C to count of the number of movies in the list." << endl;
			cout << "Press F to search movies by the star. " << endl;
			cout << "Press Q to quit." << endl;
			cin >> selection;
			if(selection == 'V' || selection == 'v')
			{
				movies.display();
			}
			if(selection == 'S' || selection == 's')
			{
				cout << endl << endl << "Please enter the name of the movie you wish to search for. " << endl;
				cin.ignore(10000, '\n');
				getline(cin, option);
				search.Movietype(option);
				int find = movies.find(search);
				if (find >= 0)
				{
					movies.display(find);
				}
				else
					cout << option << " was not found in this list." << endl;
			}
			if(selection == 'D' || selection == 'd')
			{
				cout << endl << endl << "Please enter the name of the movie you wish to delete. " << endl;
				cin.ignore(10000, '\n');
				getline(cin, option);
				search.Movietype(option);
				if(movies.findAndRemove(search))
				{
					cout << option << " has been deleted." << endl;
				}
				else
					cout << option << " was not found in this list." << endl;
			}
			if(selection == 'A' || selection == 'a')
			{
				
				cout << endl << endl << "Please enter the name of the movie you wish to add: " << endl;
				cin.ignore(10000, '\n');
				getline(cin, name);
				cout << "Enter the year the movie was released: " ;
				cin >> year;
				cout << "Enter the box office take for the movie: " ; 
				cin.ignore(1000, '\n');
				cin >> boxoffice;
				cout << "Enter the studio that released the film: " ;
				cin.ignore(1000, '\n');
				getline(cin, studio);
				cout << "Enter the stars of the film, separated by commas: " ;
				getline(cin, stars);

				add.Movietype(name, year, boxoffice, studio, stars);
				if(movies.add(add))
				{
					cout << "Movie added to the list!" << endl;

				}
				else
					cout << "There was a problem adding the movie to the list." << endl;

			}
			if(selection == 'C' || selection == 'c')
			{
				cout << "There are " << movies.getLength() << " movies in the current list." << endl;
			}
			if(selection == 'F' || selection == 'f')
			{
				cout << "Enter the name of the star you wish to search for: " ;
				cin.ignore(100, '\n');
				getline(cin, option);
				if(!movies.findByStar(option))
				{
					cout << " No movies found with that star." << endl;

				}
			}
			if(selection == 'Q' || selection == 'q')
			{
				cout << "This program was created by some of the greatest minds humanity has to offer."<< endl;
				cout << "Thank you for using it and have a pleasant day." << endl;
				system("pause");
			}
		}

		
	}
return 0 ; 
}
