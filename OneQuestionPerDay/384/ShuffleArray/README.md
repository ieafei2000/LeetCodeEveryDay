# 解题思路
一开始，只是单纯的想到随机得到两个index，然后交换数组中两个index对应的值，但是提交一直报错，后面看了题解区大佬的提示，原来这是洗牌算法，每次对数组shuffle就相当于是对n个元素的随机全排列。因此需要走一遍遍历，每次都从未挑选元素中，随机得到一个index与当前i对应元素交换即可
ps：交换采用了位运算加快速度，并且不需要中间变量，但需要注意的是，若交换的元素是同一个值，则会出现0的结果，因此需要判断一下

# 耗时
执行用时（60%） 内存消耗（60%）

# 代码

```cpp
class Solution
{
public:
    Solution(vector<int>& nums)
    {
        mOrigin = nums;
    }

    vector<int> reset()
    {
         return mOrigin;
    }

    vector<int> shuffle()
    {
        vector<int> mShuffle = mOrigin;
        for (int i = 0; i < mShuffle.size(); i++)
        {
            int index = i + rand() % (mShuffle.size() - i);

            if (index != i)
            {
                mShuffle[i] = mShuffle[i] ^ mShuffle[index];
                mShuffle[index] = mShuffle[i] ^ mShuffle[index];
                mShuffle[i] = mShuffle[i] ^ mShuffle[index];
            }

        }
        return mShuffle;
    }  
private:
    vector<int> mOrigin;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
```