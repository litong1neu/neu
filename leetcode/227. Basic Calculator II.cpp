#include<string>
#include<vector>
#include<stack>
#include<iostream>

using namespace std;

class Solution {
public:
	int calculate(string s) {
		stack<int> num_stack;
		stack<char> op_stack;
		int num = 0;
		string ss;
		for (int i = 0; i < s.size(); i++)
		{
			if (isspace(s[i]))
				continue;
			ss.push_back(s[i]);
		}
		s = ss;
		for (int i = 0; i<s.size(); i++)
		{
			if (isdigit(s[i]))
			{
				num = 10 * num + s[i] - '0';
				if (i == s.size() - 1)
					num_stack.push(num);
			}
			else
			{
				num_stack.push(num);
			//	cout << num << endl;
				num = 0;
				if (op_stack.empty())
					op_stack.push(s[i]);
				else if (s[i] == '*' || s[i] == '/')
				{
					if (op_stack.top() == '+' || op_stack.top() == '-')
						op_stack.push(s[i]);
					else
					{
						int second = num_stack.top(); num_stack.pop();
						int first = num_stack.top(); num_stack.pop();
						num_stack.push(getValue(first, second, op_stack.top()));
						op_stack.pop();
						op_stack.push(s[i]);
					}
				}
				else if (s[i] == '+' || s[i] == '-')
				{
					while (!op_stack.empty())
					{
						int second = num_stack.top(); num_stack.pop();
						int first = num_stack.top(); num_stack.pop();
						num_stack.push(getValue(first, second, op_stack.top()));
						op_stack.pop();
					}
						op_stack.push(s[i]);
				}
			}
		}
		while (!op_stack.empty())
		{
			int second = num_stack.top(); num_stack.pop();
			int first = num_stack.top(); num_stack.pop();
			num_stack.push(getValue(first, second, op_stack.top()));
			op_stack.pop();
		}

		return num_stack.top();
	}
private:
	int getValue(int first, int second, char c)
	{
		if (c == '+')
			return first + second;
		else if (c == '-')
			return first - second;
		else if (c == '*')
			return first*second;
		else
			return first / second;
	}
};

int main()
{
	Solution s;
	string equ("1*2-3/4+5*6-7*8");
	cout<<s.calculate(equ);
	system("pause");
}