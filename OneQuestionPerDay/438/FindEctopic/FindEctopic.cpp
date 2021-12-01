#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int> sCount(26);
        vector<int> pCount(26);
        vector<int> ans;

        if (p.size() > s.size())
            return ans;

        for (int i = 0; i < p.size(); i++)
        {
            sCount[s[i] - 'a']++;
            pCount[p[i] - 'a']++;
        }
                
        if (sCount == pCount)
            ans.push_back(0);

        for (int i = 0; i < s.size() - p.size(); i++)
        {
            sCount[s[i] - 'a']--;
            sCount[s[i + p.size()] - 'a']++;

            if (sCount == pCount)
                ans.push_back(i + 1);
        }
        for (auto iter : ans)
        {
            cout << iter << endl;
        }
        return ans;
    }
};


int main()
{
    Solution sln;

    string s = "cbaebabacd";
    string p = "abc";

    sln.findAnagrams(s, p);
}

