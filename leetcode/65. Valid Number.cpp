#include<iostream>
#include<string>

using namespace std;
class Solution {
public:
	bool isNumber(string s) {
		if (s.empty())
		{
			cout << "p1";
			return false;
		}
		int i = 0, len = s.size(), count_point = 0, count_num = 0, count_e = 0;
		while (i<len && s[i] == ' ') ++i;
		if (i<len && (s[i] == '+' || s[i] == '-')) ++i;
		while (i<len && ((s[i] >= '0' && s[i] <= '9') || s[i] == '.'))
			s[i++] == '.' ? ++count_point : ++count_num;
		if (count_point > 1 || count_num < 1)
		{
			cout << "p2";
			return false;
		}
		if (i<len && s[i] == 'e'){
			++i;
			if (i<len && (s[i] == '+' || s[i] == '-')) ++i;
			while (i<len && (s[i] >= '0' && s[i] <= '9')) { ++i; ++count_e; }
			if (count_e < 1)
			{
				cout << "p3";
				return false;
			}
		}
		while (i<len && s[i] == ' ') ++i;
		cout << "p4:"<<i;
		return i == len;
	}
};

//int main()
//{
//	string s1("1.3+e12");
//	Solution s;
//	cout<<s.isNumber(s1);
//	system("pause");
//}
