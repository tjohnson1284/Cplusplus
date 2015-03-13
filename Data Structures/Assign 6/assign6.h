#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template<typename T>
void Swap(T& x, T& y)
{
	T temp = x;
	x = y;
	y = temp;
}

template<typename T>
void Print( T a[], int na)
{
	for(int i = 0; i < na; i++)
		cout << a[i] << "  ";
	cout << endl;
}

template<typename T>//				0         8
void ReheapDown(T elements[], int root, int bottom)
// Post: Heap property is restored.
{
	int maxChild;
	int rightChild;
	int leftChild;

	leftChild = root*2+1;// 
	rightChild = root*2+2;
	if (leftChild <= bottom)
	{
		if (leftChild == bottom)
			maxChild = leftChild;
		else
		{
			if (elements[leftChild] <= elements[rightChild])
				maxChild = rightChild;
			else
				maxChild = leftChild;
		}
		if (elements[root] < elements[maxChild])
		{
			Swap(elements[root], elements[maxChild]);
			//                      2        8
			ReheapDown(elements, maxChild, bottom);
		}
	}
}

template<typename T> //          9
void HeapSort(T values[], int numValues)
// Post: The elements in the array values are sorted by key.
{
	int index;
	int step = 0;
	// Convert the array of values into a heap.
	for (index = numValues/2 - 1; index >= 0; index--)
	{
		ReheapDown(values, index, numValues-1);
		
	}
	
	step = 0;
	for (index = numValues-1; index >=1; index--)
	{
		Swap(values[0], values[index]);
		ReheapDown(values, 0, index-1);
	}
}
//-----------------------------------
// "Selection" sort algorithm.
template<typename T>
//           0             8
void BubbleUp(T values[], int startIndex, int endIndex, bool& sorted)
// Post: Adjacent pairs that are out of order have been 
//       switched between values[startIndex]..values[endIndex]
//       beginning at values[endIndex].
{
	sorted = true;
	for (int index = endIndex; index > startIndex; index--)
		if (values[index] < values[index-1])
		{
			Swap(values[index], values[index-1]);
			sorted = false;
		}
}

// BubbleSort(a, 9);
template<typename T>//             9
void BubbleSort(T values[], int numValues)
// Post: The elements in the array values are sorted by key.
{
	int current = 0;
	bool sorted = false;

	while (current < numValues - 1 && !sorted)
	{//			0         8
		BubbleUp(values, current, numValues-1,sorted);
		//PrintArray(values,numValues);
		cin.get();
		cout << endl;
		current++;
	}
}
// "Selection" sort algorithm.
template<typename T>
void sort( T a[], int na )
{
	T temp;
	int lowIndex;
	for( int i = 0; i < na-1; i++ )	// n times
	{
		lowIndex = i;
		for( int j = i+1; j < na; j++ )
			if( a[j] >  a[lowIndex] ) // get new lowIndex
				lowIndex = j;
		if( lowIndex != i) // swap
		{
			temp = a[lowIndex];
			a[lowIndex] = a[i];
			a[i] = temp;
		}
	}
}