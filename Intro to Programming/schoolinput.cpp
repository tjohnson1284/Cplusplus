/*
*	Programmer:	Terrence Johnson
*	Due Date:	Nov. 8, 2011
*	Lab Section:	0106
*
Problem: 
	

Analysis: What do we need to do the job? (Specifications)
	1)	User info obtained via file input from user
	2)	Output sent to file designated by user. 

	

Design: How do get the job done?  (Algorithm)
1. Bring in the ability to take file input and output, strings, input/output, and formatting

2. declare variables. You'll need a three strings and floats to deal with averages and scores and int for the test number, any counters used and bad score tracking.

3. bring in data from user defined files

4. let user define where the file will be output

5. Print the instructions via the instruction function and pull in the first name via a string

6. declare the first loop with conditions to read to the end of the file a with reset condition 
   to pull in another name.

7. before the reset, add fin.ignore(1000, '\n') to prevent bad data being added to the name string

8. inside the first loop,  then bring in the first score. Create astatement incase there are no scores for the first student represented by -1 being read first. 
   if no scores are available, print the name and inform the user that there were no scores that student.

9. create a second loop with a condition to go until score != -1. 

10. Inside that loop, add the score to a variable, use a counter to track the score being added and request a new score

11. if the score is above 100 or below 0, use two bad score trackers to track if it is above 100 or below 0.

12. Outside of the second loop divide the total of scores by the amount of scores to find the average. Set the test number to be equal to the counter. 
    add the average to a variable to track the class average.

13. Based on the average, assign a grade. if < 90, assign an A. If < 80  and <=90, assign a B. 
    if <67.5 and < 80, assign a c. if <55 and <= 67.5, assign a D. If <=0 and <=55, assign an F.

14. Inside the if statements assigning grades, print the student's name, number of tests processed, their average score, and what grade they got. 

15. After use a variable to track the students processed and reset all variables used besides the class average

16. Once all scores are processed or the end of the file is reached, inform the user of the class average by dividing it by the number of students processed.

17. If any bad scores were processed, inform the user what kind of scores they were. 18. close the file input and output.

18. add the used function to the end of the file.

*/
//   Implementation: Converting the algorithm to C++.






