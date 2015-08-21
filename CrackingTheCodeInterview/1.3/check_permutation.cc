/**
 *	CTCI-1.3
 *	check_permutation.cc
 *	Purpose: Given two strings, check if one is permutation of another
 *	
 *	@author Ankit Srivastava
 *	@version 1.0 8/20/2015
 */
 
#include "check_permutation.h"

int main()
{
	cout << "Program to check if one string is permutation of another" << endl;
	cout << "--------------------------------------------------------" << endl << endl;
	cout << "Enter two strings: " << endl;
	
	string str1;
	string str2;
	
	cout << "String 1: ";
	getline(cin, str1);
	
	cout << "String 2: ";
	getline(cin, str2);
	
	bool isPermutation = checkPermutation(str1, str2);
	
	cout << "\"" << str1 << "\"" << (isPermutation ? " is a " : " is not a ") << " permutation of " << "\"" << str2 << "\"" << endl;
	
	return 0;
}

/**
 *	Check if str1 is permutation of str2
 *	@param str1 First String
 *	@param str2 Second String
 *	@return true if first string is permutation of second else false
 */
bool checkPermutation(string str1, string str2)
{
	if(str1.length() != str2.length())
	{
		return false;
	}
	
	int charTable[256] = {0};
	
	for(char &c : str1)
	{
		charTable[(int)c]++;
	}
	
	for(char &c : str2)
	{
		charTable[(int)c]--;
	}
	
	for(int i = 0; i < 256; i++)
	{
		if(charTable[i] != 0)
		{
			return false;
		}
	}
	
	return true;
}