#include <iostream>
#include <string>

using namespace std;

// Check s2 is rotation of s1
bool IsRotation(string s1, string s2);

int main()
{
	string s1;
	string s2;

	cout << "Enter string 1: ";
	getline(cin, s1);
	cout << "Enter string 2 to check if rotation of string 1: ";
	getline(cin, s2);

	string res = IsRotation(s1, s2) ? "is" : "is not";

	cout << "String s2: \"" << s2 << "\" " << res << " rotation of string s1: \"" << s1 << "\"\n";

	return 0;
}

bool IsRotation(string s1, string s2)
{
	string c = s1 + s1;
	if (s1.length() != s2.length())
	{
		return false;
	}
	else
	{
		return (c.find(s2) != string::npos);
	}
}