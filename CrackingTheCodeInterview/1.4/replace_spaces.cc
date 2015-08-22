/**
 *	CTCI-1.4
 *	replace_chars.cc
 *	Purpose: Given a string, convert all its spaces to %20
 *	
 *	@author Ankit Srivastava
 *	@version 1.0 8/22/2015
 */
 
#include "replace_spaces.h"

int main()
{
	string inputStr;
	int trueLength = 0;
	
	cout << "Input a string: ";
	getline(cin, inputStr);
	cout << "Input its true length: ";
	cin >> trueLength;
	
	int stringLength = inputStr.length();
	char *str = new char(stringLength+1);

	strcpy(str, inputStr.c_str());
	replaceSpaces(str, trueLength);
	
	cout << "Replaced string: " << str;
	
	return 0;
}

/**
 *	Function to take a pointer to character array along with its true length (excluding final spaces) and replace chars to '%20'
 */
void replaceSpaces(char* str, int length)
{
	char* ptr = str;
	int len = 0;	
	
	while(*ptr != '\0')
	{
		len++;
		ptr++;
	}
	
	for(int i = length - 1; i  >= 0 ; i--)
	{
		if(str[i] != ' ')
		{
			str[--len] = str[i];
		}
		else
		{
			str[--len] = '0';
			str[--len] = '2';
			str[--len] = '%';
		}
	}
}