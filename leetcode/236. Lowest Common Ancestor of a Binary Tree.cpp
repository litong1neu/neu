#include<queue>
#include<unordered_map>
using namespace std;
struct TreeNode 
{
    int val;
    TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
	{
		unordered_map<TreeNode*,int> count;
		TreeNode* lowest = nullptr;
		bool find = false;
		findValue_DFS(root, p, q, count, lowest,find);
		return lowest;
	}
private:
	void findValue_DFS(TreeNode* root, TreeNode* p, TreeNode* q, unordered_map<TreeNode*, int> &count,TreeNode* &lowest,bool &find)
	{
		if (root == nullptr)
			return;
		findValue_DFS(root->left, p, q, count,lowest,find);
		findValue_DFS(root->right, p, q, count, lowest,find);

		if (find)return;

		if (root == p || root == q)
			count[root]++;
		count[root] += count[root->left] + count[root->right];
		if (count[root] == 2 && !find)
		{
			lowest = root;
			find = true;
		}
	}

	void findValue_BFS(TreeNode* root, TreeNode* p, bool &find_p, TreeNode* q, bool &find_q)
	{

		queue<TreeNode*> q_tree;
		q_tree.push(root);
		while (!q_tree.empty())
		{
			TreeNode* current = q_tree.front();
			q_tree.pop();
			if (current == p)
				find_p = true;
			else if (current == q)
				find_q = true;

			if (find_p&&find_q)
				return;

			if (current->left != nullptr)
				q_tree.push(current->left);
			if (current->right != nullptr)
				q_tree.push(current->right);
		}
		return;
	}
};