#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
int main () {

	int SCORE1;
	int SCORE2;
	int SCORE3;
	int QUIZSCORE;
	int ASSIGN; 
	int Test_Avg;
	int Average;
	string full_name;
	const double testscore=.6;
	const double progassign=.3;
	const double quizscore=.1;
//Input

	cout<<"Please provide your name full name, including any middle initial: "; getline(cin,full_name);
	cout<<"Please provide your first test score: ";cin>>SCORE1;cout<<endl;
	cout<<"Please provide your second test score: ";cin>>SCORE2;cout<<endl; 
	cout<<"Please provide your third test score: ";cin>>SCORE3;cout<<endl; 
	cout<<"Please provide your Programming Assignments score: ";cin>>ASSIGN;cout<<endl;
	cout<<"Please provide your quiz score: ";cin>>QUIZSCORE;cout<<endl;
	
//Process
	Test_Avg=(SCORE1+SCORE2+SCORE3)/3;
	Average= Test_Avg*testscore+QUIZSCORE*quizscore+ASSIGN*progassign;

//Output
	cout<<setprecision(2)<<showpoint<<left;
	cout<<setw(20);
	cout << setfill('_')<< setw(73)<<" " << setfill(' ') << "\n|" <<right <<setw(73)<<"|"<< left;
	cout<<endl; cout<<"|"<<setw(71)<<full_name<<" "<<"|"; cout<<endl;
	cout<<"|\t\t Your test scores are: "<< setw(17) <<" " << SCORE1 <<" " <<SCORE2 << " " <<SCORE3 <<"\t |"<< endl;
	cout<<"|\t\t Your average test score is: "<< setw(11) <<" "<<Test_Avg << "\t\t |" <<endl;
	cout<<"|\t\t Your quiz score is: "<< setw(19) <<" "<<QUIZSCORE << "\t\t |" <<endl;
	cout<<"|\t\t Your programming score is: "<< setw(12) <<" "<<ASSIGN << "\t\t |"<<endl;
	cout<<"|\t\t Your overall class average is: "<< setw(8) <<" "<<Average << "\t\t |"<< endl;
	cout << setfill('_')<< setw(73)<<'|'<<"|"<<endl;







return 0 ; 
}
