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
	string stepCaseTree2str(TreeNode *root) 
	{
		if (root == nullptr) {
			return "";
		} else {
			string left = stepCaseTree2str(root->left);
			string right = stepCaseTree2str(root->right);
			if (right != "" && left == "") {
				left = "()";
			}
			return "(" + to_string(root->val) + left + right + ")"; 
		}
	}

	string tree2str(TreeNode *root) 
	{
		string left = stepCaseTree2str(root->left);
		string right = stepCaseTree2str(root->right);
		if (right != "" && left == "") {
			left = "()";
		}
		return to_string(root->val) + left + right;  
	}
};
