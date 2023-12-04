#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	string largestGoodInteger(string num) {
		int currNum = -1;
		int currStr = 0;
		int ret = -1;
		for (int i = 0; i < num.length(); i++) {
			if (num[i] - 48 == currNum) {
				currStr++;
				if (currStr == 3) {
					ret = currNum;
					currNum = -1;
					currStr = 0;
				}
			} else if (num[i]- 48 < ret) {
				currStr = 0;
				currNum = -1;
				continue;
			} else {
				currStr = 1;
				currNum = num[i] - 48;
			}
		}

		if (ret != -1) {
			string retStr = to_string(ret); 
			retStr += to_string(ret) + to_string(ret); 
			return retStr;
		}
		return "";
	}
};
