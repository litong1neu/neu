#include<iostream>
using namespace std;

bool canMeasureWater(int x, int y, int z) {
	if (x>y)
		swap(x, y);
	if (x == z || y == z || x + y == z)
		return true;
	else
	{
		int volume = 0;
		while (1)
		{
			if (volume<x)
				volume += y;
			else
				volume -= x;
			if (volume == z)
				return true;
			else if (volume == 0)
				return false;
		}
	}
}

int gcd(int x, int y)
{
	if (y%x == 0)
		return x;
	if (x == 0)
		return y;
	return gcd(y%x, x);
}

int main()
{
	cout << gcd(3,6);
	system("pause");
}