/*
#include "SortedMovieList.h" 
#include <iostream>
#include <string>
#include <fstream>

sList::sList(int init_capacity) : size(0), capacity(init_capacity) // member-initialization list
{ 
	items = new ListItemType[init_capacity];
} 
void sList::copy( const sList& existing)
{
	size = existing.size;
	capacity = existing.capacity;

	
	items = new ListItemType[capacity];

	// copy data
	for( int i = 0; i < size; i++ )
			items[i] = existing.items[i];
}
sList::sList( const sList& existing)
{
	copy(existing);
}

sList& sList::operator=(const sList& l2)  // l1.operator=(l2);  l1 = l2;
{
	if( this != &l2 )
	{
		clean();

		copy( l2 );
	}
	
	// return the value assigned -> l3 = l1 = l2
	return *this;
}

sList::~sList()  // does "cleanup"
{
	clean();
}

void sList::clean()  // does "cleanup"
{
	delete [] items;
}
//-----------------------------------------------------------------------------------------

bool sList::ReadAllMoviesFromFile()
{
	int i = 0;
	ifstream fin;
	string filename; 
	ListItemType temp;

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
bool sList::isEmpty() const 
{ 
	if (size == 0)
		return true;
	else
		return false;
}  // end isEmpty 
 
int sList::getLength() const 
{ 
   return size; 
} // end getLength 
 
bool sList::insert(int index, ListItemType newItem) 
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
 
bool sList::remove(int index) 
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
 
bool sList::retrieve(int index, ListItemType& dataItem) const 
{ 
   bool success = (index >= 0) && (index < size); 
   if (success) 
      dataItem = items[index]; 
   return success;
} // end retrieve 
 
bool sList::add(const ListItemType& newItem)
{
	// is there room?
	if( size == capacity ) 
	{
		/*cout << "resizing: old capacity = " << capacity 
			 << "   new capacity = " << 2*capacity << endl;*/
		capacity *= 2;  // capacity = 2 * capacity;
		ListItemType *temp = new ListItemType[capacity]; 
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

int sList::find(const ListItemType& itemToFind) const  // stop short
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

void sList::display() const
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

void sList::display(int index) const
{
	cout << endl << items[index] << endl << "==========================" << endl;
}

bool sList::findAndRemove(const ListItemType& itemToFind)
{
	return remove(find(itemToFind)); 
}

bool sList::findAndRetrieve(ListItemType& itemToFind) const
{
	return retrieve(find(itemToFind),itemToFind);
}
bool sList::findByStar(string& itemToFind) const
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