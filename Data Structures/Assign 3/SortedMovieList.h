#pragma once
#include "movietype.h"
#include <string>
#include <fstream>
#include <iostream>
// const int MAX_LIST = 50; //maximum-size-of-list; 
//typedef desired-type-of-list-item ListItemType; 
#include<afxwin.h>
#define DEBUG_NEW

typedef MovieType ListItemType; 

template<typename T>
class sList 
{ 
public: 
	sList(int init_capacity = 10);  // default constructor 

	sList(const sList &existing); // new copy constructor 
	
	~sList(); // dtor

	sList& operator=(const sList &l2); // list comparison

	bool ReadAllMoviesFromFile();
	// Reads all the movies in a given file
	// Precondition: None
	// Postcondition: True, if movies are stored. False, if no movies are stored. 

	bool isEmpty() const; 
	// Determines whether a list is empty. 
	// Precondition: None. 
	// Postcondition: Returns true if the list is empty; 
	// otherwise returns false. 

	int getLength() const; 
	// Determines the length of a list. 
	// Precondition: None. 
	// Postcondition: Returns the number of items 
	// that are currently in the list. 

	bool insert(int index, ListItemType newItem); 
	// Inserts an item into the list at position index. 
	// Precondition: index indicates the position at which 
	// the item should be inserted in the list. 
	// Postcondition: If insertion is successful, newItem is 
	// at position index in the list, and other items are 
	// renumbered accordingly, and true is returned; 
	// otherwise false is returned. 
	// Note: Insertion will not be successful if 
	// index < 0 or index > getLength(). 

	bool add(const ListItemType& newItem); 
	//  
	// Precondition: newItem is a valid ListItemType
	// Postcondition: Either
	//	1.	There is room in the list - in this case, newItem is added 
	//	    alphabetically into the list, and true is returned.
	//	2.	The list is full - in this case, and false is returned.
	//		

	int find(const ListItemType& itemToFind) const;
	//  
	// Precondition: itemToFind.m_title is valid.
	// Postcondition: Either
	//	1.	There is an item in the list whose title matches 
	//		itemToFind.m_title - in this case, the index of the match is returned.
	//	2.	No item in the list matches itemToFind.m_title - in this case, 
	//		-1 is returned.

	bool findAndRemove(const ListItemType& itemToFind);
	//  
	// Precondition: itemToFind.m_title is valid.
	// Postcondition: Either
	//	1.	There is an item in the list whose id matches 
	//		itemToFind.m_title - in this case, the matching item is removed from
	//		the list and true is returned.
	//	2.	No item in the list matches itemToFind.m_title - in this case, 
	//		false is returned.

	bool findAndRetrieve(ListItemType& itemToFind) const;
	//  
	// Precondition: itemToFind.m_title is valid.
	// Postcondition: Either
	//	1.	There is an item in the list whose title matches 
	//		itemToFind.m_title - in this case, the matching item's data is 
	//		stored in itemToFind and true is returned.
	//	2.	No item in the list matches itemToFind.m_title - in this case 
	//		false is returned.

	bool findByStar(string& itemToFind) const;
	// 
	// Precondition: Valid string given.
	// Postcondition: Either
	// 1. The star is found, each movie the star is in displays with a pause, and returns true
	// 2. The star isn't found, message saying so prints, returns false.

	void display() const;
	// 
	// Precondition: The list is valid.
	// Postcondition: The list is displayed to cout.
	void display(int index) const;
	// 
	//Precondition: List is valid. Index of movie is provided.
	//Postcondition: Movie at said index is displayed to the monitor.

private: 

	T *items;  
	int          size, capacity;             

	
	bool remove(int index); 
   // Deletes an item from the list at a given position. 
   // Precondition: index indicates where the deletion 
   // should occur. 
   // Postcondition: If 0 <= index < getLength(), 
   // the item at position index in the list is 
   // deleted, other items are renumbered accordingly, 
   // and true is returned; otherwise false is returned. 
 
   bool retrieve(int index, ListItemType& dataItem) const; 
   // Retrieves a list item by position. 
   // Precondition: index is the number of the item to 
   // be retrieved. 
   // Postcondition: If 0 <= index < getLength(), 
   // dataItem is the value of the desired item and 
   // true is returned; otherwise false is returned. 
 
   void copy(const sList& existing);
   void clean();

}; 
//Functions 

template<typename T>
sList<T>::sList(int init_capacity) : size(0), capacity(init_capacity) // member-initialization list
{ 
	items = new T[init_capacity];
} 

template<typename T>
void sList<T>::copy( const sList& existing)
{
	size = existing.size;
	capacity = existing.capacity;

	
	items = new T[capacity];

	// copy data
	for( int i = 0; i < size; i++ )
			items[i] = existing.items[i];
}
template<typename T>
sList<T>::sList( const sList& existing)
{
	copy(existing);
}

template<typename T>
sList<T>& sList<T>::operator=(const sList& l2)  // l1.operator=(l2);  l1 = l2;
{
	if( this != &l2 )
	{
		clean();

		copy( l2 );
	}
	
	// return the value assigned -> l3 = l1 = l2
	return *this;
}

template<typename T>
sList<T>::~sList()  // does "cleanup"
{
	clean();
}

