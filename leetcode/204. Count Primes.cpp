#include<iostream>
using namespace std;
class Solution {
public:
	int countPrimes(int n) {
		int count = 0;
		for (int i = 2; i<n; i++)
			if (isPrime(i))
				count++;
		return count;
	}
private:
	bool isPrime(int num)
	{
		if (num <= 1)
			return false;
		for (int i = 2; i*i <= num; i++)
			if (num%i == 0)
				return false;
		return true;
	}
};

int main()
{
	Solution s;
	cout << s.countPrimes(4);
	system("pause");
}
