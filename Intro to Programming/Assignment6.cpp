/*
*	Programmer:	Terrence Johnson
*	Due Date:	Nov. 29, 2011
*	Lab Section:	0106
*
Problem: Create a program will read a series of test scores from a file and stores them in an array. It will then prompt user for the 
cut-off points for an A,B,C,D and store them in another array. It will print the max score, the min score, and the average score to the monitor.
Finally, it will print a histogram to the monitor and a file (prompt user for file name) for the distribution of letter grades
	

Analysis: What do we need to do the job? (Specifications)
   4)	User Obtained Info: Scores from a user submitted text document, grade cutoffs from user input.
	

Design: How do get the job done?  (Algorithm)
1. declare four arrays to store the scores, store the user submitted grade cut offs, store the amount of each grade and the final one
   to store grade characters.

2. declare a variable to control the size of the array storing the scores. 

3. declare variables to control the score array, to store the average, max/min scores and the total scores processed.

4. Pull in the file chosen by the user. Use a loop to read the scores into an array. 
   Make sure to check and make sure the array isn't full and return the total scores processed. *function*

5. Using the scores array, use if statements to find the max and min of the scores and return them to main. *function*

6. Prompt the user for the limits to each grade and store the results in an array. *function*

7. Use the scores array and the total scores processed and find the average of the class using a 
   loop to add each score. *function*

8. fill in the characters for the grade character array. Should be A, B, C, D, F.

9. using the scores array, grade array from number 6, the array to check the grade amount, and the total scores, check how many scores fall within the 
   specified guidelines given by the user. *function*

10. Using the min/max variables, the average, the total scores processed, the amount of each grade array and the letter grade array, print 
    the class statistics, nicely formatted. Include a histogram to display the total amount of each grade. Also, copy all the printing
    to the screen and to a file. 

11. In main, call the first function and store the the returned total in the total variable. 

12. check to make sure the file isn't empty, then call the functions in order. Make sure to store the average function in the average variable
    or pass the average back via pass by reference. 

13. After all the functions have been called, end the program. 
*/
//   Implementation: Converting the algorithm to C++.

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;
int scores(float nums[],int &badscores, int size);
void minmax(float &min, float &max, float nums[], float total);
void grades(float grade[]);
float avg(float total, float nums[]);
void totalgrades(float nums[], float grade[], int amount[], int total);
void statshisto(float min, float max, float average, float total, int amount[], char lettergrade[]);
void classgrade(char lettergrade[]);

int main ()
{
	
	float nums[100], average = 0, max = 0, min = 100, grade[4];
	int numsize = 100, badscores = 0, total = 0, amount[5];
	char lettergrade[5];
		

   total = scores(nums,badscores,numsize);
  
  if (total == 0)
   {
	   cout << " There were no scores to process. Please check your file and try again. " << endl ;

		 return 0;
   }
   else
   {
     minmax(min, max, nums, total);
     grades(grade);
     average = avg(total, nums);
     totalgrades(nums,grade,amount,total);
	 classgrade(lettergrade);
     statshisto(min, max, average, total, amount, lettergrade);

   }
		return 0 ; 
}


int scores(float nums[], int &badscores, int size)
{
	
	string filename; 
	int adv = 0;
	ifstream fin;

	cout << "Enter file location: " ;
	getline(cin, filename);
	fin.open(filename.c_str());
	if (fin.fail())
	{  
		cout << "No file found. " << endl ;
		return 0;
	}
	else
	{
	if (fin.eof()) 
	{
		cout << "Chosen file was empty." << endl ;
		return 0;
	} 

		fin >> nums[adv];
		while(!fin.eof())
		{ 
		
		  

		   if (nums[adv] < 0 || nums[adv] > 100)
		   { 
			   badscores ++;
			   adv++;
			   fin >> nums[adv];
            }
		   
		   adv++;
		  
		   if (adv == size)
			{
				cout << "Array is full. There may be scores left in the file. " << endl ;
				break ;
		   }
		   fin >> nums[adv]; 
		}
	
	return adv;	 
	}
}

void minmax(float &min, float &max, float nums[], float total)
{
		int adv = 0 ;

		while ( adv < total ) 
		{
			if (nums[adv] > max)
		    {
		      max = nums[adv];
		    }
		    if (nums[adv] < min)
		    {
		      min = nums[adv]; 
		    }
		adv++ ;
		}
		return; 
}

void grades(float grade[])
{
	int adv = 0 ;
	cout << left << setfill('=')<< setw(73)<<" " << endl ;
	cout << setprecision(40) << left << "Please enter the lowest score for an A: "  ;
	cin >> grade[adv];
	adv++ ;
	cout << setprecision(40) << left << endl << "Please enter the lowest score for a B: " ;
	cin >> grade[adv];
	adv++ ; 
	cout << setprecision(40) << left << endl << "Please enter the lowest score for a C: " ;
	cin >> grade[adv];
	adv++ ;
	cout << setprecision(40) << left << endl << "Please enter the lowest score for a D: " ;
	cin >> grade[adv];
	return;
}

