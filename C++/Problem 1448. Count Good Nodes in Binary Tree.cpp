#include <limits.h>

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	int goodTree(TreeNode *root, int max)
	{
		/* Base Case */
		if (root == nullptr)
			return 0;

		/* Step Case */
		int ret = 0;
		int currMax = max;

		if (root->val >= max) {
			ret = 1;
			currMax = root->val;	
		}
		
		/* Recusion */
		return ret + goodTree(root->left, currMax) + goodTree(root->right, currMax);
	}
	int goodNodes(TreeNode* root)
	{
		return goodTree(root, INT_MIN);
	}
};
