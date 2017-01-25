#include<iostream>
#include<sstream>
#include<string>

using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int last_len = 0;
		int word_len = 0;
		for (int i = 0; i != s.size(); i++)
		{
			if (isalpha(s[i]))
			{
				word_len++;
				if (isspace(s[i + 1])||i+1==s.size())
				{
					last_len = word_len;
					word_len = 0;
				}
			}
		}
		return last_len;
	}
};

class Solution2 {
public:
	int lengthOfLastWord(string s) {
			return 0;
		int last_len = 0;
		int end = s.size() - 1;
		while (isspace(s[end]))
			end--;
		for (int i = end; i >= 0; i--)
		{
			if (isdigit(s[i]))
				last_len++;
			else if (isspace(s[i]))
				break;
		}
		return last_len;
	}
};

int main()
{
	Solution s2;
	string str("Hello t  ony");
	cout<<s2.lengthOfLastWord(str);
	system("pause");
}