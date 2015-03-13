 //Main.cpp
//-------------------------
#include "phonebook.h"
#include <iostream>
#include <string>

using namespace std;


int main()
{
	char selection = 'n';
	string name = "", p_number = "";
	int age = 0;

	ULnkList l;
	l.Insert("Joe",60, "(310)555-4665");
	l.Insert("Mariesa",23,"(310)555-9666");
	l.Insert("Kenny",90,"(310)555-8666");
	l.Insert("Rain",20, "(310)555-2666");
	l.Insert("Jade",51, "(310)555-4666");
	l.Insert("Raiden",20, "(310)555-6636");
	l.Insert("Nathan",60, "(310)555-6266");
	l.Insert("Snake",24,"(310)555-7766");
	l.Insert("Ryu",90,"(310)555-7686");
	l.Insert("Greymane",21, "(310)555-6886");
	l.Insert("Thunder",90, "(310)555-6787");
	l.Insert("Dragonborn",20, "(310)555-6777");
	cout << "Original List: " << endl;
	cout << l << endl;
	cin.get();
 //Test copy ctor
	ULnkList l2(l);
	cout << "List after copy ctor: " <<endl;
	cout << l2 << endl;
	cin.get();
	//Test operator 
	ULnkList l3;
	l3 = l;
	cout << "List after operator= : " << endl;
	cout << l3 << endl;
	cin.get();

	while (selection != 'Q' && selection != 'q')
		{
			cout << endl << "Your options are as follows." << endl << endl;
			cout << "Press S to search for a particular person in the list." << endl;
			cout << "Press D to delete a person from the list." << endl;
			cout << "Press A to add a person to the list." << endl; 
			cout << "Press V to view the list. " << endl;
			cout << "Press C to count of the number of people in the list." << endl;
			cout << "Press F to find the oldest age in the list" << endl;
			cout << "Press T to search the list by age" << endl;
			cout << "Press H to find the oldest people in the list." << endl;
			cout << "Press Q to quit." << endl;
			cin >> selection;
			if(selection == 'S' || selection == 's')
			{
				cout << endl << endl << "Please enter the name of the person you wish to search for. " << endl;
				cin.ignore(10000, '\n');
				getline(cin, name);
				if (l.Lookup(name, age, p_number))
				{
					cout << "Name: " << name << endl << "Age: " << age << endl << "Phone Number: " << p_number << endl;
				}
				else
					cout << name << " was not found in this list." << endl;
			}
			if(selection == 'D' || selection == 'd')
			{
				cout << endl << endl << "Please enter the name of the person you wish to delete. " << endl;
				cin.ignore(10000, '\n');
				getline(cin, name);
				if(l.Delete(name))
				{
					cout << name << " has been deleted." << endl;
				}
				else
					cout << name << " was not found in this list." << endl;
			}
			if(selection == 'A' || selection == 'a')
			{
				
				cout << endl << endl << "Please enter the name of the person you wish to add: " << endl;
				cin.ignore(10000, '\n');
				getline(cin, name);
				cout << "Enter the age of the person you wish to add: " ;
				cin >> age;
				cout << "Enter the phone number of the person you wish to add: " ; 
				cin.ignore(1000, '\n');
				cin >> p_number;				
				if(l.Insert(name, age, p_number))
				{
					cout << name << " added to the list!" << endl;

				}
				else
					cout << "There was a problem adding that person to the list." << endl;

			}
			if(selection == 'V' || selection == 'v')
			{
				cout << l << endl;

			}
			if(selection == 'C' || selection == 'c')
			{
				cout << "There are " << l.Size() << " people in the current list." << endl;
			}
			if(selection == 'F' || selection == 'f')
			{
				age = l.getmaxage();
				cout << "The highest age in this list is: " << age << endl;
			}
			if(selection == 'T' || selection == 't')
			{
				cout << "Enter the age you want to find. " << endl;
				cin >> age;
				l2 = l.GetPeopleWithGivenAge(age);
				if(l2.Size() == l.Size())
				{
					cout << "Unable to the find age specified " << endl;
				}
				else
					cout << l2 << endl;
			}
			if(selection == 'H' || selection == 'h')
			{
				l2 = l.GetAllPeopleWithMaxAge();
				cout << l2 << endl;
				cin.get();
			}
			if(selection == 'Q' || selection == 'q')
			{
				cout << "This program was created by some of the greatest minds humanity has to offer."<< endl;
				cout << "Thank you for using it and have a pleasant day." << endl;
				system("pause");
			}
		}

return 0 ; 

}