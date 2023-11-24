#include <vector>
#include <algorithm>
using namespace std; 

class Solution {
public:
	int maxCoins(vector<int>& piles)
	{
		int ans = 0; 
		int pileSize = piles.size();
		
		/* Sort the piles */
		sort(piles.begin(), piles.end());
		
		for (int i = (pileSize/3); i < pileSize; i+=2) {
			ans += piles[i];
		}

		return ans; 

	}
};
