#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
	int totalNQueens(int n) {
		if (n == 0)
			return 0;
		vector<vector<int>> matrix(n, vector<int>(n, 0));
		helper(matrix, 0);
		return count;
	}
private:
	int count = 0;
	void helper(vector<vector<int>> &matrix, int level)
	{
		cout << matrix.size();
		if (level >= matrix.size())
		{
			count++;
			return;
		}
		for (int j = 0; j<matrix[0].size(); j++)
		{
			matrix[level][j] = 1;
			if (isValid(matrix, level, j))
				helper(matrix, level + 1);
			matrix[level][j] = 0;
		}
	}
	bool isValid(vector<vector<int>> &matrix, int row, int col)
	{
		for (int i = row - 1; i >= 0; i--)
			if (matrix[i][col] == 1)
				return false;
		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
			if (matrix[i][j] == 1)
				return false;
		for (int i = row - 1, j = col + 1; i >= 0 && j<matrix.size(); i--, j++)
			if (matrix[i][j] == 1)
				return false;
		return true;
	}
};

int main()
{
	Solution s;
	cout << s.totalNQueens(2);
	getchar();
}
