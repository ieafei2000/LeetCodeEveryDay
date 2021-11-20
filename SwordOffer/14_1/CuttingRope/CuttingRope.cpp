#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

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

int main()
{
	Solution sln;
	std::cout << sln.cuttingRope2(7) << std::endl;
}
