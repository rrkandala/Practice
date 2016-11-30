#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string CompressString(string str);

int main()
{
	string inputString;
	cout << "Enter input string to compress: ";
	getline(cin, inputString);

	cout << "Compressed String is: " << CompressString(inputString);

	return 0;
}

string CompressString(string str)
{
	stringstream ss;
	int counter = 1;
	int firstpos = 0;

	for (int i = 1; i < str.length(); i++)
	{
		if (str[i] == str[firstpos])
		{
			counter++;
		}
		else
		{
			ss << str[firstpos] << counter;
			counter = 1;
			firstpos = i;
		}
	}

	ss << str[firstpos] << counter;

	if (ss.str().length() >= str.length())
	{
		return str;
	}
	else
	{
		return ss.str();
	}
}