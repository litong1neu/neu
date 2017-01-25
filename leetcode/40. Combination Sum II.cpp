#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

		vector<vector<int>> res;
		vector<int> nums = candidates;
		sort(nums.begin(), nums.end());
		vector<int> tmp;
		helper(res, tmp, nums, target, 0);
		return res;
	}
private:
	void helper(vector<vector<int>> &res, vector<int> &tmp, vector<int> &nums, int target, int start)
	{
		if (target == 0)
		{
			res.push_back(tmp);
			return;
		}

		for (int i = start; i <nums.size(); i++)
		{
			if (nums[i]>target)
				break;
			if (i != start&&nums[i] == nums[i - 1])
				continue;
			tmp.push_back(nums[i]);
			helper(res, tmp, nums, target - nums[i], i + 1);
			tmp.pop_back();
		}
	}
};

void show(vector<vector<int>> v)
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
	vector<int> v{ 2, 2, 1, 4, 3 };
	Solution s;
	show(s.combinationSum2(v,8));
	system("pause");
}