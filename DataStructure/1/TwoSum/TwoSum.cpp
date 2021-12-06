#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		unordered_map<int, int> umap;
		for (int i = 0; i < nums.size(); i++)
		{
			if (umap.count(target - nums[i]))
			{
				return vector<int>{i, umap[target - nums[i]]};
			}
			else
			{
				umap[nums[i]] = i;
			}
		}

		return {};
	}
};

int main()
{
	vector<int> nums = { 2, 7, 11, 15 };
	int target = 9;
	Solution sln;
	sln.twoSum(nums, target);
}
