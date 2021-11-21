#include <iostream>

class Solution 
{
public:
    int hammingWeight(uint32_t n)
    {
        int cnt = 0;
        while (n != 0)
        {

            if (n % 2 == 1)
            {
                cnt++;
            }
            n /= 2;
        }
        return cnt;
    }
};

int main()
{
    Solution sln;
    std::cout << sln.hammingWeight(4294967293) << std::endl;
}