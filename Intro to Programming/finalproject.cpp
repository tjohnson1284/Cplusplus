/*
*	Programmer:	Terrence Johnson
*	Due Date:	Dec. 15, 2011
*	Lab Section:	0106
*
Problem: Create a menu driven program to simulate a simple banking system. The program will open a file, read the data, store them in an 
array/vector of structures to represent the bank customers information, including customer name, address, city, state, account number, and 
account balance. The format and a sample of the file are provided below. If you are using arrays make the size 20 and 
if there are more customers in the file print a message and only process the 20 that are stored in the array. Assume all the data stored in 
the file are correct, no need to verify them.
	

Analysis: What do we need to do the job? (Specifications)
	1)	User Obtained Info: Customer file on the accounts in question.
	

Design: How do get the job done?  (Algorithm)
1. Declare a structure called accounts to hold a name string, an address string, a state, zip and city string, 
   a long to store the account number, and a float to store the account balance.  

2. Create a function to prompt the user for a file holding the account information. Once the file is called
   create a loop to process and store the information in the file to the structure. Use an array to store each 
   account. Keep track of the total accounts processed and pass that to main. 

3. create another function containing a loop that will control the menu. use if statements to control which
   part of the menu is opened. 

   O = Open existing file. 
   A = Add new customer to the current list.
   R = Remove customer from the current list. 
   P = Print all customers in the current list.
   W = Withdrawal. 
   D = Make a deposit.  
   T = Sort the list
   X = Exit the program. 

4. For O, use 2. 

5. For A, Using the total, add a customer to the list. Prompt for each part of the account information separately. 
   Make sure that this new customer won't break the array. 

6. For R, to remove a customer, collect the chosen customer from the user and compare it to the names in the array. 
   after, increment the array up by one.

7. For P, use cout statements to print the current customer array. 

8. For W, collect the name from the customer or the account number, compare it to the array.
   once the correct customer is found. Ask for the amount to withdraw and subtract it from the current balance.

9. For D, repeat the steps from number nine except ask for the amount to deposit and add it to the current balance. 

10. For T, display a secondary menu(using the if statements) asking whether to sort by name or balance. Then sort the list.

11. For X, exit the loop and the program. Print a closing message. Save changes to the initial file that was opened by the user. 

*/
//   Implementation: Converting the algorithm to C++.
	


#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#define SIZE 20
using namespace std;
struct customer{
	string name;
	string address1;
	string city, state;
	int zipcode, totaltrans;
	long accountnum;
	float balance, transhist[25];
};
bool openfile(ifstream &fin, string &filename);
int readfile(customer account[SIZE], ifstream &fin);
void instructions(char &choice);
void addcustomer(customer account[], int &total);
void remcustomer(customer account[], int &total);
void print(customer account[], int total);
void withdraw(customer account[], int total);
void deposit(customer account[], int total);
void sort(customer account[], int total);
void exit(customer account[], int total, string filename);
void statement(customer account[], int total);
void menu(customer account[], string &filename, char &choice, int &total, ifstream &fin);


int main () 
{

	customer account[SIZE];
	int total = 0;
	char choice = 'A';
	string filename;
	ifstream fin;
	
   instructions(choice);

   menu(account, filename, choice, total, fin);

   
return 0 ; 
}


bool openfile(ifstream &fin, string &filename)
{ 
	fin.close();
	cout << "Please enter the location of your customer accounts file:" << endl;
	cin.ignore(10000, '\n');
	getline(cin, filename);
	fin.open(filename.c_str());
	
	if(fin.fail())
	{
		return false;
	}
	else 
	  return true; 
}
int readfile(customer account[], ifstream &fin)
{
	int i = 0;

	getline(fin, account[i].name);
while(!fin.eof())
 {
	 getline(fin, account[i].address1);
	 fin >> account[i].state;
	 fin >> account[i].zipcode;
	 fin.ignore(1, '\n');
	 getline(fin, account[i].city);
	 fin >> account[i].accountnum;
	 fin >> account[i].balance;
	 account[i].totaltrans = 0;
	 i++;
	 if (i == SIZE)
	 {
		 cout << "Array is full. Some customers were not processed " << endl;
		 break;
	 }

	 fin.ignore(10000, '\n');
	 getline(fin, account[i].name);
 }
    return i;
 }
