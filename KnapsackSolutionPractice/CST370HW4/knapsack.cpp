/*Name: Terrence Johnson
Title: CST 370 HW 4, Knapsack problem.
Abstract: Write a program to implement a solution to the knapsack problem. It will display all of the available options and print the best value at the end.
ID: 1202
*/

//This program is incomplete. Too sick to finish it. Sorry again

#include <iostream>
#include <algorithm>

class item{
public: 
	int value;
	double capacity;
};
using namespace std;


int main()
{

	item item[15];
	int value = 0, numOfItems = 0, setCount = 1;
	double weight = 0.0, knapsackCapacity = 0.0;
	bool flag = false;

	cout << "Enter a number if items: " ;
	cin >> numOfItems;
	if(numOfItems < 1)
	{
		cout << "Erroneous input." << endl;
		return 0;
	}
	cout << endl;

	cout << "Enter Knapsack Capacity: ";
	cin >> knapsackCapacity;
	cout << endl;
	for(int i = 0; i < numOfItems; i++)
	{
		cout << "Enter weight and value of item " << i + 1 << ": ";
		cin >> item[i].capacity >> item[i].value;
	}
	cout << endl;
	cout << endl;

	cout << "Set " << setCount << ": {} => capacity: 0.0, value: $0" << endl;
	setCount++;
	for(int i = 0 ; i < numOfItems; i++)
	{
		if(item[i].capacity <= knapsackCapacity)
		{
			cout << "Set " << setCount << ": {" << i + 1 << "} => capacity: "<< item[i].capacity << ", value: $"<< item[i].value << endl;
			setCount++;
		}
		else 
		{
			cout << "Set " << setCount << ": {" << i + 1 << "} => capacity: over, value: N/A " << endl;
			setCount++;
		}

		if(numOfItems >= 2) 
		{
			for(int j = i + 1; j < numOfItems; )
			{
				if(item[i].capacity + item[j].capacity <= knapsackCapacity )
				{
					cout << "Set " << setCount << ": {" << i + 1 << ", "<< j + 1 <<"} => capacity: "<< item[i].capacity + item[j].capacity << ", value: $"<< item[i].value + item[j].value << endl;
					setCount++;
				}
				else 
				{
					cout << "Set " << setCount << ": {" << i + 1<< ", "<< j + 1 <<"} => capacity: over, value: N/A " << endl;
					setCount++;
				}
				j++;
				if(numOfItems >= 3 && j == numOfItems) 
				{
					if(i + 3 == numOfItems)
					{
						if(item[i].capacity + item[i+1].capacity + item[i+2].capacity <= knapsackCapacity)
						{
							cout << "Set " << setCount << ": {" << i + 1 << ", "<< i + 2 << ", "<< i + 3 <<"} => capacity: "<< item[i].capacity + item[i+1].capacity + item[i+2].capacity << ", value: $"<< item[i].value + item[i+1].value + item[i+2].value << endl;
							setCount++;
						}
						else
						{
							cout << "Set " << setCount << ": {" << i + 1 << ", "<< i + 2 << ", "<< i + 3 <<"} => capacity: over, value: N/A " << endl;
							setCount++;
						}
					}
					for(int k = i + 2; k < numOfItems; )
					{
						if(item[i].capacity + item[j].capacity + item[k].capacity <= knapsackCapacity )
						{
							cout << "Set " << setCount << ": {" << i + 1 << ", "<< i + 2 << ", "<< k + 1 <<"} => capacity: "<< item[i].capacity + item[i+1].capacity + item[k].capacity << ", value: $"<< item[i].value + item[i+1].value + item[k].value<< endl;
							setCount++;
						}
						else 
						{
							cout << "Set " << setCount << ": {" << i + 1 << ", "<< i + 2 << ", "<< k + 1 <<"} => capacity: over, value: N/A " << endl;
							setCount++;
						}
						k++;
						if(k == numOfItems)
						{
							if(item[i].capacity + item[j].capacity + item[k].capacity <= knapsackCapacity )
							{
								cout << "Set " << setCount << ": {" << i + 1 << ", "<< k << ", "<< k - 1 <<"} => capacity: "<< item[i].capacity + item[k-1].capacity + item[k-2].capacity << ", value: $"<< item[i].value + item[k-1].value + item[k-2].value<< endl;
								setCount++;
							}
							else 
							{
								cout << "Set " << setCount << ": {" << i + 1 << ", "<< k << ", "<< k - 1<<"} => capacity: over, value: N/A " << endl;
								setCount++;
							}
						}
						
						if(numOfItems >= 4 && k == numOfItems) 
						{
							if(i + 4 == numOfItems)
							{
								if(item[i].capacity + item[i+1].capacity + item[i+2].capacity + item[i+3].capacity <= knapsackCapacity)
								{
									cout << "Set " << setCount << ": {" << i + 1 << ", "<< i + 2 << ", "<< i + 3 << ", "<< i + 4 <<"} => capacity: "<< item[i].capacity + item[i+1].capacity + item[i+2].capacity + item[i+3].capacity << ", value: $"<< item[i].value + item[i+1].value + item[i+2].value + item[i+3].value << endl;
									setCount++;
								}
								else 
								{
									cout << "Set " << setCount << ": {" << i + 1 << ", "<< i + 2 << ", "<< i + 3 << ", "<< i + 4 <<"} => capacity: over, value: N/A " << endl;
									setCount++;
								}
							}
							else
							{
								for(int l = i + 3; l < numOfItems; ++l)
								{
									if(item[i].capacity + item[j].capacity + item[k].capacity + item[l].capacity <= knapsackCapacity )
									{
										cout << "Set " << setCount << ": {" << i + 1 << ", "<< j + 1 << ", "<< k + 1 << ", "<< l + 1 <<"} => capacity: "<< item[i].capacity + item[i+1].capacity + item[i+2].capacity + item[l].capacity << ", value: $"<< item[i].value + item[i+1].value + item[i+2].value + item[l].value << endl;
										setCount++;
									}
									else 
									{
										cout << "Set " << setCount << ": {" << i + 1 << ", "<< i + 2 << ", "<< i + 3 << ", "<< l + 1 <<"} => capacity: over, value: N/A " << endl;
										setCount++;
									}


								}
							}
						}
					}
				}


			}
		}
	}



	return 0;
}