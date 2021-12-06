#include <iostream>
#include <vector>

using namespace std;

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

int main()
{
	std::cout << "Hello World!\n";
}
