/*
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
*/
#include<string>
#include<vector>
#include<iostream>
using namespace std;




class Solution {
public:
	string numberToWords(int num) {
		if (num == 0)
			return "Zero";
		return helper(num).substr(1);
	}
private:
	static const vector<string> below_20;
	static const vector<string> below_100;
	string helper(int num)
	{
		string str;
		if (num >= 1000000000)
			return helper(num / 1000000000) + " Billion" + helper(num % 1000000000);
		else if (num >= 1000000)
			return helper(num / 1000000) + " Million" + helper(num % 1000000);
		else if (num >= 1000)
			return helper(num/1000)+" Thousand"+helper(num%1000);
		else if (num >= 100)
			return helper(num/100)+" Hundred"+helper(num%100);
		else if (num >= 20)
			return " "+below_100[num/10-2]+helper(num%10);
		else if (num>=1)
			return " "+below_20[num - 1];
		else
		return "";
	}
};

const vector<string> Solution::below_20{ "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve",
"Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
const vector<string> Solution::below_100{ "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

int main()
{
	Solution s;
	cout << s.numberToWords(1234567);
	system("pause");
}