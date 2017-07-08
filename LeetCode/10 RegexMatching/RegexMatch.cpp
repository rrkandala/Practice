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
	
	cout << (isMatch(s, p) ? "true" : "false") << endl;
}

bool isMatch(string s, string p)
{
	int sLen = s.length();
	int pLen = p.length();
	
	int i = 0;
	int j = 0; 
	
	char prevElem = '\0';
	
	while(i < pLen)
	{
		cout << "Prev Elem: " << prevElem << endl;
        cout << "i: " << i << endl;
        cout << "j: " << j << endl;
        cout << "p[i]: " << p[i] << endl;
        cout << "s[j]: " << s[j] << endl;
        cout << endl;
		
		if(p[i] != '*' && p[i] != '.')
		{
			if(p[i] != s[j])
			{
				// It could be that next elem is asterisk and we are fine not matching
				if(i+1 < pLen && p[i+1] == '*')
				{
					cout << "Hit asterisk at next char" << endl;
					i++;
				}
				else
				{
					return false;
				}
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
			if(i-1 >= 0)
			{
				prevElem = p[i-1];
			}
			
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
				// It could be that prevElem and nextElem of asterisk is same
				else if(p[i] == prevElem)
				{
					while(j < sLen && s[j] == prevElem)
					{
						j++;
					}
					
					j--;
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
							cout << "Regex not ended, string not ended but string not matching" << endl;
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
		cout << "Still some chars left in string" << endl;
		return false;
	}
	else
	{
		return true;
	}
}