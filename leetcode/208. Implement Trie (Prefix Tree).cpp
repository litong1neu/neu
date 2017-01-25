#include<string>
#include<vector>
using namespace std;

class Trie;
class TrieNode {
	friend class Trie;
public:
	// Initialize your data structure here.
	TrieNode(char val = ' ') :c(val), end(false)
	{}
	~TrieNode()
	{
		for (auto &node : children)
			delete node;
	}
private:
	bool end;
	char c;
	vector<TrieNode*> children;

};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		TrieNode* p = root;
		TrieNode* new_char = nullptr;
		for (int i = 0; i < word.size(); i++)
		{			
			TrieNode* node = findchar(p, word[i]);
			if (node == nullptr)
			{
				new_char = new TrieNode(word[i]);
				p->children.push_back(new_char);
				p = new_char;
			}
			else
				p = node;
		}
		if (!new_char)
		new_char->end = true;
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		TrieNode* p = root;
		for (int i = 0; i < word.size(); i++)
		{
			TrieNode* node = findchar(p, word[i]);
			if (node == nullptr)
				return false;
			else
				p = node;
		}
		if (p->end)
			return true;
		else
			return false;

	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		TrieNode* p = root;
		for (int i = 0; i < prefix.size(); i++)
		{
			TrieNode* node = findchar(p, prefix[i]);
			if (node == nullptr)
				return false;
			else
				p = node;
		}
		return true;
	}

private:
	TrieNode* root;
	TrieNode* findchar(TrieNode* root,char c)
	{
		for (auto node : root->children)
			if (node->c == c)
				return node;
		return nullptr;
	}
};