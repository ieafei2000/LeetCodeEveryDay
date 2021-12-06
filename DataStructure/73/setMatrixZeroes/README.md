# 解题思路
1. 采用两个哈希表，一个记录需要置0的行，一个记录需要置0的列，遍历一遍matrix计算哈希表的值
2. 遍历两个哈希表，对矩阵置0

## 代码

```cpp
class Solution
{
public:
	void setZeroes(vector<vector<int>>& matrix)
	{
		int m = matrix.size();
		int n = matrix[0].size();

		unordered_map<int, int> umapRows;
		unordered_map<int, int> umapCols;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] == 0)
				{
					umapRows[i]++;
					umapCols[j]++;
				}
			}
		}
		//行置0
		for (auto iter : umapRows)
		{
			for (int j = 0; j < n; j++)
			{
				matrix[iter.first][j] = 0;
			}
		}
		//列置0
		for (auto iter : umapCols)
		{
			for (int i = 0; i < m; i++)
			{
				matrix[i][iter.first] = 0;
			}
		}

	}
};
```

## 通过率
执行用时（80%） 内存消耗（15%）