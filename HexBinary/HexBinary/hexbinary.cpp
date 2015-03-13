#include <iostream>
#include <string>

using namespace std;
void HextoBinary(const string &input, string &result);
void BinarytoHex(const string &input, string &result);
int main ()
{


	string input = "", result = "";
	int choice = 0;

	cout << "Which would you like to convert?  " << endl ;
	cout << "If Hex to Binary, press 1. " << endl ;
	cout << "If Binary to Hex, press 2. " << endl ;
	cin >> choice;
	
	cout << "Please enter the string you want converted: ";
	cin.ignore(1000, '\n');
	getline(cin, input);

	if(choice == 1)
	{
		HextoBinary(input, result);
	}
	else if(choice == 2)
	{
		BinarytoHex(input, result);
	}

	cout << "Your conversion result is: " << result << endl;
	return 0;
}
void HextoBinary(const string &input, string &result)
{

	for( int i = 0; i < input.size(); i++)
	{
		if(input[i] == 'F' || input[i] == 'f')
		{
			result += "1111 ";
		}

		else if(input[i] == 'E' || input[i] == 'e')
		{
			result += "1110 ";
		}

		else if(input[i] == 'D' || input[i] == 'd')
		{
			result += "1101 ";
		}

		else if(input[i] == 'C' || input[i] == 'c')
		{
			result += "1100 ";
		}

		else if(input[i] == 'B' || input[i] == 'b')
		{
			result += "1011 ";
		}

		else if(input[i] == 'A' || input[i] == 'a')
		{
			result += "1010 ";
		}

		else if(input[i] == '9')
		{
			result += "1001 ";
		}

		else if(input[i] == '8')
		{
			result += "1000 ";
		}

		else if(input[i] == '7')
		{
			result += "0111 ";
		}

		else if(input[i] == '6')
		{
			result += "0110 ";
		}

		else if(input[i] == '5')
		{
			result += "0101 ";
		}

		else if(input[i] == '4')
		{
			result += "0100 ";
		}

		else if(input[i] == '3')
		{
			result += "0011 ";
		}

		else if(input[i] == '2')
		{
			result += "0010 ";
		}

		else if(input[i] == '1')
		{
			result += "0001 ";
		}

		else if(input[i] == '0')
		{
			result += "0000 ";
		}

	}

}
void BinarytoHex(const string &input, string &result)
{

	int value = 0, count = 0;
	
	for( int i = 0; i < input.size(); i++)
	{	if(input[i] == '1')
		{
			if(count == 0)
			{
				value += 8;
			}
			else if(count == 1)
			{
				value += 4;
			}
			else if(count == 2)
			{
				value += 2;
			}
			else if(count == 3)
			{
				value += 1;
			}
		}
		
		count++;

		if(count % 4 == 0 && value > 9 && count > 3 )
		{
			if(value == 15)
			{
				result += "F ";
			}

			else if(value == 14)
			{
				result += "E ";
			}
			
			else if(value == 13)
			{
				result += "D ";
			}

			else if(value == 12)
			{
				result += "C ";
			}

			else if(value == 11)
			{
				result += "B ";
			}

			else if(value == 10)
			{
				result += "A ";
			}

			value = 0;
			count = 0;
		}
		else if( count % 4 == 0 && count > 3 )
		{
			if(value == 9)
			{
				result += "9 ";
			}

			else if(value == 8)
			{
				result += "8 ";
			}
			
			else if(value == 7)
			{
				result += "7 ";
			}

			else if(value == 6)
			{
				result += "6 ";
			}

			else if(value == 5)
			{
				result += "5 ";
			}

			else if(value == 4)
			{
				result += "4 ";
			}

			else if(value == 3)
			{
				result += "3 ";
			}

			else if(value == 2)
			{
				result += "2 ";
			}

			else if(value == 1)
			{
				result += "1 ";
			}

			else if(value == 0)
			{
				result += "0 ";
			}

			count = 0;
			value = 0;
		}
		
	}

}