/**
 *	CTCI-1.5
 *	Compressing a string from aaabbbbbccc to a3b5c3 only if it reduces its length
 *
 *	Author: Ankit Srivastava
 *	09/04/2015
 */
 
#include "compress_repeated_chars.h"

int main()
{
	string inputStr;
	
	cout << "Enter string to be compressed: ";
	getline(cin, inputStr);
	
	cout << "Compressed String: " << compressString(inputStr);
	
	return 0;
}
 
/*
 *	Function which takes a string as input and performs basic string compression on repeated consecutive chars
 *	If it is unable to reduce the original string's length then the original string is returned
*/
string compressString(string inputStr)
{
	int len = inputStr.length();
	string outputStr;
	
	if(len <= 1)
	{
		return inputStr;
	}
	else
	{
		int inc = 1;
		char c = inputStr[0];
		
		for(unsigned int i = 1; i <= len; i++)
		{
			if(i != len && inputStr[i] == c)
			{
				inc++;
			}
			else
			{
				outputStr = outputStr + c;
				outputStr = outputStr + to_string(inc);
				
				inc = 1;
				c = inputStr[i];
			}
		}
		
		if(len > outputStr.length())
		{
			return outputStr;
		}
		else
		{
			return inputStr;
		}
	}
}