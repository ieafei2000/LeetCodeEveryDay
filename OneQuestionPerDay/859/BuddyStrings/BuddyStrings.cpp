#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution
{
public:
    bool buddyStrings(string s, string goal)
    {   
        bool res = false;
        if (s.length() != goal.length())
        {
            return false;
        }
        if (s == goal)
        {
            map<char, int> count;
            for (int i = 0; i < s.length(); i++)
            {
                if (++count[s[i]] > 1)
                    return true;
            }
            return false;
        }
        else
        {
            int first = -1, second = -1;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] != goal[i])
                {
                    if (first == -1)
                        first = i;
                    else if (second == -1)
                        second = i;
                    else
                        return false;
                }
            }
            return (second != -1 && s[first] == goal[second] && s[second] == goal[first]);
        }
    }
private:
};

int main()
{
    Solution sln;
    cout << sln.buddyStrings("abcacaba", "abbacaca") << endl;
}
