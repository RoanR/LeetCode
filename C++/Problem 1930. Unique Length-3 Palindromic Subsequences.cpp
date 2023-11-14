#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
	public: 
	int countPalindromicSubsequences(string s)
	{
		int total = 0; 

		/* Find Pairs */
		unordered_map<char, vector<int>> pairs;

		/* Find earliest occurance of each char */
		for (int i = 0; i < s.length(); i++) {
			if (!pairs.contains(s[i])) {
				pairs[s[i]] = {i};
			}
		}

		/* Find latest occurance of each char */
		/* Also prune chars with just single occurance */
		for (int i = s.length()-1; i >= 0; i--) {
			if (pairs[s[i]].second.size()==1) {
				if (i == pairs[s[i]].second[0]){
					pairs.erase(s[i]);
				} else {
					pairs[s[i]].second.push_back(i);
				}
			}
		}
		
		unordered_map<char, int> current;
		/* Count unique chars between each pair then add to total */
		for (auto pair : pairs) {
			for (int i=pair.second[0]+1; i<pair.second[1]; i++) {
				if(!current.contains(s[i])) {
					current[s[i]] = 1;
					if (current.size()==26) {
						break;
					}
				}
				total += current.size();
				current.clear();
			}

		}
	return total;	
	}
};