float avg(float total, float nums[])
{
	float score = 0, average = 0 ; 

	for ( int adv=0; adv < total; adv++)
	{ 
		score += nums[adv];
	}
   average = score/total;
   return average;
}
void classgrade(char lettergrade[])
{
	lettergrade[0] = 'A';
	lettergrade[1] = 'B';
	lettergrade[2] = 'C';
	lettergrade[3] = 'D';
	lettergrade[4] = 'F';
}
		
void statshisto(float min, float max, float average, float total, int amount[], char lettergrade[])
{
	string file_name;
	int adv = 0, i;
	ofstream fout;
	
	
	cout << "Enter output file name and where you wish to save it: " ; 
	cin >> file_name;
	fout.open(file_name.c_str());
	
	
	cout << endl << endl << "\t \t CLASS STATISTICS" << setprecision(4) << setfill(' ') << endl ; 
	cout << " \t\t ~~~~~ ~~~~~~~~~~" << endl;
	cout << setw(16) << "Max Score: " << setw(5) << " " << setw(3) << max << endl ; 
	cout << setw(16) << "Min Score: " << setw(5) << " " << setw(3) << min << endl ;
	cout << setw(16) << "Average: " << setw(5) << " " << setw(3) << average << endl;
	cout << setw(16) << "Number of Scores: " << setw(3) << " " << setw(3) << total << endl << endl; 
    cout << " \t \t Distribution of Grades" << endl << endl;
	
	fout << endl << endl << "\t \t CLASS STATISTICS" << setprecision(4) << setfill(' ') << endl ; 
	fout << " \t\t ~~~~~ ~~~~~~~~~~" << endl;
	fout << setw(16) << left << "Max Score: " << setw(5) << " " << setw(3) << max << endl ; 
	fout << setw(16) << left << "Min Score: " << setw(5) << " " << setw(3) << min << endl ;
	fout << setw(16) << left << "Average: " << setw(5) << " " << setw(3) << average << endl;
	fout << setw(16) << left << "Number of Scores: " << setw(3) << " " << setw(3) << total << endl << endl; 
    fout << " \t \t Distribution of Grades" << endl << endl;
	
	while(adv < 5)
	{
		cout << " " << lettergrade[adv] << left << "'s ";
		
	    i=amount[adv];
		while (i > 5)
		{
		  if (i%5 == 0)
		   {
			  cout << "*****" << " " ;
			  fout << "*****" << " " ;
		   }
		  else if (i%5)
		   {
			  cout << "*****" << " " ;
			  fout << "*****" << " " ;
		   }
		   i=i-5;
		}
		 cout << left << setfill('*') << setw(i) << "" << " (" << amount[adv] << ")" << endl<< setfill(' ') ;
		 fout << left << setfill('*') << setw(i) << "" << " (" << amount[adv] << ")" << endl<< setfill(' ') ;
		  
	    i=0;
		adv++;
	}
	cout << left << setfill('-')<< setw(73)<<" " << endl ;
	cout << setfill(' ') << setw(5) << " " << setw(5) << "0" << setw(5) << "5" << setw(6) << "10" << setw(6) << "15" << setw(6) << "20" << setw(6) 
		<< "25" << setw(6) << "30" << setw(6) << "35" << setw(6) << "40" << setw(6) << "45" << setw(6) << "50" << endl << endl; 
	fout << left << setfill('-')<< setw(73)<<" " << endl ;
	fout << setfill(' ') << setw(5) << " " << setw(5) << "0" << setw(5) << "5" << setw(5) << "10" << setw(5) << "15" << setw(5) << "20" << setw(5) << "25" << setw(5) << "30" << setw(5) << "35" 
		<< setw(5) << "40" << setw(5) << "45" << setw(5) << "50" << endl << endl; 


}
void totalgrades(float nums[], float grade[], int amount[], int total)
{
	amount[0] = amount[1] = amount[2] = amount[3] = amount[4] = 0;
	
	for(int adv = 0; adv < total; adv++)
	{
		if (nums[adv] >= grade[0] && nums[adv] <= 100)
		{
			amount[0]++;
		}
	    if (nums[adv] >= grade[1] && nums[adv] < grade[0])
		{
			amount[1]++;
		}
		if (nums[adv] >= grade[2] && nums[adv] < grade[1])
		{
			amount[2]++;
		}
		if (nums[adv] >= grade[3] && nums[adv] < grade[2])
		{
			amount[3]++;
		}
		if (nums[adv] > 0 && nums[adv] < grade[3])
		{
			amount[4]++;
		}

	}
 


}