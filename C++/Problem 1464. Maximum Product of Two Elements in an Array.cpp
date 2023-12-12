#include <vector>
using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int maxF = 0; // First max
		int maxS = 0; // Second max
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > maxF) {
				maxS = maxF;
				maxF = nums[i];
				continue;
			}
			if (nums[i] > maxS) {
				maxS = nums[i];
			}
		}

		return (maxF-1)*(maxS-1);
	}
};
