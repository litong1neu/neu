#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<int> ugly(n, INT_MAX);
		vector<int> index(primes.size(), 0);
		ugly[0] = 1;		
		for (int i = 1; i < n; i++)
		{
			int flag = 0;
			for (int j = 0; j < index.size(); j++)
				ugly[i] = min(ugly[i], ugly[index[j]] * primes[j]);
			for (int j = 0; j < index.size(); j++)
				if (ugly[index[j]] * primes[j] == ugly[i])
					index[j]++;
		}



		return ugly[n - 1];
	}

private:
	void show(vector<int> &v)
	{
		for (auto val : v)
			cout << val << " ";
	}
};

int main()
{
	Solution s;
	vector<int> v{ 2, 7, 13, 19 };
	cout<<s.nthSuperUglyNumber(12, v);

	system("pause");
}