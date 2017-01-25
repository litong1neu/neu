#include<string>
#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		unordered_map<char, int> roman_map;
		roman_map['I'] = 1;
		roman_map['V'] = 5;
		roman_map['X'] = 10;
		roman_map['L'] = 50;
		roman_map['C'] = 100;
		roman_map['D'] = 500;
		roman_map['M'] = 1000;
		int max_num = 1, result = 0, digit = 0;
		for (int i = s.size() - 1; i >= 0; i--)
		{
			digit = roman_map[s[i]];
			if (digit >= max_num)
			{
				result += digit;
				max_num = digit;
			}
			else
				result -= digit;
		}
		return result;
	}
};

int main()
{
	string s("IV");
	Solution gg;
	cout << gg.romanToInt(s);
	system("pause");
}