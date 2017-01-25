#include<string>
#include<iostream>
#include<vector>
using namespace std;


string longestPalindrome(string s) {
	if (s.empty()) return "";
	if (s.size() == 1) return s;
	int min_start = 0, max_len = 1;
	for (int i = 0; i < s.size();) {
		if (s.size() - i <= max_len / 2) break;
		int j = i, k = i;
		while (k < s.size() - 1 && s[k + 1] == s[k]) ++k; // Skip duplicate characters.
		i = k + 1;
		while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
		int new_len = k - j + 1;
		if (new_len > max_len) { min_start = j; max_len = new_len; }
	}
	return s.substr(min_start, max_len);
}

string MYlongestPalindrome(string s) {
	if (s.empty())
		return s;
	int start = 0, max_len = 1, n = s.size();
	for (int i = 0; i<n;i++ )
	{
		if (n - i <= max_len / 2)
			break;
		int right=i, left = i;
		cout << "*****" << right<<endl;
		cout << "*****" << left << endl;
		while (right<n - 1 && s[right] == s[right + 1])
			right++;
		cout << "p1:" << right << endl;
		//i = right + 1;
		while (right<n - 1 && left>0 && s[right+1] == s[left-1])
		{
			right++;
			left--;
		}
		cout << "p2:" << right << endl;
		int new_len = right - left + 1;

		if (new_len>max_len)
		{
			start = left;
			max_len = new_len;
		}
	}


	return s.substr(start, max_len);
}

string DPlongestPalindrome(string s)
{
	int n=s.size(),start=0,max_len=1;
	vector<vector<bool>> table(n, vector<bool>(n));
	
	//for (int i = 0; i < n; i++)
	//	table[i][i] = true;

	for (int i = 0; i < n ; i++)
	{
		table[i][i] = true;
		if (s[i] == s[i + 1])
		{
			table[i][i + 1] = true;
			start = i;
			max_len = 2;
		}
	}

	for (int k = 3; k <= n; k++)
	{
		//cout << k << endl;
		for (int i = 0; i < n - k + 1; i++)
		{
			int j = i + k - 1;
			if (s[i] == s[j] && table[i + 1][j - 1])
			{
				table[i][j] =true;
				if (k > max_len)
				{
					max_len = k;
					start = i;
				}
			}
		}
	}
	//cout << table[0][4];
	return s.substr(start, max_len);
}
int main()
{
	string str1("aba");
	string str("iopsajhffgvrnyitusobwcxgwlwniqchfnssqttdrnqqcsrigjsxkzcmuoiyxzerakhmexuyeuhjfobrmkoqdljrlojjjysfdslyvckxhuleagmxnzvikfitmkfhevfesnwltekstsueefbrddxrmxokpaxsenwlgytdaexgfwtneurhxvjvpsliepgvspdchmhggybwupiqaqlhjjrildjuewkdxbcpsbjtsevkppvgilrlspejqvzpfeorjmrbdppovvpzxcytscycgwsbnmspihzldjdgilnrlmhaswqaqbecmaocesnpqaotamwofyyfsbmxidowusogmylhlhxftnrmhtnnljjhhcfvywsqimqxqobfsageysonuoagmmviozeouutsiecitrmkypwknorjjiaasxfhsftypspwhvqovmwkjuehujofiabznpipidhfxpoustquzyfurkcgmioxacleqdxgrxbldcuxzgbcazgfismcgmgtjuwchymkzoiqhzaqrtiykdkydgvuaqkllbsactntexcybbjaxlfhyvbxieelstduqzfkoceqzgncvexklahxjnvtyqcjtbfanzgpdmucjlqpiolklmjxnscjcyiybdkgitxnuvtmoypcdldrvalxcxalpwumfx");

	cout<<MYlongestPalindrome(str1);
	system("pause");
}