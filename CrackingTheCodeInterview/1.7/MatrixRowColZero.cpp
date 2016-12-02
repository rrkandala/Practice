#include <iostream>
#include <vector>

using namespace std;

void PrintMatrix(int **a, int m, int n);
void MatrixRowColZero(int **a, int m, int n);

int main()
{
	int **a;

	int m = 0, n = 0;

	cout << "Enter M*N Matrix number of rows (M): ";
	cin >> m;

	cout << "Enter M*N Matrix number of columns (N): ";
	cin >> n;

	a = new int *[m];

	for (int i = 0; i < m; i++)
	{
		a[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			cout << "[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}
	}

	cout << "Original Matrix: " << endl;
	PrintMatrix(a, m, n);

	cout << "Replacing row col of any index whose value is 0: " << endl;
	MatrixRowColZero(a, m, n);
	PrintMatrix(a, m, n);

	return 0;
}

void PrintMatrix(int **a, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << "\t";
		}

		cout << endl;
	}
}

void MatrixRowColZero(int **a, int m, int n)
{
	vector<int> rows;
	vector<int> cols;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 0)
			{
				rows.push_back(i);

				if (find(cols.begin(), cols.end(), j) == cols.end())
				{
					cols.push_back(j);
				}
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((find(rows.begin(), rows.end(), i) != rows.end()) || (find(cols.begin(), cols.end(), j) != cols.end()))
			{
				a[i][j] = 0;
			}
		}
	}
}