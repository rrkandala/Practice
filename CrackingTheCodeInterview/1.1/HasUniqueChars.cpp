#include <iostream>
#include <string>

using namespace std;

bool HasUniqueCharsBruteForce(string str);
bool HasUniqueCharsAscii(string str);
bool HasUniqueCharsBitVector(string str);

int main()
{
	string inputString;

	cout << "Enter a string to check if it has all unique chars or not: ";
	getline(cin, inputString);

	string res = HasUniqueCharsBitVector(inputString) ? "\" has " : "\" does not have ";

	cout << "The string \"" << inputString << res << " all unique chars" << endl;

	return 0;
}

bool HasUniqueCharsBruteForce(string str)
{
	for (int i = 0; i < (int)str.length(); i++)
	{
		for (int j = i + 1; j < (int)str.length(); j++)
		{
			if (str[i] == str[j])
			{
				return false;
			}
		}
	}

	return true;
}

bool HasUniqueCharsAscii(string str)
{
	bool a[256] = { false };

	for (int i = 0; i < str.length(); i++)
	{
		if (a[(int)str[i]] == false)
		{
			a[(int)str[i]] = true;
		}
		else
		{
			return false;
		}
	}

	return true;
}

bool HasUniqueCharsBitVector(string str)
{
	int checker = 0;

	for (int i = 0; i < str.length(); i++)
	{
		int val = str[i] - (int)'a';

		if ((checker & (1 << val)) > 0)
		{
			return false;
		}
		else
		{
			checker = checker | (1 << val);
		}
	}
}