#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        if (magazine.size() < ransomNote.size())
            return false;

        unordered_map<char, int> umap;

        for (int i = 0; i < magazine.size(); i++)
            umap[magazine[i]]++;
        
        for (int j = 0; j < ransomNote.size(); j++)
        {
            if (umap.count(ransomNote[j]))
            {
                if (--umap[ransomNote[j]] < 0)
                    return false;
            }
            else
                return false;
        }

        return true;
    }
};

int main()
{
    unordered_map<int, int> umap;

    umap[1] = 1;
    umap[2] = 2;

    cout << umap.count(3) << endl;
    cout << umap[3] << endl;
    cout << umap.count(3) << endl;

}

