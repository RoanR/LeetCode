#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
	string destCity(vector<vector<string>>& paths) 
	{
		// Map of possible starting locations
		unordered_set<string> startCitys;
		for (int i = 0; i < paths.size(); i++) {
			startCitys.insert(paths[i][0]);
		}

		for (int i = 0; i < paths.size(); i++) {
			if (startCitys.count(paths[i][1]) == 0) {
				return paths[i][1];
			}
		}

		return "";
	}
};

