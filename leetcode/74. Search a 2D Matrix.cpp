#include<vector>
#include<iostream>

using namespace std;
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int row = matrix.size(), col = matrix[0].size();
		int find_row = -1;
		for (int i = 0; i<row; i++)
		{
			if (target >= *matrix[i].begin() && target <= matrix[i].back())
			{
				find_row = i;
				break;
			}
		}
		if (find_row<0)
			return false;
		else
		{
			for (int j = 0; j<col; j++)
				if (target == matrix[find_row][j])
					return true;
		}
		return false;

	}
};