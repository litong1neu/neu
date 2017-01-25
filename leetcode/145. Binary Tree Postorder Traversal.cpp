#include<vector>
#include<stack>
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
	vector<int> postorderTraversal(TreeNode* root) {
		TreeNode* current = root;
		stack<TreeNode*> tree_s;
		vector<int> res;

		while (current||!tree_s.empty())
		{
			if (current)
			{
				tree_s.push(current);
				current = current->left;			
			}
			else
			{
				TreeNode* temp = tree_s.top()->right;
				if (temp)
				{
					current = temp;
				}
				else
				{
					temp = tree_s.top();
					tree_s.pop();
					res.push_back(temp->val);
					cout << "haha" << endl;
					while (!tree_s.empty() && temp == tree_s.top()->right)
					{
						cout << "haha" << endl;
						temp = tree_s.top();
						tree_s.pop();
						res.push_back(temp->val);
					}

				}
			}
		}

		return res;


	}

	vector<int> postorderTraversalWithTwoStack(TreeNode* root)
	{
		stack<TreeNode*> s1;
		stack<TreeNode*> s2;
		vector<int> res;
		if (root)
		s1.push(root);

		while (!s1.empty())
		{
			TreeNode* current = s1.top();
			s2.push(current);
			s1.pop();
			if (current->left)
				s1.push(current->left);
			if (current->right)
				s1.push(current->right);
		}

		while (!s2.empty())
		{
			res.push_back(s2.top()->val);
			s2.pop();
		}

		return res;
	}
};

int main()
{
	Solution s;
	TreeNode head(1);
	head.right = new TreeNode(2);
	vector<int> v = s.postorderTraversalWithTwoStack(&head);
	for (auto val : v)
		cout << val << " ";
	system("pause");
}