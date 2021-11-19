#include <iostream>
#include <vector>

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
        for (int l = 0; l < 2; l++)
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
    int dir[2][2] = {{0, 1}, {1, 0} };
    std::vector<std::vector<int>> matrix;
};


int main()
{
    Solution sln;
    std::cout << sln.movingCount(3, 1, 0) << std::endl;
}

