# 解题思路
1. 对每行采用哈希表计数，若存在非.键对应值>1，无效返回false
2. 对每列采用哈希表计数，若存在非.键对应值>1，无效返回false
3. 对每个9宫格采用哈希表计数，若存在非.键对应值>1，无效返回false（每次i+=3, j+=3）

## 代码

```cpp
class Solution
{
public:
	bool isValidSudoku(vector<vector<char>>& board)
	{
		unordered_map<char, int> umap;

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] != '.')
					umap[board[i][j]]++;
			}
			for (auto iter : umap)
			{
				if (iter.first != '.' && iter.second > 1)
					return false;
			}
			umap.clear();
		}

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (board[j][i] != '.')
					umap[board[j][i]]++;
			}
			for (auto iter : umap)
			{
				if (iter.first != '.' && iter.second > 1)
					return false;
			}
			umap.clear();
		}

		for (int i = 0; i <= 6; i += 3)
		{
			for (int j = 0; j <= 6; j += 3)
			{
				umap[board[i][j]]++;
				umap[board[i][j + 1]]++;
				umap[board[i][j + 2]]++;

				umap[board[i + 1][j]]++;
				umap[board[i + 1][j + 1]]++;
				umap[board[i + 1][j + 2]]++;

				umap[board[i + 2][j]]++;
				umap[board[i + 2][j + 1]]++;
				umap[board[i + 2][j + 2]]++;

				for (auto iter : umap)
				{
					if (iter.first != '.' && iter.second > 1)
						return false;
				}
				umap.clear();
			}
		}
		return true;
	}
};
```

## 通过率
执行用时（60%） 内存消耗（30%）