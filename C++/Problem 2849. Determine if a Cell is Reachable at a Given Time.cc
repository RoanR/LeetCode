#include <algorithm>
#include <cstdlib>
using namespace std;

class Solution {
public:
	bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
		if ((sx==fx) && (sy==fy)) {
			if (t != 1) {
				return true;
			} else {
				return false;
			}
		}
		if (t >= max(abs(sx-fx), abs(sy-fy))) {
			return true;
		}
		return false;
	}
};