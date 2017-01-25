#include<iostream>
#include<stack>
#include<string>
using namespace std;
class Solution {
public:
	int longestValidParentheses(string s) {
		int count = 0;
		stack<char> ss;
		for (int i = 0; i<s.size(); i++)
		{
			if (s[i] == '(')
				ss.push('(');
			else if (s[i] == ')'&&!ss.empty())
			{
				count++;
				ss.pop();
			}
		}
		return count * 2;
	}
};

int main()
{
	Solution s;
	cout << s.longestValidParentheses(")(");
	getchar();
}