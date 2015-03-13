/*Title: Anagram
* Abstract: Read from a file and determine if two words are an anagram without using any library calls.
* Author: Terrence Johnson
* ID: 1202
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void readFile(string s[]);
int strLength(const string s);
bool anagramCheck(string s[], const int l[]);

int main()
{
	string anagram[2];
	int i = 0, length[2];
	
	

	readFile(anagram);

	for( int i = 0; i < 2; i++)
	{
		length[i] = strLength(anagram[i]);
	}
	if(anagramCheck(anagram, length))
	{
		cout << "The words are an anagram." << endl;
		cout << "Done." << endl;
	}
	else 
	{
		cout << "The words are not an anagram." << endl;
		cout << "Done." << endl; 
	}
	cin.get();
	return 0;
}

void readFile(string s[])
{
	ifstream fin;
	string filename = " ", test; 
	int i = 0;

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
			getline(fin, s[i]);
			i++;
		}
	}

}
int strLength(const string s)
{
	char* test;
	int count = 0;

	test = (char*)s.c_str();

	for(int i = 0; test[i] != '\0'; i++)
		count++;

	return count;
}
bool anagramCheck(string s[], const int l[])
{
	int length = l[0], i;
	char ana[1024];

	if(l[0] != l[1])
	{
		cout << "Not an anagram, two words are the same length." << endl;
		return false;
	}
	
	for(int i = 0; i < length ; i++)
	{
		ana[i] = s[0][i];
	}
	
	i = 0;
	while(i < length)
	{
		for(int h = 0; h < length; h++)
		{
			if(ana[i] == s[1][h])
			{
				ana[i] = ' ';
				s[1][h] = ' ';
				break;
			}
		}
		i++;
	}
	for(int i = 0; i < length; i++)
	{
		if(ana[i] != ' ')
		{
			return false;
		}
	}
	return true;
}
