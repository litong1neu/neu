

class Solution {
public:
	int guessNumber(int n) {
		int low = 1, high = n;
		while (low <= high)
		{
			if (guess(low) == 0)
				return low;
			if (guess(high) == 0)
				return high;
			int mid = (low + high) / 2;//(high-low)/2+low
			if (guess(mid) == 0)
				return mid;
			else if (guess(mid) == 1)
			{
				low = mid + 1;
				high--;
			}
			else if (guess(mid) == -1)
			{
				high = mid - 1;
				low++;
			}
		}
		return 0;
	}
};