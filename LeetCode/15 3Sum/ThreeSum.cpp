/* Program: Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0. Find all unique triplets in the array which gives sum of zero
 * Author: Ankit Srivastava
 *
 * Date: 8/23/2017
 */
 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		vector<vector<int>> results;
		vector<int> triplet;
		
		sort(nums.begin(), nums.end());
		
		int len = nums.size();
		int j = 0, k = 0, candidate = 0, target = 0;
		vector<int> targets;
		
		for(int i = 0; i < len - 2; i++)
		{
			target = (-1) * nums[i];
			
			if (find(targets.begin(), targets.end(), target) == targets.end())
			{
				targets.push_back(target);
				
				j = i + 1;
				k = len - 1;
				
				while(k > j)
				{	
					candidate = nums[j] + nums[k];
					
					if(target == candidate)
					{
						triplet.push_back(nums[i]);
						triplet.push_back(nums[j]);
						triplet.push_back(nums[k]);
						results.push_back(triplet);
						triplet.clear();
						k--;
						j++;
						
						
						while(k > j && nums[j] == nums[j-1])
						{
							j++;
						}
						while(k > j && nums[k] == nums[k+1])
						{
							k--;
						}
					}
					else if(candidate < target)
					{
						j++;
					}
					else
					{
						k--;
					}
				}
			}
			else
			{
				continue;
			}
		}
		
		return results;
	}
};

int main()
{
	Solution s;
	vector<int> nums{-1, 0, 1, 2, -1, -4};
	vector<vector<int>> res = s.threeSum(nums);
	
	for(int i = 0; i < res.size(); i++)
	{
		cout << "{" << res[i][0] << ", " << res[i][1] << ", " << res[i][2] << "}" << endl;
	}
}