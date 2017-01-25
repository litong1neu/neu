#include<string>
#include<iostream>
#include<vector>
using namespace std;

//要将十进制转为各进制的方式，只需除以各进制的权值，取得其余数，第一次的余数当个位数，
//第二次余数当十位数，其余依此类推，直到被除数小于权值，最后的被除数当最高位数。


class Solution {
public:
	string convertToTitle(int n) {
		string result("");
		while (n != 0)
		{
			int digit = (n - 1) % 26;
			char c = 'A' + digit;
			result = c + result;
			n = (n - 1) / 26;
		}
		return result;
	}
};

int main()
{
	Solution s;
	cout <<s.convertToTitle(52);
	system("pause");
}