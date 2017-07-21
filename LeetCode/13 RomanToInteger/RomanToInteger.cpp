/* Program: Convert roman string to integer
 * Author: Ankit Srivastava
 * Date: 7/20/2017
 */
 
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	int romanToInt(string s)
	{
		int val = 0;
		string sub;
		int len = s.length();
		
		for(int i = 0; i < len; i++)
		{
			if(i < len - 1)
			{
				sub = s.substr(i, 2);
				if(sub == "CM" || sub == "CD" || sub == "XC" || sub == "XL" || sub == "IX" || sub == "IV")
				{
					i++;
				}
				else
				{
					sub = s.substr(i, 1);
				}
			}
			else
			{
				sub = s.substr(i, 1);
			}
			
			val = val + GetInt(sub);
		}
		
		return val;
	}
	
	int GetInt(string roman)
	{
		if(roman == "M")
		{
			return 1000;
		}
		else if(roman == "CM")
		{
			return 900;
		}
		else if(roman == "D")
		{
			return 500;
		}
		else if(roman == "CD")
		{
			return 400;
		}
		else if(roman == "C")
		{
			return 100;
		}
		else if(roman == "XC")
		{
			return 90;
		}
		else if(roman == "L")
		{
			return 50;
		}
		else if(roman == "XL")
		{
			return 40;
		}
		else if(roman == "X")
		{
			return 10;
		}
		else if(roman == "IX")
		{
			return 9;
		}
		else if(roman == "V")
		{
			return 5;
		}
		else if(roman == "IV")
		{
			return 4;
		}
		else
		{
			return 1;
		}
	}
};

int main()
{
	Solution s;
	string inputRoman;
	
	cout << "Enter a string: ";
	cin >> inputRoman;
	
	cout << s.romanToInt(inputRoman) << endl;
}