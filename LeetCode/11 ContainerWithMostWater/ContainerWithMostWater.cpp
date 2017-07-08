/* Program: Find container with most water
 * Date: 7/8/2017
 * Author: Ankit Srivastava
 */
 
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int maxArea(vector<int>& height)
	{
		int len = height.size();
		int max = 0;
		int area = 0;
		int minHeight = 0;
		int width = 0;
		
		for(int i = 0; i < len; i++)
		{
			for(int j = len-1; j > i; j--)
			{
				width = j - i;
				
				if(max < width * height[i])
				{
					if(height[i] < height[j])
					{
						minHeight = height[i];
					}
					else
					{
						minHeight = height[j];
					}
					
					area = (j-i) * minHeight;
					
					if(area > max)
					{
						max = area;
					}
				}
				else
				{
					break;
				}
			}
		}
		
		return max;
	}
};

int main()
{
	Solution s;
	
	int heights[] = {1,1};
	vector<int> heightsVec(heights, heights + sizeof(heights) / sizeof(int));
	cout << s.maxArea(heightsVec) << endl;
}