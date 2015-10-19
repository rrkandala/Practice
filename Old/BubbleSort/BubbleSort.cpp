/* 
This program is an implementation of bubble sort algorithm

Input: Space delimited string of unsorted integers
Output: Space delimited string of sorted integers

Author: Ankit Srivastava
Date: 6/14/2015
*/

#include <iostream>
#include <sstream>

using namespace std;

int* inputarray(string input, int *size);
void bubblesort(int *A, int size);
void printarray(int *A, int size);
void swap(int *A, int i, int j);

int main()
{
	string input;
	
	cout << "Enter a space delimited string of integers: " << endl;
	getline(cin, input);
	
	int size = 0;
	
	// Inputting the array
	int *A = inputarray(input, &size);
	cout << "Input Array" << endl;
	
	// Printing the unsorted array
	printarray(A, size);
	
	// Performing bubble sort
	bubblesort(A, size);
	
	// Printing the sorted array
	cout << "Sorted Array: " << endl;
	printarray(A, size);
	
	return 0;
}

// Taking an array of integers as input
int* inputarray(string input, int *size)
{
	istringstream linestream(input);
	
	int value;
	while(linestream >> value)
	{
		(*size)++;
	}
	
	linestream.clear();
	linestream.str(input);
	int* A = new int[*size];
	int i = 0;
	string val;
	
	while(getline(linestream, val, ' '))
	{
		A[i] = stoi(val);
		i++;
	}
	
	return A;
}

// Bubble Sort implementation
void bubblesort(int *A, int size)
{
	for(int i = 0; i < size; i++)
	{
		for(int j = i + 1; j < size; j++)
		{
			if(A[i] > A[j])
			{
				swap(A, i, j);
			}
		}
	}
}

void swap(int *A, int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void printarray(int *A, int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << A[i] << ' ';
	}
	
	cout << endl;
}