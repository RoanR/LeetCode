#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
	vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {

		
		/* Building Hashmap */
		unordered_map<int, vector<int>> pairMap;
		for (const vector<int>& pair : adjacentPairs) {
			pairMap[pair[0]].push_back(pair[1]);
			pairMap[pair[1]].push_back(pair[0]);
		}

		vector<int> result;
		int start = 0;

		/* Find First Element */
		for (const auto& adjs : pairMap) {
			if (adjs.second.size() == 1) {
				start = adjs.first;
				break;
			}
		}

		/* Left initialised to outside of range */
		int left = -1000000;
		result.push_back(start);

		/* Building list depth first */
		for (int i = 1; i <= adjacentPairs.size(); i++) {
			const vector<int> current = pairMap[start];
			int newval = (current[0] == left) ? 
				current[1] : current[0];
			result.push_back(newval);
			left = start;
			start = newval;
		}

		return result;
	}
};