/* Program: Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three numbers. 
 * You may assume that each input would have exactly one solution.
 * Author: Ankit Srivastava
 *
 * Date: 08/24/2017
 */

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int threeSumClosest(vector<int>& nums, int target)
	{
		int len = nums.size();	
		int j = 0, k = 0, t = 0;
		int tripletSum = 0;
		
		int closestSum = nums[0] + nums[1] + nums[2];
		int closestDiff = abs(target - closestSum);
		int diff = closestDiff;
		
		sort(nums.begin(), nums.end());
		
		for(int i = 0; i < len - 2; i++)
		{
			j = i + 1;
			k = len - 1;
			
			while(k > j)
			{
				tripletSum = nums[i] + nums[j] + nums[k];
				
				if(target == tripletSum)
				{		
					return tripletSum;
				}
				else if(target < tripletSum)
				{
					diff = tripletSum - target;
					k--;
				}
				else
				{
					diff = target - tripletSum;
					j++;
				}
				
				if(diff < closestDiff)
				{
					closestDiff = diff;
					closestSum = tripletSum;
				}
			}
		}
		
		return closestSum;
	}
};

int main()
{
	Solution s;
	vector<int> v{-3,-2,-5,3,-4};
	
	cout << s.threeSumClosest(v, -1);
	
	return 0;
}