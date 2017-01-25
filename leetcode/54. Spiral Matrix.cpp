//finished myself
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int row = matrix.size(), col = row ? matrix[0].size() : 0;
		vector<int> res;
		vector<vector<int>> map(row, vector<int>(col, 1));
		int total = row*col;
		int start = 0;
		while (res.size() != total)
		{
			int i = start, j = start;
			while (j<col)
			{
				if (map[i][j])
				{
					res.push_back(matrix[i][j]);
					map[i][j] = 0;
					j++;
				}
				else
					break;
			}
			j--;
			i++;
			while (i<row)
			{
				if (map[i][j])
				{
					res.push_back(matrix[i][j]);
					map[i][j] = 0;
					i++;
				}
				else
					break;
			}
			i--;
			j--;
			while (j >= 0)
			{
				if (map[i][j])
				{
					res.push_back(matrix[i][j]);
					map[i][j] = 0;
					j--;
				}
				else
					break;
			}
			j++;
			i--;
			while (i >= 0)
			{
				if (map[i][j])
				{
					res.push_back(matrix[i][j]);
					map[i][j] = 0;
					i--;
				}
				else
					break;
			}
			start++;
		}
		return res;
	}
};

int main()
{
	vector<vector<int>> vec{ vector < int > {1, 2, 3}, vector < int > {4, 5, 6}, vector < int > {7, 8, 9} };
	Solution s;
	vector<int> res=s.spiralOrder(vec);
	for (auto val : res)
		cout << val << " ";
	getchar();
}