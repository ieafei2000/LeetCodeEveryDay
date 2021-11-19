# 解题思路
跟12题矩阵路径类似，同样采用深度遍历回溯法，但是不同的是，当走过一个格子，将改格子的值置为21即可
1. 开辟一个m行n列的二维数组，下标i，j的值为i和j的数位和，即下标3，4值为7，下标10，12值为4（1+0 + 1+2）
2. 初始化二维数组Matrix
3. 从0,0开始DFS，每当下标越界或者当前下标对应值>k返回false
4. 否则count++,并把当前下标对应值赋值为21（题目要求k<=20，所以标记为21即表示当前格子被访问过）
5. 递归dfs上下左右四个格子

# 耗时
执行用时（55%） 内存消耗（10%）

# 补充
可以广度遍历，采用队列

### 代码

```cpp
class Solution 
{
public:
    int getBitSum(int num)
    {
        int res = 0;
        while (num != 0)
        {
            res += num % 10;
            num /= 10;
        }
        return res;
    }

    bool dfs(int m, int n, int k, int i, int j, std::vector<std::vector<int>>& matrix)
    {
        if (i < 0 || j < 0 || i >= m || j >= n || matrix[i][j] > k)
            return false;
        count++;
        matrix[i][j] = 21;
        for (int l = 0; l < 4; l++)
            dfs(m, n, k, i + dir[l][0], j + dir[l][1], matrix);
        return true;
    }


    int movingCount(int m, int n, int k)
    {
        for (int i = 0; i < m; i++)
        {
            std::vector<int> temp;
            for (int j = 0; j < n; j++)
            {
                temp.push_back(getBitSum(i) + getBitSum(j));
            }
            matrix.push_back(temp);
        }

        dfs(m, n, k, 0, 0, matrix);

        return count;
    }
private:
    int count = 0;
    int dir[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
    std::vector<std::vector<int>> matrix;
};
```