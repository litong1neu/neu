#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
	void solve(vector<vector<char>>& board) {
		if (board.size() == 0 || board[0].size() == 0)
			return;
		int row = board.size(), col = board[0].size();
		queue<pair<int, int>> points;

		init(board, points);

		while (!points.empty())
		{
			pair<int, int> p = points.front();
			points.pop();
			board[p.first][p.second] = 'E';
			if (p.first - 1 >= 0 && board[p.first - 1][p.second] == 'O')
				points.push(pair<int, int>(p.first - 1, p.second));
			if (p.first + 1<row&&board[p.first + 1][p.second] == 'O')
				points.push(pair<int, int>(p.first + 1, p.second));
			if (p.second - 1 >= 0 && board[p.first][p.second - 1] == 'O')
				points.push(pair<int, int>(p.first, p.second - 1));
			if (p.second + 1<col&&board[p.first][p.second +1] == 'O')
				points.push(pair<int, int>(p.first, p.second + 1));
		}

		for (int i = 0; i<board.size(); i++)
			for (int j = 0; j<board[0].size(); j++)
				if (board[i][j] == 'E')
					board[i][j] = 'O';
				else if (board[i][j] == 'O')
					board[i][j] = 'X';
	}
private:
	void init(vector<vector<char>>& board, queue<pair<int, int>>& points)
	{
		for (int i = 0; i<board.size(); i++)
		{
			if (board[i][0] == 'O')
				points.push(pair<int, int>(i, 0));
			if (board[i][board[0].size() - 1] == 'O')
				points.push(pair<int, int>(i, board[0].size() - 1));
		}
		for (int i = 0; i<board[0].size(); i++)
		{
			if (board[0][i] == 'O')
				points.push(pair<int, int>(0, i));
			if (board[board.size() - 1][i] == 'O')
				points.push(pair<int, int>(board.size() - 1, i));
		}
	}
};

void show(vector<vector<char>> &v)
{
	for (auto vec : v)
	{
		for (auto c : vec)
			cout << c << " ";
		cout << endl;
	}
}

vector<char> change(string s)
{
	vector<char> v;
	for (auto c : s)
		v.push_back(c);
	return v;
}

int main()
{
	Solution s;
	vector<vector<char>> v = { vector < char > {'X', 'X', 'X', 'X'}, 
		vector < char > {'X', 'O', 'O', 'X'}, vector < char > {'X', 'X', 'O', 'X'}, vector < char > {'X', 'O', 'X', 'X'} };

	vector<vector<char>> v1 = { vector < char >{'O', 'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O'}, 
		vector < char > {'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'X'},
		vector < char > {'O', 'X', 'O', 'X', 'O', 'O', 'O', 'O', 'X'},
		vector < char > {'O', 'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O'},
		vector < char > {'X', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'X'},
		vector < char > {'X', 'X', 'O', 'O', 'X', 'O', 'X', 'O', 'X'},
		vector < char > {'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O'},
		vector < char > {'O', 'O', 'O', 'X', 'O', 'O', 'O', 'O', 'O'},
		vector < char > {'O', 'O', 'O', 'O', 'O', 'X', 'X', 'O', 'O'} };

	vector<vector<char>> v2{ vector < char > {'X', 'X', 'O', 'O', 'X', 'O', 'X', 'O', 'X'} };

	vector<vector<char>> v3{change("OOOOXX"), change("OOOOOO"), change("OXOXOO"), change("OXOOXO"), change("OXOXOO"), change("OXOOOO")};

	show(v3);
	cout << endl;
	s.solve(v3);
	show(v3);

	system("pause");
}