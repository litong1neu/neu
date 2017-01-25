#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
	int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		if (envelopes.empty())
			return 0;

		sort(envelopes.begin(), envelopes.end(), cmp());
		int count1 = 0, minW = INT_MIN, minH = INT_MIN;
		for (int i = 0; i<envelopes.size(); i++)
		{
			if (envelopes[i].first>minW&&envelopes[i].second>minH)
			{
				count1++;
				minW = envelopes[i].first;
				minH = envelopes[i].second;
			}
		}
		return max(count1, count2);
	}
private:
	struct cmp{
		bool operator()(pair<int, int> &p1, pair<int, int> &p2)
		{
			if (p1.first == p2.first)
				return p1.second>p2.second;
			return p1.first<p2.first;
		}
	};
};

class Solution1 {
public:
	static bool cmp_first(const pair<int, int>& i, const pair<int, int>& j) {
		if (i.first == j.first)
			return i.second > j.second;
		return i.first < j.first;
	}
	int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		vector<int> candidates;
		sort(envelopes.begin(), envelopes.end(), cmp_first);
		vector<int> dp;
		for (int i = 0; i < envelopes.size(); ++i) {
			auto itr = lower_bound(dp.begin(), dp.end(), envelopes[i].second);
			if (itr == dp.end()) {
				dp.push_back(envelopes[i].second);
			}
			else {
				*itr = envelopes[i].second;
			}
		}
		for (auto val : dp)
			cout << val << endl;
		return dp.size();
	}
};
int main()
{
	Solution s;
	s.maxEnvelopes(vector < pair<int, int> > { make_pair(77, 81), make_pair(72, 45), make_pair(52, 68), make_pair(50, 53), make_pair(46, 89) });
	//vector<pair<int, int>> vec{ make_pair(2, 100), make_pair(3, 200), make_pair(4, 300), make_pair(5, 500), make_pair(5, 400),
	//	make_pair(5, 250), make_pair(6, 370), make_pair(6, 360), make_pair(7, 380), make_pair(1,500) };
	//sort(vec.begin(), vec.end(), [](pair<int, int>&p1, pair<int, int>&p2){
	//	if (p1.second == p2.second)
	//		return p1.first < p2.first;
	//	return p1.second < p2.second; });
	//for (auto p : vec)
	//	cout << p.first<<" "<<p.second << endl;
	getchar();
}