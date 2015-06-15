/*
This program is an implementation of insertion sort algorithm

Input: A space delimited string of unsorted integers
Output: Monotonically increasing sorted string of integers

Author: Ankit Srivastava
Date: 6/14/2015
*/

#include <iostream>
#include <sstream>

using namespace std;

void insertionsort(int *A, int size);
void printarray(int *A, int size);

// Program execution starts here
int main()
{
	string input;
	
	cout << "Enter a space delimited string of integers" << endl;
	getline(cin, input);
	istringstream linestream(input);
	
	int value = 0;
	int size = 0;
	
	while(linestream >> value)
	{
		size++;
	}
	
	linestream.clear();
	
	int *A;
	A = new int[size];
	
	int i = 0;
	
	linestream.str(input);
	
	while(linestream >> value)
	{
		A[i] = value;
		i++;
	}
	
	cout << "Inserted Array: " << endl;
	printarray(A, size);
	
	// Perform insertion sort on input array
	insertionsort(A, size);
	
	// Print sorted array
	cout << "Sorted Array: " << endl;
	printarray(A, size);
	
	return 0;
}

// Go back from current position, find the right position left of the current position and insert the element
void insertionsort(int *A, int size)
{
	if(size > 1)
	{
		int j = 0;
		int x = 0;
		
		for(int i = 1; i < size; i++)
		{
			x = A[i];
			j = i;
			
			while(j > 0 && A[j-1] > x)
			{
				A[j] = A[j-1];
				j--;
			}
			
			A[j] = x;
		}
	}
}

// Printing the array
void printarray(int *A, int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << A[i] << ' ';
	}
	
	cout << endl;
}