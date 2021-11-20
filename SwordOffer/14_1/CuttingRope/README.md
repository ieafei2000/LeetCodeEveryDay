# 题解思路
没有写出来，参考了答案的动态递归和贪心算法，还是自己太菜了

# 代码
```
class Solution
{
public:
	int cuttingRope(int n)
	{
		dp.resize(n + 1);
		dp[2] = 1;
		for (int i = 3; i <= n; i++)
		{
			for (int j = 2; j < i; j++)
			{
				dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
			}
		}
		return dp[n];
	}

	int cuttingRope2(int n)
	{
		if (n == 2)
		{
			return 1;
		}
		if (n == 3)
		{
			return 2;
		}
		if (n == 4)
		{
			return 4;
		}
		int sum = 1;
		while (n > 4)
		{
			sum *= 3;
			n -= 3;
		}
		return sum * n;
	}

private:
	vector<int> dp;
};
```

