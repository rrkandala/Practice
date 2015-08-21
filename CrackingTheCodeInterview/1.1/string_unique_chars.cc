/**
 *	CTCI-1.1
 *	string_unique_chars.cc
 *	Purpose: Implement an algorithm to determine if a string has all unique characters
 *	
 *	@author Ankit Srivastava
 *	@version 1.0 8/20/2015
 */

#include "string_unique_chars.h"

// Controla operation of the program
int main()
{
	string inputStr;
	
	cout << "Enter a string: ";
	
	
	getline(cin, inputStr);
	
	bool hasUniqueChars = checkUniqueChars(inputStr);
	
	cout << "Input String: \"" << inputStr << "\" has " << (hasUniqueChars ? " all unique characters" : "duplicate characters");
	
	return 0;
}

/**
 *	Function to take an input string and determine if it has unique characters or not
 *	
 *	@param inputStr Input String
 *	@return If the input string has no duplicate chars, then return true else false
 */
bool checkUniqueChars(string inputStr)
{
	// 1 character is a byte and can contain 256 values
	int charTable[256] = { 0 };
	
	for(char& c : inputStr)
	{
		int intC = (int)c;
		
		if(charTable[intC] == 0)
		{
			charTable[intC] = 1;
		}
		else
		{
			return false;
		}
	}
	
	return true;
}