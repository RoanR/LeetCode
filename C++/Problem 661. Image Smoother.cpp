#include <vector>
using namespace std;

class Solution {
private:
	int avg_kernel(int i, int j, vector<vector<int>>& img, int x, int y) {
		int total = 0;
		int div = 0;
		for (int m = i-1; m <= i+1; m++) {
			for (int n = j-1; n <= j+1; n++) {
				if (m<0||n<0)
					continue;
				if (m>=x||n>=y)
					continue;
				total += img[m][n];
			}
		}
		return total/9;
	}
public: 
	vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
		int m = img.size();
		int n = img[0].size();

		vector<vector<int>> ans(m, vector<int>(n));

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				ans[i][j] = avg_kernel(i, j, img, m, n);
			}
		}
		return ans;
	}
};
