#include<vector>
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		heights.push_back(0);
		int len = heights.size(), pos = 0;
		stack<int> st_pos;
		int max_area = 0;
		while (pos<len)
		{
			if (st_pos.empty() || (heights[st_pos.top()] <= heights[pos]))
			{
				st_pos.push(pos++);
			}
			else
			{
				while (!st_pos.empty() && heights[st_pos.top()]>heights[pos])
				{
					int tmp_pos = st_pos.top();
					st_pos.pop();
					max_area = max(max_area, heights[tmp_pos] *(st_pos.empty()?pos: (pos - st_pos.top()-1)));
				}
			}
		}
		//while (!st_pos.empty())
		//{
		//	int tmp_pos = st_pos.top();
		//	st_pos.pop();
		//	max_area = max(max_area, heights[tmp_pos] * (st_pos.empty() ? pos : (pos - st_pos.top() - 1)));
		//}
		return max_area;
	}
};

int main()
{
	Solution s;
	vector<int> v{ 4,2,0,3,2,5 };
	cout<<s.largestRectangleArea(v);
	system("pause");
}