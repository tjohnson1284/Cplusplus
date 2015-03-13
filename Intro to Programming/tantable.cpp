/*
*	Programmer:	Terrence Johnson
*	Due Date:	Oct. 26, 2011
*	Lab Section:	0106
*
Problem: 
	Develop a solution to generate a tangent table.

Analysis: 
	1)	Formula: radian conversion. a * pi/180
	2)	Units to use : 	none
	3)	table should terminate when numbers outside of the range 0 to 89.9
	4)  Use loops to make the table print properly and request new numbers until the user terminates it.
	5.  Set the precision to use no more than five digits.
	

Design: 
	1)	Input
		a.	grab input values from the users. if the input is not a number or the numbers are entered in the incorrect order, 
		    close the program with an error message.
	2)	Process
		a. Create a loop to govern the table repetition with a reset at the bottom that rechecks if the numbers are in range
		   and in the proper order. Also include the formatting in this loop. Fixed notation, set precision to four digits. 
		b. Create a second loop to govern the table generation from the first given number to the last number. 
		c. Create a third loop to do the calculations to produce the tangent values. To deal with the five significant values
		   issue, use an if statement to change the precision to three once the tangent value exceeds 10. Have this loop print
		   the values. 

*/
//   Implementation: Converting the algorithm to C++.
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main () 
{
double min, max, pi, rad, radconver, tanvalue; 
int counter;
counter = 0;
pi = 3.14159;
radconver = pi/180;

cout << "This program will generate tables of tangents." << endl;

cout << "Enter a number >= 90 or < 0, or numbers in the wrong order to terminate." << endl ; 

cout << "***" << setw(7) << "***" << setw(7) << "***" << setw(7) << "***" << setw(7) << "***" << setw(7) << "***" << setw(7) << "***"
	<< setw(7) << "***" << setw(7) << "***" << setw(7) << "***" << setw(7) << "***" << endl;

cout << "Enter minimum and maximum values for left column of table: "; cin >> min >> max;

if (!cin || min > max || min < 0 || max >= 90)
{ 
	cout << "Invalid input, table generation will not occur." << endl << endl;

return 0;
}



//processing
while ( min >= 0 && max < 90 )
{

min = ((int)((min*10)+0.5))/10.0;
if (max <= .05)
{
	max = ((int)(max*10))/10.0;
}

max = ((int)((max*10)+0.5))/10.0;	


cout << setw(11) << "0" << setw(7) <<"1" << setw(7) << "2" << setw(7) << "3" << setw(7) << "4" << setw(7) << "5" << 
		setw(7) << "6" << setw(7) << "7" << setw(7) << "8" << setw(7) << "9" <<endl;
	
cout << setfill('-')<< setw(80)<<" " << setfill(' ');

	while (min <= max + 0.1  && min < 90 )
	{
	 
		

		cout <<fixed << showpoint<<setprecision(1) << min << " |" <<setprecision(4);
		while (counter <= 9)
		{
			rad = min*radconver;
			tanvalue = tan(rad);
			if ( tanvalue > 1000)
			{ 
				cout<<setprecision(1);
			}
			else if ( tanvalue > 100)
			{
				cout<<setprecision(2);
			}
			else if (tanvalue > 10)
			{
				cout<<setprecision(3);
			}
			cout << setw(1) << " " << fixed << showpoint << tanvalue ;
			
			min = min + .01;
			counter++;
			
			
			
		}
		cout << endl;
		cout << setprecision(1);
		counter = 0;
		
		
	}

cout << setfill('-')<< setw(80)<<" " << setfill(' ') << endl;
cout << "***" << setw(7) << "***" << setw(7) << "***" << setw(7) << "***" << setw(7) << "***" << setw(7) << "***" << setw(7) << "***"
	<< setw(7) << "***" << setw(7) << "***" << setw(7) << "***" << setw(7) << "***" << endl;
cout << "Enter minimum and maximum values for left column of table: "; cin >> min >> max;

if(!cin || min > max || min < 0 || max >= 90)
{
	cout << "Table generation has been halted. "<<endl ;

return 0;
}

}
return 0;
}
