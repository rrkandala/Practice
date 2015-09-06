/**
 *	CTCI - 1.6
 *	Program to rotate a matrix by 90 degrees
 *
 *	Author: Ankit Srivastava
 *	Date: 9/6/2015
 */
 
#include "rotate_matrix.h"

int main()
{
	int n = 0;
	
	cout << "Enter the value of N for filling a N*N matrix: ";
	cin >> n;
	
	int **a = new int*[n];
	
	for(int i = 0; i < n; i++)
	{
		a[i] = new int[n];
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << "(" << i << ", " << j << "): ";
			cin >> a[i][j];
		}
	}
	
	cout << "Input Matrix: " << endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << left << setw(8) << a[i][j]; 
		}
		
		cout << endl;
	}
	
	for(int i = 0; i < ceil((double)n/2); i++)
	{
		for(int j = 0; j < n/2; j++)
		{
			swap(a[i][j], a[j][n-i-1], a[n-i-1][n-j-1], a[n-j-1][i]);
		}
	}
	
	cout << "Rotated Matrix: " << endl;	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << left << setw(8) << a[i][j]; 
		}
		
		cout << endl;
	}
}

void swap(int& a, int& b, int& c, int& d)
{
	int temp = d; 
	
	d = c;
	c = b;
	b = a;
	a = temp;
	
} 