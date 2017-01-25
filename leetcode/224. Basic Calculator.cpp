#include<stack>
#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<cmath>
using namespace std;

int opRank(char c)
{
	if (c == '+' || c == '-')
		return 1;
	if (c == '(')
		return 3;
	return 0;
}

int getValue(int first, int second, char c)
{
	if (c == '+')
		return first + second;
	if (c == '-')
		return first - second;
	return 0;
}

int caculator(string& s)
{
	stack<char> stack_op;
	stack<int> stack_num;

	for (int i = 0; i < s.size();)
	{
		if (isspace(s[i]))
		{
			i++; continue;
		}
		else if (s[i] == '(')
			stack_op.push(s[i++]);
		else if (s[i] == '+' || s[i] == '-')
		{
			if (stack_op.empty())
				stack_op.push(s[i++]);
			else if (stack_op.top()=='(')
				stack_op.push(s[i++]);
			else
			{
				char op = stack_op.top();
				stack_op.pop();
				int second = stack_num.top(); stack_num.pop();
				int first = stack_num.top(); stack_num.pop();
				int value = getValue(first, second, op);
				stack_num.push(value);
			}
		}
		else if (isdigit(s[i]))
		{
			int number = s[i++] - '0';
			while (i < s.size() && isdigit(s[i]))
				number = 10 * number + s[i++] - '0';
			stack_num.push(number);
		}

		else if (s[i] == ')')
		{
			i++;
			while (stack_op.top() != '(')
			{
				char op = stack_op.top();
				stack_op.pop();
				int second = stack_num.top(); stack_num.pop();
				int first = stack_num.top(); stack_num.pop();
				int value = getValue(first, second, op);
				stack_num.push(value);
			}			
			stack_op.pop();
		}											
	}

	while (!stack_op.empty())
	{
		char op = stack_op.top();
		stack_op.pop();
		int second = stack_num.top(); stack_num.pop();
		int first = stack_num.top(); stack_num.pop();
		int value = getValue(first, second, op);
		stack_num.push(value);
	}
	return stack_num.top();

}



int main()
{
	string s("123+(10-7+34)-44");
	string s2("(1+(4+5+2)-3)+(6+8)");
	cout << caculator(s2);
	system("pause");
}