#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
class Solution {
public:
	string shortestPalindrome(string s) {
		s += "#";
		string rev_s(s.rbegin(), s.rend());
		unordered_set<string> hash;
		for (int i = 0; i<int(s.size()) - 1; i++)
			hash.insert(s.substr(0, i + 1));
		string pre;
		for (int i = 1; i<rev_s.size(); i++)
		{
			if (hash.count(rev_s.substr(i)))
			{
				pre = rev_s.substr(0, i);
				break;
			}
		}
		string res = pre + s;
		return res.substr(1,int(res.size())-2);
	}
};

class Solution1 {
public:
	string shortestPalindrome(string s) {
		string rev_s(s.rbegin(), s.rend());
		int len = s.size();
		string pre;
		for (int k = len; k >= 1; k--)
		{
			if (s.substr(0, k) == rev_s.substr(len - k))
			{
				pre = rev_s.substr(0, len - k);
				break;
			}
		}
		return pre + s;
	}
};

int main()
{
	string str("aacec");
	Solution1 s;
	cout<<s.shortestPalindrome(str);
	getchar();
}