#include <vector>
#include <string>
using namespace std;

class Solution {
	public:
		string findDifferentBinaryString(vector<string>& nums) 
		{
			string unique = "";
			for (int i = 0; i < nums.size(); i++) {
				string current = nums[i];
				if (current[i] == '0') {
					unique += "1";
				} else {
					unique += "0";
				}
			}
			return unique;
		}
};
