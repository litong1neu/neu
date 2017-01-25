#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		unordered_map<string, int> dict;
		
		vector<int > res;
		if (!words.empty() && !words[0].empty())
		{
			int wlen = words[0].size();
			//int left = 0;
			for (auto word : words)
				dict[word]++;
			for (int i = 0; i<wlen; i++)
			{
				int left = i;
				int count = words.size();
				unordered_map<string, int> temp_dict;
				for (int j = i; j <= int(s.size()) - wlen; j += wlen)
				{
					string temp = s.substr(j, wlen);
					if (!dict.count(temp))
					{
						temp_dict.clear();
						left = j + wlen;
						count = words.size();
					}
					else
					{
						temp_dict[temp]++;
						if (temp_dict[temp] <= dict[temp])
							count--;
						else
						{
							while (temp_dict[temp]>dict[temp])
							{
								string head = s.substr(left, wlen);
								temp_dict[head]--;
								left += wlen;
								//if (temp_dict[head]<dict[head])
								if (head!=temp)
									count++;				
							}
						}
						if (count == 0)
						{
							res.push_back(left);
							temp_dict[s.substr(left, wlen)]--;
							count++;
							left += wlen;
							
						}
					}
				}

			}
		}
		return res;
	}
};
void show(vector<int> v)
{
	for (auto val : v)
		cout << val << " ";
}
int main()
{
	string str("barfoofoobarthefoobarman");
	vector<string> v{ "bar", "foo", "the" };
	Solution s;
	show(s.findSubstring(str, v));
	system("pause");
}