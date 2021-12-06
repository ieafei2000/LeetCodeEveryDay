# 解题思路
1. 采用dp[i]表示以下标i对应元素结尾的最长字串和
2. 则dp[i] = max{dp[i-1] + nums[i], nums[i]}，即要么nums加入，要么nums单独成一段，遍历dp数组，取最大值即可
3. 进一步发现，并不需要保存所有dp[i]且dp[i]只与dp[i-1]有关，故每次只需采用一个变量temp存贮dp[i]即可，同时更新temp最大值

# 通过率
执行用时（65%） 内存消耗（60%）

# 代码

```cpp
class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int maxSum = nums[0], temp = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            temp = max(temp + nums[i], nums[i]);
            maxSum = max(maxSum, temp);
        }
        return maxSum;
    }
};
```