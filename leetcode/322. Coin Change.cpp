#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		if (amount == 0)
			return 0;
				
		vector<int> res(amount + 1, INT_MAX);
		sort(coins.begin(), coins.end());
		res[0] = 0;
		for (int i = coins[0]; i <= amount; i++)
		{
			int minVal = INT_MAX;
			for (auto denomination : coins)
				if (denomination > i)
					break;
				else
				{
					int temp = res[i - denomination];
					minVal = min(temp, minVal);
				}
			res[i] = minVal==INT_MAX?INT_MAX:minVal + 1;
		}
		//int kk = 0;
		//for (auto val : res)
		//	cout << kk++<<" "<<val << endl;
		//cout << res[186+83+83];
		
		return res[amount]==INT_MAX?-1:res[amount];
	}
};

class Solution2 {
public:
	int coinChange(vector<int>& coins, int amount) {
		int Max = amount + 1;
		vector<int> dp(amount + 1, Max);
		dp[0] = 0;
		for (int i = 1; i <= amount; i++) {
			for (int j = 0; j < coins.size(); j++) {
				if (coins[j] <= i) {
					dp[i] = min(dp[i], dp[i - coins[j]] + 1);
				}
			}
		}
		int kk = 0;
		for (auto val : dp)
			cout << kk++<<" "<<val << endl;
		return dp[amount] > amount ? -1 : dp[amount];
	}
};

int main()
{
	vector<int> v{ 186, 419, 83, 408 };
	vector<int> v2{ 2,5 };
	Solution s;
	cout<<s.coinChange(v, 6049);
	system("pause");
}