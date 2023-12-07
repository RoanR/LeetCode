#include <string>
using namespace std;

class Solution {
public:
	string largestOddNumber(string num) 
	{
		for (int i = num.length()-1; i >= 0; i--) {
			int curr = num[i] - '0';
			if (curr % 2 == 1) {
				return num.substr(0, i+1);
			}
		}
		return "";
	}	
};
