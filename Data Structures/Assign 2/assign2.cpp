/*
*	Programmer:	Terrence Johnson
*	Due Date:	Mar. 7, 2012
*	Lab Section:	0112
*
Description: This program adds, subtracts, multiplies and divides positive integers outside of the normal available range of the integer 
function using arrays. The maximum allowed digits is controlled by the const int declared at the beginning of the program.
	
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class BigInt{
	friend BigInt operator+(const BigInt &num1, const BigInt &num2);
	friend ostream& operator<<(ostream& os, const BigInt &num);
	friend bool AddBigInts(const BigInt&num1, const BigInt &num2, BigInt &sum);
	friend bool AddWithLongestFirst(const BigInt &longer, const BigInt &shorter, BigInt &sum);
	friend bool MultiBigIntbyDigit( const BigInt &num1, const BigInt &num2, int &counter, BigInt &product);
	friend bool MultiplyWithLongestFirst(const BigInt &num1, const BigInt &num2, int &counter, BigInt &product);
	friend BigInt operator*(const BigInt &num1, const BigInt &num2);

public:
	static const int MAX_DIGITS = 100; 
	BigInt();
	BigInt(const string &goodString);
	bool BigInt::ExtractGoodString(const string &input, string &output);
	bool ReadBigInt(istream &is = cin);
	void PrintBigInt(ostream &os = cout) const;
	
private:
	void StringtoBigInt(const string& goodString);
	int numdigits; 
	int digits[MAX_DIGITS];


};

void BigInt::StringtoBigInt(const string& goodString)
{
	//Purpose: Stores a valid string into an array and stores the number of digits into another field
	//Precondition: A valid string given
	//Postcondition: String entered into array, number of digits stored. 
	//----------------------------------------------------

	int length;

	length = goodString.length();


	for( int i = 0; i < length; i++)
		digits[length - i - 1] = goodString[i] - '0';

	numdigits = length;
	
}
BigInt::BigInt()
{
	//Purpose: Initializes the number of digits in a Big Integer.
	//Precondition: none
	//Postcondition: number of digits set to 0
	//-------------------------

	numdigits = 0; 
}
BigInt::BigInt(const string &goodString)
{
	//Purpose: Initializes a given string and sets it up to be stored
	//Precondition: A valid string given
	//Postcondition: String stored in given variable.

	StringtoBigInt(goodString);
}
bool BigInt::ExtractGoodString(const string &input, string &output)
{
	int length = input.length();

	for(int i = 0 ; i < length; i++)
	{
		if (input[i] == ' ')
		{ 
			/*if (input[i+1] == ' ')
			{
				
			}*/
			if (output.length() > 0 && input[i+1] >= '0' && input[i] <= '9' ) 
			{
				return false;
			}
		}

		else if (input[i] >= '0' && input[i] <= '9')
		{ 
			output += input[i] ;
		} 

		else 
			return false; 

	}
	return true;
}
bool BigInt::ReadBigInt(istream &is)
{
	// Purpose: Read and store a large integer.
    // Precondition: None.
	// Postcondition: Either
	// 1. Given number is valid and stored. True is returned.
	// or 2. Given number is invalid. False is returned.
	//---------------------------------------------

	string s1, s2;
	int length;
	
	getline(cin, s1);
	if(!ExtractGoodString(s1, s2))
	{
		return false; 
	}
	length = s2.length();
	if(length > MAX_DIGITS)
	{
		return false;
	} 
    StringtoBigInt(s2);

	return true;
}
void BigInt::PrintBigInt(ostream &os) const
{
	// Purpose: print a big integer.
	// Precondition: A valid big integer is entered.
	// Postcondition: Prints the big integer.
	//---------------------------------------------

	for (int i= 0 ; i < numdigits; i++)
		os << digits[numdigits - i - 1]; 
}

