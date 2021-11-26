#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution 
{
public:
    string originalDigits(string s) 
    {
        int cnt[10] = {0};
        map<char, int> count;
        for (int i = 0; i < s.size(); i++)
            count[s[i]]++;

        cnt[0] = count['z'];
        cnt[2] = count['w'];
        cnt[4] = count['u'];
        cnt[6] = count['x'];
        cnt[8] = count['g'];

        cnt[3] = count['t'] - cnt[2] - cnt[8];
        cnt[5] = count['f'] - cnt[4];
        cnt[7] = count['s'] - cnt[6];

        cnt[1] = count['o'] - cnt[0] - cnt[2] - cnt[4];
        cnt[9] = count['i'] - cnt[5] - cnt[6] - cnt[8];

        string res = "";
        for (int i = 0; i <= 9; i++)
        {
            while (cnt[i] > 0)
            {
                res += to_string(i);
                cnt[i]--;
            }
        }
        return res;
    }
};

int main()
{
    Solution sln;
    cout << sln.originalDigits("nnei") << endl;
}