void instructions(char &choice)
{
	cout << "\t\t\t Welcome to my Banking Program. " << endl;
	cout << left << " Please make your selection from the following options: " << endl << endl << endl;
	cout << left << " \t\t Press O to Open an existing customer's file. " << endl;
	cout << left << " \t\t Press A to Add a new customer to the file. " << endl;
	cout << left << " \t\t Press R to Remove a customer from the file. " << endl;
	cout << left << " \t\t Press P to Print all customers in the file. " << endl;
	cout << left << " \t\t Press W to make a Withdrawal. " << endl;
	cout << left << " \t\t Press D to make a Deposit. " << endl;
	cout << left << " \t\t Press S to Sort the customers in the file. " << endl;
	cout << left << " \t\t Press V to View your statement. " << endl;
	cout << left << " \t\t Press X to Exit." << endl;
   cin >> choice;
}
void addcustomer(customer account[], int &total)
{
	customer temp;
	int trigger = 0;
	
	if(total+1 < SIZE)
	{
		cout << "Enter the Account Number of the customer you wish to add in the format: " << endl;
		cin >> temp.accountnum ;
		
		for(int i = 0; i < total; i++)
		{
			if (account[i].accountnum == temp.accountnum)
			{
				cout << "Customer already exists with that account number. " << endl; 
				trigger++;
				break;
			}

		} 
	   if(trigger == 0)
	   {
		   cout << "Enter the customer's name in the format Last Name, First Name, Initial.: " << endl;
		   cin.ignore(1000, '\n');
		   getline(cin, temp.name);
		   cout << "Enter the customer's street address: " ;
		   getline(cin, temp.address1);
		   cout << "Enter the city the customer's from: " ;
		   getline(cin, temp.city);
		   cout << "Enter the state the customer's from: " ;
		   cin >> temp.state;
		   cout << "Enter the customer's zip code: " ;
		   cin >> temp.zipcode; 
		   cout << "Enter the customer's current balance: " ;
		   cin >> temp.balance ;
		   temp.totaltrans = 0;
		   account[total] = temp;
		   total ++ ;
	   }
	
	}
	else 
	{
		cout << "The customer file is full. A customer cannot be added." << endl;
	}

}
void remcustomer(customer account[], int &total)
{
	cin.ignore(10000, '\n');
	customer temp;
	char choice = 'A';
	int j = 0;
	
	cout << left << "To delete a customer, select from the following options. " << endl ;
	cout << left << "Press N to search by name." << endl;
	cout << left << "Press A to search by account number. " << endl;
	cin >> choice;
	

	if (choice == 'N' || choice == 'n')
	{
      cout << "Enter the name of the customer you wish to remove from the file: " << endl;
	  cin.ignore(10000, '\n');
	  getline(cin, temp.name);

	 for(int i = 0 ; i < total; i ++)
	 {
		if (account[i].name == temp.name)
		{
			cout << "The customer you wish to delete is " << account[i].name << endl;
			cout << "If this is correct, press Y. If not, press N." << endl;
			cin >> choice ;
			cin.ignore(10000, '\n');

		    if (choice == 'Y' || choice == 'y')
			{
				account[i] = account[total-1];
				total--;
				j++;
				cout << "Customer removed. " << endl;
				break;
			}
			
		}
		
	 }
	}
	else if (choice == 'A' || choice == 'a')
	{
		 cout << "Enter the account number of the customer you wish to remove from the file: " << endl;
	     cin >> temp.accountnum;

	for(int i = 0 ; i < total; i ++)
	{
		if (account[i].accountnum == temp.accountnum)
		{
			cout << "The customer you wish to delete is " << account[i].name << endl;
			cout << "If this is correct, press Y. If not, press N." << endl;
			cin >> choice ;
			cin.ignore(10000, '\n');

		    if (choice == 'Y' || choice == 'y')
			{
				account[i] = account[total-1];
				total--;
				j++;
				cout << "Customer removed. " << endl;
				break;
			}
		}
	}
	}
	else 
			cout << "No changes made. Returning to the main menu." << endl; 

}
void print(customer account[], int total)
{
	char choice;
	ofstream fout;
	string filename;

	cout << "Please select an option from the following menu." << endl;
	cout << "\t\t Press L to print in a page format." << endl;
	cout << "\t\t Press T to print in a table format." << endl;
	cout << "\t\t Press F to print in a table format to a file." << endl;
	cout << fixed << setprecision(2);
	cin >> choice;

	  if(choice == 'L' || choice == 'l')
	   {
		   for(int i = 0; i < total; i++)
		    {
				cout << setw(25) << left << "Name: " << setw(30) << left << account[i].name << endl ;
				cout << setw(25) << left << "Account Number: " << left <<"*****" << account[i].accountnum%10000 << endl ;
				cout << setw(25) << left << "Balance: " << setw(10) << left << account[i].balance << endl ;
				cout << setw(25) << left << "Address: " << setw(20) << left << account[i].address1 << endl;
	            cout << setw(25) << " " << left << account[i].city << " " << account[i].state << " " << account[i].zipcode << endl << endl << endl;
                cout << setw(73) << setfill('*') << " " << endl << setfill(' ') << endl;   
		   }
				
	   }
	  else if(choice == 'T' || choice == 't')
	   {
		 cout << setw(30) << left << "Name" << setw(30) << left << "Account Number" << setw(10) << left << "Balance" << endl ;
		 for(int i = 0; i < total; i++)
		 cout << setw(30) << left << account[i].name << left <<"*****" << account[i].accountnum%10000<< setw(21) <<"" << "$" << account[i].balance << endl;
	   }
	  else if(choice == 'F' || choice == 'f' )
	   {
		   cin.ignore(10000, '\n');
		   cout << "Please enter the location you wish to save the data to: " << endl;
	       getline(cin, filename);
	       fout.open(filename.c_str());

		   fout << setw(30) << left << "Name" << setw(30) << left << "Account Number" << setw(10) << left << "Balance" << endl ;
		 
		 for(int i = 0; i < total; i++)
		   fout << setw(30) << left << account[i].name << left <<"*****" << account[i].accountnum%10000<< setw(21) <<"" << "$" << account[i].balance << endl;
		   
	   }
	  else
	  {  
		  cout << "Choice invalid. Returning to the main menu. " << endl;
	  }

	}
