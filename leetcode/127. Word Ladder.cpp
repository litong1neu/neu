
class Solution {
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
		wordList.insert(endWord);
		wordList.erase(beginWordWord);
		vector<string> cur_l{ beginWord };
		helper(cur_l, wordList, endWord, 1);
		return path_len;
	}
private:
	int path_len = 0;
	vector<string> findNextWord(vector<string> current_level, unordered_set<string> &wordList)
	{
		vector<string> next_level;
		for (auto cur : current_level)
		{
			for (auto &c : s)
			{
				char c_origin = c;
				for (c = 'a'; c <= 'z'; c++)
					if (c != c_origin)
					{
						if (wordList.count(s))
							result.push_back(s);
					}
				c = c_origin;
			}

			return next_level;
		}

		void helper(vector<string> current_level, unordered_set<string> &wordList, end, count)
		{
			for (auto w : current_level)
			{
				if (w == end)
				{
					path_len = count;
					return;
				}
			}
			for (auto word : current_level)
				wordList.erase(word);
			vector<string> next_level = findNextWord(current_level);
			helper(next_level, wordList, end, count + 1);
		}
	};