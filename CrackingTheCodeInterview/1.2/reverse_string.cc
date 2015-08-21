/**
 *	CTCI-1.2
 *	reverse_string.cc
 *	Purpose: Reverse a null terminated string
 *
 *	@author: Ankit Srivastava
 *	@version 1.0 8/20/2015
 */
 
#include "reverse_string.h"
 
int main()
{
	string inputStr;
	
	cout << "Input a string: ";
	getline(cin, inputStr);
	
	char *str = new char[inputStr.length() + 1];
	strcpy(str, inputStr.c_str());
	
	reverse(str);
	
	cout << "Reversed String: " << str;
	
	return 0;
}

void reverse(char* str)
{
	int length = 0;
	char *cstr = str;
	
	while(*cstr != '\0')
	{
		cstr++;
		length++;
	}
	
	int j = length - 1;
	
	for(int i = 0; i < length/2; i++)
	{
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		
		j--;
	}
}