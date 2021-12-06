# 解题思路
1. 若杂志长度小于赎金信长度，返回false
2. 对杂志遍历一遍，统计哈希表umap
3. 对赎金信遍历，若存在不在umap中元素，返回false，若存在umap中，则--，若--后小于0，返回false

### 代码

```cpp
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        if (magazine.size() < ransomNote.size())
            return false;

        unordered_map<char, int> umap;

        for (int i = 0; i < magazine.size(); i++)
            umap[magazine[i]]++;
        
        for (int j = 0; j < ransomNote.size(); j++)
        {
            if (umap.count(ransomNote[j]))
            {
                if (--umap[ransomNote[j]] < 0)
                    return false;
            }
            else
                return false;
        }

        return true;
    }
};
```

## 通过率
执行时间（90%） 内存消耗（10%）