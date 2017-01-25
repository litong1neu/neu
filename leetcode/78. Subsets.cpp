#include<vector>
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		res.push_back(vector<int>());
		for (auto element : nums)
		{
			int len = res.size();
			for (int i = 0; i<len; i++)
			{
				vector<int> subset = res[i];
				subset.push_back(element);
				res.push_back(subset);
			}
		}
		return res;
	}
};

void bit_subset(const string& str)
{
	int len = str.size();
	int start = 1, end = 1 << len;
	for (int i = start; i < end; i++)
	{
		int I = i;
		string temp;
		for (auto c : str)
		{
			if (I & 1)
				temp.push_back(c);
			I >>= 1;
		}
		cout << temp << endl;	
	}
}

int main()
{
	string s("abcd");
	bit_subset(s);
	system("pause");
}