template<typename T>
void sList<T>::clean()  // does "cleanup"
{
	delete [] items;
}
//-----------------------------------------------------------------------------------------

template<typename T>
bool sList<T>::ReadAllMoviesFromFile()
{
	int i = 0;
	ifstream fin;
	string filename; 
	T temp;

	cout << "Please enter the location of your file" << endl;
	getline(cin, filename);

	fin.open(filename.c_str());
	if (fin.fail())
	{
		return false;
	}
	else
	{
		while(temp.ReadOneMovieFromFile(fin))  // too many
		{

			if(add(temp))
			{
				i++;
			}
			else
				break;

		}
		if(i == 0 )
		{
			cout << "File was empty. Please check your file and try again." << endl;
			return false;
		}
		size = i;
		fin.close();
		return true;
	}
}

template<typename T>
bool sList<T>::isEmpty() const 
{ 
	if (size == 0)
		return true;
	else
		return false;
}  // end isEmpty 

template<typename T>
int sList<T>::getLength() const 
{ 
   return size; 
} // end getLength 

template<typename T>
bool sList<T>::insert(int index, ListItemType newItem) 
{ 
   bool success = (index >= 0) && (index <= size ) && (size < capacity); 
   if (success) 
   {  // make room for new item by shifting all items at 
      // positions >= index toward the end of the 
      // list (no shift if index == size) 
      for (int pos = size; pos > index; --pos) 
         items[pos] = items[pos-1]; 
	  //          
      // insert new item      
	  items[index] = newItem; 
      ++size;  // increase the size of the list by one 
   }  // end if 
   return success;
} // end insert 

template<typename T>
bool sList<T>::remove(int index) 
{ 
   bool success = (index >= 0) && (index < size) ; 
   if (success) 
   {  // delete item by shifting all items at positions > 
      // index toward the beginning of the list 
      // (no shift if index == size) 
      for (int fromPosition = index; fromPosition < size-1; ++fromPosition) 
         items[fromPosition] = items[fromPosition + 1];
      --size;  // decrease the size of the list by one 
   }  // end if 
   return success;
}  // end remove 
 
template<typename T>
bool sList<T>::retrieve(int index, ListItemType& dataItem) const 
{ 
   bool success = (index >= 0) && (index < size); 
   if (success) 
      dataItem = items[index]; 
   return success;
} // end retrieve 

template<typename T>
bool sList<T>::add(const ListItemType& newItem)
{
	// is there room?
	if( size == capacity ) 
	{
		/*cout << "resizing: old capacity = " << capacity 
			 << "   new capacity = " << 2*capacity << endl;*/
		capacity *= 2;  // capacity = 2 * capacity;
		T *temp = new ListItemType[capacity]; 
		for( int i = 0; i < size; i++ )
			temp[i] = items[i];

		delete [] items;
		items = temp;
	}
	int i = 0;
	for( ; i < size; i++)
	{
		if(items[i] > newItem)
			break;
	}
	return (insert(i, newItem));
}
//bool sList::add(const ListItemType& newItem)
//{
//	
//	if( size <  MAX_LIST  )
//	{
//	    int i = 0;
//		for ( ; i < size; i++)
//		{
//			if(items[i] > newItem)
//				break;
//		}
//		return (insert(i, newItem));
//	}
//	
//	return false;
//}

template<typename T>
int sList<T>::find(const ListItemType& itemToFind) const  // stop short
{

	//for( int i = 0; i < size; i++ )
	//	//if( items[i].getKey() == itemToFind.getKey() )
	//	if(items[i] > itemToFind)
	//		return -1;
	//	
	//	else if(items[i] == itemToFind)
	//		return i;
	//
	//return -1;
	int top = 0, bot = size-1, mid;
 

	while( top <= bot )
	{

		mid = (top+bot)/2;
		if(items[mid] < itemToFind)
		{
			top = mid + 1;
		}
		else if(items[mid] > itemToFind)
		{
			bot = mid - 1; 
		}
		else
			return mid;

	}
	
	return -1;
}

template<typename T>
void sList<T>::display() const
{
	int i = 0 , j = 0;
	char selection = 'a';

	while ( i < size)
	{
		cout << items[i]<< endl << "==========================" << endl;
		i++;
		j++;
		if (j == 3)
		{
			
			system("pause");
			j = 0; 
		}
		
	}
}

template<typename T>
void sList<T>::display(int index) const
{
	cout << endl << items[index] << endl << "==========================" << endl;
}

template<typename T>
bool sList<T>::findAndRemove(const ListItemType& itemToFind)
{
	return remove(find(itemToFind)); 
}

template<typename T>
bool sList<T>::findAndRetrieve(ListItemType& itemToFind) const
{
	return retrieve(find(itemToFind),itemToFind);
}

template<typename T>
bool sList<T>::findByStar(string& itemToFind) const
{
	int tracking = 0;
	string temp;

	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			
			if(items[i].getstar(j) == itemToFind)
			{
				display(i);
				system("pause");
				tracking++;
			}
			
		}

	}
	if(tracking > 0)
	{
		cout << endl << itemToFind << " was found in " << tracking << " movie(s)." << endl;
		return true;
	}
	else 
		return false;
}