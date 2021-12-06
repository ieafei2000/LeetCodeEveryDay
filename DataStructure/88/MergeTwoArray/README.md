# 解题思路
1. 双指针i,j指向nums1，nums2。当有任意一个指针未达到数组末尾时即(i < m || j < n),判断
2. 若nums1到达末尾，则直接放入nums2，若nums2到达末尾，则直接放入nums1
3. 否则放入较小值即可

# 通过率
执行用时（100%） 内存消耗（30%）

# 代码

```cpp
class Solution
{
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		vector<int> ans;
		int i = 0, j = 0;

		while (i < m || j < n)
		{
			if (i == m)
				ans.push_back(nums2[j++]);
			else if (j == n)
				ans.push_back(nums1[i++]);
			else if (nums1[i] < nums2[j])
				ans.push_back(nums1[i++]);
			else
				ans.push_back(nums2[j++]);
		}

		nums1 = ans;
	}
};
```