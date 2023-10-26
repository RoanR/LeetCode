#include <vector>
#include <iostream>
namespace std {
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index = 0;
        bool loop = true;
        while (loop == true){
            if (nums.size() == 0){
                return index;}

            int i= (nums.size()/2); 

            if (nums[i] == target) {
                return index;} 
            else if (nums[i] < target) {
                nums = slice(nums, i+1, nums.size());
                index += i+1;}
            else if (nums[i] > target) {
                nums = slice(nums, 0, i);
                index += 0;}
        }
        return -2;
    }

    vector<int> slice(vector<int> &v, int m, int n){
        auto first = v.cbegin() + m; 
        auto last = v.cbegin() + n;
        vector<int> vec(first, last);
        return vec;
    }
};
}