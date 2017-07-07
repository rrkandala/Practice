/* Program: Match a string to a regex
 * Date: 7/6/2017
 * Author: Ankit Srivastava
 */
 
#include <iostream>
#include <string>

using namespace std;

bool isMatch(string s, string r);

int main()
{
	string s, p;
	
	cout << "Enter string: ";
	getline(cin, s);
	cout << "Enter regex (only * and . allowed): ";
	getline(cin, p);
	
	cout << isMatch(s, p) << endl;
}

bool isMatch(string s, string p)
{
	int sLen = s.length();
	int pLen = p.length();
	
	int i = 0;
	int j = 0; 
	
	char prevElem;
	
	while(i < pLen)
	{
		if(p[i] != '*' && p[i] != '.')
		{
			if(p[i] != s[j])
			{
				cout << "Not matching" << endl;
				return false;
			}
			else
			{
				prevElem = s[i];
				i++;
				j++;
			}
		}
		else if(p[i] == '.')
		{
			prevElem = '.';
			i++;
			j++;
		}
		else if(p[i] == '*')
		{
			i++;
			
			// End of regex expression
			if(i == pLen)
			{
				if(prevElem == '.')
				{
					cout << "Everything is allowed" << endl;
					return true;
				}
				else
				{
					while(j < sLen && s[j] == prevElem)
					{
						j++;
					}
					
					if(j < sLen)
					{
						cout << "Not matching previous element and regex ended" << endl;
						return false;
					}
				}
			}
			else
			{
				if(prevElem == '.')
				{
					while(j < sLen && s[j] != p[i])
					{
						j++;
					}
				}
				else
				{
					while(j < sLen && s[j] == prevElem)
					{
						j++;
					}
					
					if(j == sLen)
					{
						cout << "Regex not ended but string ended" << endl;
						return false;
					}
					else
					{
						if(s[j] != p[i])
						{
							cout << "
							return false;
						}
						else
						{
							prevElem = p[i];
							i++;
							j++;
						}
					}
				}
			}
		}
	}
	
	if(j < sLen)
	{
		return false;
	}
	else
	{
		return true;
	}
}