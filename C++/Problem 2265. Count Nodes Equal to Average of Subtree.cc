using namespace std;
/* Definition for a binary tree node. */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : 
		val(x), left(left), right(right) {}
};

struct Results {
	int total;
	int numNodes;
	Results(int x, int y) : total(x), numNodes(y) {}
};

class Solution {
public:
Results getAverage(TreeNode *root, int *answer) 
{
	/* Base case */
	if (root == nullptr) {
		return Results(0,0);
	}

	/* Get subtree Values */
	Results left = getAverage(root->left, answer);
	Results right = getAverage(root->right, answer);

	/* Calculate Subtree Average */
	int total = left.total + right.total + root->val;
	int numNodes = left.numNodes + right.numNodes + 1;

	/* Increment if condition is met */
	if ((total/numNodes) == root->val) {
		(*answer)++;
	}

	return Results(total, numNodes);
}
int averageOfSubtree(TreeNode* root) 
{
	int answer = 0;
	getAverage(root, &answer);
	return answer;
}
};