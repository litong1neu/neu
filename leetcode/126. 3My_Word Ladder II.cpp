#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

class Vertex
{
public:
	int depth;
	string word;
	Vertex* parent;
	vector<Vertex*> next;
	bool known;
public:
	Vertex(const string &s) :word(s), depth(0), parent(nullptr),known(true){}
	Vertex(const string &s, int i, Vertex* par) :word(s), depth(i), parent(par),known(false){}
};

bool OneCharDiff(const string &s, const string &cmp)
{
	int flag = 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i] - cmp[i] != 0)
			flag++;
	if (flag == 1)
		return true;
	else
		return false;
}

vector<Vertex*> findNextWords(Vertex* v, unordered_set<string> &wordList)
{
	vector<Vertex*> result;
	for (auto cmp_it = wordList.begin(); cmp_it != wordList.end(); cmp_it++)
		if (OneCharDiff(v->word, *cmp_it))
		{
			Vertex* next_word = new Vertex(*cmp_it, v->depth + 1, v);
			result.push_back(next_word);
		}
	return result;
}

void buildtree(Vertex* current_vertex, unordered_set<string> &wordList)
{
	queue<Vertex*> q;
	q.push(current_vertex);
	while (!q.empty())
	{
		Vertex* v = q.front();
		q.pop();
		if (v->parent!=nullptr)
			for (auto w:v->parent->next)
				wordList.erase(w->word);
		v->next = findNextWords(v, wordList);
		for (auto w : v->next)
			q.push(w);
			
		
	}
}

vector<string> buildOnePath(Vertex* v)
{
	vector<string> path;
	while (1)
	{
		path.push_back(v->word);
		v = v->parent;
		if (v == nullptr)
			break;
	}
	return path;
}

void buildPaths(Vertex* begin_vertex, const string &endWord, int &depth, vector<vector<string>> &paths)
{
	queue<Vertex*> q;
	q.push(begin_vertex);
	while (!q.empty())
	{
		Vertex* v = q.front();
		q.pop();
		
		if (OneCharDiff(v->word, endWord))
		{
			paths.push_back(buildOnePath(v));
			while (!q.empty())
			{
				Vertex* w = q.front();
				q.pop();
				if (OneCharDiff(w->word, endWord))
					paths.push_back(buildOnePath(w));;
			}
			return;
		}

		for (auto w : v->next)
			q.push(w);
	}

}

void show(Vertex* head)
{
	cout << head->word << " depth: " << head->depth;
	cout << endl;
	if (head->next.size() == 0)
		return;
	for (auto &next : head->next)
		show(next);
}

void reverse(vector<vector<string>> &paths, const string& endWord)
{
	for (auto &path : paths)
	{
		reverse(path.begin(), path.end());
		path.push_back(endWord);
	}
}

vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
	if (beginWord == endWord)
		return vector < vector<string> > {vector < string > {beginWord}};
	Vertex* head = new Vertex(beginWord);
	buildtree(head, wordList);
	show(head);
	vector<vector<string>> paths;
	int depth = INT_MAX;
	buildPaths(head, endWord, depth, paths);
	reverse(paths, endWord);
	return paths;
}


int main()
{

	//unordered_set<string> wordList{ "miss", "dusk", "kiss", "musk", "tusk", "diss", "disk", "sang", "ties", "muss" };
	//string beginWord = "kiss"; string endWord = "tusk";
	unordered_set<string> wordList{ "ted","rex","tad","tex" };
	string beginWord = "red"; string endWord = "tax";
	wordList.erase(beginWord);
	wordList.erase(endWord);

	vector<vector<string> > result;
	result = findLadders(beginWord, endWord, wordList);
	for (auto &a : result)
	{
		for (auto &b : a)
			cout << b << " ";
		cout << endl;
	}

	system("pause");
}