

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
    int treeSumTotal(TreeNode* root){
        if (root == nullptr) return 0;
        root->val = root->val + treeSumTotal(root->left) + treeSumTotal(root->right);
        return root->val;
    }
    void recursiveMaxProduct(int treeTotal, long int *currentMax, TreeNode* currentNode){
        if (currentNode == nullptr) return;
        long int a = treeTotal - currentNode->val;
        long int b = currentNode->val;
        if (a*b > *currentMax) *currentMax = (a*b);
        recursiveMaxProduct(treeTotal, currentMax, currentNode->left);
        recursiveMaxProduct(treeTotal, currentMax, currentNode->right);
    }
    int maxProduct(TreeNode* root) {
        int total = treeSumTotal(root);
        int long max = 0;
        recursiveMaxProduct(total, &max, root);
        return max%(1000000007); 
    }
};