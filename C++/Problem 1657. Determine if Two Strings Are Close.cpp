#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool closeStrings(string word1, string word2) 
	{
		if (word1.length() != word2.length())
			return false;
	
		set<char> set1(word1.begin(), word1.end());
		set<char> set2(word2.begin(), word2.end());
		
		if (set1 != set2) 
			return false;

		unordered_map<char, int> map1;
		unordered_map<char, int> map2;
		
		for (int i = 0; i < word1.length(); i++) {
			map1[word1[i]]++;
			map2[word2[i]]++;
		}

		vector<int> freq1;
		for (auto i : map1) {
			freq1.push_back(i.second);
		}

		vector<int> freq2;
		for (auto i : map2) {
			freq2.push_back(i.second);
		}

		sort(freq1.begin(), freq1.end());
		sort(freq2.begin(), freq2.end());

		for (int i = 0; i < freq1.size(); i++){
			if (freq1[i] != freq2[i]) {
				return false;
			}
		}

		return true;
	}
};
