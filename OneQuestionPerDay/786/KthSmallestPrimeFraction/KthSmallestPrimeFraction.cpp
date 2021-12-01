#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Fraction
{
    int up;
    int down;
};

bool compare(Fraction a, Fraction b)
{
    return (a.up * b.down) < (b.up * a.down);
}


class Solution 
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) 
    {
        vector<Fraction> ans;
        for (int i = 0; i < arr.size() - 1; i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                ans.push_back(Fraction{arr[i], arr[j]});
            }
        }
        
        sort(ans.begin(), ans.end(), compare);
        return vector<int>{ans[k - 1].up, ans[k - 1].down};
    }
};

int main()
{
    vector<int> arr = { 1, 2, 3, 5 };
    int k = 3;
    Solution sln;
    sln.kthSmallestPrimeFraction(arr, k);
}

