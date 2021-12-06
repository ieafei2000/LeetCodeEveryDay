# 解题思路
1. 动态规划，dp[i] 表示在第i天卖出获得的最大利润，则dp[i] = max(dp[i-1], prices[i] - minPrice)
2. 发现dp[i]只与dp[i-1]有关，故可以采用临时变量temp更新dp[i]，同时采用maxProfit更新dp[i]最大值即可

## 代码

```cpp
class Solution
{
public:
	int maxProfit(vector<int>& prices)
	{
		//profits[i]表示第i天卖出获得的最大利润
		int minPrice = INT_MAX;
		int tempProfit = 0;
		int maxProfit = 0;

		for (int i = 0; i < prices.size(); i++)
		{
			//统计股票在前i天最小价格值
			minPrice = prices[i] < minPrice ? prices[i] : minPrice;
			tempProfit = max(tempProfit, prices[i] - minPrice);
			maxProfit = max(tempProfit, maxProfit);
		}
		return maxProfit;
	}
};
```

## 通过率
执行用时（75%） 内存消耗（98%）