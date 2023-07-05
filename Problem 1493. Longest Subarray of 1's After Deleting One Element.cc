class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int k = 0;
        bool all_ones = true; //special case

        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0){
                all_ones = false;
                continue;
            }
            if (nums[i] == 1 && (i == 0|| nums[i-1] == 0)){
                int current_k = 1; //Keeps track of current length of window
                bool current_z = false; //Keeps track of zeros encountered

                for (int j =i+1; j < nums.size(); j++){
                    if (nums[j] == 1){
                        current_k ++;
                        continue;
                    } else {
                        all_ones = false;
                        if (current_z)
                            break;
                        else
                            current_z = true;
                    }
                }
                if (current_k > k)
                    k = current_k;
            }
        }
        if (all_ones)
            return k-1; 
        return k;
    }           
 };
