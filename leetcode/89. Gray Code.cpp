#include<vector>
#include<iostream>
#include<bitset>
using namespace std;

class Solution {
public:
	vector<int> grayCode(int n) {
		int flag = 1, count = 0, num = 0,full=1<<n;

		vector<int> result(full);
		for (int i = 0; i < full; i++)
		{
			result[i] = btog(i);
		}

		return result;
	}
private:
	int btog(int num)
	{
		return (num >> 1) ^ num;
	}
};

void show(vector<int> &v)
{
	for (auto val : v)
		cout << bitset<3>(val) << " ";
}

int main()
{
	Solution s;
	show(s.grayCode(3));
	//vector<int> v(8);
	//for (int i = 0; i < v.size(); i++)
	//	v[i] = i;

	system("pause");
}