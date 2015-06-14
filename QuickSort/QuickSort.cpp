#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void QuickSort(vector<int>& A, int p, int q);
int partition(vector<int>& A, int p, int q);
void swap(vector<int>& A, int i, int j);
void printarray(vector<int>& A);

// Program execution starts here
int main()
{
	string input;
	vector<int> A;

	cout << "Enter a string of space delimited integers to be sorted: " << endl;
	getline(cin, input);

	stringstream linestream(input);

	int value;
	while (linestream >> value)
	{
		A.push_back(value);
	}

	cout << endl << "Unsorted Array" << endl;
	printarray(A);

	QuickSort(A, 0, A.size());
	cout << endl << "Sorted Array" << endl;
	printarray(A);

	system("pause");
}

// Main Quicksort function
void QuickSort(vector<int>& A, int p, int q)
{
	if (p < q)
	{
		int r = partition(A, p, q);
		QuickSort(A, p, r);
		QuickSort(A, r + 1, q);
	}
}

// Quicksort O(n) partition subroutine
int partition(vector<int>& A, int p, int q)
{
	int x = A[p];
	int i = p;

	for (int j = p + 1; j < q; j++)
	{
		if (A[j] <= x)
		{
			i++;
			swap(A, i, j);
		}
	}

	swap(A, p, i);
	return i;
}

// Swapping integers during partition to have all integers less than pivot on left
// and all integers greater than x to right
void swap(vector<int>& A, int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

// Printing the Array
void printarray(vector<int>& A)
{
	for (int i = 0; i < A.size(); i++)
	{
		cout << A[i] << ' ';
	}

	cout << endl;
}