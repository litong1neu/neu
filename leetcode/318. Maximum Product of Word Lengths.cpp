#include<unordered_map>
#include<unordered_set>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maxProduct(vector<string>& words) {
		if (words.empty())
			return 0;

		helper(map, words);
		int maxProduct = 0;
		for (int i = 0; i<words.size(); i++)
			for (int j = i + 1; j<words.size(); j++)
			{
				if (isDiff(words[i], words[j]))
					maxProduct = max(maxProduct, int(words[i].size()*words[j].size()));
			}
		return maxProduct;
	}
private:
	unordered_map<string, unordered_set<char>> map;
	void helper(unordered_map<string, unordered_set<char>> &map, vector<string> &words)
	{
		for (auto &word : words)
			for (auto &c : word)
				map[word].insert(c);
	}
	bool isDiff(string &s1, string &s2)
	{
		for (auto c : s1)
			if (map[s2].count(c))
				return false;
		return true;
	}
};