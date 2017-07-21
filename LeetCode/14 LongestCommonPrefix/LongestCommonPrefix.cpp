/* Program: Find longest common prefix in an array of strings
 * Author: Ankit Srivastava
 * Date: 7/21/2017
 */
 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
	public:
	string longestCommonPrefix(vector<string>& strs) 
	{
		string lcp;
		char c;
		int numStrings = strs.size();
		bool toAppend = true;
		
		if(numStrings == 0)
		{
			return "";
		}
		else if(numStrings == 1)
		{
			return strs[0];
		}
		else
		{
			int minLength = strs[0].length();
			
			for(int k = 1; k < numStrings; k++)
			{
				if(strs[k].length() < minLength)
				{
					minLength = strs[k].length();
				}
			}
			
			for(int i = 0; i < minLength; i++)
			{
				for(int j = 1; j < numStrings; j++)
				{
					c = strs[0][i];
					
					if(strs[j].length() <= i)
					{
						toAppend = false;
						break;
					}
					else
					{
						if(strs[j][i] != c)
						{
							toAppend = false;
							break;						 
						}
					}
				}
				
				if(toAppend)
				{
					lcp.push_back(c);
				}
				else
				{
					break;
				}
			}
			
			return lcp;
		}

    }
};

int main()
{
	Solution s;
	
}