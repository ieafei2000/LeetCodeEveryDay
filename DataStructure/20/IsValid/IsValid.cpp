#include <iostream>
#include <stack>

using namespace std;

class Solution 
{
public:
    bool isValid(string s)
    {
        stack<char> stack;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                stack.push(s[i]);
            else
            {
                if (stack.empty())
                    return false;
                char temp = stack.top();
                stack.pop();
                if ((s[i] == ')' && temp == '(') || (s[i] == ']' && temp == '[') || (s[i] == '}' && temp == '{'))
                    continue;
                else
                    return false;
            }
        }
        return stack.empty();
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

