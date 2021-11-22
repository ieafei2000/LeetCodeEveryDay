#include <iostream>

class Solution 
{
public:
    int hammingWeight(uint32_t n)
    {
        int cnt = 0;
        while (n != 0)
        {

            cnt += (n & 1);
            n = n >> 1;
        }
        return cnt;
    }
};

int main()
{
    Solution sln;
    std::cout << sln.hammingWeight(4294967293) << std::endl;

    int a = -4;
    a = a >> 1;
    std::cout << a << std::endl;
}