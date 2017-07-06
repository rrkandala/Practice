/* Program: Convert an input string which is an acceptable integer to In32 format
 * Date: 7/6/2017
 */
 
// #include <iostream>
// #include <string>

// using namespace std;

// int myAtoi(string str);

class Solution
{
	public:
		int myAtoi(string str)
		{
			int len = str.length();
			bool isIntNeg = false;
			long result = 0;
			int firstNonWhiteSpaceChar = 0;
			int lastNumericChar = 0;
			int asciiChar = 0;
			
			// Special case of string being empty
			if(len == 0)
			{
				return (int)result;
			}
			else
			{	
				while(firstNonWhiteSpaceChar < len)
				{
					if(!isspace(str[firstNonWhiteSpaceChar]))
					{
						break;
					}
					
					firstNonWhiteSpaceChar++;
				}				
				
				// Special case of all whitespaces
				if(firstNonWhiteSpaceChar == len)
				{
					return (int)result;
				}
				else
				{
					// Checking for optional plus or minus sign
					if(str[firstNonWhiteSpaceChar] == '-')
					{
						isIntNeg = true;
						firstNonWhiteSpaceChar++;
					}
					else if(str[firstNonWhiteSpaceChar] == '+')
					{
						firstNonWhiteSpaceChar++;
					}
					
					// Set last Numeric character
					int i = firstNonWhiteSpaceChar;
					
					while(i < len)
					{
						asciiChar = (int)str[i] - 48;
						if(asciiChar < 0 || asciiChar > 9)
						{
							break;
						}
						
						i++;
					}
					
					lastNumericChar = i-1;
					
					// Check if lastNumericChar is lesser than firstNonWhiteSpaceChar
					if(lastNumericChar < firstNonWhiteSpaceChar)
					{
						return 0;
					}
					
					// Check if there are any non-whitespace chars after that
					for(int i = lastNumericChar+1; i < len; i++)
					{
						if(!isspace(str[i]))
						{
							return 0;
						}
					}
					
					// Legit integer at hand if you reached so far
					for(int i = firstNonWhiteSpaceChar; i <= lastNumericChar; i++)
					{
						result = (result*10) + ((int)str[i]-48);
					}
					
					// Check if number is negative
					if(isIntNeg == true)
					{
						result = result * -1;
					}
					
					// Check if number is beyond representable values
					if(result > INT_MAX)
					{
						return INT_MAX;
					}
					else if(result < INT_MIN)
					{
						return INT_MIN;
					}
					else
					{
						return (int)result;
					}
				}
			}
		}
		
	// int main()
	// {
		// string inputStr;
		
		// cout << "Enter string to convert to integer: ";
		// getline(cin, inputStr);
		
		// cout << myAtoi(inputStr);
	// }
};