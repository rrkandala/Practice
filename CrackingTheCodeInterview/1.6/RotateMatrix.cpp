#include <iostream>

using namespace std;

void RotateMatrix(int **a, int n);
void PrintMatrix(int **a, int n);

int main()
{
	int n;
	cout << "Enter size N of a N * N matrix: ";
	cin >> n;

	int **a = new int*[n];

	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];

		for (int j = 0; j < n; j++)
		{
			cout << "[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}
	}

	cout << "Original Matrix: " << endl;
	PrintMatrix(a, n);
	cout << "Rotated Matrix: " << endl;
	RotateMatrix(a, n);
	PrintMatrix(a, n);

	return 0;
}

void RotateMatrix(int **a, int n)
{
	int temp = 0;

	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < (n + 1) / 2; j++)
		{
			temp = a[i][j];
			a[i][j] = a[n - j - 1][i];
			a[n - j - 1][i] = a[n - i - 1][n - j - 1];
			a[n - i - 1][n - j - 1] = a[j][n - i - 1];
			a[j][n - i - 1] = temp;
		}
	}
}

void PrintMatrix(int **a, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << "\t";
		}

		cout << endl;
	}
}