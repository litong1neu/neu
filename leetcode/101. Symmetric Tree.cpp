#include<deque>

using namespace std;
 struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution_iterative {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr)
			return true;
		deque<TreeNode*> cur;
		cur.push_back(root->left);
		cur.push_back(root->right);
		while (!cur.empty())
		{
			if (!levelSym(cur))
				return false;
			deque<TreeNode*> next;
			for (int i = 0; i<cur.size(); i++)
			{
				if (cur[i])
				{
					next.push_back(cur[i]->left);
					next.push_back(cur[i]->right);
				}
			}
			cur = next;
		}
		return true;

	}
private:
	bool levelSym(deque<TreeNode*> cur)
	{
		if (cur.size() % 2 != 0)
			return false;
		while (!cur.empty())
		{
			TreeNode *head = *cur.begin();
			TreeNode *tail = *(cur.end() - 1);
			cur.pop_front();
			cur.pop_back();
			if (!head&&!tail)
				continue;
			if ((head&&!tail) || (!head&&tail))
				return false;
			if (head->val != tail->val)
				return false;
		}
		return true;
	}
};