#include<vector>
#include<string>
#include<iostream>
using namespace std;


class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		int row = board.size();
		int col = row ? board[0].size() : 0;
		if (word.empty())
			return false;
		use = vector<vector<int>>(row, vector<int>(col, 1));
		for (int i = 0; i<row; i++)
			for (int j = 0; j<col; j++)
			{
				if (word[0] == board[i][j])
				{
					helper(board, word, i, j, 0);
					if (find)
						return true;
				}
			}

		return false;
	}
private:
	vector<vector<int>> use;
	bool find = false;
	void helper(vector<vector<char>>& board, string word, int I, int J, int pos)
	{
		if (word[pos] == board[I][J])
		{
			if (pos + 1 == word.size())
			{
				find = true;
				return;
			}
			use[I][J] = 0;
			if (I + 1 < board.size() && use[I + 1][J] && !find)
				helper(board, word, I + 1, J, pos + 1);
			if (I - 1 >= 0 && use[I - 1][J] && !find)
				helper(board, word, I - 1, J, pos + 1);
			if (J + 1 < board[0].size() && use[I][J + 1] && !find)
				helper(board, word, I, J + 1, pos + 1);
			if (J - 1 >= 0 && use[I][J - 1] && !find)
				helper(board, word, I, J - 1, pos + 1);
			use[I][J] = 1;
		}
	}
};


int main()
{
	Solution s;
	vector<vector<char>> board{ { 'A', 'B', 'C', 'E' }, { 'S', 'F', 'C', 'S' }, { 'A', 'D', 'E', 'E' } };
	cout<<s.exist(board, "ADFB");
	system("pause");
}