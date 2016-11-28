#include <iostream>
#include <string>

using namespace std;

void reverse(char *str);

int main()
{
	string inputString;
	cout << "Enter string to reverse: ";

	getline(cin, inputString);
	char *charString = new char[inputString.length()];

	strcpy_s(charString, inputString.length() + 1, inputString.c_str());
	reverse(charString);

	cout << "Reversed string: " << charString << endl;

	return 0;
}

void reverse(char *str)
{
	int len = strlen(str);

	int begin = 0;
	int end = len - 1;
	char temp;

	for (int i = 0; i < len / 2; i++)
	{
		temp = str[begin];
		str[begin] = str[end];
		str[end] = temp;

		begin++;
		end--;
	}
}