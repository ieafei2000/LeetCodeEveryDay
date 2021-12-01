#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
                return true;
        }
        return false;
    }

    bool containsDuplicate2(vector<int>& nums)
    {
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size(); i++)
        {
            if (++count[nums[i]] > 1)
                return true;
        }
        return false;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

