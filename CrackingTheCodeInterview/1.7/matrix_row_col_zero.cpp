/**
 *	CTCI-1.7
 *	Purpose: Given a M*N matrix, if an element is zero, set its entire row and column as zero
 *	
 *	Author: Ankit Srivastava
 *	Date: 9/7/2015
 */
 
#include "matrix_row_col_zero.h"

int main()
{
	int M = 0;
	int N = 0;
	
	cout << "Enter number of rows in matrix: ";
	cin >> M;
	
	cout << "Enter number of columns in matrix: ";
	cin >> N;
	
	int **a = new int*[M];
	
	for(int i = 0; i < M; i++)
	{
		a[i] = new int[N];
	}
	
	cout << "Enter elements in array - " << endl;
	
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cout << "(" << i << ", " << j << "): ";
			cin >> a[i][j];
		}
	}
	
	cout << "Input Array: " << endl;
	print_array(a, M, N);
	
	set_row_col_zero(a, M, N);
	
	cout << "Output Array: " << endl;
	print_array(a, M, N);
	
	return 0;
}

// Function to print elements of M*N array
void print_array(int **a, int M, int N)
{
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cout << left << setw(8) << a[i][j];
		}
		
		cout << endl;
	}
}

// If element in matrix is set to zero, set all rows and columns to zero  
void set_row_col_zero(int **a, int M, int N)
{
	int *rows_to_set_zero = new int[M];
	int *col_to_set_zero = new int[N];
	
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(a[i][j] == 0)
			{
				rows_to_set_zero[i] = 1;
				col_to_set_zero[j] = 1;
			}
		}
	}
	
	// Row sweep
	for(int i = 0; i < M; i++)
	{
		if(rows_to_set_zero[i] == 1)
		{
			for(int j = 0; j < N; j++)
			{
				a[i][j] = 0;
			}
		}
	}
	
	// Column sweep
	for(int j = 0; j < N; j++)
	{
		if(col_to_set_zero[j] == 1)
		{
			for(int i = 0; i < M; i++)
			{
				a[i][j] = 0;
			}
		}
	}
}