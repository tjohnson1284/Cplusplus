#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
int main () {
	int BREAD ;
	int CHEESE ;
	int PICKLE ;
	int MAYO ; 
	string FIRSTNAME;
	string LASTNAME ;
	int TotalCalories;
	int BreadCalories;
	int CheeseCalories;
	int MayonnaiseCalories;
	int PickleCalories;

	cout<<"/t/t/t/t Welcome to my Calorie Counter";
	
	cout << endl << endl;
	
	cout<< "Please enter your name:"; cin>>FIRSTNAME; cin>>LASTNAME; cout<<endl;
	
	cout<< "Hi ";cout<<FIRSTNAME; cout<<" "; cout<<LASTNAME;cout<<", please enter the number of ingredients used on your sandwich.";
	
	cout<<endl;cout<<endl;
	
	cout<<"Please enter number of slices of bread used (0 if not used): "; cin>>BREAD;
	
	cout<<"Please enter number of slices of cheese used (0 if not used): "; cin>>CHEESE;
	
	cout<<"Please enter amount of mayonnaise in grams used (0 if not used): "; cin>>MAYO;
	
	cout<<"Please enter number of pieces of pickle used (0 if not used): "; cin>>PICKLE;
	
	cout<<endl;cout<<endl;
	
	BreadCalories= BREAD*63;
	
	CheeseCalories=CHEESE*106;
	
	MayonnaiseCalories=MAYO*49;
	
	PickleCalories=PICKLE*25;
    
	TotalCalories=BREAD*63+CHEESE*106+MAYO*49+PICKLE*25;
	
	cout<<"\t\t Bread calories: \t\t" << BreadCalories <<endl;
	
	cout<<"\t\t Cheese calories: \t\t" << CheeseCalories <<endl;
	
	cout<<"\t\t Mayonnaise calories: \t\t";cout<<MayonnaiseCalories;cout<<endl;
	
	cout<<"\t\t Pickle calories: \t\t";cout<<PickleCalories;cout<<endl;cout<<endl;
	
	cout<<"\t\t Total calories: \t\t"; cout<<TotalCalories; cout<<endl;cout<<endl;
    
	cout<<"There were ";cout<<TotalCalories<<" calories in your lunch yesterday.";cout<<endl;
	
	cout<<"What is for lunch today? Funny!!!!";cout<<endl;cout<<endl;

return 0 ; 
}
