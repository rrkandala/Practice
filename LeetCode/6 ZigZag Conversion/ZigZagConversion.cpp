#include <iostream>
#include <string>

using namespace std;

class Solution
{
	public:
		string convert(string s, int numRows)
		{
			int len = s.size();
			string res;
			int currRow = 0;
			int upperLimit = numRows - 1;
			int lowerLimit = 0;
			bool gofront = true;
			
			if(numRows == 1)
			{
				return s;
			}
			else if(numRows == 2)
			{
				for(int i = 0; i < len; i+=2)
				{
					res.append(s, i, 1);
				}
				
				for(int i = 1; i < len; i+=2)
				{
					res.append(s, i, 1);
				}
			}
			else
			{
				for(int i = 0; i < numRows; i++)
				{
					currRow = i;
					gofront = true;
					
					for(int j = i; j < len; j++)
					{
						if(currRow == i)
						{
							res.append(s, j , 1);
						}
						
						if(gofront && currRow < numRows - 1)
						{
							currRow++;
						}
						else if(gofront && currRow == numRows -1)
						{
							gofront = false;
							currRow--;
						}
						else if(!gofront && currRow > 0)
						{
							currRow--;
						}
						else
						{
							gofront = true;
							currRow++;
						}
					}
				}
			}
			
			return res;
		}
};