#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
	int minTimeToVisitAllPoints(vector<vector<int>>& points) 
	{
		int total = 0;
		for (int i = 0; i < points.size()-1; i++) {

			int yDiff = abs(points[i][1] - points[i+1][1]);
			int xDiff = abs(points[i][0] - points[i+1][0]);
			total += max(xDiff, yDiff); 
		}

		return total; 
	}
};
