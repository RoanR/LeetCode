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
                return -1;}

            int i= (nums.size()/2); 

            if (nums[i] == target) {
                return index;} 
            else if (nums[i] < target) {
                nums = slice(nums, i+1, nums.size());
                print(nums);
                index += i+1;}
            else if (nums[i] > target) {
                nums = slice(nums, 0, i);
                print(nums);
                index += 0;}
        }
        return -2;
    }

    int print(vector<int> &v){
        for (auto i: v) {
            cout << i << ' ';
        }
        cout << endl;
        return 0;
    }

    vector<int> slice(vector<int> &v, int m, int n){
        auto first = v.cbegin() + m; 
        auto last = v.cbegin() + n;
        vector<int> vec(first, last);
        return vec;
    }
};
}