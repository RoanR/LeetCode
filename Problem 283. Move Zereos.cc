#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_index = 0;
        while (zero_index < nums.size()){
            if (nums[zero_index] == 0) {
                for (int i=zero_index; i<nums.size(); i++){
                    if (nums[i] != 0){
                        swap(nums,i, zero_index);
                        i = nums.size();
                    }
                }
            }
            zero_index++;
            }
        }

    void swap(vector<int>& nums, int a, int b){
        int temp_a = nums[a];
        int temp_b = nums[b];
        nums[a] = temp_b;
        nums[b] = temp_a;
    }
};