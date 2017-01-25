#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		int carry = 0;
		string str;
		if (a.size()<b.size())
			swap(a, b);
		int lenb = b.size(), lena = a.size();
		int posb = lenb - 1, posa = lena - 1;
		while (posb >= 0)
		{
			int digit = carry + a[posa--] - '0' + b[posb--] - '0';
			if (digit == 0)
			{
				str.push_back('0');
				carry = 0;
			}
			else if (digit == 1)
			{
				str.push_back('1');
				carry = 0;
			}
			else if (digit == 2)
			{
				str.push_back('0');
				carry = 1;
			}
			else if (digit == 3)
			{
				str.push_back('1');
				carry = 1;
			}
		}
		while (posa >= 0)
		{
			int digit = carry + a[posa--]-'0';
			if (digit == 0)
			{
				str.push_back('0');
				carry = 0;
			}
			else if (digit == 1)
			{
				str.push_back('1');
				carry = 0;
			}
			else if (digit == 2)
			{
				str.push_back('0');
				carry = 1;
			}
		}
		if (carry)
			str.push_back('1');
		return string(str.rbegin(), str.rend());
	}
};

int main()
{
	string a("11"), b("1");
	Solution s;
	cout<<s.addBinary(a, b);
	getchar();
}