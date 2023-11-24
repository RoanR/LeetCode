#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool checkMatch(string str1, string prefix) 
	{
		int length1 = str1.length() - 1;
		int lengthP = prefix.length() - 1;

		while (length1 >= 0) {
			if (str1[length1] != prefix[lengthP]){
				return false;
			}

			length1--;
			if (lengthP == 0) {
				lengthP = prefix.length()-1;
			} else {
				lengthP--;
			}
		}
		return true;	
	}
	string gcdOfStrings(string str1, string str2) 
	{
		int r, minL; 
		string prefix = "";
		string maxStr, minStr;

		if (str1.length() > str2.length()) {
			maxStr = str1;
			minStr = str2;
			minL   = str2.length();
		} else {
			maxStr = str2;
			minStr = str1;
			minL   = str1.length();
		}


		for (r = minL-1; r > 0; r--){
			prefix = minStr.substr(0, r);
			if ((str1.length()%(r+1) != 0) || 
					(str2.length() % (r+1) != 0)) {
				continue; 
			} 
			if (checkMatch(maxStr, prefix))
				return prefix;
		}
		return "";
	}
};
