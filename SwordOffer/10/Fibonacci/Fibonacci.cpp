#include <iostream>
#include <queue>

int fib(int n)
{
    std::queue<int> fib;
    fib.push(0);
    fib.push(1);
    int i = 0;
    while (i < n)
    {
        int f1 = fib.front();
        fib.pop();
        fib.push((f1 + fib.front()) % 1000000007);
        i++;
    }
    return fib.front();
}

int main()
{
    std::cout << fib(100) << std::endl;
}
