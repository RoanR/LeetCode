#include <cmath>
using namespace std;

class Solution {
public:
	int minimumBitOperations(int n) 
	{	
		int res = 0;
		while (n > 0) {
			res = -(res + (n^(n-1)));
			n &= n-1;
		}
		return abs(res); 
	}
};
