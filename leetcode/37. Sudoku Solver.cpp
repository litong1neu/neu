#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		int row = board.size(), col = row ? board[0].size() : 0;
		for (int i = 0; i<row; i++)
			for (int j = 0; j<col; j++)
				if (isdigit(board[i][j]))
				{
					char c = board[i][j];
					hash1[i].insert(c);
					hash2[j].insert(c);
					hash3[i / 3 * 3 + j / 3].insert(c);
				}
		solve(board);

	}
private:
	bool solve(vector<vector<char>>& board)
	{
		for (int i = 0; i<board.size(); i++)
			for (int j = 0; j<board[0].size(); j++)
				if (board[i][j] == '.')
				{
					for (char c = '1'; c <= '9'; c++)
					{
						if (isValid(board, i, j, c))
						{
							board[i][j] = c;
							hash1[i].insert(c);
							hash2[j].insert(c);
							hash3[i / 3 * 3 + j / 3].insert(c);
							if (solve(board))
								return true;
							else
							{
								board[i][j] = '.';
								hash1[i].erase(c);
								hash2[j].erase(c);
								hash3[i / 3 * 3 + j / 3].erase(c);
							}
						}
					}
					return false;
				}
		return true;


	}
	bool isValid(vector<vector<char>>& board, int I, int J, char c)
	{
		if (hash1[I].count(c) || hash2[J].count(c) || hash3[I / 3 * 3 + J / 3].count(c))
			return false;
		return true;
	}
	unordered_map<int, unordered_set<char>> hash1;
	unordered_map<int, unordered_set<char>> hash2;
	unordered_map<int, unordered_set<char>> hash3;

};