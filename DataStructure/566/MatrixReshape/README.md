# 解题思路
1. 首先判断m\*n == r\*c，若不相等，则表明矩阵不匹配，无法重塑，返回原始矩阵
2. 若相等，则首先根据关系temp[i * n + j] = mat[i][j]映射到一维数组temp，再重新填充r\*c的矩阵即可

## 代码

```cpp
class Solution
{
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c)
	{
		int m = mat.size();
		int n = mat[0].size();

		if (m * n != r * c)
			return mat;
		else
		{
			vector<int> temp;
			temp.resize(m * n);

			vector<vector<int>> ans;
			ans.resize(r);
			for (int i = 0; i < r; i++)
				ans[i].resize(c);

			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
					temp[i * n + j] = mat[i][j];
			}

			int k = 0;
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
					ans[i][j] = temp[k++];
			}

			return ans;
		}
	}
};
```

## 通过率
执行用时（98%） 内存消耗（80%）