#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
void instructions(void);     //prototype function
int main () {

	string full_name, file_name, class_name;
	float score = 0, average = 0, class_average = 0, total_score = 0;
	int test_number = 0, counter = 0, bad_score1 = 0, bad_score2 = 0, students = 0; 
	char grade = 'F'; 
	ifstream fin;
	ofstream fout;
	

	cout << "Enter the location of the file you wish to process: "; 
	cin >> file_name;
	fin.open(file_name.c_str());
	if (fin.fail())
	{	
		cout << "Bad file or bad file location." << endl;
	
	}
	else 
	{
		cout << "Enter output file name and where you wish to save it: " ; 
		cin >> file_name;
		fout.open(file_name.c_str());
		getline(fin, class_name);
        cout << endl;
		cout << setw(20) << " " << "Grade report for " << class_name << endl << endl;
		instructions();
		fout << setw(20) << " " << "Grade report for " << class_name << endl << endl;
		fout << "This program will process test scores to provide individuals with letter grades according to the following scale: " << endl << endl;
		fout << setw(30) << " " <<  "90   < Average           A" << endl;
		fout << setw(30) << " " <<  "80   < Average  <=  90   B" << endl;
		fout << setw(30) << " " <<  "67.5 < Average  <=  80   C" << endl;
		fout << setw(30) << " " <<  "55   < Average  <= 67.5  D" << endl; 
		fout << setw(30) << " " <<  "0    < Average  <= 67.5  F" << endl << endl;
	
		fout << setw(18) << left << "Name"  << setw(23) << left << "Number of Tests" << setw(21) << "Average" << setw(5)  << left << "Grade" << endl; 
		fout << setfill('-') << setw(73) << " " << setfill(' ') << endl;
		
		
		getline(fin, full_name);
		while (!fin.eof())
		{

			fin >> score;
			
			if (score == -1)
			{
				cout << setw(25) << left << full_name << setw(5) << left << test_number << setw(18) << left << "There were no scores to process for this student." << endl;   
				fout << setw(25) << left << full_name << setw(5) << left << test_number << setw(18) << left << "There were no scores to process for this student." << endl; 
			}
			else
			{
			while (score != -1)
			{
				if (score < 0)
				{ 
					bad_score1 ++; 
				}
				
				else if (score > 100)
				{
					bad_score2 ++;
				}

				if (score >= 0 && score <=100)
				{ 
					total_score += score;
					counter ++; 
				}

				fin >> score;
			}
				average = total_score/counter;
				test_number = counter;
				class_average = class_average + average;
				if (average > 90 )
				{ 
				   grade = 'A'; 
				}
				else if (average > 80 && average <= 90)
				{ 
					grade = 'B'; 
				
				}
				else if (average > 67.5 && average <= 80)
				{ 
					grade = 'C';
				}
				else if (average > 55 && average <= 67.5)
				{ 
					grade = 'D';
				}
				else if (average >= 0 && average <= 55)
				{ 
					grade = 'F';
				}
				cout << setw(25) << left << full_name << setprecision(3) << setw(18) << left  << test_number 
					 << setw(20) << left  << average << left << setw(15) << grade << endl;
				fout << setw(25) << left << full_name << setprecision(3) << setw(18) << left  << test_number 
						<< setw(20) << left  << average << left  << setw(15) << grade << endl;
				students ++;
				counter = 0;
				total_score = 0;
				test_number = 0;
				average = 0;
				
			}
			fin.ignore(10000, '\n');
			getline(fin, full_name);
			cout << endl;
		}
		if (class_average > 0) 
		{
			cout << class_average;
			class_average = class_average/students;
			cout << setfill('-') << setw(73) << " " << setfill(' ') << endl;
			fout << setfill('-') << setw(73) << " " << setfill(' ') << endl;
			cout << "The class average is: " << class_average << " out of " << students << " students." << endl;
			fout << "The class average is: " << class_average << " out of " << students << "students." << endl;
		}
		if (bad_score1 > 0)
		{
			cout << endl ; 
			cout << setw(10) << left << "There were " << left << bad_score1 << setw(30) << left <<  " scores under 0 that were not the control number -1." << endl 
			<< "Please check your provided scores. " << endl;
		}
		if(bad_score2 > 0)
		{
			cout << endl ;
			cout << setw(10) << left << "There were " << left <<  bad_score2 << setw(30) << left <<  " scores over 100. Please check your provided scores. " << endl;
		}

		else if (class_average == 0)
		{
			cout << endl;
			cout << setw(40) << left << "There were no scores present in this file to process. Please check the file you wish to process and try again. " << endl << endl ;

			return 0;
		}

	}
	
return 0;
}

// functions
void instructions(void) 
{       cout << "This program will process test scores to provide individuals with letter grades according to the following scale: " << endl << endl;
		cout << setw(30) << " " <<  "90   < Average           A" << endl;
		cout << setw(30) << " " <<  "80   < Average  <=  90   B" << endl;
		cout << setw(30) << " " <<  "67.5 < Average  <=  80   C" << endl;
		cout << setw(30) << " " <<  "55   < Average  <= 67.5  D" << endl; 
		cout << setw(30) << " " <<  "0    < Average  <= 67.5  F" << endl << endl;
		
		cout << setfill('=') << setw(73) << " " << setfill(' ') << endl;
		cout << setw(18) << left << "Name"  << setw(23) << left << "Number of Tests" << setw(20) << "Average" << setw(5)  << left << "Grade" << endl; 
		cout << setfill('-') << setw(73) << " " << setfill(' ') << endl;
return; 
}