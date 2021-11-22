#include <iostream>
#include <vector>

using namespace std;

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

int main()
{
    vector<int> nums = { 1,2,3,4,5 };
    Solution sln(nums);
    vector<int> res;
    res = sln.shuffle();
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
    }
    cout << endl;
    res = sln.reset();
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
    }
    cout << endl;
}

