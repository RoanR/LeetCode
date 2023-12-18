#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public: 
	int maxProductDifference(vector<int>& nums) 
	{
		int fMax = 0; 	    // Max Value
		int sMax = 0;       // Second Max Value
		int fMin = INT_MAX; // Min Value
		int sMin = INT_MAX; // Second Min Value 
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] >= fMax) {
				int temp = fMax;
				fMax = nums[i];
				sMax = temp;
			} else if (nums[i] > sMax) {
				sMax = nums[i];
			}

			if (nums[i] <= fMin) {
				int temp = fMin;
				fMin = nums[i];
				sMin = temp;
			} else if (nums[i] < sMin) {
				sMin = nums[i];
			}
		}

		return ((fMax*sMax) - (sMin*fMin));
	}
};
