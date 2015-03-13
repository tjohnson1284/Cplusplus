#include <iostream>

using namespace std;


int main()
{
	string  test = "CABAAXBYA"; 
	int i = 2, sum = 0;

	while(i < 1024)
	{
		sum += i;

		i = i * 2;
	}

	cout << sum << " " << i;
	cin.get();
	return 0;
}

