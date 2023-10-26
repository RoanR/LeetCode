#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int x = text1.length();
        int y = text2.length();
        int res = 0;
        vector<vector<int>> DP(y ,vector<int> (x, 0)); 

        for (int j = 0; j < x; j ++){
            if (text2[0] == text1[j]) {
                DP[0][j] = 1;
                res = 1; 
            }
            else if (j > 0) DP[0][j] = DP[0][j-1];
        }
        
        for (int i = 0; i < y; i ++){
            if (text2[i] == text1[0]) {
                DP[i][0] = 1;
                res = 1; 
            }
            else if (i > 0) DP[i][0] = DP[i-1][0];
        }

        for (int i = 1; i < y; i ++){
            for (int j = 1; j < x; j ++){
                if (text1[j] == text2[i]) DP[i][j] = DP[i - 1][j - 1] + 1;
                else DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
                if (DP[i][j] > res) res = DP[i][j];
            }
        }
        
        for (int i = 0; i < y; i ++){
            for (int j = 0; j < x; j ++){
                cout << DP[i][j] << " ";
            }
            cout << "\n";
        }
        
        return res; 
    }
};