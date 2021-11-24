# 解题思路
本题我采用的是消元法，通过观察，可以发现每一个字符串都有独有的字母
1. 首先第一次筛选出zero(z),two(w),four(u),six(x),eight(g)
2. 第二次则可以直接筛选出所有剩余字符串，如下图所示
3. 因此可以通过map计数，逐个消元即可，同时定义cnt[10]用来表示最终数字对应的个数
![164351e2779965af56ea9d27f6663da.jpg](https://pic.leetcode-cn.com/1637723671-qDlHez-164351e2779965af56ea9d27f6663da.jpg)
（map也更换为int数组，对应为'' - 'a'）
4. 也可以通过已经筛选出来的，得到剩下的，如代码二

# 通过率
执行用时（40%） 内存消耗（75%）

# 代码一

```cpp
class Solution 
{
public:
    string originalDigits(string s) 
    {
        int cnt[10] = {0};
        string nums[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
        int count[27] = { 0 };
        //map<char, int> count;
        for (int i = 0; i < s.size(); i++)
            count[s[i] - 'a']++;
        while (count['z' - 'a'] > 0)
        {
            for (int i = 0; i < nums[0].size(); i++)
                count[nums[0][i] - 'a']--;
            cnt[0]++;
        }
        while (count['w' - 'a'] > 0)
        {
            for (int i = 0; i < nums[2].size(); i++)
                count[nums[2][i] - 'a']--;
            cnt[2]++;
        }
        while (count['u' - 'a'] > 0)
        {
            for (int i = 0; i < nums[4].size(); i++)
                count[nums[4][i] - 'a']--;
            cnt[4]++;
        }
        while (count['x' - 'a'] > 0)
        {
            for (int i = 0; i < nums[6].size(); i++)
                count[nums[6][i] - 'a']--;
            cnt[6]++;
        }
        while (count['g' - 'a'] > 0)
        {
            for (int i = 0; i < nums[8].size(); i++)
                count[nums[8][i] - 'a']--;
            cnt[8]++;
        }
        while (count['o' - 'a'] > 0)
        {
            for (int i = 0; i < nums[0].size(); i++)
                count[nums[0][i] - 'a']--;
            cnt[1]++;
        }
        while (count['t' - 'a'] > 0)
        {
            for (int i = 0; i < nums[3].size(); i++)
                count[nums[3][i] - 'a']--;
            cnt[3]++;
        }
        while (count['f' - 'a'] > 0)
        {
            for (int i = 0; i < nums[5].size(); i++)
                count[nums[5][i] - 'a']--;
            cnt[5]++;
        }
        while (count['s' - 'a'] > 0)
        {
            for (int i = 0; i < nums[7].size(); i++)
                count[nums[7][i] - 'a']--;
            cnt[7]++;
        }
        cnt[9] = count['i' - 'a'];

        string res = "";
        for (int i = 0; i <= 9; i++)
        {
            while (cnt[i] > 0)
            {
                res += to_string(i);
                cnt[i]--;
            }
        }
        return res;
    }
};
```
# 代码二
```
class Solution 
{
public:
    string originalDigits(string s) 
    {
        int cnt[10] = {0};
        map<char, int> count;
        for (int i = 0; i < s.size(); i++)
            count[s[i]]++;

        cnt[0] = count['z'];
        cnt[2] = count['w'];
        cnt[4] = count['u'];
        cnt[6] = count['x'];
        cnt[8] = count['g'];

        cnt[3] = count['t'] - cnt[2] - cnt[8];
        cnt[5] = count['f'] - cnt[4];
        cnt[7] = count['s'] - cnt[6];

        cnt[1] = count['o'] - cnt[0] - cnt[2] - cnt[4];
        cnt[9] = count['i'] - cnt[5] - cnt[6] - cnt[8];

        string res = "";
        for (int i = 0; i <= 9; i++)
        {
            while (cnt[i] > 0)
            {
                res += to_string(i);
                cnt[i]--;
            }
        }
        return res;
    }
};
```
