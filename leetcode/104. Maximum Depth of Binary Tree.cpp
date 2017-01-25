#include<vector>
#include<iostream>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	int maxDepth(TreeNode* root) {
		vector<TreeNode*> ss;
		if (root)
			ss.push_back(root);
		return BFS(ss);
	}

private:
	int BFS(vector<TreeNode*> current_level)
	{
		static int depth = 0;
		if (current_level.empty())
			return depth;

		else
		{
			vector<TreeNode*> next_level;
			depth++;
			for (auto node : current_level)
			{
				if (node->left)
					next_level.push_back(node->left);
				if (node->right)
					next_level.push_back(node->right);
			}

			return BFS(next_level);
		}
	}

};

int main()
{
	TreeNode head(1);
	head.left = new TreeNode(2);
	Solution s;
	cout << s.maxDepth(&head);
	system("pause");
}