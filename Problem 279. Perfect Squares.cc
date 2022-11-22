#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        
        queue<vector<int>> to_check;
        vector<int> squares;
        int num_squares;

        //Find Squares under n
        for(int i = n; i > 0; i--){
            if ((i*i) < n) {
                squares.push_back(i*i);
                to_check.push({i*i,1});
            }  
            //cout<<"Checking "<<i*i;
            if ((i*i) == n) {
                return 1;
            }  
        }
        num_squares = squares.size()-1;

        //conduct a BFS to find minimum number 
        int total, level; 
        while(to_check.size()>0){
            total = to_check.front()[0];
            level = to_check.front()[1];
            to_check.pop();
            for (int i = num_squares; i >= 0; i--){
                //cout<<"Checking "<<total + squares[i];
                if (total + squares[i] == n){
                    return level + 1; 
                } else if (total + squares[i] < n){
                    to_check.push({total+squares[i], level+1});
                }
            }
        }
        return 0; 
    }
};