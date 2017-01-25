#include<vector>
#include<algorithm>
#include<numeric>
#include<iostream>
using namespace std;

class Solution {
public:
	int candy(vector<int>& ratings) {
		vector<int> candies(ratings.size(), 1);
		int len = ratings.size();
		for (int i = 0; i<len - 1; i++)
		{
			if (ratings[i]<ratings[i + 1])
				candies[i + 1] += candies[i] + 1;
		}
		for (int j = len - 1; j>0; j--)
		{
			if (ratings[j]<ratings[j - 1] && candies[j] >= candies[j - 1])
				candies[j - 1]++;
		}
		return accumulate(candies.begin(), candies.end(), 0);
	}
};

int candy(vector<int>& ratings) {
	vector<int> candies(ratings.size(), 1);
	int len = ratings.size();
	for (int i = 0; i<len - 1; i++)
	{
		if (ratings[i]<ratings[i + 1])
			candies[i + 1] = candies[i] + 1;
	}
	for (int j = len - 1; j>0; j--)
	{
		if (ratings[j]<ratings[j - 1] && candies[j] >= candies[j - 1])
			candies[j - 1]=candies[j]+1;
	}
	return accumulate(candies.begin(), candies.end(), 0);
}

int main()
{
	vector<int> vec{ 1, 2 };
	cout << candy(vec);
	system("pause");
}