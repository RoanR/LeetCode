#include <vector>
using namespace std; 
class Solution {
	vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
	{
		int max = candies[0];
		for (int n = 1; n < candies.size(); n++) {
			if (candies[n] > max)
				max = candies[n];
		}

		vector<bool> ans;
		for (int n = 0; n < candies.size(); n++) {
			if (candies[n] + extraCandies > max) {
				ans.push_back(true);
			} else {
				ans.push_back(false);
			}
		}
		return ans;
	}
};

