#include<vector>
#include<deque>
#include<iostream>
using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		deque<int> res;
		int num = 0;
		vector<int> vec=digits;
		auto rit = vec.rbegin();
		while (rit != vec.rend())
		{
			num = *rit + 1;
			rit++;
			if (num >= 10)
				res.push_front(0);
			else
			{
				res.push_front(num);
				break;
			}
		}

		//auto oldit = digits.rbegin();
		//auto newit = res.rbegin();
		//for (; newit != res.rend(); oldit++, newit++)
		//	*oldit = *newit;
		return vector<int>(digits.begin(), digits.end());
	}
};

//int main()
//{
//	std::vector<int> myvector(5);  // 5 default-constructed ints
//
//	int i = 0;
//
//	std::vector<int>::reverse_iterator rit = myvector.rbegin();
//	for (; rit != myvector.rend(); rit++)
//		*rit = ++i;
//
//	std::cout << "myvector contains:";
//	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//
//	return 0;
//}

int main()
{
	vector<int> v{ 1 };
	Solution s;
	s.plusOne(v);

}