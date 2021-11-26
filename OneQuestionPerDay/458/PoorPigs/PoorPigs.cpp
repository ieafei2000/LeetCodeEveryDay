#include <iostream>

class Solution
{
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        int base = minutesToTest / minutesToDie + 1;
        return ceil(log(buckets) / log(base));
    }
};

int main()
{
    Solution sln;
    std::cout << sln.poorPigs(1000, 15, 60) << std::endl;
}
