#include<vector>
#include<unordered_map>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};



class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty() || inorder.empty())
			return nullptr;
		   unordered_map<int,int> in_map;
		   for(int i=0;i!=inorder.size();i++)
		       in_map[inorder[i]]=i;
		return help(preorder, in_map, 0, 0, inorder.size() - 1);
	}
private:
	TreeNode* help(vector<int>& preorder, unordered_map<int, int>& in_map, int preBegin, int inBegin, int inEnd)
	{
		if (inBegin>inEnd || preBegin>preorder.size() - 1)
			return nullptr;
		TreeNode* root = new TreeNode(preorder[preBegin]);
		int rootPos = in_map[preorder[preBegin]];
		root->left = help(preorder, in_map, preBegin + 1, inBegin, rootPos - 1);
		root->right = help(preorder, in_map, preBegin+rootPos - inBegin + 1, rootPos + 1, inEnd);
		return root;
	}
};

int main()
{
	vector<int> pre{ 1, 2, 3 };
	vector<int> in{ 2, 3, 1 };
	Solution s;
	s.buildTree(pre, in);
}