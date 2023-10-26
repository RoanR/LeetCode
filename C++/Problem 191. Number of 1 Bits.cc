using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int total = 0;
        for (int i = 0; i < 32; i++){
            total += (n >> i) & 1U;
        }
        return total; 
    }
};