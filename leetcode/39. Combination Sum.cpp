#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<int> nums = candidates;
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		vector<int > tmp;
		helper(0, nums, res, target, tmp);
		return res;
	}
private:
	void helper(int start, vector<int> &nums, vector<vector<int>> &res, int target, vector<int> &tmp)
	{
		if (target == 0)
		{
			cout << "haha";
			res.push_back(tmp);
			return;
		}
		for (int i = start; i<nums.size(); i++)
		{
			if (nums[i]>target)
				return;
			tmp.push_back(nums[i]);
			helper(i, nums, res, target - nums[i], tmp);
			tmp.pop_back();
		}
	}
};

int main()
{
	vector<int > v{ 2, 3, 6, 7 };
	Solution s;
	s.combinationSum(v, 7);
	system("pause");
}