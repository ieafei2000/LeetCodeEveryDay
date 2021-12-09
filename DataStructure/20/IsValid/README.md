# 解题思路
1. 遍历字符串s
2. 若当前s[i] == ([{, 则直接压栈
3. 否则进行匹配
4. 若当前栈为空，返回false
5. 若不为空，且无法匹配对应括号，返回false
6. 遍历完成，返回stack.empty(), 即若遍历完毕后，若栈内还有元素，表明还有左括号未被匹配，无效

## 代码

```cpp
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
```

## 通过率
执行用时（100%） 内存消耗（85%）