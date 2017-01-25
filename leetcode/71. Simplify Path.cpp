#include<sstream>
#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		stringstream str(path);
		string tmp;
		stack<string> sstack;
		while (getline(str, tmp, '/'))
		{
			if (tmp == "" || tmp == ".")
				continue;
			else if (tmp == "..")
			{
				if (sstack.empty())
					return "/";
				else
					sstack.pop();
			}
			else
				sstack.push(tmp);
		}
		string res = "";
		while (!sstack.empty())
		{
			res = "/" + sstack.top() + res;
			sstack.pop();
		}
		return res;
	}
};

int main()
{
	string old("/a/./b/../../c/");
	string old2("/home2/");
	Solution s;
	cout << s.simplifyPath(old2);
	system("pause");
}