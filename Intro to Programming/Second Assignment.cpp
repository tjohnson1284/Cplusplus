/*
*	Programmer:	Terrence Johnson
*	Due Date:	Oct. 18, 2011
*	Lab Section:	0106
*
Problem: Develop a program to read, verify, and print a solution, provided a non zero leading coefficient.
	

Analysis: What do we need to do the job? (Specifications)
	1)	Formula: First: -B+sqrt(B^2-4AC)/2A  Second: -B-sqrt(B^2-4AC)/2A. 
			 Also use the discriminant formula: B^2-4AC to determine number and type
 			 of solutions to provide. If the formula = 0, 1 real solution, if < 1, two real solutions, 
                         if >0 two imaginary solutions
	2)	Units to use : none specified
	3)	output format : Scientific notation, 4-digit precision with two real solutions, one real solution or
                		two imaginary solutions
	4)	User Obtained Info: Values for the three variables A, B, and C
	

Design: How do get the job done?  (Algorithm)
	1)	Input 
		a. Greet user
		b. Prompt user for the variables a, b, and c	 
	2)	Process
		a. Check to make sure A is not zero, if it is, provide feedback saying so and close the program
		b. Use the discriminant formula to find the number of solutions, if one real solution, use one formula. If two real solutions, use both formulas. 
		c. If discriminant is negative, separate the problems into two equations. The first equation equal to -B/2a and the second equal to the discriminant/2a.
		   before computing the second equation, multiply the discriminant by negative 1 and provide a stored variable slot for each answer.
        d. If the discriminant is positive, separate the problems into two equations, use both formulas and provide a variable for each answer.
	3)	Output
		a. inform the user of how many solutions resulted	
		b. provide the answers for resulting solutions in scientific notation with 4 digit precision.
		c. If printing imaginary solutions, include that the second equation is multiplied by I
		d. close the program.
			
*/
//   Implementation: Converting the algorithm to C++.


#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
int main () {

	float variable_a, variable_b, variable_c;
	float first_solution, second_solution, solutionpt1, solutionpt2;
	float discriminant,  divisor;
//Input

cout<<"\t\t\t Welcome to the Quadratic Equation Solver." << endl << endl; 
cout<<"\nThis program will solve equations in the form of Ax^2 + Bx^2 + Cx^2."<< endl <<"\nA, B, and C must be real numbers and A cannot be equal to zero."<< 
endl << "\nYou can also enter 0 or a letter to end the program."<< endl;
cout<<"\n\nPlease enter your value for A: "; cin>>variable_a;
if(variable_a == 0)
{
	cout<< endl << "You entered "<<variable_a<<". The A variable cannot be equal to 0. Please try again."<<endl;
	return 0;
}
else if (!cin)
{
	cout << endl << "You entered an invalid character. Please try again with a valid number" <<endl;
	return 0;
}
cout<<"\nPlease enter your value for B: "; cin>>variable_b;

if (!cin)
{
	cout << endl << "You entered an invalid character. Please try again with a valid number" <<endl;
	return 0;
}
cout<<"\nPlease enter your value for C: "; cin>>variable_c;

if (!cin)
{
	cout << endl << "You entered an invalid character. Please try again with a valid number" <<endl;
	return 0;
}

//Processing
discriminant = (pow(variable_b*1.0, 2) - 4*variable_a*variable_c);
divisor = 2*variable_a;

if(discriminant == 0)
{
	first_solution = -variable_b/divisor + sqrt(discriminant)/ divisor; 
	cout << scientific << setprecision(4) <<"\nYour one real solution is: \t" <<setw(10) << " "  << first_solution << endl <<endl;
	return 0; 
}
else if (discriminant < 0)
{
solutionpt1 = -variable_b/divisor;
discriminant=discriminant*-1;
solutionpt2 = sqrt(discriminant)/divisor;
cout << scientific << setprecision(4) << "\nYour first imaginary solution is: \t" <<setw(10) << " " << solutionpt1 << " + " << solutionpt2 <<"*I " << endl 
	<< "\nYour second imaginary solution is: \t" << setw(10) << " " << solutionpt1 << " - " << solutionpt2 << "*I "<< endl << endl;
return 0;
}
else if (discriminant > 0)
{
	first_solution = -variable_b/divisor + sqrt(discriminant)/divisor;
	second_solution = -variable_b/divisor - sqrt(discriminant)/divisor;
	cout << scientific << setprecision(4) <<"\nYour first real solution is: \t" <<setw(10) << " " << first_solution << endl 
	<< "\nYour second real solution is: \t" <<setw(9) << " " << second_solution << endl;
	return 0;
}




return 0 ; 
}
