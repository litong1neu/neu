#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		vector<int> tmp;
		if (k <= 0)
			return res;
		helper(1, n, k, res, tmp);
		return res;
	}
private:
	void helper(int begin, int n, int k, vector<vector<int> > &res, vector<int> &tmp)
	{
		if (tmp.size() == k)
		{
			res.push_back(tmp);
			return;
		}
		for (int i = begin; i <= n; i++)
		{
			tmp.push_back(i);
			helper(i + 1, n, k, res, tmp);
			tmp.pop_back();
		}
	}
};

void show(vector<vector<int>> &v)
{
	for (auto vec : v)
	{
		for (auto val : vec)
			cout << val << " ";
			cout << endl;
	}
}

int main()
{
	Solution s;
	show(s.combine(4, 2));
	system("pause");
}