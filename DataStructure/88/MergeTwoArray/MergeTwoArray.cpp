#include <iostream>
#include <vector>

using namespace std;

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

int main()
{
	vector<int> nums1 = { 0 };
	int m = 0;
	vector<int> nums2 = { 1 };
	int n = 1;
	Solution sln;
	sln.merge(nums1, m, nums2, n);
}
