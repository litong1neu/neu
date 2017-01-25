/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given[100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is[1, 2, 3, 4].Return its length : 4.

Your algorithm should run in O(n) complexity.

*/
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
	int longestConsecutive(vector<int>& num) {
		if (num.empty())
			return 0;
		unordered_set<int> num_set(num.begin(), num.end());
		int max_sep = 1;			
			for (auto val : num)  //(auto val:num_set) is wrong because of erase!
				//Range-based for is for when you need to access each element of a container once.
			{
				int cnt = 1;
				num_set.erase(val);
				int large = val + 1, small = val - 1;
				while (num_set.count(large))
				{
					cnt++;
					num_set.erase(large++);
				}
				while (num_set.count(small))
				{
					cnt++;
					num_set.erase(small--);
				}
				max_sep = max(cnt, max_sep);
			}
		return max_sep;
	}
};

int main()
{
	vector<int> v{ 100, 4, 200, 1, 3, 2 };
	Solution s;
	cout<<s.longestConsecutive(v);
	system("pause");
}