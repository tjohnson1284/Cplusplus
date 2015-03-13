/*Title: String Match
* Abstract: Program will take a user defined string and search for it within a file using a brute force method.
* ID: 1202
* Name: Terrence Johnson
* Date: 1/31/14
*/


#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

void readfile(string s[], int &c);
void stringmatch(string s[], string userchoice, const int &count);
bool comparestrings(string a, string b);
bool comparecharacter(char char1, char char2);

int main()
{
	string booklines[600], user = " ";
	int count = 0;

	
	
	readfile(booklines, count);
	
	cout << "Enter a string: " ;
	getline(cin, user);
	while(user == "")
	{
		cout << "Erroneous entry.";
		cout << "Enter a string: " ;
		getline(cin, user);
	}
	stringmatch(booklines, user, count);

	return 0;
}
void readfile(string s[], int &c)
{
	ifstream fin;
	string filename = " ", test; 

	cout << "Enter a file name: " << endl ;
	getline(cin, filename);
	fin.open(filename.c_str());
	if (fin.fail())
	{  
		cout << "No file found. " << endl ;
		return;
	}
	else if (fin.eof()) 
	{
		cout << "Chosen file was empty." << endl ;
		return;
	} 
	else
	{
		while(!fin.eof())
		{
			getline(fin, s[c]);			
			c++;
		}
	}

}
bool comparestrings(string a, string b)
{
	transform(a.begin(), a.end(), a.begin(), tolower);
	transform(b.begin(), b.end(), b.begin(), tolower);
	if(a == b)
	{
		return true;
	}
	else
		return false;
}
bool comparecharacter(char char1, char char2)
{
	if(tolower(char1) == tolower(char2))
		return true;
	else
		return false;
}
void stringmatch(string s[], string userchoice, const int &count)
{
	int i = 0, linenumber = 0, location = 0, match = 0;
	string test, sub;


	while( i < count)
	{
		linenumber = i;
		sub = "";

		for(size_t j = 0; j < s[i].size(); j++)
		{
			if(j + userchoice.size() > s[i].size())
			{
				break;
			}
			else if(comparecharacter(s[i][j], userchoice[0]))
			{
				sub = s[i].substr(j, userchoice.size());
				
				if(userchoice.size() == 1)
				{

					match = 1;
					location = j;

				}
				else if(comparestrings(sub, userchoice))
				{
					match = 1;
					location = j;
				}
				
			}
		}
		if(match == 1)
		{
			cout << "Match at line # " << linenumber + 1 << ", col # " << location + 1 << endl;
			location = 0;
			match = 0;
		}
		i++;
	}
	cout << "Done." << endl;
	cin.get();

}