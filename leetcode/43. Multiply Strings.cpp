#include<iostream>
#include<string>
#include<vector>

using namespace std;
class Solution {
public:
	string multiply(string num1, string num2)
	{
		if (num1 == "0" || num2 == "0")
			return string("0");
		string result(num1.size() + num2.size(), '0');
		for (int i = num1.size() - 1; i >= 0; i--)
			for (int j = num2.size() - 1; j >= 0; j--)
			{
				int val = (num1[i] - '0')* (num2[j] - '0');
				char unit = val % 10 + '0';
				char tens = val / 10 + '0';
				result[i + j + 1] += unit - '0';
				for (int k = 0; result[i + j + 1 - k] > '9'; k++)
				{
					result[i + j + 1 - k] -= 10;
					result[i + j - k]++;
				}
				result[i + j] += tens - '0';
				for (int k = 0; result[i + j - k] > '9'; k++)
				{
					result[i + j - k] -= 10;
					result[i + j - k - 1]++;
				}
			}
		int start = result.find_first_not_of('0');

		return result.substr(start);
	}

};

int main()
{
	string s1("1"), s2("1");
	Solution s;
	//cout << s.multiChar(s1[0], s2[0]);
	cout << s.multiply(s1, s2);
	system("pause");
}