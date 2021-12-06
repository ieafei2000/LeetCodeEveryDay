# 解题思路
1. 暴力遍历，时间复杂度O（n²）
2. 哈希表，一次遍历nums数组，每次查询在当前map中是否含有target-nums[i]，若有则直接返回，若无则map[nums[i]] = i（将值与下标reverse）

# 通过率
执行耗时（70%） 内存消耗（20%）

# 代码

```cpp
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
```