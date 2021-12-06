#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
	{
		unordered_map<int, int> umap;
		vector<int> ans;
		for (int i = 0; i < nums1.size(); i++)
			umap[nums1[i]]++;
		for (int i = 0; i < nums2.size(); i++)
		{
			if (umap[nums2[i]] > 0)
			{
				ans.push_back(nums2[i]);
				umap[nums2[i]]--;
			}
		}
		return ans;
	}

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

};



int main()
{
	std::cout << "Hello World!\n";
}
