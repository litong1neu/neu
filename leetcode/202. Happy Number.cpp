#include<iostream>

using namespace std;
class Solution {
public:
	bool isHappy(int n) {
		int walk = digitSquare(n);
		int run = digitSquare(walk);
		while (walk != run)
		{
			walk = digitSquare(walk);
			cout << "walk: " << walk;
			run = digitSquare(digitSquare(run));
			cout << "run: " << run;
		}
	
		return walk == 1;
	}
private:
	int digitSquare(int n)
	{
		int res = 0;
		while (n)
		{
			res += pow(n % 10, 2);
			n /= 10;
		}
	//	cout << res << endl;
		return res;
	}
};

int main()
{
	Solution s;
	s.isHappy(19);
	system("pause");
}