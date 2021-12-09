# 解题思路
1. 两个栈一个in，一个out，每次入队列向inStack里面压入
2. 每次出队列，检测outStack里面是否存在元素，若存在直接弹出outstack顶层元素，否则将instack倒入outstack即可

## 代码

```cpp
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

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
```

## 通过率
执行用时（100%） 内存消耗（99%）