#include"leetcode.h"
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int row = matrix.size(), col = row ? matrix[0].size() : 0;
		unordered_map<int, vector<int>> X_Y;
		for (int i = 0; i<row; i++)
			for (int j = 0; j<col; j++)
			{
				if (matrix[i][j] == 0)
				{
					for (int I = 0; I<row; I++)
						X_Y[I].push_back(j);
					for (int J = 0; J < col; J++)
						X_Y[i].push_back(J);
				}
			}
		for (auto pair : X_Y)
			for (auto y : pair.second)
				matrix[pair.first][y] = 0;
	}
};

int main()
{
	Solution s;
	vector<vector<int>> vv(1, vector < int > {1, 0});
	s.setZeroes(vv);
	show_matrix(vv);
	system("pause");
}