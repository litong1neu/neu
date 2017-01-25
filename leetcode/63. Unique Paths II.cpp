class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int row = obstacleGrid.size(), col = row ? obstacleGrid[0].size() : 0;
		vector<vector<int>> matrix(row, vector<int>(col, 0));
		for (int i = 0; i<row; i++)
		{
			if (obstacleGrid[i][0] == 1)
				break;
			matrix[i][0] = 1;
		}
		for (int j = 0; j<col; j++)
		{
			if (obstacleGrid[0][j] == 1)
				break;
			matrix[0][j] = 1;
		}

		for (int i = 1; i<row; i++)
			for (int j = 1; j<col; j++)
			{
				if (obstacleGrid[i][j] == 1)
					continue;
				matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
			}

		return matrix[row - 1][col - 1];
	}
};