#include <vector>
using namespace std;

class Solution {
public:
	int checkRow(vector<int>& row) {
		int index = -1;
		for (int i = 0; i < row.size(); i++) {
			if (row[i] == 1) {
				if (index >= 0) {
					return -1;
				} else {
					index = i; 
				}
			}
		}
		return index; 
	}

	int checkCol(vector<vector<int>>& mat, int j) {
		int index = -1; 
		for (int i = 0; i < mat.size(); i++) {
			if (mat[i][j] == 1) {
				if (index >= 0) {
					return false;
				} else {
					index = i;
				}
			}
		}
		return true;
	}

	int numSpecial(vector<vector<int>>& mat) {
		int ans = 0;
		for (int i = 0; i < mat.size(); i++) {
			int index = checkRow(mat[i]);
			if (index >= 0) {
				if (checkCol(mat, index)) {
					ans++;	
				}		
			}	
		}
		return ans; 	
	}
};
