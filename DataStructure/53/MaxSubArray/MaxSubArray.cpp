#include <iostream>
#include <vector>

using namespace std;

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

int main()
{
    std::cout << "Hello World!\n";
}

