# 解题思路
1. 此题可用动态规划求解
2. 初始状态是每一行的0号元素和对角线元素都是1
3. 动态转移方程是ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j]

## 代码

```cpp
class Solution
{
public:
	vector<vector<int>> generate(int numRows)
	{
		vector<vector<int>> ans;
		ans.resize(numRows);
		for (int i = 0; i < numRows; i++)
		{
			ans[i].resize(i + 1);
			ans[i][0] = 1;
			ans[i][i] = 1;

			if (i >= 2)
			{
				for (int j = 1; j < i; j++)
				{
					ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
				}
			}
		}

		return ans;
	}
};
```

## 通过率
执行用时（100%） 内存消耗（85%）