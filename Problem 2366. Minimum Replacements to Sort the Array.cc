class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long count = 0;

        int n = nums.size();
        int previous = nums[n-1];
        int steps = 0;

        for(int i = n-2; i >=0; i--){
            if(nums[i] > previous){
                steps = (nums[i] - 1)/previous;
                previous = nums[i]/(steps+1);
                count+= steps;
            }else{
                previous = nums[i];
            }
        }
        return count;
    }
};
