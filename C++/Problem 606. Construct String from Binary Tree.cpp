#include <string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
		right(right) {}
};

class Solution {
public:
	void SC(TreeNode *root, string &ans) 
	{
		if (root == nullptr)
			return;

		ans += to_string(root->val);
		if (root->left || root->right) {
			ans += "("; 
			SC(root->left, ans); 
			ans += ")";
		}

		if (root->right) {
			ans += "(";
		       	SC(root->right, ans);
			ans += ")";
		}
	}

	string tree2str(TreeNode *root) 
	{
		string ans;
		SC(root, ans);
		return ans; 
	}
};
