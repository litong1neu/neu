#include<string>
#include<vector>
#include<queue>
#include<unordered_set>
#include<iostream>
using namespace std;

class Solution {
public:
	vector<string> removeInvalidParentheses(string s) {
		queue<string> q;
		unordered_set<string> visited;
		vector<string> res;
		bool found = false;
		static int haha = 1;
		q.push(s);
		while (!q.empty())
		{
			string str = q.front();
			q.pop();
			if (isValid(str))
			{
				res.push_back(str);
				found = true;
			}
			if (found)
				continue;
			else
			{
				for (int i = 0; i<str.size(); i++)
				{
					if (str[i] != '('&&str[i] != ')')
						continue;
					string tmp = str.substr(0, i) + str.substr(i + 1);
					cout <<haha<<" " <<tmp << endl;
					if (visited.count(tmp) == 0)
					{
						visited.insert(tmp);
						q.push(tmp);
					}
				}
				haha++;
			}
		}
		return res;
	}
private:
	bool isValid(string s)
	{
		if (s.empty())
			return false;
		
		int count = 0;
		for (int i = 0; i<s.size(); i++)
		{
			if (s[i] == '(')
				count++;
			else if (s[i] == ')'&&--count<0)
				return false;
		}
		return count == 0;
	}
};

int main()
{
	string str("x(");
	Solution s;
	s.removeInvalidParentheses(str);
	system("pause");
}