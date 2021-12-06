#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c)
	{
		int m = mat.size();
		int n = mat[0].size();

		if (m * n != r * c)
			return mat;
		else
		{
			vector<int> temp;
			temp.resize(m * n);

			vector<vector<int>> ans;
			ans.resize(r);
			for (int i = 0; i < r; i++)
				ans[i].resize(c);

			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
					temp[i * n + j] = mat[i][j];
			}

			int k = 0;
			for (int i = 0; i < r; i++)
			{
				for (int j = 0; j < c; j++)
					ans[i][j] = temp[k++];
			}

			return ans;
		}
	}
};

int main()
{
	std::cout << "Hello World!\n";
}
