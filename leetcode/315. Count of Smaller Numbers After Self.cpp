#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;


class Solution {
public:
	vector<int> countSmaller(vector<int>& nums) {
		vector<int> t, res(nums.size());
		for (int i = nums.size() - 1; i >= 0; --i) {
			int d = distance(t.begin(), lower_bound(t.begin(), t.end(), nums[i]));
			res[i] = d;
			t.insert(t.begin() + d, nums[i]);
		}
		return res;
	}
};

int main()
{
	vector < int > v{5, 2, 6, 1};
	Solution s;
	for (auto val : s.countSmaller(v))
		cout << val << " ";
	getchar();
}