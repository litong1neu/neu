#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int low = 0, high = nums.size() - 1;
		int min_index = 0;
		if (nums[low]>nums[high])
		{
			while (1)
			{
				int mid = (low + high) / 2;
				cout << "mid: " << mid << endl;
				if (nums[mid]>nums[mid + 1])
				{
					min_index = mid + 1;
					break;
				}
				if (nums[low] <= nums[mid])
				{
					low = mid + 1;
					cout << low << endl;
				}
				else
					high = mid - 1;
			}
		}
		cout << min_index;
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
				return mid;
			else if (nums[mid]>target)
				high = mid - 1;
			else
				low = mid + 1;
		}
		return -1;
	}

};

int main()
{
	vector<int > v{ 4,5,1,2,3 };
	Solution s;
	s.search(v,1);
	system("pause");
}