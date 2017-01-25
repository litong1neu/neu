#include<iostream>
using namespace std;

class Solution
{
public:
	int divide(int dividend, int divisor)
	{
		if (divisor == 0 || (dividend == INT_MIN&&divisor == -1))
			return INT_MAX;
		bool sign = (dividend > 0 ^ divisor > 0) ? false : true;
		int res = 0;

		long long up = labs(dividend), down = labs(divisor);

		while (up >= divisor)
		{
			long long temp = down;
			int multi = 1;
			while (up >= temp << 1)
			{
				temp <<= 1;
				multi <<= 1;
			}
			up -= temp;
			res += multi;
		}
		return sign ? res : -res;
	}
};