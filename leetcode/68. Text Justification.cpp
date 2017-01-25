/*

Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces '&' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:
[
"This    is    an",
"example  of text",
"justification.  "
]

*/

#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<deque>
using namespace std;

class Solution {
private:
	bool lastLine(vector<string>& words, int start,int maxWidth)
	{
		int width = 0;
		for (int i = start; i < words.size(); i++)
			width += words[i].size()+1;
		if (width-1 <= maxWidth)
			return true;
		return false;
	}
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> res;
		int start = 0, end = 0; 
		while (start<words.size() && end<words.size())
		{
			int width = 0;
			while (width - 1 <= maxWidth&&end < words.size())
				width += words[end++].size() + 1;
			if (end==words.size()&&width-1<=maxWidth)
			{
				string line;
				for (int i = start; i < end; i++)
				{
					if (words[i].empty())
						continue;
					for (auto c : words[i])
						line.push_back(c);
					if (line.size() < maxWidth)
					line.push_back('&');
				}
				while (line.size() < maxWidth)
					line.push_back('&');
				res.push_back(line);
				return res;
			}
			end-=2;
			int num_words = end - start + 1;
			if (num_words>1)
			{
				int total_size = 0;
				for (int i = start; i <= end; i++)
					total_size += words[i].size();
				int num_spaces = maxWidth - total_size;
				int even = num_spaces / (num_words - 1);
				int remain = num_spaces % (num_words - 1);
				deque<int> space_count(num_words - 1, even);
				
				for (auto &val : space_count)
				{
					if (remain == 0)
						break;
					val++;
					remain--;
				}

				string line;
				for (int i = start; i <= end; i++)
				{
					for (auto c : words[i])
						line.push_back(c);
					if (!space_count.empty())
					{
						int spaces = space_count.front();
						space_count.pop_front();
						while (spaces-- != 0)
							line.push_back('&');
					}
				}
				start = ++end;
				res.push_back(line);
			}
			else if (num_words == 1)
			{
				string line = words[end];
				while (line.size() <maxWidth)
					line.push_back('&');
				start = ++end;
				res.push_back(line);
			}
		}
		return res;
	}
};

template<class T>
void show(vector<T> &vec)
{
	for (auto str : vec)
		cout << str << endl;
}

int main()
{
	vector<string> v{ "This", "is", "an","example","of","text","justification." };
	vector<string> v1{ "This", "is", "an" };
	vector<string> v2{ "" };
	vector<string> v3{ "a" };
	Solution s;
	show(s.fullJustify(v,16));
	system("pause");
}