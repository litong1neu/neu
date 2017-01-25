#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> subset;
		sort(nums.begin(), nums.end());
		helper(0, nums, subset, res);
		return res;
	}
private:
	void helper(int start, vector<int> &nums, vector<int> &subset, vector<vector<int>> &res)
	{
		res.push_back(subset);
		for (int i = start; i<nums.size(); i++)
		{
			if (i == start || nums[i] != nums[i - 1])
			{
				subset.push_back(nums[i]);
				helper(i + 1, nums, subset, res);
				subset.pop_back();
			}
		}
	}
};
class Solution2 {
public:
	std::vector<std::vector<int> > subsetsWithDup(std::vector<int> &nums) {
		std::sort(nums.begin(), nums.end());
		std::vector<std::vector<int> > res;
		std::vector<int> vec;
		subsetsWithDup(res, nums, vec, 0);
		return res;
	}
private:
	void subsetsWithDup(std::vector<std::vector<int> > &res, std::vector<int> &nums, std::vector<int> &vec, int begin) {
		res.push_back(vec);
		for (int i = begin; i != nums.size(); ++i)
			if (i == begin || nums[i] != nums[i - 1]) {
				vec.push_back(nums[i]);
				subsetsWithDup(res, nums, vec, i + 1);
				vec.pop_back();
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
	vector<int > nums{ 1, 2, 2,3 };
	Solution s;
	show(s.subsetsWithDup(nums));
	system("pause");
}