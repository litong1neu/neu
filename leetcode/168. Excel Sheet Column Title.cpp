#include<string>
#include<iostream>
#include<vector>
using namespace std;

//Ҫ��ʮ����תΪ�����Ƶķ�ʽ��ֻ����Ը����Ƶ�Ȩֵ��ȡ������������һ�ε���������λ����
//�ڶ���������ʮλ���������������ƣ�ֱ��������С��Ȩֵ�����ı����������λ����


class Solution {
public:
	string convertToTitle(int n) {
		string result("");
		while (n != 0)
		{
			int digit = (n - 1) % 26;
			char c = 'A' + digit;
			result = c + result;
			n = (n - 1) / 26;
		}
		return result;
	}
};

int main()
{
	Solution s;
	cout <<s.convertToTitle(52);
	system("pause");
}