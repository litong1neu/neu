#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lengthOfLongestSubstring(string s) {
	if (s.empty())
		return 0;
	int longest = 1; 
	vector<char> v;
	for (int i = 0; i<s.size(); i++)
	{
		auto itr = find(v.begin(), v.end(), s[i]);
		if (itr == v.end())
			v.push_back(s[i]);
		else
		{
			if (longest<v.size())
				longest = v.size();		
			v.erase(v.begin(), ++itr);
			v.push_back(s[i]);
		}
	}
	if (longest<v.size())
		longest = v.size();
	return longest;
}

int main()
{
	string s1 = "ckilbkd";//"abcabcbb""bbbbb""pwwkew""ckilbkd"
	cout << lengthOfLongestSubstring(s1);
	system("pause");
}