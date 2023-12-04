#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public: 
	int countCharacters(vector<string>& words, string chars) 
	{
		int ret = 0;

		unordered_map<char, int> frequency;
		for (int i = 0; i < chars.length(); i++) {
			frequency[chars[i]]++;
		}

		unordered_map<char, int> temp_freq = frequency;
		for (auto word : words) {
			temp_freq = frequency;
			int i; 
			for (i = 0; i < word.length(); i++) {
				temp_freq[word[i]]--;
				if (temp_freq[word[i]] < 0) {
					break; 
				}
			}

			if (i < word.length())
				continue;
		       ret += word.length();	

		}

		return ret; 
	}
};
