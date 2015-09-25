/** CTCI-1.8
 *	Purpose: Check if one string is a rotation of another. You are given one call to isSubstring handy to implement
 *
 *	Author: Ankit Srivastava
 *	Date: 9/8/2015
 */
 
#include "is_string_rotated.h"

int main()
{
	string str1;
	string str2;
	
	cout << "Enter string 1: ";
	getline(cin, str1);
	
	cout << "Enter string 2: ";
	getline(cin, str2);
	
	string result = (isRotated(str1, str2) == true) ? " is " : " is not ";
	
	cout << "String 1: " << str1 << result << "a rotation of String 2: " << str2;
	
	return 0;
}

// Check if str1 is a substring of str2
bool isSubstring(string str1, string str2)
{
	int len1 = str1.length();
	int len2 = str2.length();
	
	if(len1 > len2)
	{
		return false;
	}
	
	int j = 1;
	
	for(int i = 0; i < len2; i++)
	{
		if(str1[0] == str2[i])
		{
			int k = i+1;
			
			for(j = 1; j < len1 && k < len2; j++)
			{
				if(str1[j] == str2[k])
				{
					k++;
				}
				else
				{
					break;
				}
			}
			
			if(j == len1)
			{
				return true;
			}
		}
	}
	
	return false;
}

bool isRotated(string str1, string str2)
{
	int len1 = str1.length();
	int len2 = str2.length();
	
	string str3 = str1 + str1;
	
	if(len1 != len2)
	{
		return false;
	}
	
	if(isSubstring(str2, str3))
	{
		return true;
	}
	else
	{
		return false;
	}
}