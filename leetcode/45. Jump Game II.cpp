#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		int len = nums.size();
		vector<int> minJump(len, INT_MAX);
		minJump[0] = 0;
		for (int i = 1; i<len; i++)
			for (int j = 0; j<i; j++)
				if (nums[j] + j >= i)
					minJump[i] = min(minJump[i], minJump[j] + 1);
		return minJump[len - 1];
	}
	int jump2(vector<int>& nums) {
		int len = nums.size(), start = 0, end = 0, maxreach = 0, step = 0;
		while (end<len - 1)
		{
			step++;
			for (int i = start; i <= end; i++)
				maxreach = max(maxreach, i + nums[i]);
			if (maxreach >= len - 1)
				return step;
			start = end + 1;
			end = maxreach;
		}
		return step;
	}
};

int main()
{
	vector<int> v{ 2, 3, 0, 1, 4 };
	Solution s;
	cout << s.jump2(v);
	system("pause");
}