#include<vector>
#include<iostream>
using namespace std;

int low_index(vector<int> vec,int val)
{
	int low = 0, high = vec.size()-1;
	while (low < high)
	{
		int mid = low + (high - low) / 2;
		if (vec[mid] < val)
			low=mid+1;
		else
			high = mid;
	}
	if (vec[low] != val)
		return -1;
	else
		return low;
}

int up_index(vector<int> vec, int val)
{
	int low = 0, high = vec.size() - 1;
	while (low<high)
	{
		int mid = low + (high - low) / 2;
		if (vec[mid] <= val)
			low = mid + 1;
		else
			high = mid;
	}
	if (vec[low] <= val)
		return -1;
	else
		return low;
}