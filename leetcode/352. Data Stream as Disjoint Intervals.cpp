#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
	 friend ostream& operator<<(ostream& os, Interval rhs)
	 {
		 os << "start:" << rhs.start << " end:" << rhs.end << endl;
		 return os;
	 }
 };

class SummaryRanges {
public:
	/** Initialize your data structure here. */
	SummaryRanges() {

	}

	void addNum(int val) {
		int left = val, right = val;
		for (auto it = s.begin(); it != s.end();)
		{
			if (val>=it->start&&val<=it->end)
				return;
			else if (val - it->end == 1)
			{
				right = max(it->end,right);
				left = min(it->start,left);
				it = s.erase(it);
			}
			else if (it->start - val == 1)
			{
				left = min(it->start,left);
				right = max(right,it->end);
				it = s.erase(it);
			}
			else
				it++;
		}
		s.insert(Interval(left, right));
	}

	vector<Interval> getIntervals() {
		
		return vector<Interval> (s.begin(),s.end());
	}
private:
	struct cmp
	{
		bool operator()(Interval a, Interval b)
		{
			return a.start < b.start;
		}
	};
	
	set<Interval,cmp> s;

};

/**
* Your SummaryRanges object will be instantiated and called as such:
* SummaryRanges obj = new SummaryRanges();
* obj.addNum(val);
* set<Interval,cmp> param_2 = obj.getIntervals();
*/

int main()
{
	SummaryRanges s;
	s.addNum(6);
	s.addNum(1);
	s.addNum(3);
	s.addNum(7);
	s.addNum(2);
	s.addNum(4);
	s.addNum(5);
	for (auto in : s.getIntervals())
		cout << in;
	system("pause");
}