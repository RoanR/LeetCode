#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
	int garbageCollection(vector<string>& garbage, vector<int>& travel) 
	{
		unordered_map<char, int> rubbish;
		rubbish['M'] = 0;
		rubbish['P'] = 0; 
		rubbish['G'] = 0;
		int total = 0; 
		for (int i = 0; i < garbage.size(); i++) {
            		for (int j = 0; j < garbage[i].length(); j++) {
				rubbish[garbage[i][j]] = i;
				total++;
			}
		}
		int runningTotal = 0;
		for (int i = 0; i <= travel.size(); i++) {
			if (i == rubbish['M']) {
				total += runningTotal;
			}
			if (i == rubbish['G']) {
				total += runningTotal;
			}
			if (i == rubbish['P']) {
 				total += runningTotal;
			}
			if (i < travel.size()){
				runningTotal += travel[i];
			}
		}
		return total;
	}
};
