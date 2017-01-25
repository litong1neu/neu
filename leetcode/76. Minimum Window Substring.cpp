#include<string>
#include<vector>
#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		unordered_map<char, int> char_map;
		for (auto c : t)
			char_map[c]++;
		int start = 0, end = 0, pos = 0, len = INT_MAX, counter = t.size();
		while (end<s.size())
		{
			if (char_map[s[end++]]-->0)
				counter--;
			while (counter == 0)
			{
				if (end - start<len)
				{
					len = end - start;
					pos = start;
				}
				if (char_map[s[start++]]++ == 0)
					counter++;
			}
		}
		return len == INT_MAX ? "" : s.substr(pos, len);
	}
};

string minWindow(string s, string t) {
	unordered_map<char, int> char_map;
	unordered_map<char, int> tchar_map;
	for (auto c : t)
		char_map[c]++;
	int start = 0, end = 0, pos = 0, len = INT_MAX, counter = t.size();
	while (end<s.size())
	{
		if (char_map.count(s[end]))
		{
			tchar_map[s[end]]++;
			if (tchar_map[s[end]] <= char_map[s[end]])
				counter--;
			end++;
		}
		else
			end++;
		while (counter == 0)
		{
			if (end - start<len)
			{
				len = end - start;
				pos = start;
			}
			if (char_map.count(s[start]))
			{
				tchar_map[s[start]]--;
				if (tchar_map[s[start]] < char_map[s[start]])
				counter++;
			}
			start++;
		}
	}
	return len == INT_MAX ? "" : s.substr(pos, len);
}


int main()
{
	string s("ADOBECODEBANC"), t("ABC");
	Solution s1;
	cout<<minWindow(s, t);
	system("pause");
}