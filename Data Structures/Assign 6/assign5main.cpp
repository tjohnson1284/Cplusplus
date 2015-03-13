#include "StudentTree.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;


int main()
{
	string filename, name = "", major = "";
	Student test, search;
	Tree t1;
	vector<Student> v_stu;
	ifstream fin; ofstream fout;
	char selection = 'y', select2 = 'a';
	int id = 0, tests[3], age = 0;
	
	while ( selection != 'X' && selection != 'x' )
	{
		cout << endl << "Your options are as follows." << endl << endl;
		cout << "Press R to read data from a file." << endl;
		cout << "Press S to search for a particular student in the list." << endl;
		cout << "Press F to save the data to a file." << endl;
		cout << "Press A to add a student to the list." << endl; 
		cout << "Press P to print the list to the screen." << endl;
		cout << "Press D to remove a student from the list. " << endl;
		cout << "Press M to find the max average. " << endl;
		cout << "Press T to find everyone with a given average. " << endl;
		cout << "Press U to find everyone with a given major. " << endl;
		cout << "Press V to find everyone with the max average. " << endl;
		cout << "Press X to quit." << endl;
		cin >> selection;
		
		if(selection == 'R' || selection == 'r')
		{
			cout << "Enter file location: " ;
			cin.ignore(100, '\n');
			getline(cin, filename);
			t1.readfromfile(filename);
			cout << "There are "<< t1.Size() << " students in this list." << endl;
			fin.close();
		}
		if(selection == 'F' || selection == 'f')
		{
			cout << "Would you like to save the data to a new file or your original file location? Press Y for the original location. Press N for a new location." << endl;
			cin >> select2;
			if(select2 == 'Y' || select2 == 'y')
			{
				fout.open(filename.c_str());
				if(fout.fail())
				{
					cout << "Unable to find original file. If you would like to create a new file, press N. Anything else will return to the main menu." << endl;
					cin >> select2;
				}
				else
				{
					fout << t1 ;;	
				}
				fout << "***";
			}
			if(select2 == 'N' || select2 == 'n')
			{
				cout << "Enter file location: " ;
				cin.ignore(100, '\n');
				getline(cin, filename);
				fout.open(filename.c_str());
				if(fout.fail())
				{
					cout << " Unable to create a file in the chosen location. Please check your location and try again." << endl;
				}
				else 
				{
					fout << t1;
					fout << "***";
					fout.close();
				}
				
			}
		}
		if (selection == 'P' || selection == 'p')
		{
			cout << t1;
			cin.get();
		}
		if ( selection == 'S' || selection == 's')
		{
			cout << "Enter the student's ID: " << endl;
			cin >> id;
			search.setkey(id);
			if(t1.Lookup(search))
			{
				cout << search;
			}
			else 
				cout << "Student not found." << endl;
		}
		if ( selection == 'A' || selection == 'a')
		{
			cout << "Enter the ID of the student you wish to add: " << endl;
			cin >> id;
			search.setkey(id);
			if(t1.Lookup(search))
			{
				cout << "That student already exists. " << endl;
			}
			else 
			{
				cout << "Enter the name of the student you wish to add: " << endl;
				cin.ignore(100, '\n');
				getline(cin, name);
				cout << "Enter the major of the student you wish to add: " << endl;
				getline(cin, major);
				cout << "Enter the age of the student you wish to add: " << endl;
				cin >> age;
				cout << "Enter the test scores of the student, with a space between each score: " << endl;
				cin >> tests[0]; cin >> tests[1]; cin >> tests[2];
				Student add(name,age,major,tests,id);
				t1.Insert(add);
			}
		}
		if(selection == 'D' || selection == 'd')
		{
			cout << "Enter the ID of the student you wish to delete: " << endl;
			cin >> id;
			if(t1.Delete(id))
			{
				cout << "Student deleted from the list." << endl;
			}
			else
			{
				cout << "Student not found in the list. " << endl;
			}
		}
		if(selection == 'M' || selection == 'm')
		{
			t1.GetMaxAve(age);
			cout << " The maximum average in this list is " << age << "." << endl;
		}
		if(selection == 'T' || selection == 't')
		{
			cout << "What average do you wish to search for? " << endl;
			cin >> age;
			t1.GivenMaxAve(age, v_stu);
			if(v_stu.size() == 0)
			{
				cout << "No student found with that average." << endl;
			}
			else
				cout << v_stu;
			v_stu.clear();
		}
		if(selection == 'U' || selection == 'u')
		{
			cin.ignore(100, '\n');
			cout << "What major do you wish to search for? " << endl;
			getline(cin, major);
			t1.GivenMajor(major, v_stu);
			cout << v_stu;
			v_stu.clear();
		}
		if(selection == 'V' || selection == 'v')
		{
			t1.AllPeopMaxAve(age, v_stu);
			cout << "The Maximum Average in this list is: " << age <<"%" << endl;
			cout << "The people with this average are: " << endl;
			cout << v_stu;
			v_stu.clear();
		}
	}
		
	return 0;

}
	