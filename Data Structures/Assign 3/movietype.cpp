#include <iostream>
#include <fstream>
#include <string>
#include "movietype.h"
using namespace std;


MovieType::MovieType()
	:m_title("N/A"), m_studio("N/A"), m_year(-1), m_receipts("N/A"), m_stars()
{
}
void MovieType::Movietype(string title, int year, string receipts, string studio, string star1, string star2, string star3)
{
	m_title = title;
	m_year = year;
	m_receipts = receipts;
	m_studio = studio;
	m_stars[0] = star1;
	m_stars[1] = star2;
	m_stars[2] = star3;
}
void MovieType::Display(ostream& os) const
{
	os << "Movie Name: " << m_title << endl; 
	os << "Movie Studio: " << m_studio << endl;
	os << "Release Year: " << m_year << endl;
    os << "Adjusted Gross: $" << m_receipts << endl;
	os << "Stars: " ;
	for(int i = 0 ; i < 3 ; i++)
		if (m_stars[i] != "" && m_stars[i+1] !="" && i < 2)
		{
			cout << m_stars[i] << ", ";
		}
		else
			cout << m_stars[i] ;
	cout << endl;
}
void MovieType::StringSort(string &s1)
{
	int pos[3];
	pos[0] = s1.find(',',0);
	pos[1] = s1.find(',',pos[0]+1);
	pos[2] = s1.find(',',pos[1]+1);
	if (pos[0] > 0)
	{
		m_studio = s1.substr(0,pos[0]);
		for (int i = 0; i < 3; i++) 
		{
			if (pos[i] > 0)
			{
				m_stars[i] = s1.substr(pos[i]+2,pos[i+1]-pos[i]-3); 
			}
			else if (pos[i] < 0)
			{
				m_stars[i] = "";
				if(i == 1) 
				{
					m_stars[i+1] = "";
					break;
				}
			}
		}
	}
	else
	{
		m_studio = s1;
		for (int i = 0; i < 3; i++) 
			m_stars[i] = "";
	}
	return;
}

bool MovieType::ReadOneMovieFromFile(ifstream& fin)
{
	string stop = "***";
	string temp;
	int i =0;

	getline(fin, m_title);
	if(m_title == stop)
	{
		return false;
	}
	else
	{
		fin >> m_year;
		fin >> m_receipts;
		//adding commas
		i = m_receipts.length();
		for (int j = 3 ; j < i ; )
		{
			m_receipts.insert((i - j), ","); 
			j = j+3;
		}
		//--------------
		fin.ignore(100, '\n');
		getline(fin, temp);
		StringSort(temp);
		return true;
	}
}
ostream& operator<<(ostream& os, const MovieType &m)
{
	m.Display(os);
	return os;
}

int MovieType::compareKeys(const MovieType& m2) const  // result = p1.compareKeys(p2);
{
	if (m_title == m2.m_title)
		return 0;
	else if (m_title > m2.m_title)
		return 1;
	else 
		return -1;
// three way comparison ==, > , <
// p1.compareKeys(p2) == 0 --> p1 == p2
// p1.compareKeys(p2) > 0  --> p1 > p2
// p1.compareKeys(p2) < 0  --> p1 < p2

// p1.operator==(p2)  <-->  p1 == p2
}
bool operator==(const MovieType &m1, const MovieType &m2)
{
	return m1.m_title == m2.m_title;
}
bool operator!=(const MovieType &m1, const MovieType &m2)
{
	return m1.m_title != m2.m_title;
}
bool operator<(const MovieType &m1, const MovieType &m2)
{
	return m1.m_title < m2.m_title;
}
bool operator>(const MovieType &m1, const MovieType &m2)
{
	return m1.m_title > m2.m_title;
}
bool operator<=(const MovieType &m1, const MovieType &m2)
{
	return m1.m_title <= m2.m_title;
}
bool operator>=(const MovieType &m1, const MovieType &m2)
{
	return m1.m_title >= m2.m_title;
}
string MovieType::getKey() const
{
	return m_title;
}
string MovieType::getstar(int index) const
{
	if(index == 0)
	{
		return m_stars[0];
	}
	else if (index == 1) 
	{
		return m_stars[1];
	}
	else 
		return m_stars[2];
}

