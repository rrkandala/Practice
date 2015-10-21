/*	Program: Implementation of sorting algorithms
 *	Author: Ankit Srivastava
 */

#include <iostream>

using namespace std;
 
class Sorting
{
	private:
		int *d;
		int size;
	public:
		Sorting();
		Sorting(int n);
		void insert();
		void bubblesort();
		void selectionsort();
		void insertionsort();
		void print();
		void swap(int i, int j);
};

Sorting::Sorting()
{
	d = NULL;
	size = 0;
}

Sorting::Sorting(int n)
{
	size = n;
	d = new int[n];
}

// Bubble Sort 
void Sorting::bubblesort()
{
	for(int i = 0; i < size; i++)
	{
		// Compares and swaps a lot of times for no need
		for(int j = i + 1; j < size; j++)
		{
			if(d[i] > d[j])
			{
				swap(i, j);
			}
		}
	}
}

// Selection Sort
void Sorting::selectionsort()
{
	int max;
	
	int j = size-1;
	
	for(int i = size-1; i >= 0; i--)
	{
		max = i;
		
		// Finds max for decreasing length of array
		for(int j = 0; j < i; j++)
		{
			if(d[max] < d[j])
			{
				max = j;
			}
		}
		
		swap(i, max);
	}
}

// Insertion Sort
void Sorting::insertionsort()
{
	int temp = 0;
	int j = 0;
	
	if (size > 1)
	{
		for(int i = 1; i < size; i++)
		{
			j = i-1;
			temp = d[i];
			
			// Shifting to the right to make way for element to be placed in correct position
			// This is why insertion sort does so well on nearly sorted arrays
			// Also, notice that insertion sort requires only shifts and no swaps
			while(j >= 0 && d[j] > temp)
			{
				d[j+1] = d[j];
				j--;
			}
			
			d[j+1] = temp;
		}
	}
}

void Sorting::insert()
{
	for(int i = 0; i < size; i++)
	{
		cout << "Enter element " << i + 1 << ": ";
		cin >> d[i];
	}
}

void Sorting::swap(int i, int j)
{
	int temp = d[i];
	d[i] = d[j];
	d[j] = temp;
}

void Sorting::print()
{
	for(int i = 0; i < size; i++)
	{
		cout << d[i] << endl;
	}
}

int main()
{
	Sorting *obj = new Sorting(5);
	obj->insert();
	cout << "Insertion Sort" << endl;
	obj->insertionsort();
	obj->print();
}