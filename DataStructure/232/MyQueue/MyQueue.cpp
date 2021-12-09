#include <iostream>
#include <stack>

using namespace std;

class MyQueue 
{
public:

    void inToOut()
    {
        while (!inStack.empty())
        {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

    MyQueue() 
    {

    }

    void push(int x) 
    {
        inStack.push(x);
    }

    int pop()
    {
        if (outStack.empty())
            inToOut();
        int res = outStack.top();
        outStack.pop();
        return res;
    }

    int peek() 
    {
        if (outStack.empty())
            inToOut();
        return outStack.top();
    }

    bool empty()
    {
        return outStack.empty() && inStack.empty();
    }
private:
    stack<int> outStack;
    stack<int> inStack;
};


int main()
{
    std::cout << "Hello World!\n";
}
