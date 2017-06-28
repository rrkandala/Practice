#include <iostream>

using namespace std;
class Solution
{
	public:
	int reverse(int x)
	{
		long val = 0;
		
		long res = 0;
		int remainder = 0;
		
		if(x < 0)
		{
			val = -1 * (long)x;
		}
		else
		{
			val = (long)x;
		}
		
		while(val >= 10)
		{
			remainder = val % 10;
			val = val / 10;
			res = res * 10 + remainder;
		}
		
		res = res * 10 + val;
		
		if(x < 0)
		{
			res = -1 * res;
		}
		
		if(x < 0 && res < INT_MIN)
		{
			return 0;
		}
		else if(x > 0 && res > INT_MAX)
		{
			return 0;
		}
		else
		{
			return res;
		}
	}
};