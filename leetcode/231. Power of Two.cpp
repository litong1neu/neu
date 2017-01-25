#include<iostream>

bool isPowerOfTwo(int n) {
	if (n <= 0)
		return false;
	else
	{
		int count = 0;
		for (int i = 0; i<31; i++)
		{
			if ((n >> i & 1) == 1)
				count++;
		}
		std::cout << count;
		if (count == 1)
			return true;
		else
			return false;
	}
}

bool better_isPowerOfTwo(int n)
{
	return n>0 & !(n&(n - 1));	// if n=8, 1000 & 0111 = 0 
}

int main()
{
	isPowerOfTwo(4);
	//int a = 2;
	//std::cout << ((a>>=10)&1);
	system("pause");
}