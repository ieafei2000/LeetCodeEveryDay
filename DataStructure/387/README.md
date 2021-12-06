# 解题思路
1. 采用哈希表统计字符出现频率
2. 键值对为<字符，<字符出现次数，字符对应最后下标>>
3. 第一次遍历计算哈希表，第二次遍历哈希表计算出只出现一次的字符对应最小下标

## 代码

```cpp
class Solution
{
public:
	int firstUniqChar(string s)
	{
		unordered_map<char, pair<int, int>> umap;

		for (int i = 0; i < s.size(); i++)
		{
			umap[s[i]].first++;
			umap[s[i]].second = i;
		}

		int index = INT_MAX;

		for (auto iter : umap)
		{
			if (iter.second.first == 1)
			{
				index = iter.second.second < index ? iter.second.second : index;
			}
		}

        return index == INT_MAX ? -1 : index;

	}
};
```

# 通过率
执行用时（35%） 内存消耗（6%）