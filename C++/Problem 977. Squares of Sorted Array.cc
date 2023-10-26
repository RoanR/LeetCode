#include <vector>
#include <cmath>

using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int positive; 
        int negative;
        vector<int> sortedSquareNums = {};

        positive = nums.size() -1;
        negative = 0;

        while (positive != negative){
            if (pow(nums[positive],2) > pow(nums[negative],2)){
                sortedSquareNums.insert(sortedSquareNums.begin(),pow(nums[positive],2));
                positive += -1; 
            } else {
                sortedSquareNums.insert(sortedSquareNums.begin(),pow(nums[negative],2));
                negative += 1;  
            }
        }

        sortedSquareNums.insert(sortedSquareNums.begin(),pow(nums[positive],2));
        return sortedSquareNums;
    }
};