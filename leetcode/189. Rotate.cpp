#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int len = nums.size();
		k %= len;
		if (k == 0)
			return;
		int pos = len - k;
		auto mid = nums.begin() + pos;
		reverse(nums.begin(), mid);
		reverse(mid, nums.end());
		reverse(nums.begin(), nums.end());
	}
};

int main()
{
	vector<int> vec{ 1, 2, 3, 10 };
	cout << *(vec.begin() + 3);
	system("pause");
}