#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		int n = nums.size();
		auto midit = nums.begin() + n / 2;
		nth_element(nums.begin(), midit, nums.end());

		vector<int> temp;
		for (int i = n/2-1, j = nums.size() - 1; temp.size() < nums.size(); i--, j--)
		{
			if(i>=0)
			temp.push_back(nums[i]);
			if (j>n/2-1)
			temp.push_back(nums[j]);
		}
		if (temp.size() != nums.size())
			temp.pop_back();
		//swap(nums, temp);
	}
};

class Solution2 {
public:
	void wiggleSort(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<int>temp;
		if (nums.size() % 2 == 0)
		{
			for (int i = nums.size() / 2 - 1, j = nums.size() - 1; temp.size() < nums.size(); i--, j--)
			{

				if (i >= 0)
					temp.push_back(nums[i]);
				if (j > nums.size() / 2 - 1)
					temp.push_back(nums[j]);
			}
		}
		else
		{
			for (int i = nums.size() / 2, j = nums.size() - 1; temp.size() < nums.size(); i--, j--)
			{

				if (i >= 0)
					temp.push_back(nums[i]);
				if (j > nums.size() / 2 )
					temp.push_back(nums[j]);
			}
		}
		swap(temp, nums);
	}
};


int main()
{
	//vector<int> v{ 5, 3, 1, 2, 6, 7, 8, 5, 5};
	vector<int> v{ 4, 5, 5, 5, 5, 6, 6, 6 };
	Solution2 s;
	s.wiggleSort(v);
	for (int val : v)
		cout << val << " ";
	system("pause");
}

//[4,5,5,5,5,6,6,6]
