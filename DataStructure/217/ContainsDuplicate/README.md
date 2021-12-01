
# 解题思路
1. 对数组进行排序，遍历一遍数组，若存在nums[i] == nums[i+1],则返回true，否则返回false
2. 采用unordered_map<int, int>count进行统计，若存在count[nums[i]] > 1,则表明存在某个元素重复2次级以上，则返回true

# 通过率
执行用时（90%） 内存耗时（80%）

# 代码一

```cpp
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
};
```
# 通过率
执行用时（50%） 内存耗时（50%）

# 代码二
```
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
```
