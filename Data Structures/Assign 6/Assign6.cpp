#include <iostream>
#include <fstream>
#include <string>
#include "assign6.h"
#include <iomanip>
using namespace std;

// which sort operators to compile
 #define State_SORT

#define MAX  10


struct stateInfo
{
	char s_name[15]; // C string – compare “strcmp” strcmp(s1,s2) > 0 -> s1 > s2
	int s_population;
	int s_area;
	int s_year;
	int s_order;
	char s_capital[15];
	char s_abbrev[3];
	int s_zip;			// ~~~     ~~~~~~~~~~~~~~~~~~

	stateInfo(const char name[] = "", int population = -1, int area = -1, int year = -1, int order = -1, const char capital[] ="", const char abr[] ="", int zip = -1)
	:  s_population(population),s_area(area), s_year(year),s_order(order),s_zip(zip)
	{
		strcpy(s_name,name);
		strcpy(s_capital, capital);
		strcpy(s_abbrev, abr);
	}

	void Print()
	{
		cout << setfill(' ') << left << setw(16) << s_name << "   " <<  setw(8) << s_population << " " << setw(6) << s_area 
			<< " " << setw(4) << s_year << " " << setw(2) << s_order << " " << setw(15) << s_capital << " "<< setw(2) << s_abbrev << 
			" "<< setw(5) << s_zip << endl;
	}
} ;

#ifdef State_SORT
// operators for "name" sort
//
bool operator>(const stateInfo& p1, const stateInfo& p2)
{
	return strcmp(p1.s_name,p2.s_name) > 0;
}

bool operator<(const stateInfo& p1, const stateInfo& p2)
{
	return strcmp(p1.s_name,p2.s_name) < 0;
}

bool operator<=(const stateInfo& p1, const stateInfo& p2)
{
	return strcmp(p1.s_name,p2.s_name) <= 0;
}
#else
// // operators for "age" sort
bool operator>(const stateInfo& p1, const stateInfo& p2)
{
	return p1.s_population > p2.s_population;
}

bool operator<(const stateInfo& p1, const stateInfo& p2)
{
	return p1.s_population < p2.s_population;
}

bool operator<=(const stateInfo& p1, const stateInfo& p2)
{
	return p1.s_population <= p2.s_population;
}

#endif

const int MAX_STATES = 50;

void main()
{
	stateInfo States[MAX_STATES]; 
	int count = 0;
	// ~~~~~~~~~~~~~~~
	ifstream inBin;
	inBin.open("States.dat",ios::binary);
	if( !inBin)
	{
		cout << "Could not open filer\n";
		exit(1);	
	}
	stateInfo p;

	int i = 0;
	int SIZE = sizeof(stateInfo);

	while( i < MAX_STATES &&  inBin.read((char *)&p,SIZE) )
		States[i++] = p;

	for( int j = 0; j < i; j++ )
	{
		States[j].Print();
		count++;
		if( count == 10)
		{
			cin.get();
			count = 0;
		}
	}
	count = 0;
	cout << "===================================" << endl << endl;

#ifdef State_SORT
	HeapSort(States,i);
#else
	sort(States, i);
#endif

#ifdef State_SORT
	cout << "Sorted by State Name using Heap Sort:" << endl;
	cout << "~~~~~~~~~~~~~~" << endl;
#else
	cout << "Sorted by Population using Selection Sort:" << endl;
	cout << "~~~~~~~~~~~~~~" << endl;
#endif
	// print the array
	for( int j = 0; j < i; j++ )
	{
		States[j].Print();
		count++;
		if( count == 10)
		{
			cin.get();
			count = 0;
		}
	}
	count = 0;
	cout << "===================================" << endl << endl;
	

	return;
	
	cin.get();
}