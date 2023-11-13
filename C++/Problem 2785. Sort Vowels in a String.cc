#include <string>
#include <map>
using namespace std;
/*
 * ASCII Chars Vowels:
 * 65, 69,  73,  79,  85, 
 * 97, 101, 105, 111, 117
 */

class Solution {
	public:
	map<int, int> baseMap() 
	{
		map<int, int> base;
		base.insert({117, 0});
		base.insert({111, 0});
		base.insert({105, 0});
		base.insert({101, 0});
		base.insert({97, 0});
		base.insert({85, 0});
		base.insert({79, 0});
		base.insert({73, 0});
		base.insert({69, 0});
		base.insert({65, 0});
		return base;
	}
	string sortVowels(string s) 
	{
		map<int, int> vowelMap = baseMap();
		for (int i = 0; i < s.length(); i++) {
			if (vowelMap.find(int(s[i])) != vowelMap.end()) {
				vowelMap[int(s[i])]++;
				s[i]='#';
			}
		}
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '#') {
				while(vowelMap.begin()->second == 0){
					vowelMap.erase(vowelMap.begin()->first);
				}
				s[i] = char(vowelMap.begin()->first);
				vowelMap.begin()->second--;
			}
		}
		return s;
	}
};