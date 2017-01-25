#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		vector<int> factorial(10);
		initFactorial(factorial);
		string str = initial(n);
		k--;
		int divide = factorial[--n];
		int index = 0;
		string result;
		while (1)
		{
			index = k / divide;
			result.push_back(str[index]);
			str.erase(str.begin() + index);
			if (str.empty())
				break;
			k -= index*divide;
			divide = factorial[--n];
		}
		return result;
	}
private:
	void initFactorial(vector<int> &v)
	{
		v[0] = 1;
		for (int i = 1; i <= 9; i++)
		{
			v[i] = i*v[i - 1];
		}
	}
	string initial(int n)
	{
		string s;
		for (int i = 1; i <= n; i++)
			s.push_back( '0'+i);
		return s;
	}
};

int main()
{
	Solution s;
	cout << s.getPermutation(4, 14);
	system("pause");
}