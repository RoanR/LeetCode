#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
	int minPairSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int start = 0;
		int end   = nums.size()-1;
		int max   = 0;
		while (start < end) {
			if ((nums[start]+nums[end])>max) {
				max = nums[start]+nums[end]; 
			}
			start++;
			end--;
		}
		return max;
	}
};