class OverFlowException
{
public:
	BigInt m_num1,m_num2;
	char m_op;
	OverFlowException(const BigInt& num1,const BigInt& num2, char op)
	{
		m_num1 = num1;
		m_num2 = num2;
		m_op = op;
	}
};
bool AddWithLongestFirst(const BigInt &longer, const BigInt &shorter, BigInt &sum)
{
	// Purpose: Adds given large integers with the longest first.
	// Precondition: Valid big integers given, big Integers in the correct order.
	// Postcondition: Either
	// 1. large integers added, stored in sum. True Returned
	// or 2. Overflow occurs. Returns false.
	//---------------------------------------------

	int carry = 0;
	sum.numdigits = 0; 

	for(int i = 0; i < shorter.numdigits; i++)
	{
		sum.digits[i] = longer.digits[i] + shorter.digits[i] + carry ;

		if(sum.digits[i] >= 10)
		{
			sum.digits[i] = sum.digits[i] - 10 ;

			carry = 1;
			sum.numdigits++;
		}

		else 
		{
			carry = 0; 
		    sum.numdigits++;
		}
	}

	for(int i = shorter.numdigits ; i < longer.numdigits; i++)
	{
		sum.digits[i] = longer.digits[i] + carry;

		if(sum.digits[i] >= 10)
		{
			sum.digits[i] = sum.digits[i] - 10 ;

			carry = 1;
			sum.numdigits++;
		}

		else 
		{
			carry = 0; 
	        sum.numdigits++;
		}
	}
	if (carry == 1) 
	{
		if (sum.numdigits < BigInt::MAX_DIGITS)
		{ 
			sum.digits[sum.numdigits] = 1;
			sum.numdigits ++;
			return true;
		} 
		else
			return false;
	}

	if (sum.numdigits > BigInt::MAX_DIGITS)
	{
		return false; 
	}
	else
		return true;
}

bool AddBigInts(const BigInt&num1, const BigInt &num2, BigInt &sum)
{
	// Purpose: Takes given big integers and rearranges them in order of largest to smallest.
	// Precondition: Valid big integers given.
	// Postcondition: adds the given big integers utilizing a function with the biggest number first with either
	// 1. Returns true if overflow does not occur
	// 2. Returns false if overflow does not occur
	//---------------------------------------------

 	if(num1.numdigits > num2.numdigits)
	 {
 		
		return AddWithLongestFirst(num1, num2, sum);
		
	 }
	 else 
	 {     

 		return AddWithLongestFirst(num2, num1, sum);
		 
	 }
}

BigInt operator+(const BigInt &num1, const BigInt &num2)
{
	//Purpose: Adds additional capabilities to the addition operator
	//Precondition: Valid big integers given
	//Postcondition: Either 
	// 1. Digits added, sum returned.
	// 2. Digits outside given range, exception thrown
	//---------------------------------------------------

	BigInt sum;

	if(AddBigInts(num1, num2, sum))
	{
		return sum;

	}
	 throw OverFlowException(num1, num2, '+');	

}


bool MultiBigIntbyDigit( const BigInt &num1, const BigInt &num2, int &counter, BigInt &product)
{ 
	// Purpose: Multiplies given large integers with the longest first.
	// Precondition: Valid big integers given, big Integers in the correct order.
	// Postcondition: Either
	// 1. Large Integers multiplies, stored in product. True Returned
	// or 2. Overflow occurs. Returns false.
	//---------------------------------------------

	int carry = 0, tempdigit = 0, tabover = 0;
	BigInt temp, temp2;
	tempdigit = num2.digits[counter];
	temp.numdigits = 0;

	
	for (int i = 0; i < num1.numdigits ; i++)
	{
		if(counter > 0)
		{
			while(tabover < counter)
			{
				temp.digits[tabover] = 0;
				temp.numdigits ++;
				tabover++;
				
			}
			temp.digits[counter+i] = num1.digits[i] * tempdigit + carry;
			if (temp.digits[counter+i] >= 10)
			{
				carry = temp.digits[counter+i] / 10;
				temp.digits[counter+i] = temp.digits[counter+i] % 10 ;
				temp.numdigits ++;
				
			}	
			else 
			{
				carry = 0;
				temp.numdigits ++;
			}
		}
		else
		{
			temp.digits[i] = num1.digits[i] * tempdigit + carry;
			if (temp.digits[i] >= 10)
			{
				carry = temp.digits[i] / 10;
				temp.digits[i] = temp.digits[i] % 10 ;
				temp.numdigits++;
			}
			else 
				carry = 0 ;
				temp.numdigits++;
		}
	}
	counter ++;
	if (temp.numdigits > BigInt::MAX_DIGITS)
	{
		return false;
	}
	if (carry > 0)
	{
		temp.digits[temp.numdigits] = carry;
		temp.numdigits++;

	}

	if(AddBigInts(product, temp, temp2))
	{
		product = temp2;
		return true;
	}
	else
		return false; 
}

