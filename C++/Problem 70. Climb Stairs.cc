#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        vector<int> fibonacci = {1,1};
        //cout << "1, 1";
        if (n == 1) return 1;
        for (int i = 1; i < n; i++){
            fibonacci.push_back(fibonacci[i] + fibonacci[i-1]);
            //cout << ", " << fibonacci[i] + fibonacci[i-1];
        }
        return fibonacci[n-1] + fibonacci[n-2]; 
    }
};