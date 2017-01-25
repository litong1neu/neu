/*


* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };

class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		if (intervals.empty())
			return vector<Interval>{newInterval};
		vector<Interval> res = intervals;
		auto it = res.begin();
		auto pos = res.end();
		while (pos == res.end() && it != res.end())
		{
			if (newInterval.start > it->end)
				it++;
			else
			{
				pos = it;
				if (newInterval.end<pos->start)
				{
					res.insert(pos, newInterval);
					return res;
				}
				pos->start = min(pos->start, newInterval.start);
				pos->end = max(pos->end, newInterval.end);
			}
		}
		if (pos == res.end())
		{
			res.push_back(newInterval);
			return res;
		}

		it = pos + 1;
		while (it != res.end())
		{
			if (it->start <= pos->end)
			{
				pos->end = max(pos->end, it->end);
				it = res.erase(it);
			}
			else
				break;
		}
		return res;

	}
};


*/