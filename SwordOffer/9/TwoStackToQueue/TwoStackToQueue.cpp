#include <iostream>
#include <stack>

class CQueue 
{
public:
    CQueue() 
    {

    }

    void appendTail(int value) 
    {
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }

        stack1.push(value);

        while (!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
    }

    int deleteHead()
    {
        if (stack1.empty())
        {
            return -1;
        }
        else
        {
            int res = stack1.top();
            stack1.pop();
            return res;
        }
    }

private:
    std::stack<int> stack1;
    std::stack<int> stack2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

int main()
{

}
