#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

bool IsPermutation(string s1, string s2);
bool IsPermutation_CountChars(string s1, string s2);

int main()
{
	string s1, s2;

	cout << "Enter string 1: ";
	getline(cin, s1);

	cout << "Enter string 2: ";
	getline(cin, s2);

	string result = IsPermutation_CountChars(s1, s2) ? "is" : "is not";

	cout << "The string \"" << s1 << "\" " << result << " permutation of string \"" << s2 << "\"" << endl;

	return 0;
}

/*
Sort both strings and then compare them for equality
*/
bool IsPermutation(string s1, string s2)
{
	if (s1.length() != s2.length())
	{
		return false;
	}
	else
	{
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());

		if (s1.compare(s2) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

/*
Count of occurence of each character in string 1 and then string 2
*/
bool IsPermutation_CountChars(string s1, string s2)
{
	map<char, int> dict;
	int occurences = 0;

	char* s1_c = new char[s1.length() + 1];
	char* s2_c = new char[s2.length() + 1];

	strcpy_s(s1_c, s1.length() + 1, s1.c_str());
	strcpy_s(s2_c, s2.length() + 1, s2.c_str());

	if (s1.length() != s2.length())
	{
		return false;
	}
	else
	{
		for (int i = 0; i < s1.length(); i++)
		{
			occurences = dict.count(s1_c[i]);
			if (occurences == 0)
			{
				dict[s1_c[i]] = 1;
			}
			else
			{
				dict[s1_c[i]]++;
			}
		}

		for (int i = 0; i < s2.length(); i++)
		{
			occurences = dict.count(s2_c[i]);
			
			if (occurences == 0)
			{
				return false;
			}
			else
			{
				dict[s2_c[i]]--;
			}
		}

		map<char, int>::iterator iter;

		for (iter = dict.begin(); iter != dict.end(); ++iter)
		{
			if (iter->second != 0)
			{
				return false;
			}			
		}
	}

	return true;
}