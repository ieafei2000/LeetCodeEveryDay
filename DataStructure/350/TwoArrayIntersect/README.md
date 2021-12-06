# 解题思路
1. 首先想到hash，对nums1统计一边hash，在遍历nums2，每当遇到map[nums2[i]] > 0时，也就是此时nums2[i]对应元素在map中已存在，即该元素为两个数组交集，同时对应map值-1
2. 对两个数组进行排序后，双指针对两个数组进行遍历，需要注意的是结束条件是两个指针需都小于数组长度，因为若存在一个指针大于对应数组size，表明当前数组已经遍历完，不可能在有交集元素存在。

## 代码一

```cpp
class Solution
{
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
	{
		int i = 0, j = 0;
		vector<int> ans;
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());

		while (i < nums1.size() && j < nums2.size())
		{
			if (nums1[i] == nums2[j])
			{
				ans.push_back(nums1[i]);
				i++;
				j++;
			}
			else if (nums1[i] < nums2[j])
				i++;
			else
				j++;
		}
		return ans;
	}
};
```

## 通过率
执行用时（45%） 内存消耗（25%）


## 代码二
```
vector<int> intersect2(vector<int>& nums1, vector<int>& nums2)
	{
		int i = 0, j = 0;
		vector<int> ans;
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());

		while (i < nums1.size() && j < nums2.size())
		{
			if (nums1[i] == nums2[j])
			{
				ans.push_back(nums1[i]);
				i++;
				j++;
			}
			else if (nums1[i] < nums2[j])
				i++;
			else
				j++;
		}
		return ans;
	}
```

## 通过率
执行用时（100%） 内存消耗（80%）
