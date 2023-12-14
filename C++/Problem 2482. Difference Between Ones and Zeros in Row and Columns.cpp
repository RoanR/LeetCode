#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> oneMinusZeros (vector<vector<int>>& grid) {
		vector<int> rows(grid.size(), 0);
		vector<int> cols(grid[0].size(), 0);

		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				if (grid[i][j] == 0) {
					rows[i]--;
					cols[j]--;
					continue;
				}
				rows[i]++;
				cols[j]++;
			}	
		}

		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[i].size(); j++) {
				grid[i][j] = rows[i]+ cols[j];
			}
		}

		return grid; 
		
	}
};
