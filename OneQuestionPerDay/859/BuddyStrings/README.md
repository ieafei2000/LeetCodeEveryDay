# 解题思路
1. 首先判定s与goal长度是否相等，若不相等，则直接返回false
2. 若s与goal相等，即s==goal，则在s中当且仅当某个字母出现频率大于2，与goal为buddy strings
3. 若s != goal，则采用first，second标记s与goal字符串中前两次不相等的下标，若除此之外还有不相等则直接返回false（大于两个不相等的字母），而后判定second是否为-1（若为-1，则表明只有一个不相等的下标，返回false，first必定不为-1，因为前提是s!=goal）且s[first] == goal[second] && s[second] == goal[first]即可

# 通过率
执行用时（75%） 内存消耗（50%）

# 代码

```cpp
class Solution
{
public:
    bool buddyStrings(string s, string goal)
    {   
        bool res = false;
        if (s.length() != goal.length())
        {
            return false;
        }
        if (s == goal)
        {

            map<char, int> count;
            for (int i = 0; i < s.length(); i++)
            {
                if (++count[s[i]] > 1)
                    return true;
            }
            return false;
        }
        else
        {
            int first = -1, second = -1;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] != goal[i])
                {
                    if (first == -1)
                        first = i;
                    else if (second == -1)
                        second = i;
                    else
                        return false;
                }
            }
            return (second != -1 && s[first] == goal[second] && s[second] == goal[first]);
        }
    }
private:
};
```