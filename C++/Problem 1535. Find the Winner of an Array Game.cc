#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int getWinner(vector<int>& arr, int k) 
	{
		/* To Store State info */
		int currWins = 0; 
		int currMax  = arr[0];

		/* Base Case */
		if (k == 1) {
			return max(currMax, arr[1]); 
		}

		/* Step Case */
		for (int i = 1; i < arr.size(); i++) {
			if (currMax >= arr[i]) {
				/* Repeat Winner*/
				currWins++;
				if  (currWins==k) {
					return currMax;
				}
			} else {
				/* New Winner */
				currWins = 1;
				currMax = arr[i];
			}
		}
		return currMax; 
	}
};