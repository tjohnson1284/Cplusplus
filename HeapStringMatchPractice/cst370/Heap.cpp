#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

bool readFile(ifstream &fin,int heapList[], int &length);
void heapify(int heapList[], const int &length);
int heapMax(int heapList[]);
void deleteMax(int heapList[], int &length);
void insert(int heapList[], int &length, int numToInsert);
void print(int heapList[], const int &length);

int main()
{
	
	ifstream fin;
	int heapList[500] = {0}, length = 0, loopControl = 0, choice = 0, number = 0; 

	if(!readFile(fin, heapList, length))
	{
		return 0;
	}
	heapify(heapList, length);
	cout << "Heap constructed: " ;
	print(heapList, length);

	while(loopControl != 1)
	{
		cout << "Select Option (1: Find Max, 2: Insert, 3: Delete Max, 4: Exit): ";
		cin >> choice;
		if(choice != 1 && choice != 2 && choice != 3 && choice != 4)
		{
			cout << "Invalid choice. Please try again." << endl;
		}
		else if(choice == 1)
		{
			cout << "Current max: " << heapMax(heapList) << endl;
		}
		else if(choice == 2)
		{
			cout << "New item to be inserted: " ; 
			cin >> number;
			insert(heapList, length, number);
			cout << endl;
			cout << "Heap updated: " ;
			print(heapList, length);
			cout << endl;
		}
		else if(choice == 3)
		{
			deleteMax(heapList, length);
			cout << endl;
			cout << "Heap updated: " ;
			print(heapList, length);
			cout << endl;
		}
		else if(choice == 4)
		{
			loopControl = 1;
		}

	}
	cout << "Bye!" ;





	return 0;

}

bool readFile(ifstream &fin, int heapList[], int &length)
{ 
	string filename;

	int  temp;
	//fin.close();
	cout << "Enter file location: " << endl;
	//cin.ignore(10000, '\n');
	getline(cin, filename);
	fin.open(filename.c_str());
	
	if(fin.fail())
	{
		cout << "Invalid file location. Please Try again." << endl;
		return false;
	}

	fin >> length; 
	while(!fin.eof())
	{
		for(int i = 1; i <= length; i++)
		{
			fin >> temp; 
			heapList[i] = temp;
		}

	}
	return true;
}

bool heapCheck(int heapList[], const int &length)
{
	for(int i = length/2 ; i >= 1; i--)
	{
		if(heapList[i] < heapList[i*2])
		{
			return false;
		}
		else if(heapList[i] < heapList[i*2 + 1])
		{
			return false;
		}
	}
	return true;
}
void heapify(int heapList[], const int &length)
{
	int temp;
	while(!heapCheck(heapList, length))
	{
		for(int i = length/2 ; i >= 1; i--)
		{
			if(heapList[i] < heapList[i*2])
			{
				temp = heapList[i];
				heapList[i] = heapList[i*2];
				heapList[i*2] = temp;
			}
			else if(heapList[i] < heapList[i*2 + 1])
			{
				temp = heapList[i];
				heapList[i] = heapList[i*2 + 1];
				heapList[i*2 + 1] = temp;
			}
		}
	}
}

int heapMax(int heapList[])
{
	return heapList[1];
}

void deleteMax(int heapList[], int &length)
{ 	
	heapList[1] = heapList[length];
	length--;
	heapify(heapList, length);
}

void insert(int heapList[], int &length, int numToInsert)
{

	length++;
	heapList[length] = numToInsert;
	heapify(heapList, length);
}
void print(int heapList[], const int &length)
{

	for(int i = 1; i <= length; i++)
	{
		cout << heapList[i] << " " ;
	}
	cout << endl;
}