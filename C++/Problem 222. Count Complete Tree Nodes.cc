
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
    int countNodes(TreeNode* root) {
        if (root){
            int total = 0;
            if (root->left){
                total += countNodes(root->left); 
            }
            if (root->right){
                total += countNodes(root->right);
            }

            return 1 + total;
        }
        return 0;
    }
};