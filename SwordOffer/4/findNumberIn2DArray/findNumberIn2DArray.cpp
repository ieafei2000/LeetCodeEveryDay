#include <iostream>
#include <vector>

using namespace std;

bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) 
{
	if (matrix.size() == 0)
	{
		return false;
	}

	int m = matrix.size();
	int x = 0;
	int y = matrix.at(0).size() - 1;

	while (y >= 0 && x <= m - 1)
	{
		cout << matrix[x][y] << endl;
		//等于目标值，返回
		if (matrix[x][y] == target)
		{
			return true;
		}
		//大于目标值，向左移动
		if (matrix[x][y] > target)
		{
			y--;
		}
		//小于目标值，向右移动
		else
		{
			x++;
		}
	}

	return false;
}

int main()
{
	vector<vector<int>> matrix = {
		{}
		};
	
	cout << findNumberIn2DArray(matrix, -4) << endl;

}
