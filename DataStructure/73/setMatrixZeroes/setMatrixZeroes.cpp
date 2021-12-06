#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	void setZeroes(vector<vector<int>>& matrix)
	{
		int m = matrix.size();
		int n = matrix[0].size();

		unordered_map<int, int> umapRows;
		unordered_map<int, int> umapCols;

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] == 0)
				{
					umapRows[i]++;
					umapCols[j]++;
				}
			}
		}
		//行置0
		for (auto iter : umapRows)
		{
			for (int j = 0; j < n; j++)
			{
				matrix[iter.first][j] = 0;
			}
		}
		//列置0
		for (auto iter : umapCols)
		{
			for (int i = 0; i < m; i++)
			{
				matrix[i][iter.first] = 0;
			}
		}

	}
};

int main()
{
	std::cout << "Hello World!\n";
}
