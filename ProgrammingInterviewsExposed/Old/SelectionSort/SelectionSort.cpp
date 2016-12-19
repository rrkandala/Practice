/* This program is an implementation of selection sort algorithm
Input: Space delimited string of unsorted integers
Output: Space delimited string of sorted integers

Author: Ankit Srivastava
Date: 6/14/2015
*/

#include <iostream>
#include <sstream>

using namespace std;

int* inputarray(string input, int* size);
void printarray(int *A, int size);
void selectionsort(int *A, int size);
void swap(int *A, int i, int j);

int main()
{
	string input;
	int size = 0;
	
	cout << "Emter a space delimited string of integers" << endl;
	getline(cin, input);
	
	// Inputting the array
	int *A = inputarray(input, &size);
	
	// Printing the unsorted array
	printarray(A, size);
	
	// Performing the selection sort
	selectionsort(A, size);
	
	// Printing the sorted array
	printarray(A, size);
	
	return 0;
}

// Method to input array from user
int* inputarray(string input, int* size)
{
	istringstream linestream(input);
	int value = 0;
	
	while(linestream >> value)
	{
		(*size)++;
	}
	
	linestream.clear();
	linestream.str(input);
	int* A = new int[*size];
	
	int i = 0;
	while(linestream >> value)
	{
		A[i] = value;
		i++;
	}
	
	return A;
}

// Selection sort implementation - At every iteration find the max value to input at the end
// Better than bubble sort as only n swaps at maximum but n^2 comparisons
void selectionsort(int *A, int size)
{
	int max = 0;
	int maxindex = 0;

	for (int i = size - 1; i > 0; i--)
	{
		max = A[i];

		for (int j = 0; j < i; j++)
		{
			if (A[j] > max)
			{
				max = A[j];
				maxindex = j;
			}
		}

		swap(A, i, maxindex);
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

void swap(int *A, int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}