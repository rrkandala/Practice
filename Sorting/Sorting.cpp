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

void Sorting::bubblesort()
{
	for(int i = 0; i < size; i++)
	{
		for(int j = i + 1; j < size; j++)
		{
			if(d[i] > d[j])
			{
				swap(i, j);
			}
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
	obj->bubblesort();
	obj->print();
}