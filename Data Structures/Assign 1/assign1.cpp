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
#include <cmath>
#include <iomanip>
const int MAX_DIGITS = 50;
using namespace std;
struct BigInt{ 

	int numdigits;
	int digits[MAX_DIGITS];
}; 
 
bool readBigInt(BigInt &num)
{   
	// Purpose: Read and store a large integer.
    // Precondition: None.
	// Postcondition: Either
	// 1. Given number is valid and stored. True is returned.
	// or 2. Given number is invalid. False is returned.
	//---------------------------------------------
   string s; 
            
   int length;
   getline(cin, s); 
   length = s.length();

   if ( length <= MAX_DIGITS )  
     {

       for( int i = 0; i < length; i++)
        num.digits[length - i - 1] = s[i] - '0';
        
	   
	   num.numdigits = length;
       
	   return true;
     }
            
    else
        return false ;
}
void printBigInt(const BigInt &num)
{
	// Purpose: print a big integer.
	// Precondition: A valid big integer is entered.
	// Postcondition: Prints the big integer.
	//---------------------------------------------

   cout << "Result: " ; 
   for (int i= 0 ; i < num.numdigits; i++)
	cout << num.digits[num.numdigits - i - 1]; 
   
   cout << endl;
}
int comparestructs(BigInt longer, BigInt shorter)
{
	// Purpose: Compares two structures. 
	// Precondition: Two Valid structures given.
	// Postcondition:
	// returns 0, if longer struct is bigger
	// returns 1, if the structs are equal
	// returns 2, if the longer struct is smaller than the shorter.
	//-----------------------------------------------

	int counter = 0 ; 

	if(longer.numdigits == shorter.numdigits)
	{
		if (longer.numdigits == 1)
		{
			if(longer.digits[0] > shorter.digits[0])
			{
				return 0;
			}
			if(longer.digits[0] == shorter.digits[0])
			{
				return 1;
			}
			else 
				return 2;
		}

		counter = longer.numdigits;

		if(longer.digits[counter-1] > shorter.digits[counter-1])    // checks to see if the longer number is bigger.
		{
			for(int i = 2; i < longer.numdigits; i++)
			{
				if (!longer.digits[counter - i] > shorter.digits[counter - 1])           // checks to see if longer is bigger in reverse order
				{
					return 2;
				}
			}
		}
		else if(longer.digits[counter-1] < shorter.digits[counter-1])         
		{                                                                                       
		                                                                                        
			return 2; 

		}

		else if (longer.digits[counter-1] == shorter.digits[counter-1])
		{	

			for(int i = 0 ; counter < longer.numdigits; i++)
			{

				if(!longer.digits[i] == shorter.digits[i])
				{
					return 0;
				}

			}

			return 1;                                              
		}

		return 0;
	
	}
	else if (longer.numdigits < shorter.numdigits)
	{
		return 2;
	}

	else 
		return 0;
		
}
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
	if (sum.numdigits < MAX_DIGITS)
	{
		if (carry == 1) 
		{ 
			sum.digits[sum.numdigits] = 1;
			sum.numdigits ++;
		} 
		return true;
	}

	else 
		return false; 
		
}
bool AddBigInt(const BigInt &num1, const BigInt &num2, BigInt &sum)
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
			if (temp.digits[i] > 10)
			{
				carry = temp.digits[i] / 10;
				temp.digits[i] = temp.digits[i] % 10 ;
				temp.numdigits ++;
				
			}	
			else 
				temp.numdigits ++; 
		}
		else
		{
			temp.digits[i] = num1.digits[i] * tempdigit + carry;
			if (temp.digits[i] > 10)
			{
				carry = temp.digits[i] / 10;
				temp.digits[i] = temp.digits[i] % 10 ;
				temp.numdigits++;
			}
			else 
				temp.numdigits++;
		}
	}
	counter ++;
	if (temp.numdigits > MAX_DIGITS)
	{
		return false;
	}
	
	if(AddBigInt(product, temp, temp2))
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
bool SubtractWithLongestFirst( BigInt &longer,  BigInt &shorter, BigInt &difference)
{
	// Purpose: Subtracts given large integers with the longest first.
	// Precondition: Valid big integers given, big Integers in the correct order.
	// Postcondition: Either
	// 1. large Integers subtracted, stored in difference. True Returned
	// or 2. Overflow occurs. Returns false.
	//---------------------------------------------

	int carry = 0;

	

	for(int i = 0; i < shorter.numdigits; i++)
	{
		if ( carry > 0)
		{
			longer.digits[i] = longer.digits[i] - carry; 
			carry = 0;
		}
		if( longer.digits[i] < shorter.digits[i])
		{
			longer.digits[i] = longer.digits[i] + 10;
			difference.digits[i] = longer.digits[i] - shorter.digits[i] ;
		    carry ++;
			difference.numdigits++;
		}
		else 
		{
			difference.digits[i] = longer.digits[i] - shorter.digits[i] ;
			if(difference.numdigits + 1 == longer.numdigits && difference.digits[i] == 0 )
			{
				carry = 0;
			}
			else
			{	
				carry = 0; 
		        difference.numdigits++;
			}
		}
	}

	for(int i = shorter.numdigits ; i < longer.numdigits; i++)
	{
		if ( carry > 0)
		{
			if (difference.numdigits == longer.numdigits - 1)
			{
				if(longer.digits[i] == 1)
				{
					return true;
				}
			}

			if(longer.digits[i] == 0)
			{
				longer.digits[i] = longer.digits[i] + 10;
				difference.digits[i] = longer.digits[i] - carry;
				difference.numdigits++;
			}
			else
			{
				difference.digits[i] = longer.digits[i] - carry; 
				carry = 0;
				difference.numdigits++;
			}
		}
		else
		{
			difference.digits[i] = longer.digits[i] ;
			difference.numdigits++;
		}
	}
	return difference.numdigits <= MAX_DIGITS;
	

}
bool SubtractBigInt(BigInt &num1, BigInt &num2, BigInt &difference)
{

	// Purpose: Takes given big integers and rearranges them in order of largest to smallest.
	// Precondition: Valid big integers given.
	// Postcondition: adds the given big integers utilizing a function with the biggest number first with either
	// 1. Returns true if overflow does not occur
	// 2. Returns false if overflow does not occur
	//---------------------------------------------

 	if(num1.numdigits > num2.numdigits)
	 {
 		
		return SubtractWithLongestFirst(num1, num2, difference);
		
	 }
	 else if (num1.numdigits == num2.numdigits)
	 {     
		 if(comparestructs(num1, num2) == 0)
		 {	
			 return SubtractWithLongestFirst(num1, num2, difference);
		 }
		 else if(comparestructs(num1, num2) == 2)
		 {
			 return SubtractWithLongestFirst(num2, num1, difference);
		 }
		 else if(comparestructs(num1, num2) == 1)
			 return SubtractWithLongestFirst(num1, num2, difference);
	 }
	 else
		 return SubtractWithLongestFirst(num2, num1, difference);

}
bool DivideWithLongestFirst(BigInt &longer,  BigInt &shorter, BigInt &quotient, BigInt &remainder)
{
	// Purpose: Divides given large integers with the longest first.
	// Precondition: Valid big integers given, big Integers in the correct order.
	// Postcondition: Either
	// 1. large integers divided, stored in quotient. Remainder stored in remainder. True Returned
	// or 2. Overflow occurs. Returns false.
	//---------------------------------------------


	BigInt temp, temp2, reset;
	int counter = 0, length ; 
	string s ;
	temp.numdigits = temp2.numdigits = reset.numdigits = remainder.numdigits = 0; //initializes all three to 0;
	remainder.digits[0] = 0; 

	SubtractBigInt(longer, shorter, temp2); 
	counter ++;
	temp = temp2;
	temp2 = reset;

	while(comparestructs(temp, shorter) == 0)
	{
		SubtractBigInt(temp, shorter, temp2);
		counter++;
		temp = temp2;
		temp2 = reset;
	}
	if(comparestructs(temp, shorter) == 1)
	{
		SubtractBigInt(temp, shorter, temp2);
		counter++;
		temp = temp2;
		temp2 = reset;
	}
	s = counter;
	length = s.length();

	if ( length <= MAX_DIGITS )  
    {
	       for( int i = 0; i < length; i++)
			  quotient.digits[length - i - 1] = s[i] ;
        
	   
	   quotient.numdigits = length;
     }
            
    else
        return false ;
	if(comparestructs(temp, shorter) == 1)
	{
		return true;
	}
	if(comparestructs(temp, shorter) == 2)
	{
		remainder = temp;
		return true;
	}
}
bool DivideBigInt(BigInt &num1, BigInt &num2, BigInt &quotient, BigInt &remainder)
{
	// Purpose: Takes given big integers and rearranges them in order of largest to smallest.
	// Precondition: Valid big integers given.
	// Postcondition: divides the given big integers utilizing a function with the biggest number first with either
	// 1. Returns true if overflow does not occur
	// 2. Returns false if overflow does not occur
	//---------------------------------------------

 	if(num1.numdigits > num2.numdigits)
	 {
 		
		return DivideWithLongestFirst(num1, num2, quotient, remainder);
		
	 }
	 else if (num1.numdigits == num2.numdigits)
	 {     
		 if(comparestructs(num1, num2) == 0)
		 {	
			 return DivideWithLongestFirst(num1, num2, quotient, remainder);
		 }
		 else if(comparestructs(num1, num2) == 2)
		 {
			 return DivideWithLongestFirst(num1, num2, quotient, remainder);
		 }
		 else if(comparestructs(num1, num2) == 1)
			 return DivideWithLongestFirst(num2, num1, quotient, remainder);
	 }
	else
		return DivideWithLongestFirst(num2, num1, quotient, remainder);
}

