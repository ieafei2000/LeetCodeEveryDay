# 解题思路
1. 若s与t长度不等，返回false
2. 采用数组对s中字符计数
3. 对t中字符，数组对应--，若小于0，表明在s中没有该字符或者t中出现次数大于s，返回false

## 代码

```cpp
class Solution 
{
public:
    bool isAnagram(string s, string t) 
    {
        int count[26] = { 0 };

        if (s.size() != t.size())
            return false;

        for (int i = 0; i < s.size(); i++)
        {
            count[s[i] - 'a']++;
        }

        for (int j = 0; j < t.size(); j++)
        {
            if (--count[t[j] - 'a'] < 0)
                return false;
        }
        
        return true;
    }
};
```

## 通过率
执行用时（95%） 内存消耗（60%）