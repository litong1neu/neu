#include<vector>
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<string> vec(n, string(n, '.'));
		vector<vector<string>> res;
		helper(res, vec, 0);
		return res;
	}
private:
	void helper(vector<vector<string>> &res, vector<string> &vec, int level)
	{
		if (level == vec.size())
		{
			res.push_back(vec);
			return;
		}
		for (int j = 0; j<vec[0].size(); j++)
		{
			vec[level][j] = 'Q';
			if (isValid(vec, level, j))
			{
				helper(res, vec, level + 1);

			}
			vec[level][j] = '.';
		}
	}
	bool isValid(vector<string> &vec, int row, int col)
	{
		for (int i = row - 1, j = col; i >= 0;i--)
			if (vec[i][j] == 'Q')
				return false;
		for (int i = row - 1, j = col - 1; i >= 0&&j >= 0; i--, j--)
			if (vec[i][j] == 'Q')
				return false;
		for (int i = row - 1, j = col + 1; i >= 0&&j<vec.size(); i--, j++)
			if (vec[i][j] == 'Q')
				return false;
		return true;
	}
};

void show(vector<vector<string>> &vec)
{
	for (auto val : vec)
	{
		cout << endl;
		for (auto str : val)
			cout << str << endl;
	}
}

int main()
{
	Solution s;
	show(s.solveNQueens(4));
	system("pause");
}