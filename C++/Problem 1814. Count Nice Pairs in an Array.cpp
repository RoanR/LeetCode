#include <vector>
#include <unordered_map>
using namespace std; 

class Solution {
public:
	int reverseInt(int &num)
	{
		int ret = 0;
		int rem; 
		while (num != 0) {
			rem = num % 10;
			ret = (ret * 10) + rem;
			num /= 10; 
		}
		return ret; 
	}

	int countNicePairs(vector<int>& nums)
	{
		int mod = 1e9+7;
		unordered_map<int, long long> freq;
		for (int i = 0; i < nums.size(); i++) {
			freq[nums[i]-reverseInt(nums[i])]++;
		}

		long long total = 0; 
		for (auto &it: freq) {
			if (it.second > 1) {
				total += (it.second * (it.second -1) /2);
			}
		}
		return total%mod;
	}
};
