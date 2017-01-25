#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		int low = 0, high = nums.size() - 1;
		if (nums[low]>nums[high])
		{
			while (1)
			{
				int mid = (low + high) / 2;
				if (nums[mid]>nums[mid + 1])
					return nums[mid + 1];
				else if (nums[mid]>nums[low])
					low = mid + 1;
				else
					high = mid - 1;
			}
		}

		return nums[0];
	}
};