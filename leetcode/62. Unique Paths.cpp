#include<vector>
#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;

void setVal(vector<vector<int>> &mat, int row, int col)
{
	int temp = row;
	while (row >= 0)
		mat[row--][col] = 1;
	row = temp;
	while (col >= 0)
		mat[row][col--] = 1;
}

int uniquePaths(int m, int n) {
	vector<vector<int>> mat;
	mat.resize(m);
	for (auto &col : mat)
		col.resize(n);
	setVal(mat, m - 1, n - 1);
	for (int col = n - 2; col >= 0; col--)
	{
		for (int row = m - 2; row >= 0; row--)
			mat[row][col] = mat[row + 1][col] + mat[row][col + 1];
	}


	return mat[0][0];
}



int main()
{
	cout << uniquePaths(4, 4);
	system("pause");
}