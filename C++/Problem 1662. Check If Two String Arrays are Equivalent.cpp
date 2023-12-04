#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2)
	{
		int length = max(word1.size(), word2.size());
		string str1, str2;

		for (int i = 0; i < length; i++){
			if (i < word1.size())
				str1 += word1[i];
			if (i < word2.size())
				str2 += word2[i];
		}

		return str1 == str2; 
	}
};
