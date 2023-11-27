#include <vector>
using namespace std;

class Solution {
public:
	int n;
	int MOD = 1e9+7;
	vector<vector<int>> workingPath;
	vector<vector<int>> jumps {
		{4,6},{6,8},{7,9},{4,8},{3,9,0},{},{1,7,0},{2,6},{1,3},{2,4}};
	
	int dp (int remain, int square) {
		if (remain == 0)
			return 1;
		if (workingPath[remain][square]!=0) 
			return workingPath[remain][square];

		int ans = 0;
		for (int i = 0; i < jumps[square].size(); i++)
			ans = (ans +  dp(remain - 1, jumps[square][i])) % MOD;

		workingPath[remain][square] = ans;
		return ans;
	}
	int knightDialer (int n) {
		this->n = n;	
		workingPath = vector(n+1, vector(10, 0));
		int ans = 0;
		for (int square = 0; square < 10; square++) 
			ans = (ans + dp(n-1, square)) % MOD;
		return 0; 
	}
};
