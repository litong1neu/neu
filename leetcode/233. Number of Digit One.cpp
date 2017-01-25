#include<iostream>

using namespace std;
class Solution {
public:
	int countDigitOne(int n) {
		int ones = 0;
		long long digit = 1;
		while (digit<=n)
		{
			int l_part = n / digit;
			int r_part = n%digit;
			if (l_part % 10 == 1)
			{
				ones += (l_part / 10)*digit + r_part + 1;
				std::cout << "p1"<<endl;
			}

			else if (l_part % 10 == 0)
			{
				ones += (l_part / 10)*digit;
				std::cout << "p2"<<endl;
			}
			else
			{
				ones += (l_part / 10 + 1)*digit;
				std::cout << "p3"<<endl;
			}
			digit *= 10;
		}
		return ones;
	}
};

int countDigitOne(int n) {
	int ones = 0;
	for (long long m = 1; m <= n; m *= 10)
		ones += (n / m + 8) / 10 * m + (n / m % 10 == 1) * (n%m + 1);
	return ones;
}

int main()
{
	Solution s;
	std::cout << countDigitOne(1410065408) << endl;
	std::cout << s.countDigitOne(1410065408);
	system("pause");
}