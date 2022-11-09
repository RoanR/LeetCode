#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int increment = k%nums.size();
        k = gcd(k, nums.size());
        cout << k;

        for (int rot = 0; rot<k; rot++){
            int save_temp = 0;
            int write_temp = nums[rot];
            int count = rot + increment;

            while (count != rot){
                save_temp = nums[count];
                nums[count] = write_temp;
                write_temp = save_temp;
                count += increment;
                if (count >= nums.size()) {
                    count = count - nums.size();
                }
            }
            nums[rot] = write_temp;
        }
    }

    int gcd(int a, int b) {
        if (b == 0) 
            return a;
        else
            return gcd(b, a % b);
    }
};