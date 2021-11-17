#include <iostream>
#include <array>

int numWays(int n) 
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    int mod = 1000000007;
    //std::array<int, 101> ways;
    //ways[0] = 1;
    //ways[1] = 1;
    //ways[2] = 2;

    //ways[n] = ways[n-1] + ways[n-2]

    int way1 = 2;
    int way2 = 1;
    int temp = 0;
    for (int i = 3; i <= n; i++)
    {
        temp = (way1 + way2) % mod;
        way2 = way1;
        way1 = temp;
    }
    return way1;
}

int main()
{
    std::cout << numWays(7) << std::endl;
}
