#include <vector>
#include <iostream>
#include <algorithm>

using namespace std; 
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
    void print(vector<int> v) {
        for (auto i: v) {
            cout << i << ' ';
        }
        cout << endl;
    }
    void getLeaves(TreeNode* root, vector<int>& v){
        if (root==NULL){
            return;
        } else if (root->left==NULL && root->right==NULL){
            v.push_back(root->val);
            return;
        }

        getLeaves(root->left, v);
        getLeaves(root->right, v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        getLeaves(root1, v1);
        vector<int> v2; 
        getLeaves(root2, v2);

        return (v1 == v2);

    }
};