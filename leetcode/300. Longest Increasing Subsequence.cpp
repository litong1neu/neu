#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
			return 0;
		if (len == 1)
			return 1;

		vector<int> dp(nums.size(), 1);
		int maxlen = 0;
		for (int j = 1; j<len; j++)
		{
			for (int i = 0; i<j; i++)
				if (nums[j]>nums[i])
					dp[j] = max(dp[j], dp[i] + 1);
			cout << dp[j] << endl;
			maxlen = max(maxlen, dp[j]);
		}
		return maxlen;
	}
};

int main()
{
	vector<int> vec{ 10, 9, 2, 5,3,7,101,18 };
	vector<int> vec1 = { 8, 9, 10, 1, 2, 3 };
	Solution s;
	//cout << s.lengthOfLIS(vec);

	getchar();
}