#include <iostream>
#include <string>

using namespace std;

class Solution
{
	public:
		string longestPalindrome(string input)
		{
			string substr;
			string a = input;
			
			int back = 0;
			int front = 0;
			int start = 0;
			int end = 0;
			int finalStart = 0;
			int finalEnd = 0;
			int diff = 0;
			int len = input.size();
			
			for(int i = 1; i < len; i++)
			{
				back = 0;
				front = 0;
				start = i;
				end = i;
				
				while(i - back - 1 >= 0 && a[i-back - 1] == a[i])
				{
					back++;
				}
				
				while(i + front + 1 < len && a[i+front+1] == a[i])
				{
					front++;
				}
				
				diff = 0;
				
				while((i-back-diff-1 >= 0) && (i+front+diff+1< len) && a[i-back-diff-1] == a[i+front+diff+1])
				{
					diff++;
				}
				
				if(((finalEnd - finalStart)) < ((i+front+diff) - (i-back-diff)))
				{
					finalStart = i - back - diff;
					finalEnd = i + front + diff;
				}
			}
			
			return substr.append(a, finalStart, (finalEnd - finalStart + 1));
		}
};
