#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> seq(nums.size());
		unordered_map<int, int> num_count;
		for (int i = 0; i<nums.size(); i++)
			num_count[nums[i]]++;
		helper(num_count, 0, result, seq);

		return result;
	}
private:
	void helper(unordered_map<int, int> &num_count, int level, vector<vector<int>> &result, vector<int> &seq)
	{
		if (level == seq.size())
		{
			result.push_back(seq);
			return;
		}
		for (auto &num : num_count)
		{
			if (num.second == 0)
				continue;
			seq[level] = num.first;
			num.second--;
			helper(num_count, level + 1, result, seq);
			num.second++;
		}
	}
};

void show(vector<vector<int>> &v)
{
	for (auto &vec : v)
	{
		for (auto val : vec)
			cout << val << " ";
		cout << endl;
	}
}

int main()
{
	Solution s;
	vector<int> v{ 1, 2, 3,4 };
	show(s.permute(v));
	system("pause");
}