int main () 
{

	BigInt num1, num2, sum, product, reset, difference, quotient, remainder, a ;
	char exit = 'Y', selection;
	int counter = 0;
	product.numdigits = 0;
	reset.numdigits = 0;
	difference.numdigits = 0; 

	cout << "The Maximum Digits that can be used is " << MAX_DIGITS << ". " << endl; 
	cout << setw(73) << setfill('~') << " " << endl << setfill(' ') << endl;   


	while( exit != 'X' && exit != 'x')
	{
		cout << "Press A, if you wish to Add " << endl; 
		cout << "Press M, if you wish to Multiply." << endl;
		cout << "Press S, if you wish to Subtract." << endl;
		cout << "Press D, if you wish to Divide." << endl;
		cin >> selection;
		if(selection == 'A' || selection == 'a')
		{ 
			cin.ignore(1000, '\n');
			cout << "Enter the first number you wish to add: " ; 
			while(!readBigInt(num1))
			{
				cout << "The number entered was too big. Please try again. " << endl;
				cout << "Enter the first number you wish to add: " ; 
			}
			cout << "Enter the second number you wish to add: " ;
			while(!readBigInt(num2))
			{
				cout << "The number entered was too big. Please try again. " << endl;
				cout << "Enter the first number you wish to add: " ; 
			}

			if (!AddBigInt(num1, num2, sum))
			{
				cout << "Sum outside of stated range. Please check your numbers and try again." << endl;
			}
			else
				printBigInt(sum);
		}
		if(selection == 'M' || selection == 'm')
		{
			cin.ignore(1000, '\n');
			cout << "Enter the first number you wish to multiply: " ; 
			while(!readBigInt(num1))
			{
				cout << "The number entered was too big. Please try again. " << endl;
				cout << "Enter the first number you wish to multiply: " ; 
			}
			cout << "Enter the second number you wish to multiply: " ;
			while(!readBigInt(num2))
			{
				cout << "The number entered was too big. Please try again. " << endl;
				cout << "Enter the first number you wish to multiply: " ; 
			}

			if(!MultiplyWithLongestFirst(num1, num2, counter, product))
			{
				cout << " Product outside of stated range. Please check your numbers and try again." << endl << endl;
			}
			else
				printBigInt(product);
			
			
			product = reset;
			counter = 0;

		}	
		if ( selection == 'S' || selection == 's')
		{
			cin.ignore(1000, '\n');
			cout << "Enter the first number you wish to subtract: " ; 
			while(!readBigInt(num1))
			{
				cout << "The number entered was too big. Please try again. " << endl;
				cout << "Enter the first number you wish to subtract: " ; 
			}
			cout << "Enter the second number you wish to subtract: " ;
			while(!readBigInt(num2))
			{
				cout << "The number entered was too big. Please try again. " << endl;
				cout << "Enter the first number you wish to subtract: " ; 
			}
	        if (!SubtractBigInt(num1, num2, difference))
			{
				cout << "Difference outside of stated range. Please check your numbers and try again." << endl;
			}
			else
				printBigInt(difference);
		}
		if ( selection == 'D' || selection == 'd')
		{
			cin.ignore(1000, '\n');
			cout << "Largest number will automatically be the dividend." << endl;
			cout << "Enter the first number you wish to divide: " ; 
			while(!readBigInt(num1))
			{
				cout << "The number entered was too big. Please try again. " << endl;
				cout << "Enter the first number you wish to divide: " ; 
			}
			cout << "Enter the second number you wish to divide: " ;
			while(!readBigInt(num2))
			{
				cout << "The number entered was too big. Please try again. " << endl;
				cout << "Enter the first number you wish to divide: " ; 
			}
			if (!DivideBigInt(num1, num2, quotient, remainder))
			{
				cout << "Quotient outside of stated range. Please check your numbers and try again." << endl;
			}
			else
			{	
				cout << "Quotient " ;
				printBigInt(quotient);
				cout << endl << "Remainder: " ;
				printBigInt(remainder);
			}	

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
