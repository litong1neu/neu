#include<vector>
#include<unordered_set>
#include<cctype>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int row = board.size(), col = row ? board[0].size() : 0;
		for (int i = 1; i<row; i += 3)
			for (int j = 1; j<col; j += 3)
			{
				unordered_set<char> hash;
				for (int I = i - 1; I <= i + 1; I++)
					for (int J = j - 1; J <= j + 1; J++)
					{
						if (isdigit(board[I][J]))
						{
							if (hash.count(board[I][J]))
								return false;
							hash.insert(board[I][J]);
						}
					}
			}
		for (int i = 0; i<row; i++)
		{
			unordered_set<char> hash;
			for (int j = 0; j<col; j++)
			{
				if (isdigit(board[i][j]))
				{
					if (hash.count(board[i][j]))
						return false;
					hash.insert(board[i][j]);
				}
			}
		}
		for (int j = 0; j<col; j++)
		{
			unordered_set<char> hash;
			for (int i = 0; i<row; i++)
			{
				if (isdigit(board[i][j]))
				{
					if (hash.count(board[i][j]))
						return false;
					hash.insert(board[i][j]);
				}
			}
		}
		return true;
	}
};