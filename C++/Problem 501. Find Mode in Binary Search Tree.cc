#include <iostream>
#include <vector>
#include <unordered_map>
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



class Solution {
public:
	void recursion(TreeNode *root, unordered_map<int, int> *occurance)
	{
		if (root == nullptr) {
			return;
		}
		(*occurance)[(*root).val]++;
		recursion((*root).left, occurance);
		recursion((*root).right, occurance);
		return; 
	}

	vector<int> findMode(TreeNode* root) 
	{

		/* Setting up map for val:occurance */
		unordered_map<int, int> occurance;

		/* Starting recursion which maps vals to their frequency */
		recursion(root, &occurance);

		/* finding the max frequency */
		int freq = 0;
		for (auto i : occurance) {
			if (i.second > freq) {
				freq = i.second;
			}
		}

		/* Building return vector */
		vector<int> answer; 
		for (auto i: occurance) {
			if (i.second == freq) {
				answer.push_back(i.first); 
			}
		}

		return answer;
	}
};