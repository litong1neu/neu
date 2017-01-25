#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.size() == 0 || grid[0].size() == 0)
			return 0;
		int row = grid.size(), col = grid[0].size();
		int res = 0;
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				if (grid[i][j] == '1')
				{
					res++;
					//DFS(grid, i, j);
					BFS(grid, i, j);
				}
		return res;
	}
private:
	void DFS(vector<vector<char>> &grid, int i, int j)
	{
		grid[i][j] = '0';
		if (i - 1>=0 && grid[i - 1][j] == '1')
			DFS(grid, i - 1, j);
		if (i + 1 < grid.size() && grid[i + 1][j] == '1')
			DFS(grid, i + 1, j);
		if (j - 1>=0 && grid[i][j - 1] == '1')
			DFS(grid, i, j - 1);
		if (j + 1 < grid[0].size() && grid[i][j + 1] == '1')
			DFS(grid, i, j + 1);
	}
	struct Point
	{
		int i;
		int j;
		Point(int Y, int X) :i(Y), j(X){}
	};
	void BFS(vector<vector<char>> &grid, int i, int j)
	{
		queue<Point> Q;
		Q.emplace(i,j);
		while (!Q.empty())
		{
			Point p = Q.front();
			Q.pop();
			grid[p.i][p.j] = '0';
			if (p.j + 1 < grid[0].size() && grid[p.i][p.j+1] == '1')
				Q.emplace(p.i, p.j + 1);
			if (p.i + 1 < grid.size() && grid[p.i+1 ][p.j] == '1')
				Q.emplace(p.i+1, p.j );
			if (p.j - 1 >= 0 && grid[p.i][p.j - 1] == '1')
				Q.emplace(p.i, p.j - 1);
			if (p.i - 1 >= 0 && grid[p.i-1][p.j] == '1')
				Q.emplace(p.i-1, p.j);
		}
	}
};


int main()
{
	vector<vector<char>> v{ vector < char > {'1', '1', '1', '1', '0'}, 
		vector < char > {'1', '1', '0', '1', '0'}, vector < char > {'1', '1', '0', '0', '0'}, vector < char > {'0', '0', '0', '0', '0'} };
	vector<vector<char>> v2{ vector < char > {'1', '1', '1'},
		vector < char > { '0', '1', '0'}, vector < char > {'1', '1', '1'}};
	vector<vector<char>> v3{ vector < char > {'1', '1', '0'} };
	Solution s;

	cout << s.numIslands(v2);
	system("pause");
}