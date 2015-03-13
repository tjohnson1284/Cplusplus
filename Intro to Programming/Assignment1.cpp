/*
*	Programmer:	Terrence Johnson
*	Due Date:	Oct. 4, 2011
*	Lab Section:	0106
*
Problem: 
	Develop a solution and write a C++ program to compute the force of repulsion between two similarly charged
given their charges and the distance between them.

Analysis: 
	1)	Formula: 8.988*10^9 or Coulomb * ChargedParticle1 * Charged Particle2 all divided by the distance(r)^2
	2)	Units to use : 	Newton
	3)	output format : Initially print with with 5 digit precision in fixed format and again in scientific notation with 3 digit precision
	4)	Obtain Distance and particle charges from user.
	

Design: 
	1)	Input
		a.	Prompt user distance(r),chargedparticle1(q1), and chargedparticle2(q2) 
	2)	Process
		a.	Force = 8.988*10^9(newton)*chargedp1*chargedp2/r^2
	3)	Output
		a.	Set precision to 5, fixed notation and left justification
		b.	Print result with labels and unit of measurement
		c.	Set precision to 3, set to scientific notation, left justification
		d.	Print result again with labels and unit of measurement
*/
//   Implementation: Converting the algorithm to C++.
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
int main () {
	float chargedp1, chargedp2, distance;
	float Force;
	const float coulomb=8.988 * pow(10.0, 9);  

	//Input
	cout<<"\t\t\t Welcome to the Coulomb's Law Program!" << endl << endl;
	cout<<"Please enter the charge level of the first particle: "; cin>>chargedp1; cout<<endl;
	cout<<"Please enter the charge level of the second particle: "; cin>>chargedp2; cout<<endl;
	cout<<"Please enter the distance between the two particles: "; cin>>distance; cout<<endl;

	//Processing
	Force = (coulomb * chargedp1 * chargedp2)/(pow(distance,2));

	//Output
	cout<< fixed << setprecision(5) << left << endl;
	cout << setfill('*')<< setw(73)<<" " << setfill(' ') << "\n*" <<right <<setw(73)<<"*"<< left << endl;
	cout <<"* \t\t\t  Fixed Notation \t\t\t\t *" << endl;
	cout << setw(10) << "* The charge level of the first particle: " << setw(8) << " " << chargedp1 << " coulombs." << setw(8) <<"\t *"<< endl;
	cout << setw(10) << "* The charge level of the Second particle: " << setw(7) << " " << chargedp2 << " coulombs." << setw(8) <<"\t *"<< endl;
	cout<< setw(10) <<"* Your fixed results are: "<< setw(24) << " " << Force << " newt."<< setw(5) <<" *"<< endl;
	cout << setfill('*')<< setw(73)<<'*'<<"*"<<endl << endl << endl;
	cout<< scientific << setprecision(3) << left;
	cout << setfill('*')<< setw(73)<<" " << setfill(' ') << "\n*" <<right <<setw(73)<<"*"<< left << endl;
	cout <<"* \t\t\t  Scientific Notation \t\t\t\t *" << endl;
	cout << setw(10) << "* The charge level of the first particle: " << setw(8) << " " << chargedp1 << " coulombs." << setw(8) <<"\t *"<< endl;
	cout << setw(10) << "* The charge level of the Second particle: " << setw(7) << " " << chargedp2 << " coulombs." << setw(8) <<"\t *"<< endl;
	cout<< setw(10) <<"* Your results in scientific not. are: "<< setw(11) << " " << Force << " newt."<< setw(5) <<"\t *"<< endl;
	cout << setfill('*')<< setw(73)<<'*'<<"*"<<endl<<endl;








return 0 ; 
}
