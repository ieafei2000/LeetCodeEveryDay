#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
	bool isValidSudoku(vector<vector<char>>& board)
	{
		unordered_map<char, int> umap;

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] != '.')
					umap[board[i][j]]++;
			}
			for (auto iter : umap)
			{
				if (iter.first != '.' && iter.second > 1)
					return false;
			}
			umap.clear();
		}

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (board[j][i] != '.')
					umap[board[j][i]]++;
			}
			for (auto iter : umap)
			{
				if (iter.first != '.' && iter.second > 1)
					return false;
			}
			umap.clear();
		}

		for (int i = 0; i <= 6; i += 3)
		{
			for (int j = 0; j <= 6; j += 3)
			{
				umap[board[i][j]]++;
				umap[board[i][j + 1]]++;
				umap[board[i][j + 2]]++;

				umap[board[i + 1][j]]++;
				umap[board[i + 1][j + 1]]++;
				umap[board[i + 1][j + 2]]++;

				umap[board[i + 2][j]]++;
				umap[board[i + 2][j + 1]]++;
				umap[board[i + 2][j + 2]]++;

				for (auto iter : umap)
				{
					if (iter.first != '.' && iter.second > 1)
						return false;
				}
				umap.clear();
			}
		}
		return true;
	}
};

int main()
{
	std::cout << "Hello World!\n";
}
