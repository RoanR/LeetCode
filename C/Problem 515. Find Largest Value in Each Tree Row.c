#include <stdlib.h> 
/* Definition for a binary tree node */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int* recursiveLargestValues(struct TreeNode *root, int *max, int index, 
	int *returnSize)
{
	if (root->val > max[index]) {
		max[index] = root->val;
	}

	if (*returnSize < index+1) {
		if ((root->left != NULL) || (root->right != NULL)) {
			max = realloc(max, sizeof(int)*index+1);
			*returnSize += 1;
		}
	}

	if (root->left != NULL) {
		recursiveLargestValues(root->left, max, index+1, returnSize);
	}

	if (root->right != NULL) {
		recursiveLargestValues(root->right, max, index+1, returnSize);
	}

	return max;
}
/*
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* largestValues(struct TreeNode* root, int* returnSize) 
{
	*returnSize = 0;
	if (root == NULL)
		return NULL;

	int *retVal = malloc(sizeof(int));
	retVal[0] = root->val;

	if ((root->left != NULL) || (root->right != NULL)) {
		retVal = realloc(retVal, sizeof(int)*2);
		*returnSize += 1;
	}

	if (root->left != NULL) {
		recursiveLargestValues(root->left, retVal, 1, returnSize);
	}

	if (root->right != NULL) {
		recursiveLargestValues(root->right, retVal, 1, returnSize);
	}

	return retVal;
}
