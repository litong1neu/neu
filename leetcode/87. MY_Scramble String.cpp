#include<string>
#include<set>
#include<unordered_map>
#include<iostream>
using namespace std;


class Solution {
public:
	bool isScramble(string s1, string s2) {

		unordered_map<string, bool> isScramblePair;
		return helper(isScramblePair, s1, s2);
	}

private:
	bool isNotScramble(string s1, string s2)
	{
		if (s1.size() != s2.size())
			return false;
		set<char> set_s1(s1.begin(), s1.end());
		set<char> set_s2(s2.begin(), s2.end());
		if (set_s1 != set_s2)
			return true;
		else
			return false;
	}
	bool helper(unordered_map<string, bool> &m,string s1,string s2)
	{
		bool res = false;
		int len = s1.size();
		if (s1 == s2)
			return m[s1 + s2] = true;
		else if (isNotScramble(s1, s2))
			return m[s1 + s2] = false;
		else
		{
			if (m.count(s1 + s2))
				return m[s1 + s2];
			else
			{
				for (int i = 1; i <len; i++)
				{
					cout << len << endl;
					if ((helper(m, s1.substr(0, i), s2.substr(0, i)) && helper(m, s1.substr(i, len - i), s2.substr(i, len - i)))
						|| (helper(m, s1.substr(0, i), s2.substr(len - i, i)) && helper(m, s1.substr(i, len - i), s2.substr(0, len - i)))
						)
					{
						res = true; break;
					}
				}
			}
		}
		return m[s1 + s2] = res;
	}
};

int main()
{
	Solution s;
	string s1("abcd"), s2("bdac");
	cout << s.isScramble(s1, s2);
	system("pause");
}