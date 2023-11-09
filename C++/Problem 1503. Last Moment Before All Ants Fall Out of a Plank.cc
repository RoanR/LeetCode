#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int getLastMoment(int n, vector<int>& left, vector<int>& right)
	{

	/* Find Min of right */
	int min_ants = n; 
	if (right.size() != 0) {
		min_ants = *min_element(begin(right), end(right));
	}

	/* Find Max of left */
	int max_ants = 0; 
	if (left.size() != 0) {
		max_ants = *max_element(begin(left), end(left));
	}
	return max(max_ants, (n-min_ants));
	}
};