# 解题思路
对无符号整数n转换二进制，但并不保存，在每次%2的时候计算是否==1，若为1，则cnt++即可

# 耗时
执行用时（100%） 内存消耗（60%）

# 补充
可采用位运算

### 代码

```cpp
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
```