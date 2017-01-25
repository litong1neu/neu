#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	int numSquares(int n) {
		int sq = pow(n, 0.5);
		if (n == pow(sq, 2))
		return 1;

		vector<int> res(n + 1, INT_MAX);
		res[0] = 0;
		for (int i = 1; i <= sq; i++)
			res[i*i] = 1;
		for (int i = 2; i <= n; i++)
		{
			if (res[i] == 1)
				continue;
			else
			{
				for (int j = 1; j*j <= i; j++)
					res[i] = min(res[i], 1 + res[i - j*j]);
			}
		}
		return res[n];
	}
};

int main()
{
	Solution s;
	cout<<s.numSquares(2);
	system("pause");
}