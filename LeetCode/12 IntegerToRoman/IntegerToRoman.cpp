/* Program: Convert an integer to roman string
 * Date: 7/9/2017
 * Author: Ankit Srivastava
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;
 
class Solution
{
public:
	string intToRoman(int num)
	{
		int n = num;
		int remainder = 0;
		string ans;
		int counter = 1;
		string roman; 
		
		while(n > 0)
		{
			remainder = n % 10;
			roman = GetRoman(remainder * counter);
			
			if(roman != "")
			{
				ans.insert(0, roman);
			}
			n = n / 10;
			counter = counter * 10;
		}
		
		return ans;
	}
	
	string GetRoman(int val)
	{
		int quotient = 0;
		int base = 0;
		string c;
		
		if(val >= 1000)
		{
			base = 1000;
			c = 'M';
		}
		else if(val >= 900)
		{
			c = 'CM';
			return c;
		}
		else if(val >= 500)
		{
			base = 500;
			c = "D";
		}
		else if(val >= 400)
		{
			c = "CD";
			return c;
		}
		else if(val >= 100)
		{
			base = 100;
			c = "C";
		}
		else if(val >= 90)
		{
			c = "XC";
			return c;
		}
		else if(val >= 50)
		{
			base = 50;
			c = "L";
		}
		else if(val >= 40)
		{
			c = "XL";
			return c;
		}
		else if(val >= 10)
		{
			base = 10;
			c = "X";
		}
		else if(val >= 9)
		{
			c = "IX";
			return c;
		}
		else if(val >= 5)
		{
			base = 5;
			c = "V";
		}
		else if(val >= 4)
		{
			c = "IV";
			return c;
		}
		else if(val >= 1)
		{
			base = 1;
			c = "I";
		}
		else
		{
			base = 0;
			c = "";
		}
		
		quotient = val / base;
		string res; 
		
		for(int i = 0; i < quotient; i++)
		{
			res = res.append(c);
			cout << res << endl;
		}
		
		return res;
	}
};

int main()
{
	Solution s;
	int inputNum = 0;
	
	cout << "Enter integer between 1 to 3999: ";
	cin >> inputNum;
	
	cout << s.intToRoman(inputNum);
}