/* Program: Binary Search
Input: Sorted integer array and key to find
Output: true if key is found in the array, false if the key is not found
Author: Ankit Srivastava
*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

bool binarysearch(vector<int> v, int k, int min, int max);
int getmid(int min, int max);

int main()
{
	string line;
	int key;

	cout << "Enter space delimited set of sorted integers in ascending order: " << endl;
	getline(cin, line);

	vector<int> data;

	stringstream linestream(line);

	int value;
	// Read an integer at a time from the line
	while (linestream >> value)
	{
		// Add the integers from a line to a 1D array (vector)
		data.push_back(value);
	}

	cout << "Enter integer to find in the array: ";
	cin >> key;

	int min = 0;
	int max = data.size() - 1;

	bool foundkey = binarysearch(data, key, min, max);

	if (foundkey)
	{
		cout << key << " found in array" << endl;
	}
	else
	{
		cout << key << " not found in array" << endl;
	}

	data.clear();

	system("pause");
	return 0;
}

// Method to perform binary search O(log n) to find an integer in a sorted array
bool binarysearch(vector<int> v, int k, int min, int max)
{
	if (max < min)
	{
		return false;
	}
	else
	{
		int mid = getmid(min, max);

		if (v[mid] > k)
		{
			return binarysearch(v, k, min, mid - 1);
		}
		else if (v[mid] < k)
		{
			return binarysearch(v, k, mid + 1, max);
		}
		else
		{
			return true;
		}
	}
}

int getmid(int min, int max)
{
	return min + ((max - min) / 2);
}