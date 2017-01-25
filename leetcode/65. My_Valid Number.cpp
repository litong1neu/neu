#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	bool isNumber(string s) {
		if (s.empty())
			return false;
		int i = 0, len = s.size();
		while (i < len&&isspace(s[i]))
			i++;
		if (s[i] == '+' || s[i] == '-')
			i++;
		int count_num = 0, count_point = 0;
		while (i < len && (isdigit(s[i]) || s[i] == '.'))
			s[i++] == '.' ? count_point++ : count_num++;
		if (count_point > 1 || count_num < 1)
		{
			cout << "p1:";
			return false;
		}
		if (i < len && (s[i] == 'e' || s[i] == 'E'))
		{
			i++;
			int count_e_num = 0;
			if (i<len && (s[i] == '+' || s[i] == '-')) ++i;
			while (i < len&&isdigit(s[i]))
			{
				count_e_num++;
				i++;
			}
			if (count_e_num < 1)
				return false;
		}

		while (i < len&&isspace(s[i])) 
			i++;
		return i == len;
	}
};


int main()
{
	string s1("3");
	Solution s;
	cout << s.isNumber(s1);
	system("pause");
}