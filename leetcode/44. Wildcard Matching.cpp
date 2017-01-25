#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) 
	{
		int slen = s.size(), plen = p.size();
		int i = 0, j = 0,match=0;
		int pos_asterisk = -1;
		while (i < slen)
		{
			if (s[i] == p[j] || p[j] == '?')
			{
				i++;
				j++;
			}
			else if (p[j] == '*')
			{
				pos_asterisk = j;
				match = i;
				j++;
			}
			else if (pos_asterisk != -1)
			{
				j = pos_asterisk + 1;
				match++;
				i = match;
			}
			else
				return false;
		}
		while (j != plen&&p[j] == '*')
			j++;
		return j == plen;
	}
};

class Solution2 {
public:
	bool isMatch(string s, string p) {
		int m = s.length(), n = p.length();
		if (n > 30000) return false; // the trick
		vector<bool> cur(m + 1, false);
		cur[0] = true;
		for (int j = 1; j <= n; j++) {
			bool pre = cur[0]; // use the value before update
			cur[0] = cur[0] && p[j - 1] == '*';
			for (int i = 1; i <= m; i++) {
				bool temp = cur[i]; // record the value before update
				if (p[j - 1] != '*')
					cur[i] = pre && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
				else cur[i] = cur[i - 1] || cur[i];
				pre = temp;
			}
		}
		return cur[m];
	}
};

int main()
{
	
	string s("aa");
	string p("a");
	int i = 0,j=0;
	while (i < s.size())
	{
		if (s[i] == p[j] || p[j] == '?')
		{
			i++;
			j++;
		}
		else
			break;
	}
	cout << j;

	//Solution sol;
	//cout<<sol.isMatch(s, p);
	system("pause");

	//abefcdgiescdfimde
	//ab*cd?i*de
}