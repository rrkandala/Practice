#include <iostream>
#include <string>

using namespace std;

void ReplaceSpaces(char *str);

int main()
{
	string inputString;
	cout << "Enter a string with spaces to replace with %20: ";

	getline(cin, inputString);
	char *str = new char[inputString.length() + 1];
	strcpy_s(str, inputString.length() + 1, inputString.c_str());

	ReplaceSpaces(str);

	cout << "Replaced space with %20 string is: " << str << endl;

	return 0;
}

void ReplaceSpaces(char *str)
{
	int len = strlen(str);

	bool lastchars = true;
	int firstpos = len - 1;
	int lastpos = len - 1;

	for (int i = len - 1; i >= 0; i--)
	{
		if (str[i] != ' ')
		{
			firstpos = i;
			break;
		}
	}

	for (int i = firstpos; i >= 0; i--)
	{
		if (str[firstpos] != ' ')
		{
			str[lastpos--] = str[firstpos--];
		}
		else
		{
			str[lastpos--] = '0';
			str[lastpos--] = '2';
			str[lastpos--] = '%';
			firstpos--;
		}
	}
}