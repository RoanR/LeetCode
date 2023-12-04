#include <string>
using namespace std;

class Solution {
public: 
	int numberOfWays(string corridor) 
	{
		int total = 0;
		int MOD   = 1e9 +7;
		int currS = 0; 
		int seenS = 0;
		while(currS < corridor.size()) {
			/* Skip if Plant */
			if (corridor[currS] == 'P') {
				currS++;
				continue;
			}

			/* Count to Two chairs*/ 
			seenS++; 
			if (seenS < 2) {
				currS++;
				continue;
			}

			/* Find Next Chair */
			int nextS;
			for (nextS = currS+1; nextS < corridor.size(); nextS++) {
				if (corridor[nextS] == 'S')
					break;
			}

			if (nextS == corridor.size()) {
				seenS = 0;
				break; 
			} else {
				total = (total * (nextS - currS)) % MOD;
				currS = nextS;
				seenS = 0; 
			}
		}

		if (seenS != 0)
			return 0;
		return total;
	}
};
