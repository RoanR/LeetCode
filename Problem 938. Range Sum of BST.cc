
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

    int treeSum(TreeNode* root){
        if (root == nullptr)
            return 0; 
        else 
            return (root->val) + treeSum(root->left) + treeSum(root->right);
    }

    int lowSum(TreeNode* root, int low){
        if (root == nullptr)
            return 0;
        else if (low <= root->val)
            return lowSum(root->left, low);
        else
            return root->val + lowSum(root->left, low) + lowSum(root->right, low);
    }

    int highSum(TreeNode* root, int high){
        if (root == nullptr)
            return 0;
        else if (high >= root->val)
            return highSum(root->right, high);
        else
            return root->val + highSum(root->left, high) + highSum(root->right, high);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        return treeSum(root) - lowSum(root, low) - highSum(root, high);
    }
};