void withdraw(customer account[], int total)
{
	customer temp;
	float temp2 = 0;
	int j = 0;
	char choice = 'z';

   cout << left << "Press N to search by name." << endl;
	cout << left << "Press A to search by account number. " << endl;
	cin >> choice;
	cin.ignore(1000, '\n');

	if (choice == 'N' || choice == 'n')
	{
		cout << left << "Enter your name in the format Last Name, First Name, Initial.:" <<endl ; 
		getline(cin, temp.name);

	for(int i=0; i < total; i++)
	  {
		  if (account[i].name == temp.name)
		  {
			  cout << fixed << setprecision(2) << "Your current account balance is: " << account[i].balance << "." << endl;
			  if (account[i].balance == 0)
			  {
				  cout << "Please make a deposit before trying to make a withdrawal." << endl;
				  j++;
				  break;
			  }
			  cout << "How much do you wish to withdraw? " << endl;
			  cin >> temp2 ;
			  if (temp2 <=0 || !cin)
			  {
				  cout << "Amount entered invalid. " << endl;
				  j++;
				  break;
			  }
			  if (temp2 > account[i].balance)
			  {
				  cout << "Insufficient funds. " << endl; 
				  j++;
				  break;
			  }
			  account[i].balance = account[i].balance - temp2;
			  account[i].transhist[account[i].totaltrans] = -temp2; 
			  account[i].totaltrans += 1;
			  cout << "Your remaining balance is: " << account[i].balance << endl ;
			  j++;
			  break;
		  }
	   }

	}
	else if (choice == 'A' || choice == 'a')
	{
		cout << left << "What is your account number? " ; 
		cin >> temp.accountnum;
	
	for(int i=0; i < total; i++)
	  {
		  if (account[i].accountnum == temp.accountnum)
		  {
			  cout << fixed << setprecision(2) << "Your current account balance is: " << account[i].balance << endl;
			  if (account[i].balance == 0)
			  {
				  cout << "Please make a deposit before trying to make a withdrawal." << endl;
				  j++;
				  cin.clear();
				  break;
			  }
			  cout << "How much do you wish to withdraw? " << endl;
			  cin >> temp2 ;
			  if (temp2 <=0 || !cin)
			  {
				  cout << "Amount entered invalid. " << endl;
				  j++;
				  cin.clear();
				  break;
			  }
			  if (temp2 > account[i].balance)
			  {
				  cout << "Insufficient funds. " << endl; 
				  j++;
				  break;
			  }
			  account[i].balance = account[i].balance - temp2;
			  account[i].transhist[account[i].totaltrans] = -temp2; 
			  account[i].totaltrans += 1;
			  cout << "Your remaining balance is: " << account[i].balance << endl ;
			  j++;
			  break;
		  }
	   }
    if (j == 0)
		  { 
			  cout << "No account found by that account number. Returning to the main menu." << endl; 
		  }
	}
	else
	{
		cout << "Choice invalid. Returning to the main menu. " << endl;
	}
}
void deposit(customer account[], int total)
{
	cin.ignore(10000, '\n');
	customer temp;
	float temp2 = 0;
	char choice = 'z';

    cout << left << "Press N to search by name." << endl;
	cout << left << "Press A to search by account number. " << endl;
	cin >> choice;
	cin.ignore(1000, '\n');

	if (choice == 'N' || choice == 'n')
	{
		cout << left << "Enter your name in the format Last Name, First Name, Initial.:" << endl ; 
		getline(cin, temp.name);

	   for(int i = 0; i < total; i++)
	   {
		 if(account[i].name == temp.name)
		 {
			 cout << fixed << setprecision(2) << "Your current balance is: " << account[i].balance << "." << endl;
			 cout << "How much do you wish to deposit?" << endl;
			 cin >> temp2 ;
			 if (temp2 <= 0 )
			 {
				 cout << "Amount entered invalid. " << endl;
				 break;
			 }
			 if (!cin)
			  {
				  cout << "Amount entered invalid. " << endl;
				  cin.clear();
				  break;
			  }
			 account[i].balance += temp2;
			 account[i].transhist[account[i].totaltrans] = +temp2; 
			 account[i].totaltrans += 1;
			 cout << "Your new balance is: " << account[i].balance << endl;
			 break;
		 }
	   }
	}
	else if (choice == 'A' || choice == 'a')
	{
		cout << left << "What is your account number?" ; 
		cin >> temp.accountnum;

		for(int i = 0; i < total; i++)
	   {
		 if(account[i].accountnum == temp.accountnum)
		 {
			 cout << fixed << setprecision(2) << "Your current balance is: " << account[i].balance << "." << endl;
			 cout << "How much do you wish to deposit?" << endl;
			 cin >> temp2 ;
			 if (temp2 <= 0 )
			 {
				 cout << "Amount entered invalid. " << endl;
				 break;
			 }
			 if (!cin)
			  {
				  cout << "Amount entered invalid. " << endl;
				  cin.clear();
				  break;
			  }
			 account[i].balance += temp2;
			 account[i].transhist[account[i].totaltrans] = +temp2; 
			 account[i].totaltrans += 1;
			 cout << "Your new balance is: " << account[i].balance << endl;
			 break;
		 }
		 
	   }
	}
		 else 
	      {
		     cout << "No account. Returning to the main menu. " << endl;
	      }
		
}
void sort(customer account[], int total)
{
	customer temp;
	char choice;
	bool flag;

	cout << "Please select from the following menu: " << endl;
	cout << "\t\t Press N to sort by name. " << endl;
	cout << "\t\t Press B to sort by balance." << endl; 
	cin >> choice ;

	if (choice == 'N' || choice == 'n') 
	{
	 do 
	  {
		flag = false;
		for(int i = 0 ; i < total - 1; i++)
		if (account[i].name > account[i+1].name)
		{
			temp = account[i];
			account[i] = account[i+1];
			account[i+1] = temp;
			flag = true;
		}
	  }while(flag);
	  cout << "Names sorted! Returning to main menu." << endl;
		
	  
	}
	else if (choice == 'B' || choice == 'b') 
	{
	 do 
	  {
		flag = false;
		for(int i = 0 ; i < total - 1; i++)
		if (account[i].balance > account[i+1].balance)
		{
			temp = account[i];
			account[i] = account[i+1];
			account[i+1] = temp;
			flag = true;
		}
	  }while(flag);
	  cout << "Names sorted! Returning to main menu." << endl;
	}
}
void exit(customer account[], int total, string filename)
{
	string filename2; 
	ofstream  fout;

	fout.open(filename.c_str());
	if(fout.fail())
	{
		cout << "Enter file name where you wish to store this file. " << endl;
		cin.ignore(1000, '\n');
		getline(cin, filename2);
		fout.open(filename2.c_str());
	}
	for(int i = 0 ; i < total; i++)
	{
	   fout << account[i].name << endl;
	   fout << account[i].address1 << endl;
	   fout << account[i].state ;
	   fout << " " << account[i].zipcode ;
	   fout << " " << account[i].city << endl;
	   fout << account[i].accountnum ;
	   fout << " " << account[i].balance << endl;
	}
}	
void statement(customer account[], int total)
{
	char choice = 'Z';
	customer temp;
	int  trigger = 0;

	cout << left << "Press N to search by name." << endl;
	cout << left << "Press A to search by account number. " << endl;
	cin >> choice;
	cin.ignore(1000, '\n');

	if (choice == 'N' || choice == 'n')
	{
		cout << left << "Enter the your name in the format Last Name, First Name, Initial.:" <<endl ; 
		getline(cin, temp.name);

		for(int i=0; i < total; i++)
	  {
		  if (account[i].name == temp.name)
		  {
			  if (account[i].totaltrans > 0 )
			  {
				  cout << setw(30) << left << "Name" << setw(30) << left << "Account Number" << setw(19) << left << "Transaction History" << endl ;
				  cout << setw(30) << left << account[i].name << setw(30) << left << account[i].accountnum << "$" << setw(10) << account[i].transhist[0] << endl;
				  trigger ++;
				  for( int j = 1; j < account[i].totaltrans; j++)
					  cout << setw(60) << " " << "$" << account[i].transhist[j] << endl;
				  cout << endl;
				  break;
			  }
			  else if (account[i].totaltrans == 0)
			  {
				  cout << "This customer has no transaction history. " << endl << endl;
				  trigger ++;
				  break;
			  }
		  }
	  }
   		  if ( trigger == 0)
		  {
			  cout << left << "No customer found with that name. " << endl; 
			  
		  }


	}

	else if (choice == 'A' || choice == 'a')
	{
		cout << left << "What is your account number: " ; 
		cin >> temp.accountnum;
		
		for(int i=0; i < total; i++)
	  {
		  if (account[i].accountnum == temp.accountnum)
		  {
			  if (account[i].totaltrans > 0 )
			  {
				  cout << setw(30) << left << "Name" << setw(30) << left << "Account Number" << setw(19) << left << "Transaction History" << endl ;
				  cout << setw(30) << left << account[i].name << setw(30) << left << account[i].accountnum << "$" << setw(10) << account[i].transhist[0] << endl;
				  trigger ++;
				  for( int j = 1; j < account[i].totaltrans; j++)
					  cout << setw(60) << " " << "$" << account[i].transhist[j] << endl;
				  cout << endl;
				  break;
			  }
			  else if (account[i].totaltrans == 0)
			  {
				  cout << "This customer has no transaction history. " << endl;
				  trigger ++;
				  break;
			  }
		  }
	  }
	if (trigger == 0)

		  {
			  cout << left << "No customer found with that account number. " << endl; 

		  } 
	}  
	else 
	{
		cout << left << "Choice invalid. Returning to the main menu. " << endl;
	}
}
void menu(customer account[], string &filename, char &choice, int &total, ifstream &fin)
{
	  while(choice != 'X' && choice != 'x')
    {
		if(choice == 'O' || choice == 'o')
		{
		   if (openfile(fin, filename))
			{
			   cout << "File found! Returning to the Main Menu. " << endl;
               total = readfile(account, fin);
			}
			else
			{
				cout << " No file found! Please check your file location and try again." << endl;
			}
		 }
		if (total > 0)
		{
		 if(choice == 'A' || choice == 'a')
		 {
			 addcustomer(account, total);
		 }
		 if(choice == 'R' || choice == 'r')
		 {
			 remcustomer(account, total);
		 }
		 if(choice == 'P' || choice == 'p')
		 {
			 print(account, total);
			 
		 }
		 if(choice == 'W' || choice == 'w')
		 {
			 withdraw(account, total);
		 }
		 if(choice == 'D' || choice == 'd')
		 {
			 deposit(account,total);
		 }
		 if(choice == 'S' || choice == 's')
		 {
			 sort(account, total);
		 }
		 if(choice == 'V' || choice == 'v')
		 {
			 statement(account, total);
		 }
		}
		else 
			cout << "No file to read from or the file was empty. Please select a file first." << endl << endl ;

		    cin.clear();
			instructions(choice);
			
    }
	

	   exit(account, total, filename);

 

   cout << "Thank you for using this program. Happy Holidays." << endl;

}
