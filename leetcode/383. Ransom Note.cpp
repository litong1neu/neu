#include<string>
#include<map>
#include<iostream>
using namespace std;

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		map<char, int> count_map;
		for (int i = 0; i<magazine.size(); i++)
			count_map[magazine[i]]++;

		for (int i = 0; i<ransomNote.size() ; i++)
		{
			cout << count_map[ransomNote[i]] << endl;
			if (count_map[ransomNote[i]] == 0)
				return false;
			else
				count_map[ransomNote[i]]--;
		}

		return true;
	}
};

int main()
{
	string r("a");
	string m("b");
	Solution s;
	bool result = s.canConstruct(r, m);
	cout << result;
	system("pause");
}