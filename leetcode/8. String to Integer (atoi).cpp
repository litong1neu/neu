#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
	int myAtoi(string str)
	{
		int i = 0;
		bool sign = true;
		while (i<str.size())
		{
			if (isspace(str[i]))
				i++;
			else if (issign(str[i]) && !isdigit(str[i + 1]))
				return 0;
			else if (!issign(str[i]) && !isdigit(str[i]))
				return 0;
			else if (str[i] == '-'&&isdigit(str[i + 1]))
			{
				sign = false;
				i++;
			}
			else if (isdigit(str[i]))
			{
				long long number = str[i++] - '0';
				while (i < str.size() && isdigit(str[i]))
				{
					number = number * 10 + str[i++] - '0';
					if (number > INT_MAX&&sign)
						return INT_MAX;
					else if (-number < INT_MIN)
						return INT_MIN;
				}
				return sign ? number : -number;
			}
			else
				i++;

		}
		return 0;
	}
private:
	bool issign(char c)
	{
		if (c == '+' || c == '-')
			return true;
		else
			return false;
	}
};

int main()
{
	string s("+1");
	Solution g;
	cout << g.myAtoi(s);
	system("pause");
}