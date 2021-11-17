#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findRepeatNumber(vector<int>& nums) 
{
	unordered_map<int, int> numCnt;
	int res = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		numCnt[nums[i]]++;
		if (numCnt[nums[i]] > 1)
		{
			res = nums[i];
			break;
		}
	}

	return res;
}

int main()
{
	vector<int> nums = { 1, 1, 1 };

	cout << findRepeatNumber(nums);
}

