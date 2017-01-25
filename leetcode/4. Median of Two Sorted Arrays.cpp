#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	if (nums1.size() > nums2.size())
		swap(nums1, nums2);
	int m = nums1.size();
	int n = nums2.size();
	int num = (m + n) / 2;
	bool odd = (m + n) % 2;
	int max_of_left, min_of_right;
	if (m == 0)
	{
		if (odd)
			return nums2[n / 2];
		else
			return (nums2[n / 2] + nums2[n / 2 - 1]) / 2.0;
	}
	int imin = 0, imax = m;
	cout << m << endl;
	int i, j;
	while (imin <= imax)
	{
		i = (imin + imax) / 2;
		j = num - i;
		cout << i << " " << j << endl;
		if (i>0 && j<n&&nums1[i - 1] >nums2[j])
			imax = i - 1;
		else if (i<m&&j>0 && nums2[j - 1] >nums1[i])
			imin = i + 1;
		else
		{
			if (i == 0)
				max_of_left = nums2[j - 1];
			else if (j == 0)
				max_of_left = nums1[m - 1];
			else
				max_of_left = max(nums1[i - 1], nums2[j - 1]);
			if (i == m)
				min_of_right = nums2[j];
			else if (j == n)
				min_of_right = nums1[i];
			else
				min_of_right = min(nums1[i], nums2[j]);
			if (odd)
				return min_of_right;
			else
				return (max_of_left + min_of_right) / 2.0;
		}

	}

	return 0;
}

int main()
{
	vector<int> v1{ 1 };
	vector<int> v2{ 2,3,4,5 };
	cout<<findMedianSortedArrays(v1, v2);
	
	system("pause");
}