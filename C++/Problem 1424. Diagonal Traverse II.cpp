#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& nums) 
	{
		queue<pair<int, int>> bfs;
		bfs.push({0,0});
		vector<int> ans;
		
		while(!bfs.empty()) {
			auto [row, col] = bfs.front();
			bfs.pop();

			ans.push_back(nums[row][col]);

			if (col == 0 && row + 1 < nums.size()) {
				bfs.push({row+1, col});
			}

			if (col + 1 < nums[row].size()) {
				bfs.push({row, col+1});
			}
		}
		return ans;
	}
};
