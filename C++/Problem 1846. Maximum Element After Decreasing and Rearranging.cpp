#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {

		/* Sort the Array */
		sort(arr.begin(), arr.end());

		/* Base case */
		arr[0] = 1;
		int previous = arr[0];

		/* Step Case */ 
		for (int i = 1; i < arr.size(); i++) {
			if (arr[i] > previous+1) {
				arr[i] = previous + 1;
			}
			previous = arr[i];
		}
		return previous;
	}
};
