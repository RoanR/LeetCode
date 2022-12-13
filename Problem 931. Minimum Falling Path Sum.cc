#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dynamic_min;
        int n = matrix.size();
        if (n == 1) return matrix[0][0];

        //Base case
        dynamic_min.push_back(matrix[0]);
        
        //Step case
        for (int i = 1; i < n; i++){
            vector<int> row = {};
            //First Element
            int current = min(dynamic_min[i-1][0], dynamic_min[i-1][1]);
            current += matrix[i][0];
            row.push_back(current);
            //Middle Elements
            for (int j = 1; j < n-1; j++){
                current = min({dynamic_min[i-1][j-1], dynamic_min[i-1][j], dynamic_min[i-1][j+1]});
                current += matrix[i][j];
                row.push_back(current);
            }
            //Last Element
            current = min(dynamic_min[i-1][n-2], dynamic_min[i-1][n-1]);
            current += matrix[i][n-1];
            row.push_back(current);
            dynamic_min.push_back(row);
        }
        return *min_element(dynamic_min[n-1].begin(), dynamic_min[n-1].end());
    }
};