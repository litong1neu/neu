#include<sstream>
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string val("321+245");
	istringstream ss;
	ss.str(val);
	while (ss)
	{
		int num;
		ss >> num;
		cout << num<<" ";
	}
	system("pause");
}
