#include <iostream>
#include <string>

using namespace std;

class Solution 
{
public:
    bool isAnagram(string s, string t) 
    {
        int count[26] = { 0 };

        if (s.size() != t.size())
            return false;

        for (int i = 0; i < s.size(); i++)
        {
            count[s[i] - 'a']++;
        }

        for (int j = 0; j < t.size(); j++)
        {
            if (--count[t[j] - 'a'] < 0)
                return false;
        }
        
        return true;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