bool MultiplyWithLongestFirst(const BigInt &num1, const BigInt &num2, int &counter, BigInt &product)
{
	// Purpose: Takes given big integers and rearranges them in order of largest to smallest.
	// Precondition: Valid big integers given.
	// Postcondition: multiplies the given big integers utilizing a function with the biggest number first with either
	// 1. Returns true if overflow does not occur
	// 2. Returns false if overflow does not occur
	//---------------------------------------------

	 if(num1.numdigits > num2.numdigits)
	 {
 		for(int i = 0 ; i < num2.numdigits; i++)
		{ 
			if(!MultiBigIntbyDigit(num1, num2, counter, product))
			{
				return false; 
			}
		}
		return true;
	 }
	 else 
	 {     
		for(int i = 0 ; i < num1.numdigits; i++)
		{
			
			if(!MultiBigIntbyDigit(num1, num2, counter, product))
			{
				return false; 
			}
		}
		return true;
	 }
}
BigInt operator*(const BigInt &num1, const BigInt &num2)
{
	//Purpose: Adds additional capabilities to the multiplication operator
	//Precondition: Valid big integers given
	//Postcondition: Either 
	// 1. Digits multiplied, product returned.
	// 2. Digits outside given range, exception thrown
	//---------------------------------------------------

	BigInt product;
	int counter = 0;

	if(MultiplyWithLongestFirst(num1,num2,counter,product))
	{
		return product;

	}
	 throw OverFlowException(num1, num2, '*');	

}
ostream& operator<<(ostream& os, const BigInt &num)
{
	//Purpose: Adds additional capabilities to the ostream operator <<
	//Precondition: Valid Big Integer given. 
	//Postcondition: Big integer printed.
	//--------------------------------------------------

	num.PrintBigInt(os);
	return os;
}

int main () {

	BigInt num1, num2;
	BigInt a("1234567890987654321556644"), b("987654321999888777666555444333222111"), c("987654321556644"), d("22111"); 
	int counter = 0;
	char exit = 'Y', selection;
	

	cout << "The maximum allowed digits in this program is: " << num1.MAX_DIGITS << endl;

	while( exit != 'X' && exit != 'x')
	{
		cout << "Press A, if you wish to Add " << endl; 
		cout << "Press M, if you wish to Multiply." << endl;
		//cout << "Press S, if you wish to Subtract." << endl;
		//cout << "Press D, if you wish to Divide." << endl;
		cin >> selection;
		if(selection == 'A' || selection == 'a')
		{ 
			cin.ignore(1000, '\n');
			cout << "Enter the first number you wish to add: " ;
			while(!num1.ReadBigInt())
			{
				cout << "There was a problem with the given number. Please try again. " << endl;
				cout << "Enter the first number you wish to add: " ; 
			}
			cout << "Enter the second number you wish to add: " ;
			
			while(!num2.ReadBigInt())
			{
				cout << "There was a problem with the given number. Please try again. " << endl;
				cout << "Enter the first number you wish to add: " ; 
			}
			try
			{
				cout << "Sum = " << num1+num2 << endl;	
			}
			catch(OverFlowException & ex)
			{
				cout << "Sum of: " << ex.m_num1 << " and " << ex.m_num2 << " was outside the given range. " << endl ; 
			}

		}
	if(selection == 'M' || selection == 'm')
		{ 
			cout <<"A: " << a<< endl;
			cout << "B: " << b << endl;
			cout << a*b <<endl;
			 }


		cout << "Press X, if you wish to exit. Anything else to return to the main menu."; 
		cin >> exit;
		if(exit != 'X' && exit != 'x')
		{
			cout << endl << "Returning to the main menu... " << endl << endl;
		}
		cin.ignore(1000, '\n');
	} 


return 0 ; 
}
