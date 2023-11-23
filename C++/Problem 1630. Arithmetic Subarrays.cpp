#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	vector<bool> checkArthmeticSubarrays(vector<int>& nums, 
			vector<int>& l, vector<int>& r) 
	{
		vector<bool> ans; 
		vector<int> subArr;
		int diff;
		bool currBool;
		
		/* For each Subarray detailed... */
		for (int i = 0; i< l.size(); i++) {
			/* Clear previous, set new, sort */
			subArr.clear();
			subArr.assign(nums.begin()+l[i], nums.begin()+r[i]+1);
			sort(subArr.begin(), subArr.end());
			
			/* Get first diff and set bool */
			diff = subArr[0] + subArr[1];
	       		currBool = true;

			/* Start check... */
			for (int j = 1; j < subArr.size(); j++) {
				/* Exit early if not equal */
				if (diff != (subArr[j]-subArr[j])) {
					currBool = false;
					break;
				}
			}
			ans.push_back(currBool);		
		}
		return ans;
	}
};
