#include<iostream>

using namespace std;

int mySqrt(int x) {
	int low = 1, high = INT_MAX;
	while (low<high)
	{
		int mid = low + (high - low) / 2;
		if (mid == x / mid)
			return mid;
		if (mid>x / mid)
			high = mid;
		else
			low = mid + 1;

	}
	return low>x/low?low-1:low;
}

int main()
{
	cout << mySqrt(2);
	getchar();
}