#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		if (nums.size() == 1)
			return target == nums[0];
		int low = 0, high = nums.size() - 1;
		int min_index = 0;
		if (nums[low]>=nums[high]&&nums[low]!=nums[low+1])
		{
			while (1)
			{
				int mid = (low + high) / 2;
				if (nums[mid]>nums[mid + 1])
				{
					min_index = mid + 1;
					break;
				}
				if (nums[low] <= nums[mid])
					low = mid + 1;
				else
					high = mid - 1;
			}
		}
		cout << min_index<<endl;
		low = 0;
		high = nums.size() - 1;
		if (target >= nums[min_index] && target <= nums[high])
			low = min_index;
		else
			high = min_index - 1;

		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (nums[mid] == target)
				return true;
			else if (nums[mid]>target)
				high = mid - 1;
			else
				low = mid + 1;
		}
		return false;
	}

};

int main()
{
	vector<int > v{  1,1 };
	Solution s;
	cout << s.search(v, 1);
	system("pause");
}