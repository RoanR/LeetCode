#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<vector<int>> findDifference(vector<int>& nums1, 
			vector<int>& nums2)
	{
		unordered_map<int, bool> map_seen;
		for (int i = 0 ; i < nums1.size(); i++) {
			map_seen[nums1[i]] = false;
		}
		
		vector<vector<int>> ans;
		ans.push_back({});
		ans.push_back({});

		for (int i = 0; i < nums2.size(); i++) {
			if (map_seen.find(nums2[i]) == map_seen.end()) {
				ans[1].push_back(nums2[i]);
			}
			map_seen[nums2[i]] = true; 
			
		}

		for (auto nums : map_seen) {
			if (nums.second == false) {
				ans[0].push_back(nums.first);
			}
		}

		return ans;
	}
};
