#include "leetcode.h"

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 1)
			return 1;
		if (nums.size() == 0)
			return 0;
		int i=1;
		for (; i<nums.size(); i++)
		{
			if (nums[i]<nums[i - 1])
				break;
			if (nums[i] == nums[i - 1])
				for (int j = i; j<nums.size() - 1; j++)
					swap(nums[j], nums[j + 1]);

		}

		return i;
	}
};

int main()
{
	//vector<int> vec{ 1, 2, 2,3,3 };
	//Solution s;
	//cout << s.removeDuplicates(vec);
	stringstream ss("a b c d");
	string s;
	while (getline(ss, s, ' '))
		cout << s << endl;
	system("pause");
}

