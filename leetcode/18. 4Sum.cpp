#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		for (int a = 0; a<nums.size() - 3; a++)
		{
			int target2 = target - nums[a];
			for (int b = a + 1; b<nums.size() - 2; b++)
			{
				int front = b + 1, back = nums.size() - 1;
				while (back>front)
				{
					if (nums[b] + nums[front] + nums[back]>target2)
						back--;
					else if (nums[b] + nums[front] + nums[back]<target2)
						front++;
					else
					{
						res.push_back(vector < int > {nums[a], nums[b], nums[front], nums[back]});
						int tempf = nums[front], tempb = nums[back];
						while (front < back&&nums[front] == tempf)
							front++;
						while (front < back&&nums[back] == tempb)
							back--;
					}
				}
				while (b<nums.size() - 2 && nums[b] == nums[b + 1])
					b++;
			}
			while (a<nums.size() - 3 && nums[a] == nums[a + 1])
				a++;
		}
		return res;
	}
};

void show(vector<vector<int>> &v)
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
	Solution s;
	vector<int> v{ 1, 0, -1, 0, -2, 2 };
	show(s.fourSum(v,0));
	system("pause");
}
