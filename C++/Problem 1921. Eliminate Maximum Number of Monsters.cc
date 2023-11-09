#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int eliminateMaximum(vector<int>& dist, vector<int>& speed) 
	{
		vector<int> time;
		for (int i = 0; i < dist.size(); i++) {
			time.push_back(1+((dist[i]-1)/speed[i]));
		}
		sort(time.begin(), time.end());
		for (int i = 0; i < time.size(); i++){
			if (time[i] < i+1) {
				return i;
			}
		}
		return time.size();
	}
};
