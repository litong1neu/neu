#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> res;
		for (int i = 0; i <= int(s.size()) - 10; i++)
		{
			int count = 0;
			cout << "haha";
			string temp = s.substr(i, 10);
			for (int j = i; j <= (s.size()) - 10; j++)
				if (s.substr(j, 10) == temp)
				{
					count++;
					if (count == 2)
					{
						res.push_back(temp);
						break;
					}
				}
		}

		return res;
	}
};

class Solution2 {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> res;
		unordered_map<string, int> hash;
		if (s.size() >= 11)
		{
			for (int i = 0; i <= int(s.size()) - 10; i++)
			{
				string temp = s.substr(i, 10);
				cout << hash[temp]<<endl;
				if (hash[temp] == 1)
				{
					res.push_back(temp);
					hash[temp]++;
				}
				else
					hash[temp]++;
			}
		}
		return res;
	}
private:

};
void show(vector<string> &vec)
{
	for (auto str : vec)
		cout << str << endl;
}
int main()
{
	Solution2 s;
	vector<string> v=s.findRepeatedDnaSequences("AAAAAAAAAAAA");
	//show(v);
	system("pause");
}