
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
    int getMaxDiff(TreeNode* root, int min, int max){
        if (root == nullptr) return max-min;
        int val = root->val;
        if (val > max) max = val;
        if (val < min) min = val;

        int left = getMaxDiff(root->left, min, max);
        int right = getMaxDiff(root->right, min, max);

        int currentDiff = max-min; 
        if (currentDiff < left) currentDiff = left;
        if (currentDiff < right) currentDiff = right;  
        return currentDiff;
    }
    int maxAncestorDiff(TreeNode* root) {
        if (root == nullptr) return 0;
        else return getMaxDiff(root, root->val, root->val); 
    }
};